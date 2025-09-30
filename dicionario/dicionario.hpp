#ifndef DICIONARIO_HPP
#define DICIONARIO_HPP

#include <string>
#include <sqlite3.h>
#include <iostream>

using namespace std;

typedef struct sPalavra {
    string pt;
    string en;

    sPalavra(string pt_br, string en_us) : pt(pt_br), en(en_us) {}
} Palavra;

typedef struct sNo {
    Palavra info;
    sNo* prox;

    sNo(Palavra &palavra) : info(palavra), prox(nullptr) {}
} No; 

typedef struct sDicionario {
    No* inicio;
    No* fim;
    int qtd_palavras;

    sDicionario() : inicio(nullptr), fim(nullptr), qtd_palavras(0) {}

    ~sDicionario()
    {
        No* atual = inicio;
        while (atual != nullptr)
        {
            No* prox = atual->prox;
            delete atual;
            atual = prox;
        }
    }
} Dicionario;

// Dicionario
void inserirPalavra(Dicionario &dic, string &pt, string &en);
void removerPalavra(Dicionario &dic, string &palavra);

string buscarPalavra(Dicionario &dic, string &palavra);
void exibirDicionario(Dicionario &dic);

void traduzir(Dicionario &dic, string &texto);
//void traduzirTeste01(Dicionario* dic, string *texto);
//void traduzirTeste02(Dicionario* dic, string *texto);


// Banco de Dados
bool inicializarBanco();
void fecharBanco();

void carregarDicionario(Dicionario &dic);



#endif