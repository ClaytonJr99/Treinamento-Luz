#include <iostream>

using namespace std;

class Node {
    public:
        int dado;
        Node *proximo;
    	Node(int dado) {
        this->dado = dado;
        this->proximo = NULL;
    }
};
class Lista {
    private:
        Node *inicio, *fim;
    public:
        Lista() {
            inicio = NULL;
            fim = NULL;
        }
        void inserirInicio(int valor) {
            Node *novoNo = new Node(valor);
            if (inicio == NULL) {
                inicio = novoNo;
                fim = novoNo;
            } else {
                novoNo->proximo = inicio;
                inicio = novoNo;
            }
        }
        void inserirFinal(int valor) {
            Node *novoNo = new Node(valor);
            if (inicio == NULL) {
                inicio = novoNo;
                fim = novoNo;
            } else {
                fim->proximo = novoNo;
                fim = novoNo;
            }
        }
        void deletarInicio() {
            Node *novoNo;
            novoNo = inicio;
            inicio = inicio->proximo;
            delete novoNo;
        }
        void removerEspecifico(int posicao) {
            Node *valorAtual;
            Node *valorAnterior;
            valorAtual = inicio;
            for (int i = 1; i < posicao; i++) {
                valorAnterior = valorAtual;
                valorAtual = valorAtual->proximo;
            }
            valorAnterior->proximo = valorAtual->proximo;
        }
        void mostrar() {
            Node *novoNo;
            novoNo = inicio;
            while (novoNo != NULL) {
                cout << novoNo->dado << " ";
                novoNo = novoNo->proximo;
            }
        }
};
