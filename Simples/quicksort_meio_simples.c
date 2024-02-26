#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int particiona(int *v, int inicio, int fim){
    int i = (inicio + fim)/2;
    int pivo = v[i]; // passo 1

    while(inicio < fim){
        while(inicio < fim && v[inicio] < pivo){ // passo 2
            inicio++;
        }
        while(inicio < fim && v[fim] > pivo){ // passo 3
            fim--;
        }
        int aux = v[inicio]; // passo 4
        v[inicio] = v[fim];
        v[fim] = aux;
    }
    return inicio; 
}

void quickSort(int *v, int inicio, int fim){
    if(inicio < fim){
        int posicao = particiona(v, inicio, fim);
        quickSort(v, inicio, posicao); // conjunto dos menores que posicao, vai até pos - 1
        quickSort(v, posicao + 1, fim); // conjunto dos maiores maiores que posicao, continua de (pos - 1) + 1
    } 
}

void imprimir(int *v, int tam){
    printf("\n\t\tquicksort rand\n\t---------------------------------------\n");
    for(int i = 0; i < tam; i++){
        printf("%2d ", v[i]);
    }
}

int main(){
    int TAM = 100;
    int vet[TAM];

    for(int i = 0; i < TAM; i++){
        vet[i] = rand() % 100000;
    }

    struct timeval start, end;
    gettimeofday(&start, NULL);
    
        quickSort(vet, 0, TAM - 1); // tem que enviar tam - 1 como último parâmetro

    gettimeofday(&end, NULL);

    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    double milliseconds = seconds * 1000 + microseconds / 1000.0;

    printf("\x1b[38;5;14m\n\n\ttempo de execução quicksort rand: %f millissegundos\x1b[0m", milliseconds);
    
    return 0;
}