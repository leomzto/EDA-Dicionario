#include "dicionario.hpp"

int main()
{
    Dicionario dic;

    int opc;
    string pt, en, palavra, texto;

    do 
    {
        cout << "\n -- Menu --" << endl;
        cout << "[1]. Inserir Palavra" << endl;
        cout << "[2]. Remover Palavra" << endl;
        cout << "[3]. Buscar Palavra" << endl;
        cout << "[4]. Exibir Dicionario" << endl;
        cout << "[5]. Traduzir Texto" << endl;
        cout << "[0]. Sair" << endl;
        cin >> opc;
        cin.ignore();

        switch(opc)
        {
            case 0:
                cout << "Saindo..." << endl;
                break;
            case 1:
                {
                    cout << "Palavra em PT-BR: "; cin >> pt;
                    cout << "Palavra em EN-US: "; cin >> en;
                    inserirPalavra(dic, pt, en);

                    break;
                }
            case 2:
                {
                    cout << "Palavra a ser removida: "; cin >> palavra;
                    removerPalavra(dic, palavra);

                    break;
                }
            case 3:
                {
                    cout << "Palavra a ser buscada: "; cin >> palavra;

                    {
                        string traducao = buscarPalavra(dic, palavra);
                        if (traducao.empty() == false)
                            cout << "Traducao: " << traducao << endl;
                        else 
                            cout << "Palavra nao encontrada." << endl;
                    }

                    break;
                }
            case 4:
                {
                    exibirDicionario(dic);

                    break;
                }
            case 5:
                {
                    cout << "Texto a ser traduzido: ";
                    getline(cin, texto);
                    traduzir(dic, texto);

                    break;
                }
        }
        
    } while (true);

    return 0;
}