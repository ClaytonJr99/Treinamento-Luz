#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct node{
	int valor;
	struct node *proximo;
}node;

typedef struct pilha{
	node *topo;
}pilha;

void inicializaPilha(pilha *p){
	p->topo = NULL;
}

void empilhar(int valor, pilha *p){
	node *novoNo = (node*) malloc(sizeof(node));
	if(novoNo == NULL){
		printf("Novo nó não alocado\n");
	}else{
		novoNo->valor = valor;
		novoNo->proximo = p->topo;
		p->topo = novoNo;
	}
}

int desempilhar(pilha *p){
	node* novoNo = p->topo;
	int valor;
	if(novoNo == NULL){
		printf("Pilha vazia\n");
		return;
	}else{
		p->topo = novoNo->proximo;
		novoNo->proximo = NULL;
		valor = novoNo->valor;
		free(novoNo);
		return valor;
	}
}

void imprimir(pilha *p){
	node *novoNo = p->topo;
	if(novoNo == NULL){
		printf("Pilha vazia\n");
		return;
	}else{
		printf("FILA: \n");
		while(novoNo){
			printf("%d", novoNo->valor);
			novoNo = novoNo->proximo;
			printf("\n");
		}
		
	}
}

int main(){
	pilha p1;

	int opcao, numero;
	do{
		printf("informe a operacao que deseja realizar\n");
		printf("1 - Empilhar\n");
		printf("2 - Desempilhar\n");
		printf("3 - Imprimir\n");
		printf("0 - Sair\n");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1:
				printf("informe informe o numero para empilhar\n");
				scanf("%d", &numero);
				empilhar(numero, &p1);
				break;
			case 2:
				desempilhar(&p1);
				break;
			case 3: 
				imprimir(&p1);
			break;
		}
	}while(opcao != 0);
	
	
}



