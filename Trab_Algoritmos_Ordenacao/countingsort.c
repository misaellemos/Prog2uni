#include "sort_func.h"

void countSort(int* v, int tam){
	int max = v[0];
	int v_copia[tam];

	for (int i = 0; i < tam; i++){
		if(max < v[i]) max = v[i]; 
		v_copia[i] = v[i];
	}
		
	int* v_aux = calloc(max + 1, sizeof(int)); 
	
	for (int i = 0; i < tam; i++)
		v_aux[v[i]]++;       

	for (int i = 1; i <= max; i++)
		v_aux[i] += v_aux[i - 1];  

	for (int i = tam - 1; i >= 0; i--){
		v[ v_aux[v_copia[i]] - 1 ] = v_copia[i];
		v_aux[v_copia[i]]--;
	}
	
	free(v_aux);
}

int main(){
	// criando e inicializando vetor de inteiros dentro dessa struct
	SortingVets *Vet = malloc(sizeof(SortingVets));
	inicializar_vetores(Vet);

	do{
		montar_vet(Vet, 'a');	// 'a' : ordem aleatória || 'c': ordem crescente || 'd': ordem decrescente

		// coisas do julio
		struct timeval start, end;
		gettimeofday(&start, NULL);
			countSort(Vet->num, Vet->tam);
		gettimeofday(&end, NULL);

		// fazendo o cálculo do tempo e imprimindo na tela
		tempo_exec(start, end, Vet->tam, 'c');	// 'c': countingsort || 'h': heapsort || 'q': quicksort || 'r': radixsort

		atualizar_tam(Vet);	// atualizando tamanho do vetor, para poder fazer vários cálculos em um só run
		
	}while(Vet->tam <= 100000);
	
	// liberando memórias alocadas
	finalizar_vetores(Vet);
	free(Vet);
    
    return 0;
}