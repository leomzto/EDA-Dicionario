#include "dicionario.hpp"
#include <sstream>

sqlite3* db;

void inserirPalavra(Dicionario &dic, string &pt, string &en, bool salvarNoDB = true)
{
    Palavra palavra(pt, en);
    No* novoNo = new No(palavra);

    if (dic.inicio == nullptr)
        dic.inicio = dic.fim = novoNo;
    
    else if (pt < dic.inicio->info.pt) // ordena alfabeticamente em pt_br
    {
        novoNo->prox = dic.inicio;
        dic.inicio = novoNo;
    }
    else
    {
        No* atual = dic.inicio;
        while (atual->prox != nullptr && atual->prox->info.pt < pt)
            atual = atual->prox;
    
        novoNo->prox = atual->prox;
        atual->prox = novoNo;

        if (novoNo->prox == nullptr)
            dic.fim = novoNo;
    }

    dic.qtd_palavras++;

    // Bando de Dados
    // "INSERT INTO palavras (pt_br, en_us) VALUES (?, ?);"

    if (salvarNoDB)
    {
        sqlite3_stmt* stmt;
        const char* sql = "INSERT INTO palavras (pt_br, en_us) VALUES (LOWER(?), LOWER(?));";
        
        int preparacao = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
        if (preparacao != SQLITE_OK)
        {
            cerr << "Erro ao preparar a query: " << sqlite3_errmsg(db) << endl;
            return;
        }
        
        sqlite3_bind_text(stmt, 1, pt.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 2, en.c_str(), -1, SQLITE_TRANSIENT);
        
        int passos = sqlite3_step(stmt);
        if (passos != SQLITE_DONE)
            cerr << "Erro ao executar a query: " << sqlite3_errmsg(db) << endl;
        
        sqlite3_finalize(stmt);
    }
}

void removerPalavra(Dicionario &dic, string &palavra)
{
    // Lista
    No* posAtual = dic.inicio;
    No* posAnterior = nullptr;

    while (posAtual != nullptr)
    {
        if (posAtual->info.pt == palavra || posAtual->info.en == palavra)
        {
            if (posAnterior != nullptr)
                posAnterior->prox = posAtual->prox;
            else
                dic.inicio = posAtual->prox;

            if (posAtual == dic.fim)
                dic.fim = posAnterior;

            delete posAtual;
            dic.qtd_palavras--;
            break;
        }

        posAnterior = posAtual;
        posAtual = posAtual->prox;
    }

    // Banco de Dados
    // "DELETE FROM palavras WHERE pt_br = ? OR en_us = ?;"

    sqlite3_stmt* stmt;
    const char* sql = "DELETE FROM palavras WHERE pt_br = LOWER(?) OR en_us = LOWER(?);";
    
    int preparacao = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (preparacao != SQLITE_OK)
    {
        cerr << "Erro ao preparar a query: " << sqlite3_errmsg(db) << endl;
        return;
    }
    
    sqlite3_bind_text(stmt, 1, palavra.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, palavra.c_str(), -1, SQLITE_TRANSIENT);
    
    int passos = sqlite3_step(stmt);
    if (passos != SQLITE_DONE)
        cerr << "Erro ao executar a query: " << sqlite3_errmsg(db) << endl;
    
    sqlite3_finalize(stmt);
}

string buscarPalavra(Dicionario &dic, string &palavra)
{
    No* aux = dic.inicio;
    while(aux != nullptr)
    {
        if(aux->info.pt == palavra)
            return aux->info.en;
        if (aux->info.en == palavra)
            return aux->info.pt;
        aux = aux->prox;
    }
    return "";
}

void exibirDicionario(Dicionario &dic)
{
    No* posAtual = dic.inicio;

    cout << "\n-=- Dicionario (" << dic.qtd_palavras << " palavras) -=-\n";
    while (posAtual != nullptr)
    {
        cout << posAtual->info.pt << " -> " << posAtual->info.en << endl;
        posAtual = posAtual->prox;
    }
}

void traduzir(Dicionario &dic, string &texto)
{
    stringstream ler(texto);
    string palavra;
    cout << "Traducao:" << endl;

    while (ler >> palavra)
    {
        string traduzida = buscarPalavra(dic, palavra);
        if(traduzida.empty() != true)
            cout << traduzida << " ";
        else
            cout << "[" << palavra << "]";
    }

    cout << endl;
}


/*
// teste de traduçao:
void traduzirPalavra(Dicionario &dic, string &texto)
{
    string palavra; 
    cout << "Traducao:" << endl;

    for (char caractere : texto) // para cada caractere no texto
    {
        if (caractere == ' ') // encontrou o fim da palavra
        {
            if (palavra.empty() == false)
            {
                string traducao = buscarPalavra(dic, palavra);
                
                if (traducao.empty() == false)
                    cout << traducao << " ";
                else
                    cout << "[" << palavra << "]";

                palavra.clear();
            }
            else
                palavra += caractere; // avança caractere
        }
    }

    if (palavra.empty() == false)
    {
        string traducao = buscarPalavra(dic, &palavra);
        
        if (traducao.empty() == false)
            cout << traducao << " ";
        else
            cout << "[ " << palavra << " ]";
    }

    cout << endl;
}
*/

// Banco de Dados

bool inicializarBanco()
{
    int openSQL = sqlite3_open("dicionario.db", &db);

    if (openSQL != SQLITE_OK)
    {
        cerr << "Erro ao abrir dicionario.db: " << sqlite3_errmsg(db) << endl;
        return false;
    }

    const char* sql = "CREATE TABLE IF NOT EXISTS palavras (id INTEGER PRIMARY KEY AUTOINCREMENT, pt_br TEXT NOT NULL COLLATE NOCASE, en_us TEXT NOT NULL COLLATE NOCASE);";
    
    char*  errmsg;

    int execSQL = sqlite3_exec(db, sql, nullptr, nullptr, &errmsg);

    if(execSQL != SQLITE_OK)
    {
        cerr << "Erro ao criar a tabela palavras: " << errmsg << endl;
        sqlite3_free(errmsg);
        return false;
    }

    return true;
}

void fecharBanco()
{
    if (db)
    {
        sqlite3_close(db);
        db = nullptr;
    }
}

void carregarDicionario(Dicionario &dic)
{
    const char* sql = "SELECT pt_br, en_us FROM palavras ORDER BY pt_br COLLATE NOCASE ASC;";

    sqlite3_stmt* stmt = nullptr;

    int declaracao = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

    if (declaracao != SQLITE_OK)
    {
        cerr << "Erro na preparacao da querry: " << sqlite3_errmsg(db) << endl;
        return;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        const char* palavra_pt = (const char*) sqlite3_column_text(stmt, 0);
        const char* palavra_en = (const char*) sqlite3_column_text(stmt, 1);

        string pt, en;

        if (palavra_pt)
            pt = palavra_pt;
        else pt = "";
        
        if (palavra_en)
            en = palavra_en;
        else
            en = "";

        inserirPalavra(dic, pt, en, false);
    }

    sqlite3_finalize(stmt);
}