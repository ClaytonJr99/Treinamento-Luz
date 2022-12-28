#include "lista.hpp"
#include "fila.hpp"
#include "pilha.hpp"

int main() {
    Lista *lista = new Lista();
    Pilha *pilha = new Pilha();
    Fila *fila = new Fila();
    int opcao1, opcao2,valor, posicao;

    do {
        cout << "1 - Lista" << endl;
        cout << "2 - Pilha" << endl;
        cout << "3 - Fila" << endl;
        cout << "0 - Sair" << endl;
        cin >> opcao1;
    	cout << "\n";

        switch (opcao1) {
	        case 1:
	            do {
	                cout << "1- Inserir no inicio" << endl;
	                cout << "2- Inserir no final" << endl;
	                cout << "3- Remover do inicio" << endl;
	                cout << "4- Remover de uma posicao" << endl;
	                cout << "5- Mostrar lista" << endl;
	                cout << "0- Sair" << endl;
	                cin >> opcao2;
	
	                switch (opcao2) {
	                case 1:
	                    cout << "Digite um valor: ";
	                    cin >> valor;
	                    lista->inserirInicio(valor);
	                    break;
	                case 2:
	                    cout << "Digite um valor: ";
	                    cin >> valor;
	                    lista->inserirFinal(valor);
	                    break;
	                case 3:
	                    lista->deletarInicio();
	                    break;
	                case 4:
	                    cout << "Digite a posicao: ";
	                    cin >> posicao;
	                    if (posicao == 1) {
	                        lista->deletarInicio();
	                    } else {
	                        lista->removerEspecifico(posicao);
	                    }
	                    break;
	                case 5:
	                    lista->mostrar();
	                    cout << "\n";
	                    break;
	                case 0:
	                    exit(0);
	                    break;
	                default:
	                    cout << "Opcao invalida" << endl;
	            }
	            } while (opcao2 != 0);
	            break;
	        case 2:
	            do {
	                cout << "1- Inserir" << endl;
	                cout << "2- Remover" << endl;
	                cout << "3- Mostrar pilha" << endl;
	                cout << "0- Sair" << endl;
	                cin >> opcao2;
	
	                switch (opcao2) {
	                case 1:
	                    cout << "Digite um valor: ";
	                    cin >> valor;
	                    pilha->empilhar(valor);
	                    break;
	                case 2:
	                    pilha->desempilhar();
	                    break;
	                case 3:
	                    pilha->mostrar();
	                    cout << "\n";
	                    break;
	                case 0:
	                    exit(0);
	                    break;
	                default:
	                    cout << "Opcao invalida" << endl;
	            }
	            } while (opcao2 != 0);
	            break;
	        case 3:
	            do {
	                cout << "1- Inserir" << endl;
	                cout << "2- Remover" << endl;
	                cout << "3- Mostrar fila" << endl;
	                cout << "0- Sair" << endl;
	                cin >> opcao2;
	
	                switch (opcao2) {
	                case 1:
	                    cout << "Digite um valor: ";
	                    cin >> valor;
	                    fila->enfileirar(valor);
	                    break;
	                case 2:
	                    fila->desenfileirar();
	                    break;
	                case 3:
	                    fila->mostrar();
	                    cout << "\n";
	                    break;
	                case 0:
	                    exit(0);
	                    break;
	                default:
	                    cout << "Opcao invalida" << endl;
	            }
	            } while (opcao2 != 0);
	            break;
	        case 0:
	            exit(0);
	            break;
	        default:
	            cout << "Opcao invalida" << endl;
    	}
	} while (opcao1 != 0);
}
