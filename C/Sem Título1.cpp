#include <stdio.h>
#include <stdlib.h>

//typedef cria um apelido 
typedef struct ponto{
	int x, y; //serão as coordenadas do ponto
	struct ponto * proximo; // ponteiro para o proximo elemento
}t_ponto; // apelido para o struct

void listaligada(){
	t_ponto * ini_ponto; //ponteiro que marca o inicio da lista
	t_ponto * proximo_ponto; // ponteiro que marca o proximo elemento
	int resp;
	
	ini_ponto = (t_ponto *)malloc(sizeof(t_ponto));
	if(ini_ponto == NULL){
		exit(1);
	}
	
	proximo_ponto = ini_ponto; // fz a proximo ponto apontar para o mesmo endereco de ini_ponto
	
	while(1){
		printf("Digite o valor de x: ");
		scanf("%d", &proximo_ponto->x); //pega o valor do X
		printf("Digite o valor de y: ");
		scanf("%d", &proximo_ponto->y); //pega o valor do X
		printf("Deseja continuar? [1] - Sim - Outro valor para Nao: ");
		scanf("%d", &resp);
		if(resp ==1){
			proximo_ponto->proximo = (t_ponto*)malloc(sizeof(t_ponto));	// Aloca a memoria para o proximo elemento
			proximo_ponto = proximo_ponto->proximo;
		}else{
			break;
		}
		
	}
	//mostrar os dados
	printf("\n");
	proximo_ponto->proximo = NULL; // Quando o proximo ponto é nul quer dizer que a lista chegou a sim
	proximo_ponto = ini_ponto; //começa a percorrer a lista do inicio
	
	while(proximo_ponto != NULL){ //ppercorre a lista até o final
		printf("x: %d, y: %d\n", proximo_ponto->x, proximo_ponto->y);
		proximo_ponto = proximo_ponto->proximo; //aponta para o proximo ponto
	}
}

int len = 10;
int numeros[10];
int fim = 0;
int ini = 0;

void qstore(int i){
	if(fim+1 == ini || (fim+1 == len && !ini)){
		printf("Fila cheia.\n" );
		return;
	}
	numeros[fim] = i;
	fim++;
	
	//reinicio da fila
	if(fim == len){
		fim = 0;
	}
	printf("Enfileirado %d\n", i);
}

int qretrieve(){
	//reinicio da fila
	if(ini == len){
		ini = 0;
	}
	
	if(ini ==fim){
		printf("fila vazia.\n");
		return 1;
	}
	ini ++;
	printf("Desenfileirado %d\n", numeros[ini-1]);
	return numeros[ini-1];
}

typedef struct lista{
	int dado;
	struct lista *prox;
}celula;

celula *top = NULL;

void push(int item){
	printf("\nEmpilhando\n");
	celula *novo = (celula*)malloc(sizeof(celula));
	novo ->dado = item;
	novo ->prox = top;
	top = novo;
	printf("\nValor %d empilhado", novo->dado);
}

void pop(){
	printf("\nDesempilhando\n");
	if(top == NULL){
		printf("\n A pilha esta vazia ");
	}
	else{
		celula *temp;
		temp = top;
		top = top->prox;
		printf("\n%d desempilhado", temp->dado);
		free(temp);
	}
}

void imprimir(){
	celula *temp;
	temp = top;
	while(temp != NULL){
		printf("\n%d", temp->dado);
		temp = temp->prox;
	}
}


int main(){
	int opcao;
	printf("Informe qual opcao: \n");
	printf("[1] Lista ligada: \n");
	printf("[2] Fila: \n");
	printf("[3] Pilha: \n");
	scanf("%d", &opcao);
	
	switch(opcao){
		case 1:
			listaligada();
			break;
		case 2:
			qstore(10);
			qstore(10);
			qretrieve();
			break;
		case 3:
			int n, opt;
			do{
				printf("\nMenu\n 1- Empilhar\n 2- Desempilhar\n 3-Imprimir\n 0- Sair\n");
				scanf("%d", &opt);
				switch(opt){
					case 1:
						printf("\n Informe o valor a ser empilhado: ");
						scanf("%d", &n);
						push(n);
						break;
					case 2:
						pop();
						break;
					case 3:
						imprimir();
						break;
				}
			}while(opt != 0);
			break;
		default:
			printf("opcao invalida");
			break;
	}
	
	return 0;
}
