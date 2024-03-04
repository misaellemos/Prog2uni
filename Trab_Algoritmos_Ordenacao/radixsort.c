
#include "sort_func.h"

int getMax(int vet[], int tam){   
	int max = vet[0];
	for (int i = 0; i < tam; i++)
		if(max < vet[i]) max = vet[i]; 
    return max;
}

void countSort(int vet[], int tam, int p_digit){
    int i, count[10] = { 0 };
 
    for(i = 0; i < tam; i++)
        count[(vet[i] / p_digit) % 10]++;
 
    for(i = 1; i < 10; i++)   
        count[i] += count[i - 1];
    
    int v_ordenado[tam];
    for(i = tam - 1; i >= 0; i--){ 
        v_ordenado[ count[(vet[i] / p_digit) % 10] - 1 ] = vet[i];
        count[(vet[i] / p_digit) % 10]--;
    }
    
    for (i = 0; i < tam; i++)
        vet[i] = v_ordenado[i]; 
}
 
void radixsort(int vet[], int tam){
    int max = getMax(vet, tam);
 
    for (int i = 1; max / i > 0; i *= 10)
        countSort(vet, tam, i);
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
            radixsort(Vet->num, Vet->tam);
		gettimeofday(&end, NULL);

		// fazendo o cálculo do tempo e imprimindo na tela
		tempo_exec(start, end, Vet->tam, 'r');	// 'c': countingsort || 'h': heapsort || 'q': quicksort || 'r': radixsort

		atualizar_tam(Vet);	// atualizando tamanho do vetor, para poder fazer vários cálculos em um só run
		
	}while(Vet->tam <= 100000);
	
	// liberando memórias alocadas
	finalizar_vetores(Vet);
	free(Vet);
    
    return 0;
}
