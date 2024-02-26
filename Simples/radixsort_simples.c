#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int getMax(int vet[], int tam){   
	int max = vet[0];
	for (int i = 0; i < tam; i++)
		if(max < vet[i]) max = vet[i]; 
    return max;
}

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
 
void radixsort(int vet[], int tam){
    int max = getMax(vet, tam);    // Find the maximum number to know number of digits
 
    for (int i = 1; max / i > 0; i *= 10)
        countSort(vet, tam, i);
}

int main(){ 
    int tam = 10000;
    int vet[tam];

    for(int i = 0; i < tam; i++){
        vet[i] = rand() % 100000;
    }

    struct timeval start, end;
    gettimeofday(&start, NULL);
        radixsort(vet, tam); // tem que enviar tam - 1 como último parâmetro
    gettimeofday(&end, NULL);

    //imprimir(vet, tam);

    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    double milliseconds = seconds * 1000 + microseconds / 1000.0;

    printf("\x1b[38;5;14m\n\n\ttempo de execução radixsort:\x1b[38;2;150;123;182m %f \x1b[38;5;14m millissegundos\x1b[0m", milliseconds);
    
    return 0;
}