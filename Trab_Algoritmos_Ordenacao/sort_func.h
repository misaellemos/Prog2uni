
#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

typedef struct vetores{
    int* num;
    int tam;
}SortingVets;

// por algum motivo o vs code não estava reconhecendo as funções do sort_func.c então deixei elas completas aqui e não somente prototipadas

void imprimir(int *v, int tam, char opcao){

    switch(opcao){
        case 'c':
            printf("\n\t\tcountingsort\n\t---------------------------------------\n");
            break;
        case 'h':
            printf("\n\t\theapsort\n\t---------------------------------------\n");          
            break;
        case 'q':
            printf("\n\t\tquicksort\n\t---------------------------------------\n");
            break;
        case 'r':
            printf("\n\t\tradixsort\n\t---------------------------------------\n");
            break;
        default:
            printf("\n\terro switchcase imprimir\n");
            return;
    }
    
    for(int i = 0; i < tam; i++){
        printf("%2d ", v[i]);
    }
}

void inicializar_vetores(SortingVets *Vet){
    Vet->tam = 1;
    Vet->num = malloc(sizeof(int*));
}
	
void montar_vetAleat(SortingVets *Vet){
    Vet->num = realloc(Vet->num, sizeof(int) * Vet->tam);

    for(int i = 0; i < Vet->tam; i++){
		Vet->num[i] = rand() % 100000;
	}
}
		
void montar_vetCresc(SortingVets *Vet){
    Vet->num = realloc(Vet->num, sizeof(int) * Vet->tam);
    
    for(int i = 0; i < Vet->tam; i++){
        Vet->num[i] = i + 1;
    }
}

void montar_vetDecresc(SortingVets *Vet){
    Vet->num = realloc(Vet->num, sizeof(int) * Vet->tam);

    for(int i = 0; i < Vet->tam; i++){
        Vet->num[i] = Vet->tam - i;
    }
}

void montar_vet(SortingVets *Vet, char opcao){

    switch(opcao){
    case 'a':
        montar_vetAleat(Vet);
        break;
    case 'c':
        montar_vetCresc(Vet);
        break;
    case 'd':
        montar_vetDecresc(Vet);
        break;
    default:
        printf("\n\terro switchcase montar_vet\n");
        return;
    }
}
		
void finalizar_vetores(SortingVets *Vet){
    free(Vet->num);
}

void atualizar_tam(SortingVets *Vet){
    if(Vet->tam < 10)
         Vet->tam++;
	else if(Vet->tam == 10) 
        Vet->tam += 9990;
	else 
        Vet->tam += 10000;
}

void tempo_exec(struct timeval start, struct timeval end, int tam, char opcao){
    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    double milliseconds = seconds * 1000 + microseconds / 1000.0;

    switch(opcao){
        case 'c':
            printf("\x1b[38;5;14m\n\n\ttempo de execução countingsort de tamanho  ");
            break;
        case 'h':
            printf("\x1b[38;5;14m\n\n\ttempo de execução heapsort de tamanho  ");            
            break;
        case 'q':
            printf("\x1b[38;5;14m\n\n\ttempo de execução quicksort de tamanho  ");
            break;
        case 'r':
            printf("\x1b[38;5;14m\n\n\ttempo de execução radixsort de tamanho  ");
            break;
        default:
            printf("\n\terro switchcase tempo_exec\n");
            return;
    }

    printf("\x1b[38;2;22;83;126m %5d:\x1b[38;2;150;123;182m %f \x1b[38;5;14m millissegundos\x1b[0m", tam, milliseconds);
}

#endif 