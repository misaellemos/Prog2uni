
#include "sort_func.h"
 
void troca(int* a, int* b){
    int aux = *a;
    *a = *b;
    *b = aux;
}
 
void heapify(int v[], int N, int i){
    int maior = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;
 
    if (esq < N && v[esq] > v[maior])
        maior = esq;

    if (dir < N && v[dir] > v[maior])
        maior = dir;

    if(maior != i){
        troca(&v[i], &v[maior]);
        heapify(v, N, maior);
    }
}

void heapSort(int v[], int N){ 
    for(int i = N / 2 - 1; i >= 0; i--)
        heapify(v, N, i);

    for(int i = N - 1; i >= 0; i--){
        troca(&v[0], &v[i]);
        heapify(v, i, 0);
    }
}
 
int main(){
    // criando e inicializando vetor de inteiros dentro dessa struct
    SortingVets *Vet = malloc(sizeof(SortingVets));
	inicializar_vetores(Vet);

	do{
		montar_vet(Vet, 'a');   // 'a' : ordem aleatória || 'c': ordem crescente || 'd': ordem decrescente

        // coisas do julio
		struct timeval start, end; 
		gettimeofday(&start, NULL);
            heapSort(Vet->num, Vet->tam);
		gettimeofday(&end, NULL);

        // fazendo o cálculo do tempo e imprimindo na tela
		tempo_exec(start, end, Vet->tam, 'h');  // 'c': countingsor || 'h': heapsort || 'q': quicksort || 'r': radixsort

		atualizar_tam(Vet); // atualizando tamanho do vetor, para poder fazer vários cálculos em um só run
		
	}while(Vet->tam <= 100000);

	// liberando memórias alocadas
	finalizar_vetores(Vet); 
	free(Vet);

    return 0;
}