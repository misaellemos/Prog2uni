#include <stdio.h>
#include <stdlib.h>

//tabela hash na prática
//tabela hash linear com vetor

//vamos trabalhar com um conjunto de dados com 15 elementos
// portanto 2 * 15 = 30 --> primo mais prox 29 ou 31, vamos pegar 31

#define TAM 31 

void inicializarTabela(int t[]){
    for(int i = 0; i < TAM; i++){
        t[i] = 0;
    }
}

int funcaoHash(int chave){
    return chave % TAM;
}

void inserir(int t[], int valor){
    int id = funcaoHash(valor);
    while(t[id] != 0){
        id = funcaoHash(id + 1);
    }
    t[id] = valor;
}

int buscar(int t[], int chave){
    int id = funcaoHash(chave);
    while(t[id] != 0){
        if(t[id] == chave){
            printf("\níndice: %dº", id);
            return t[id];
        }else{
            id = funcaoHash(id + 1);
        }
    }
    return 0;
}

void imprimir(int t[]){
    for(int i = 0; i < TAM; i++){
        printf("\n%dº: %d", i, t[i]);
    }
}

int main(){
    
    int tabela[TAM];
    int opcao, valor, retorno;

    inicializarTabela(tabela);

    do{
        printf("\n\t\tTabela\n\t0 - sair\n\t1 - inserir\n\t2 - buscar\n\t3 - imprimir\n");
        scanf("%d", &opcao);
        getchar();
        switch(opcao){
            case 0:
                printf("\nSaindo...\n");

                break;
            case 1:
                printf("\nValor que deseja inserir: ");
                scanf("%d", &valor);
                
                inserir(tabela, valor);

                break;
            case 2:
                printf("\nValor que deseja buscar: ");
                scanf("%d", &valor);

                retorno = buscar(tabela, valor);

                if(retorno){
                    printf("\nValor encontrado: %d", retorno);    
                }else{
                    printf("\nValor nao encontrado.");
                }
            
                break;
            case 3:
                imprimir(tabela);

                break;
            default:
                printf("\nOpção inválida.\n");
        }
    }while(opcao);
    
    return 0;
}