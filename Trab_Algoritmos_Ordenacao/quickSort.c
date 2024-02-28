
#include "sort_func.h"

int particiona(int *v, int inicio, int fim, char escolha_pivo){
    int pivo, i;
    
    if( escolha_pivo == 'm'){
        i = (inicio + fim)/2;
        pivo = v[i]; // passo 1
    }else if(escolha_pivo == 'a')
        pivo = (v[inicio] + v[fim] + v[(inicio + fim)/2])/3; // passo 1
        

    while(inicio < fim){
        while(inicio < fim && v[inicio] <= pivo){ // passo 2
            inicio++;
        }

        while(inicio < fim && v[fim] > pivo){ // passo 3
            fim--;
        }

        int aux = v[inicio]; // passo 4
        v[inicio] = v[fim];
        v[fim] = aux;
    }

    if(escolha_pivo == 'm' && pivo > v[fim]){
        v[i] = v[fim];
        v[fim] = pivo;
    }

    return inicio; 
}

void quickSort(int *v, int inicio, int fim, char escolha_pivo){
    if(inicio < fim){
        int posicao = particiona(v, inicio, fim, escolha_pivo);
        quickSort(v, inicio, posicao - 1, escolha_pivo); // conjunto dos menores que posicao, vai até pos - 1
        quickSort(v, posicao, fim, escolha_pivo); // conjunto dos maiores maiores que posicao, continua de (pos - 1) + 1
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
            quickSort(Vet->num, 0, Vet->tam - 1, 'm');  // 'a' : pivo escolhido  de forma aleatória || 'm': pivo como elemento do meio
		gettimeofday(&end, NULL);

        // fazendo o cálculo do tempo e imprimindo na tela
		tempo_exec(start, end, Vet->tam, 'q');  // 'c': countingsor || 'h': heapsort || 'q': quicksort || 'r': radixsort

		atualizar_tam(Vet); // atualizando tamanho do vetor, para poder fazer vários cálculos em um só run
		
	}while(Vet->tam <= 100000);
    
	// liberando memórias alocadas
	finalizar_vetores(Vet); 
	free(Vet);

    return 0;
}