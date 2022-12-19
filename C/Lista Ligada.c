#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct node{
	int valor;
	struct node *prox;

}node;

typedef struct lista{
	node *inicio;
	node *fim;
	int tamanho;
}lista;


node *criarNo(int valor)
{
    node *novoNo = (node *)malloc(sizeof(node));
    novoNo->valor = valor;
    novoNo->prox = NULL; 
    return novoNo;
}

void inserirInicio(int valor, lista *l){
	node *novoNo = criarNo(valor);
	
	if(l->inicio == NULL){  // se a lista estiver vazia
	
		l->inicio = novoNo;
		l->fim = novoNo;
	}else{
		novoNo->prox = l->inicio;
		l->inicio = novoNo;
	}
	l->tamanho ++;
	
}

void inserirFinal(int valor, lista *l){
	
	node *novoNo = criarNo(valor);
	
	if(l->inicio == NULL){
		l->inicio = novoNo;
		l->fim = novoNo;
	}else{
		l->fim->prox = novoNo;
		l->fim = novoNo;
	}
	l->tamanho ++;
	
}

void removerInicio(lista *l){
	
	if(l->inicio != NULL){
		node *novoNo = l->inicio;
		l->inicio = l->inicio->prox;
		l->tamanho --;
		if(l->inicio == NULL){
			l->fim = NULL;
		}
		free(novoNo);
	}
	
}

void removerEspecifico(int valor, lista *l){
	node *noAnterior = NULL;
	node *noAtual = l->inicio;
	
	while(noAtual != NULL && noAtual->valor != valor){
		noAnterior = noAtual;
		noAtual = noAtual->prox;
	}
	

	if(!noAtual){
		printf("\n Valor não existe \n");
		return;
	}
	
	if(noAtual != NULL){
		if(noAnterior == NULL){
			removerInicio(l);
		}
	}
	
		noAnterior->prox = noAtual->prox;
		l->tamanho --;
		if(noAtual == l->tamanho){
			l->fim = noAnterior;
		}
		free(noAtual);
	
}


void imprimir(lista *l){
	node *novoNo = l->inicio;
	if(novoNo != NULL){
		printf("\nFila:");
		while(novoNo != NULL){
			printf("%d ", novoNo->valor);
			novoNo = novoNo->prox;
		}
		printf("\n");
	}else{
		printf("Fila Vazia\n");
		return;
	}
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	lista *l1 = (lista*)malloc(sizeof(lista));
	l1->inicio = NULL;
	l1->fim = NULL;
	
	int opcao, numero;
	
	do{
		printf("\ninforme a operacao que deseja realizar\n");
		printf("1 - Inserir no inicio\n");
		printf("2 - Inserir no final\n");
		printf("3 - Remover do inicio\n");
		printf("4 - Remover um valor especifico\n");
		printf("5 - Imprimir\n");
		printf("0 - Sair\n");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1:
				printf("informe informe o numero para inserir\n");
				scanf("%d", &numero);
				inserirInicio(numero, l1);
				break;
			case 2:
				printf("informe informe o numero para inserir\n");
				scanf("%d", &numero);
				inserirFinal(numero, l1);
				break;
			case 3: 
				removerInicio(l1);
				break;
			case 4: 
				printf("informe informe o numero para remover\n");
				scanf("%d", &numero);
				removerEspecifico(numero, l1);		
				break;
			case 5: 
				imprimir(l1);	
			break;
			
		}	
			
	}while(opcao != 0);
	
}








