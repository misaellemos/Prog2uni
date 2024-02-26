#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void countsort(int* v, int tam){
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
    int tam = 10000;
    int vet[tam];

    for(int i = 0; i < tam; i++){
        vet[i] = rand() % 100000;
    }

    struct timeval start, end;
    gettimeofday(&start, NULL);
        countsort(vet, tam);
    gettimeofday(&end, NULL);

    //imprimir(vet, tam);

    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    double milliseconds = seconds * 1000 + microseconds / 1000.0;

    printf("\x1b[38;5;14m\n\n\ttempo de execução countingsort:\x1b[38;2;150;123;182m %f \x1b[38;5;14m millissegundos\x1b[0m", milliseconds);
    
    return 0;
}