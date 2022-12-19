#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct node{
	int valor;
	struct node *prox;

}node;

typedef struct fila{
	node *inicio;
	node *fim;
}fila;

void enfileira(int valor, fila *f){
	node *novoNo = (node*) malloc(sizeof(node));
	if(novoNo == NULL){
		printf("Erro de alocação.\n");
		return;
	}else{
		novoNo->valor = valor;
		novoNo->prox = NULL;
		if(f->inicio == NULL){
			f->inicio = novoNo;
		}else{
			f->fim->prox = novoNo;
		}
		
		f->fim = novoNo;
		return;
	}
}

int desenfileira(fila *f){
	node *novoNo = f->inicio;
	int dado;
	if(novoNo != NULL){
		f->inicio = novoNo->prox;
		novoNo->prox = NULL;
		dado = novoNo->valor;
		free(novoNo);
		if(f->inicio == NULL){
			f->fim == NULL;
		}
		return dado;
	}else{
		printf("Não é possivel remover, a fila já está vazia\n");
		return;
	}
}

void imprimir(fila *f){
	node *novoNo = f->inicio;
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
	
	fila *f1 = (fila*)malloc(sizeof(fila));
	f1->inicio = NULL;
	f1->fim = NULL;
	
	int opcao, numero;
	
	do{
		printf("\ninforme a operacao que deseja realizar\n");
		printf("1 - Enfileirar\n");
		printf("2 - Desenfileirar\n");
		printf("3 - Imprimir\n");
		printf("0 - Sair\n");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1:
				printf("informe informe o numero para enfileirar\n");
				scanf("%d", &numero);
				enfileira(numero, f1);
				break;
			case 2:
				desenfileira(f1);
				break;
			case 3: 
				imprimir(f1);
			break;
		}	
			
	}while(opcao != 0);
}








