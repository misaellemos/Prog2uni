#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
 
void troca(int* a, int* b){
    int aux = *a;
    *a = *b;
    *b = aux;
}
 
// To heapify a subtree rooted with node i
// which is an index in v[].
// n is size of heap
void heapify(int v[], int N, int i){
    // Find maior among root,
    // esq child and dir child
 
    // Initialize maior as root
    int maior = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;
 
    // If esq child is larger than root
    if (esq < N && v[esq] > v[maior])
        maior = esq;
 
    // If dir child is larger than maior
    // so far
    if (dir < N && v[dir] > v[maior])
        maior = dir;
 
    // troca and continue heapifying
    // if root is not maior
    // If maior is not root
    if(maior != i){
        troca(&v[i], &v[maior]);
        // Recursively heapify the affected
        // sub-tree
        heapify(v, N, maior);
    }
}

void heapSort(int v[], int N){  // Main function to do heap sort
    // Build max heap
    for(int i = N / 2 - 1; i >= 0; i--)
        heapify(v, N, i);
    // Heap sort
    for(int i = N - 1; i >= 0; i--){
        troca(&v[0], &v[i]);
        // Heapify root element
        // to get highest element at
        // root again
        heapify(v, i, 0);
    }
}
 
void imprimir(int *v, int tam){
    printf("\n\t\theapsort\n\t---------------------------------------\n");
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
 
        heapSort(vet, TAM);

    imprimir(vet, TAM);

    return 0;
}