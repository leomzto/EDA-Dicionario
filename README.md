# Projeto: Dicionário PT-EN com Lista Encadeada

## Descrição do Projeto

Projeto desenvolvido como trabalho acadêmico da disciplina de **Estruturas de Dados e Algoritmos** do curso de **Sistemas de Informação** na **Universidade Federal de Viçosa**.

O objetivo é implementar um **dicionário português-inglês** utilizando **listas encadeadas**, permitindo armazenar palavras em português e inglês e suas respectivas traduções, além de traduzir textos.

## Funcionalidades

-   Inserção de palavras com suas traduções (PT → EN) em uma **lista encadeada**.
-   Consulta de traduções de palavras.
-   Tradução de textos inteiros, palavra por palavra.
-   Remoção de palavras do dicionário.
-   Exibição de todas as palavras armazenadas.
-   Permanência de palavras em um banco de dados

## Estrutura de Dados

O dicionário é implementado utilizando uma **lista encadeada simples**, onde cada nó contém:

-   Palavra em português (`pt`)
-   Tradução em inglês (`en`)
-   Ponteiro para o próximo nó (`prox`)

## Tecnologias Utilizadas

-   Linguagem: C++
-   Conceitos aplicados:
    -   Estruturas de dados (listas encadeadas)
    -   Manipulação de strings
    -   Algoritmos de busca e inserção
    -   SQLite3 (banco de dados)

## **Referencias**

-   [C-language Interface Specification for SQLite](https://www.sqlite.org/capi3ref.html "https://www.sqlite.org/capi3ref.html")
-   [SQL using C/C++ and SQLite](https://www.geeksforgeeks.org/cpp/sql-using-c-c-and-sqlite/ "https://www.geeksforgeeks.org/cpp/sql-using-c-c-and-sqlite/")
-   [SQLite - O Pequeno Notável](https://www.devmedia.com.br/sqlite-o-pequeno-notavel/7249 "https://www.devmedia.com.br/sqlite-o-pequeno-notavel/7249")  
    
-   [C++: Leitura de Arquivo Texto](https://vinicassol.medium.com/c-leitura-de-arquivo-texto-bae9d91febe4 "https://vinicassol.medium.com/c-leitura-de-arquivo-texto-bae9d91febe4")
-   ["String Streams" em C++](https://www.inf.pucrs.br/~flash/programming/aula_stringstreams.html "https://www.inf.pucrs.br/~flash/programming/aula_stringstreams.html")
-   [std::stringstream](https://cplusplus.com/reference/sstream/stringstream/ "https://cplusplus.com/reference/sstream/stringstream/")
-   [std::string](https://cplusplus.com/reference/string/string/ "https://cplusplus.com/reference/string/string/")
-   [stringstream in C++ and its Applications](https://www.geeksforgeeks.org/cpp/stringstream-c-applications/ "https://www.geeksforgeeks.org/cpp/stringstream-c-applications/")
-   [size_t data type in C](https://www.geeksforgeeks.org/c/size_t-data-type-c-language/ "https://www.geeksforgeeks.org/c/size_t-data-type-c-language/")
-   [stringstream Class In C++ – Usage Examples And Applications](https://www.softwaretestinghelp.com/stringstream-class-in-cpp/ "https://www.softwaretestinghelp.com/stringstream-class-in-cpp/")  
    
-   [Mastering stringstream in C++: A Comprehensive Guide](https://medium.com/@luaburak/mastering-stringstream-in-c-a-comprehensive-guide-7eda8a47679a "https://medium.com/@luaburak/mastering-stringstream-in-c-a-comprehensive-guide-7eda8a47679a")
-   Material de aula
    -   [Video aulas Programação Descomplicada](https://programacaodescomplicada.wordpress.com/indice/estrutura-de-dados/ "https://programacaodescomplicada.wordpress.com/indice/estrutura-de-dados/")
    -   PDFs da matéria