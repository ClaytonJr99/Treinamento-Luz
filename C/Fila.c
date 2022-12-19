#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct node{
	int valor;
	struct node *prox;
	// verificar se da erro na linha 7;
	
}node;

typedef struct fila{
	node *inicio;
	node *fim;
}fila;

void inicializaFila(fila *f){
	f->inicio = NULL;
	f->fim = NULL;
}


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
		while(novoNo != NULL){
			printf("%d ", novoNo->valor);
			novoNo = novoNo->prox;
		}
	}else{
		printf("Fila Vazia\n");
		return;
	}
}

int main(){
	fila *f1 = (fila*)malloc(sizeof(fila));
//	fila f1;
	
	inicializaFila(f1);
	
	
	
	enfileira(10, f1);
	enfileira(20, f1);
	enfileira(30, f1);
	desenfileira(f1);
	
	imprimir(f1);
	
}








