#include <stdio.h>
#include <stdlib.h>

//fila duplamente encadeada

typedef struct no{
    int num;
    struct no *proximo;
    struct no *anterior;
}No;

//procedimento para inserir no início
void inserirListaInicio(No **lista, int n){
    No *novo = malloc(sizeof(No));
    if(novo){
        novo->num = n;
        novo->proximo = *lista;
        novo->anterior = NULL;
        if(*lista){
            (*lista)->anterior = novo;
        }
        *lista = novo;
    }else{
        printf("\nErro ao alocar memória.\n");
    }
}

//procedimento para inserir no fim
void inserirListaFim(No **lista, int n){
    No *novo = malloc(sizeof(No));
    No *aux;
    
    if(novo){
        novo->num = n;
        novo->proximo = NULL;
        aux = *lista;
        
        if(!*lista){
            *lista = novo;
            novo->anterior = NULL;
        }else{
            while(aux->proximo){
                
                aux = aux->proximo;
            }
            aux->proximo = novo;
            novo->anterior = aux;
        }
    }else{
        printf("\nErro ao alocar memória.\n");
    }
}

//procedimento para inserir no meio
void inserirListaMeio(No **lista, int n, int referencia){//se quer inserir após o valor de ref
    No *novo = malloc(sizeof(No));
    No *aux = *lista;
    
    if(novo){
        novo->num = n;
        if(!*lista){ // *lista = NULL
            novo->proximo = NULL;
            novo->anterior = NULL;
            *lista = novo;
        }else{
            while(aux->proximo && aux->num != referencia){
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;
            aux->proximo->anterior = novo;
            novo->anterior = aux;
            aux->proximo = novo;
        }
    }else{
        printf("\nErro ao alocar memória.\n");
    }
}

void inserirOrdenado(No **lista, int n){
    No *aux, *novo = malloc(sizeof(No));
    
    if(novo){
        novo->num = n;
        if(!*lista){ // *lista == NULL
            novo->proximo = NULL;
            novo->anterior = NULL;
            *lista = novo;
        }else if(novo->num < (*lista)->num){
            novo->proximo = *lista;
            novo->anterior = NULL;
            (*lista)->anterior = novo;
            *lista = novo;
        }else{
            aux = *lista;
            while(aux->proximo && novo->num > aux->proximo->num){
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;
            novo->anterior = aux;
            if(aux->proximo){ //caso exista mais elementos após
                aux->proximo->anterior = novo;
            }
            aux->proximo = novo;
        }
    }else{
        printf("\nErro ao alocar memória.\n");
    } 
}

No* removerLista(No **lista, int n){
    No *aux, *remover = NULL;
    
    if(*lista){
        if((*lista)->num == n){
            remover = *lista;
            *lista = remover->proximo;
            if(*lista){ //caso não exista apenas esse elemento
                (*lista)->anterior = NULL;
            }
        }else{
            aux = *lista;
            while(aux->proximo && aux->proximo->num != n){
                aux = aux->proximo;
            }
            if(aux->proximo){
                remover = aux->proximo;
                aux->proximo = remover->proximo;
                if(aux->proximo){ //caso exista mais elementos após
                    aux->proximo->anterior = aux;
                }
            }
        }
    }else{
        printf("\nA lista está vazia.\n");
    }
    return remover;
}

No* buscarLista(No *lista, int n){
    No *no = NULL;
    
    while(lista && lista->num != n){
        lista = lista->proximo;
    }
    if(lista){
        no = lista;
    }
    
    return no;
}

void imprimir(No *no){
    printf("\n\t---------- LISTA -----------\n\t\t");
    while(no){
        printf("%d ", no->num);
        no = no->proximo;
    }
    printf("\n\t----------------------------\n");
}

No* ultimoLista(No *lista){
    while(lista->proximo){
        lista = lista->proximo;
    }
    return lista; //ponteiro do final
}

void imprimirReverso(No *no){
    printf("\n\t---------- LISTA R -----------\n\t\t");
    while(no){
        printf("%d ", no->num);
        no = no->anterior;
    }
    printf("\n\t------------------------------\n");
}

int main(){
    No *remover,*buscar, *lista = NULL;
    int opcao, n, ref;
    
    do{
        printf("\n\t0 - sair\n\t1 - inserir no início\n\t2 - inserir no meio\n\t3 - inserir no final");
        printf("\n\t4 - inserir ordenado\n\t5 - remover\n\t6 - buscar\n\t7 - imprimir inverso\n\t8 - imprimir\nR: ");
        scanf("%d", &opcao);
        
        switch(opcao){
            case 0:
                printf("\nSaindo...\n");
                break;
            case 1:
                printf("\nDigite um número: ");
                scanf("%d", &n);
                inserirListaInicio(&lista, n);
                break;
            case 2:
                printf("\nDigite um número: ");
                scanf("%d", &n);
                imprimir(lista);
                printf("\nQuer inserir após qual número da lista?\nR: ");
                scanf("%d", &ref);
                
                inserirListaMeio(&lista, n, ref);
                break;
            case 3:
                printf("\nDigite um número: ");
                scanf("%d", &n);
                inserirListaFim(&lista, n);
                break;
            case 4:
                printf("\nDigite um número: ");
                scanf("%d", &n);
                inserirOrdenado(&lista, n);
                break;
            case 5:
                printf("\nDigite o número que quer remover: ");
                scanf("%d", &n);
                remover = removerLista(&lista, n);
                if(remover){
                    printf("\n\t%d removido com sucesso.\n\n", remover->num);
                    free(remover);
                }else{
                    printf("\n\tElemento %d não existe na lista.\n\n", n);
                }
                break;
            case 6:
                printf("\nDigite o número que quer buscar: ");
                scanf("%d", &n);
                buscar = buscarLista(lista, n);
                if(buscar){
                    printf("\n\t%d achooo\n\n", buscar->num);
                }else{
                    printf("\n\tNão achooo %d\n\n", n);
                }
                break;
            case 7:
                imprimirReverso(ultimoLista(lista));
                break;
            case 8:
                imprimir(lista);
                break;
            default:
                printf("\nOpção inválida, tente novamente.\n\n");
        }
    }while(opcao != 0);

    return 0;
}