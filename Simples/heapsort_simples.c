#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
 
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

void heapsort(int v[], int N){ 
    for(int i = N / 2 - 1; i >= 0; i--)
        heapify(v, N, i);

    for(int i = N - 1; i >= 0; i--){
        troca(&v[0], &v[i]);
        heapify(v, i, 0);
    }
}
 
int main(){
    int tam = 10000;
    int vet[tam];

    for(int i = 0; i < tam; i++){
        vet[i] = rand() % 100000;
    }

    struct timeval start, end;
    gettimeofday(&start, NULL);
        heapsort(vet, tam);
    gettimeofday(&end, NULL);

    //imprimir(vet, tam);

    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    double milliseconds = seconds * 1000 + microseconds / 1000.0;

    printf("\x1b[38;5;14m\n\n\ttempo de execução heapsort:\x1b[38;2;150;123;182m %f \x1b[38;5;14m millissegundos\x1b[0m", milliseconds);

    return 0;
}