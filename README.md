# Projeto: Dicionário PT-EN com Lista Encadeada

## Descrição do Projeto

Projeto desenvolvido como trabalho acadêmico da disciplina de **Estruturas de Dados e Algoritmos**.

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

-   [https://www.sqlite.org/docs.html](https://www.sqlite.org/docs.html "https://www.sqlite.org/docs.html")
-   [https://pt.stackoverflow.com/questions/319622/quando-usar-o-cin-ignore-em-c](https://pt.stackoverflow.com/questions/319622/quando-usar-o-cin-ignore-em-c "https://pt.stackoverflow.com/questions/319622/quando-usar-o-cin-ignore-em-c")
-   [https://www.inf.pucrs.br/~flash/programming/aula_stringstreams.html](https://www.inf.pucrs.br/~flash/programming/aula_stringstreams.html "https://www.inf.pucrs.br/~flash/programming/aula_stringstreams.html")
-   [https://cplusplus.com/reference/sstream/stringstream/](https://cplusplus.com/reference/sstream/stringstream/ "https://cplusplus.com/reference/sstream/stringstream/")
-   [https://cplusplus.com/reference/string/string/](https://cplusplus.com/reference/string/string/ "https://cplusplus.com/reference/string/string/")
-   [https://www.geeksforgeeks.org/cpp/stringstream-c-applications/](https://www.geeksforgeeks.org/cpp/stringstream-c-applications/ "https://www.geeksforgeeks.org/cpp/stringstream-c-applications/")
-   [https://www.geeksforgeeks.org/c/size_t-data-type-c-language/](https://www.geeksforgeeks.org/c/size_t-data-type-c-language/ "https://www.geeksforgeeks.org/c/size_t-data-type-c-language/")
-   [https://www.softwaretestinghelp.com/stringstream-class-in-cpp/](https://www.softwaretestinghelp.com/stringstream-class-in-cpp/ "https://www.softwaretestinghelp.com/stringstream-class-in-cpp/")
-   [https://medium.com/@luaburak/mastering-stringstream-in-c-a-comprehensive-guide-7eda8a47679a](https://medium.com/@luaburak/mastering-stringstream-in-c-a-comprehensive-guide-7eda8a47679a "https://medium.com/@luaburak/mastering-stringstream-in-c-a-comprehensive-guide-7eda8a47679a")
-   Material de aula
    -   [Video aulas Programação Descomplicada](https://programacaodescomplicada.wordpress.com/indice/estrutura-de-dados/ "https://programacaodescomplicada.wordpress.com/indice/estrutura-de-dados/")
    -   PDFs da matéria