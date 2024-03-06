#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

    //  radix sort 
// a linear sorting algorithm tat sorts elements by processing them digit by digit
// it is an efficient sorting algorithm for integers or strings with fixed-size keys

// rather tham comparing elements directly, radix sort distributes the elements into buckets based on each digit's value 
// by repeatedly sorting the elements by their significant digits, from the least significant to the most significant, 
// radix sort achieves the final sorted order 

// the key idea behind radix sort is to p_digitloit the concept of place value, it assumes that sorting numbers digits
// by digit by digit will eventually result in a fully sorted list, radix sort can be performed using different variations,
// such as Least Significant Digit(LSD) radix sort or Most Significant Digit(MSD) radix sort

// steps:
// 1 - find the largest element in the array, the number of digits will be the number of times we'll iterate, 
//      once for each significant place

// 2 - sort the elements based on the place digits (can start by the least or most significant digit),
// we use a stable sorting technique, such as counting sort, to sort the digits at each significant place

// 3 - sort the elements based on the next place digits until it's all sorted

int getMax(int vet[], int tam){   // A utility function to get maximum value in arr[]
	int max = vet[0];
	for (int i = 0; i < tam; i++)
		if(max < vet[i]) max = vet[i]; 
    return max;
}

 // A function to do counting sort of arr[] according to the digit represented by p_digit
void countSort(int vet[], int tam, int p_digit){  // p_digit == place digit
    int i, count[10] = { 0 }; // só vamos ter que ordenar até o dígito 9 com counting sort 
 
    // using counting sort on the place digit 
    for(i = 0; i < tam; i++)     // Store count of occurrences in count[]
        count[(vet[i] / p_digit) % 10]++;
 
    for(i = 1; i < 10; i++)    // Change count[i] so that count[i] now contains actual position of this digit in output[]
        count[i] += count[i - 1];
    
    int v_ordenado[tam];
    for(i = tam - 1; i >= 0; i--){    // Build the output array
        v_ordenado[ count[(vet[i] / p_digit) % 10] - 1 ] = vet[i];
        count[(vet[i] / p_digit) % 10]--;
    }
    
    for (i = 0; i < tam; i++)  // trocando por aritimética de ponteiros para não ter que mudar endereço de memória
        vet[i] = v_ordenado[i]; 
    
}
 
// The main function to that sorts arr[] of size n using Radix Sort
void radixsort(int vet[], int tam){
    int max = getMax(vet, tam);    // Find the maximum number to know number of digits
 
    // Do counting sort for every digit.
    // Note that instead of passing digit number, p_digit is passed
    // p_digit is 10^i where i is current digit number
    for (int i = 1; max / i > 0; i *= 10)
        countSort(vet, tam, i);
}
 
void imprimir(int *v, int tam){
    printf("\n\t\tradixsort\n\t---------------------------------------\n");
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

        radixsort(vet, TAM);

    imprimir(vet, TAM);
    
    return 0;
}