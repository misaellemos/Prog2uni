#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

    //  counting sort 
// non-comparison-based sorting algorithm that works well when ther is limited range of input values
// it is particularly efficient when the range of input values is small compared to the number of elements to be sorted
// the basic idea behind counting sort is to count the frequency of each distinct element in the input array and use 
//   that information to place elements in their corredt sorted positions

// steps:
// 1 - find out the maximum element from the given array 

// 2 - initialize a countArray[] of length maximum + 1 with all elements as 0. this array will be used for sorting
//      the occurrences of the elements

// 3 - in the countArray[], store the count of each unique element of the inputArray[] at their respectives indices

// 4 - store the cumulative/prefix sum of the elements of the countArray[] by doing countArray[i] += countArray[i - 1]
//      this will help in placing the elements of the input array at the correct index in the output array 

// 5 - iterate from end of the inputArray[] and because traversing inputArray[] from end preserves the order of equal elements
//      which eventually makes this sorting algorithm stable
// update:
//  outputArray[ countArray[ inputArray[i] ] - 1 ] = inputArray[i] 
//  countArray[ inputArray[i] ] = countArray[ inputArray[i] ]--

// vetor auxiliar de conta: 
// tamanho = valor_maximo , cada elemento ocupará o index correspondente ao seu valor, cada índice guardará a quantidade 
//    desse elemento no vetor original(engual harsh)
// então somar o elemento pelo seu antecessor indicará os índices que eles ocuparão no vetor ordenado
// ex: o vetor possui x repetições do menor elemento, ou seja, as primeiras x posições do vetor ordenado serão ocupadas 
//      por esse elemento, agora somando o elemento seguinte pela quantidade desse menor elemento dará 
//      os índices desse próximo elemento, pois x casas já estão ocupadas

int* countSort(int* v_i, int tam){ // v_i == vetor inicial
	
	int max = v_i[0];
	for (int i = 0; i < tam; i++)
		if(max < v_i[i]) max = v_i[i];      // Finding the maximum element of array inputArray[].

	int* v_aux = calloc(max + 1, sizeof(int));  // Initializing countArray[] with 0, v_aux == vetor auxiliar
	
	for (int i = 0; i < tam; i++)
		v_aux[v_i[i]]++;            // Mapping each element of inputArray[] as an index of countArray[] array

	for (int i = 1; i <= max; i++)
		v_aux[i] += v_aux[i - 1];     // Calculating prefix sum at every index of array countArray[]

	int* v_ordenado = malloc(tam * sizeof(int));	// Creating outputArray[] from countArray[] array

	for (int i = tam - 1; i >= 0; i--){
		v_ordenado[ v_aux[v_i[i]] - 1 ] = v_i[i];
		v_aux[v_i[i]]--;
	}
	
	free(v_aux);

	return v_ordenado;
}

void imprimir(int *v, int tam){
    printf("\n\t\tcountingsort\n\t---------------------------------------\n");
    for(int i = 0; i < tam; i++){
        printf("%2d ", v[i]);
    }
}

int main(){
	int TAM = 30;
	int vet[TAM];

    for(int i = 0; i < TAM; i++){
        vet[i] = rand() % 100000;
    }

	imprimir(vet, TAM);

		int* outputArray = countSort(vet, TAM);

	imprimir(vet, TAM);
    
    return 0;
}