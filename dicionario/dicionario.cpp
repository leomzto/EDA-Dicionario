#include "dicionario.hpp"
#include <sstream>

void inserirPalavra(Dicionario* dic, string* pt, string* en)
{
    // Lista
    Palavra* palavra = new Palavra(*pt, *en);
    No* novoNo = new No(palavra);
 
    if (dic->inicio == nullptr)
        dic->inicio = dic->fim = novoNo;
    else
    {
        dic->fim->prox = novoNo;
        dic->fim = novoNo;
    }

    dic->qtd_palavras++;

    // Banco de Dados

}


void removerPalavra(Dicionario* dic, string* palavra)
{
    // Lista
    No* posAtual = dic->inicio;
    No* posAnterior = nullptr;

    while (posAtual != nullptr)
    {
        if (posAtual->info->pt == *palavra || posAtual->info->en == *palavra)
        {
            if (posAnterior != nullptr)
                posAnterior->prox = posAtual->prox;
            else
                dic->inicio = posAtual->prox;

            if (posAtual == dic->fim)
                dic->fim = posAnterior;

            delete posAtual;
            dic->qtd_palavras--;
            break;
        }

        posAnterior = posAtual;
        posAtual = posAtual->prox;
    }

    // Banco de Dados



}

string buscarPalavra(Dicionario* dic, string* palavra)
{
    No* aux = dic->inicio;
    while(aux != nullptr)
    {
        if(aux->info->pt == *palavra)
            return aux->info->en;
        if (aux->info->en == *palavra)
            return aux->info->pt;
        aux = aux->prox;
    }
    return "";
}

void exibirDicionario(Dicionario* dic)
{
    No* posAtual = dic->inicio;

    cout << "\n-=- Dicionario (" << dic->qtd_palavras << " palavras) -=-\n";
    while (posAtual != nullptr)
    {
        cout << posAtual->info->pt << " -> " << posAtual->info->en << endl;
        posAtual = posAtual->prox;
    }
}

void traduzir(Dicionario* dic, string *texto)
{
    stringstream ler(*texto);
    string palavra;
    cout << "Traducao:" << endl;

    while (ler >> palavra)
    {
        string traduzida = buscarPalavra(dic, &palavra);
        if(traduzida.empty() != true)
            cout << traduzida << " ";
        else
            cout << palavra << " ";
    }

    cout << endl;
}


/*
void traduzirTeste01(Dicionario* dic, string *texto)
{
    string palavra; 
    cout << "Traducao:" << endl;

    for (char caractere : *texto) // para caada caractere no texto
    {
        if (caractere == ' ') // encontrou o fim da palavra
        {
            if (palavra.empty() == false)
            {
                string traducao = buscarPalavra(dic, &palavra);
                
                if (traducao.empty() == false)
                    cout << traducao << " ";
                else
                    cout << "[ " << palavra << " ]";

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