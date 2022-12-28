#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

typedef struct node{
    int valor;  
    struct node *esquerda; 
    struct node *direita;
} node;

typedef struct arvore{
    node *raiz;  
} arvore;

void inserirNo(node *raiz, node *novoNo){
    if (novoNo->valor < raiz->valor) {  
        if (raiz->esquerda == NULL) {  
            raiz->esquerda = novoNo;  
        } else {
            inserirNo(raiz->esquerda, novoNo);
        }
    } else if (novoNo->valor > raiz->valor) {
        if (raiz->direita == NULL) {  
            raiz->direita = novoNo;  
        } else {
            inserirNo(raiz->direita, novoNo); 
        }
    } else {
        free(novoNo);
    }
}

void inserirValor(arvore *a, int valor){
	node *novoNo = (node *) malloc(sizeof(node)); 
    novoNo->valor = valor;  
    novoNo->esquerda = NULL; 
    novoNo->direita = NULL;
	 
    if (a->raiz == NULL) { 
        a->raiz = novoNo; 
    } else {
        inserirNo(a->raiz, novoNo);  
    }
}

node* remover(node *raiz, int valor){
    if (raiz == NULL) { 
        printf("\nInvalido\n");
        return NULL;
    } else if (valor < raiz->valor) {  
        raiz->esquerda = remover(raiz->esquerda, valor);  //chama a função passando o filho da esquerda sendo a raiz
    } else if (valor > raiz->valor) {  
        raiz->direita = remover(raiz->direita, valor);  //chama a função passando o filho da esquerda sendo a raiz
    } else {  //se o valor for igual ao valor da raiz
        if (raiz->esquerda == NULL && raiz->direita == NULL) {  //se o nó raiz não tiver filhos
            free(raiz);  
            raiz = NULL;  
        } else if (raiz->esquerda == NULL) {  //se o nó raiz tiver apenas o filho a direita
            node *auxiliar = raiz;  
            raiz = raiz->direita;  
            free(auxiliar);  
        } else if (raiz->direita == NULL) {  //se o nó raiz tiver apenas o filho a esquerda
            node *auxiliar = raiz;  
            raiz = raiz->esquerda;  
            free(auxiliar); 
        } else {  //se o nó raiz tiver os dois filhos
            node *auxiliar = raiz->direita;  
            while (auxiliar->esquerda != NULL) {  
                auxiliar = auxiliar->esquerda;  
            }
            raiz->valor = auxiliar->valor;  
            auxiliar->valor = valor;  
            raiz->direita = remover(raiz->direita, valor);  
}
    }
    return raiz;
}

void ordem(node *raiz){
    if (raiz != NULL) {  
        ordem(raiz->esquerda); 
        printf("%d ", raiz->valor);  
        ordem(raiz->direita);
    }
}

void preOrdem(node *raiz){
    if (raiz != NULL) {  
        printf("%d ", raiz->valor);  
        preOrdem(raiz->esquerda); 
        preOrdem(raiz->direita);
    }
}

void posOrdem(node *raiz){
    if (raiz != NULL) {  
        posOrdem(raiz->esquerda);  
        posOrdem(raiz->direita);  
        printf("%d ", raiz->valor);
    } 
}

void main(){
	setlocale(LC_ALL, "Portuguese");
	
	arvore *a = (arvore *) malloc(sizeof(arvore));  
    a->raiz = NULL; 
	
    int opcao, num;
    
    inserirValor(a, 15);
    inserirValor(a, 10);
    inserirValor(a, 18);
    inserirValor(a, 7);
    inserirValor(a, 20);
    inserirValor(a, 3);
    inserirValor(a, 9);
    inserirValor(a, 30);
    inserirValor(a, 27);
    
    do
    {
        printf("\nInforme a operação que deseja realizar\n");
        printf("1 - Inserir elemento na arvore\n");
        printf("2 - Imprimir arvore em pre ordem\n");
        printf("3 - Imprimir arvore em ordem\n");
        printf("4 - Imprimir arvore em pos ordem\n");
        printf("5 - Remover elemento da arvore\n");
        printf("0 - Sair\n\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite o numero que deseja inserir: ");
            scanf("%d", &num);
            inserirValor(a, num);
            break;
        case 2:
            preOrdem(a->raiz);
            break;
        case 3:
            ordem(a->raiz);
            break;
        case 4:
            posOrdem(a->raiz);
            break;
        case 5:
            printf("Digite o numero que deseja remover: ");
            scanf("%d", &num);
            a->raiz = remover(a->raiz, num);
            break;
        default:
            printf("Opção invalida\n");
        }
    } while (opcao != 0);
    
    return;
}

