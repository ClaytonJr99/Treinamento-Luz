#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>


void bubblesort(int numeros[], int len){
	int i = 0, j = 0, auxiliar;
	int flag;
	for(j=1; j < len; j++){
		flag = 0;
		for(i=0; i< len -1; i++){
			if(numeros[i] > numeros[i +1]){
				auxiliar = numeros[i];
				numeros[i] = numeros[i +1];
				numeros[i +1] = auxiliar;
				flag = 1;
			}
		}
//		if(flag){
//			break;
//		}

	}
}

void insertionsort(int numeros[], int len){
	int i = 0, j = 0, auxiliar;
	
	for(i = 1; i< len; i++){
		auxiliar = numeros[i];
		j = i - 1;
		
		while((j >= 0) && (auxiliar < numeros[j])){
			numeros[j+1] = numeros[j];
			j--;
		}
		numeros[j+1] = auxiliar;
	}
}

void selectionsort(int numeros[], int len){
	int i = 0, j = 0, auxiliar;
	int menor;
	for(i=0; i< len - 1; i++){
		menor = i;
		for(j = i + 1; j < len; j++){
			if(numeros[menor] > numeros[j]){
				menor = j; 
			}
			if(i != menor){
				auxiliar = numeros[i];
				numeros[i] = numeros[menor];
				numeros[menor] = auxiliar;
			}
		}
	}
}

void mergesort(int *numeros, int inicio, int fim){	
	int meio;
	if(inicio < fim){
		meio = floor((inicio+fim) / 2);
		
		//chama a função para a primeira metade
		mergesort(numeros, inicio, meio);
		
		//chama a função para a segunda metade
		mergesort(numeros, meio+1, fim);
		
		//junta as 2 metades de forma ordenada
		merge(numeros, inicio, meio, fim);
	}

}

void merge(int *numeros, int inicio, int meio, int fim){
	int *temp, p1, p2, tamanho, i, j, k;
	int fim1 = 0, fim2 = 0;
	tamanho = fim-inicio+1;
	p1 = inicio;
	p2 = meio+1;
	temp = (int*) malloc(tamanho*sizeof(int));
	
	if(temp != NULL){
		for(i=0; i<tamanho; i++){
			if(!fim1 && !fim2){
				if(numeros[p1] < numeros[p2]){
					temp[i] = numeros[p1++];
				}else{
					temp[i] = numeros[p2++];
				}
				if(p1 > meio){
					fim1 = 1;
				}
				if(p2>fim){
					fim2 = 1;
				}
			}else{
				if(!fim1){
					temp[i] = numeros[p1++];
				}else{
					temp[i] = numeros[p2++];
				}
			}
		}
		for(j=0, k=inicio; j<tamanho; j++, k++){
			numeros[k] = temp[j];
		}
	}
}

void quicksort (int numeros[], int inicio, int fim){
	int pivo;
	if(fim > inicio){
		pivo = particiona(numeros, inicio, fim);
		
		// ordena o vetor da esquerda até o pivô
		quicksort(numeros, inicio, pivo-1);
		
		// ordena do pivô até a direita(final)
		quicksort(numeros, pivo+1, fim);
	}
	
}

int particiona(int *numeros, int inicio, int final){
	int esq, dir, pivo, aux;
	esq = inicio;
	dir = final;
	pivo = numeros[inicio];
	while(esq < dir){
		while(esq <= final && numeros[esq] <= pivo)
            esq++;
    	while(dir >= 0 && numeros[dir] > pivo)
            dir--;
		if(esq < dir){
			aux = numeros[esq];
			numeros[esq] = numeros[dir];
			numeros[dir] = aux;
		}
	}
	numeros[inicio] = numeros[dir];
	numeros[dir] = pivo;
	
	return dir;
}


main(void){
	int i = 0, j = 0;
	
	int len;
	printf("Digite a quantidade de registros: \n");
	scanf("%i", &len);
	
	float t;
	int selecao = 9;
	
	int *numeros = (int*) malloc (len * sizeof(int));
	
//	for(i = 0; i < len; i++){
//		printf("%.i ", teste[i]);	
//	}
	
	for(i=1; i <= len; i++){
		numeros[i -1] = rand() % RAND_MAX;
	}

	while(1){

	printf("Informe qual metodo o metodo de ordenacao: \n");
	printf("1 - Bubblesort \n");
	printf("2 - Insertionsort \n");
	printf("3 - Selectionsort \n");
	printf("4 - Mergesort \n");
	printf("5 - Quicksort \n");
	scanf("%i", &selecao);
	
	t = clock();
	switch(selecao){
		case 1:
			bubblesort(numeros, len);
			break;
		case 2:
			insertionsort(numeros, len);
			break;
		case 3:
			selectionsort(numeros, len);
			break;
		case 4:
			mergesort(numeros, 0, len-1);
			break;
		case 5:
			quicksort(numeros, 0, len-1);
			break;
		default:
			printf("opcao invalida");
			break;
	}
	t = clock() - t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("\n Tempo de execucao: %.2lf segundos \n", time_taken);	
	
	}

}



