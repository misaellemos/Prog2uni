#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

    //      Algoritmo de ordenação
    //  Quick sort 
 // é um algoritmo de ordenação, um dos algoritmos de ordenação mais eficientes que existem

//      Passos do quick sort 
//  1 - Escolher um pivô que será usado nas comparações
//  2 - Percorrer o vetor da esquerda para a direita até encontrar um elemento maior que o pivô
//  3 - Percorrer o vetor da direita para a esquerda até encontrar um elemento menor que o pivô
//  4 - Trocar os dois elementos

// basicamente é um algoritmo recursivo 
// o coração, a parte principal, do quick sort é um procedimento/função chamada de 'partição/particionamento/particionar'
// basicamente esse procedimento divide o vetor em duas partes
// o pivô vai ser o elemento que vamos utilizar para comparar com todos os outros elementos, para particionar/dividir o vetor em dois
//   um conjunto dos elementos menores e um conjunto dos elementos maiores

// Existem diversas formas de quick sort, diversas implementações
// Essa é uma das mais eficientes pois trabalha movendo dois elementos por vez 

//   Escolhendo um pivô, já que o vetor não está ordenado não temos como ter certeza para achar a mediana desse vetor
//    porém podemos tentar pegar três valores aleatórios desse vetor e dividir por 3, e então usar essa média deles como pivô
//    (o primeio elemento + o último elemento + o elemento do meio)/ 3 = pivô

//   O quick sort é um método que implementa o que é conhecido na ciência da computação como "divisão e conquista"
//    a gente divide o problema em partes menores pra então resolver as partes menores e atingir o todo que a gente quer atingir

// depois de finalizada a primeira partição, você faz uma recursão com o lado esquerdo, contendo o conjunto dos valores menores, e com
//  o lado direito, contendo o conjunto dos valores maiores
// faremos isso até que tenhamos vetores unitários e esses vetores unitários estejam ordenados


int particiona(int *v, int inicio, int fim){
    int pivo = (v[inicio] + v[fim] + v[(inicio + fim)/2])/3; // passo 1

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
    return inicio; // o while terminará quando inicio == fim; o termo que está ordenado, com os menores a esq e os maiores a dir
}

void quickSort(int *v, int inicio, int fim){
    if(inicio < fim){
        int posicao = particiona(v, inicio, fim);
        quickSort(v, inicio, posicao - 1); // conjunto dos menores que posicao, vai até pos - 1
        quickSort(v, posicao, fim); // conjunto dos maiores maiores que posicao, continua de (pos - 1) + 1
    } 
// para não repetir elementos nos vetores, nem sempre sobrará um termo só na posição certa(como foi no exemplo do slide)
//  por isso passamos certinho metade metade
}

void imprimir(int *v, int tam){
    printf("\n\t\tquicksort rand\n\t---------------------------------------\n");
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

        quickSort(vet, 0, TAM - 1); // tem que enviar tam - 1 como último parâmetro

    imprimir(vet, TAM);

    
    return 0;
}