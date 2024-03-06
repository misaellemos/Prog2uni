#include <stdio.h>
#include <stdlib.h>

//Lista Circular
//segunda versão

typedef struct no{
    int num;
    struct no *proximo;
}No;

typedef struct{
    No *inicio;
    No *fim;
    int tam;
}Lista;

void criarLista(Lista *lista){
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tam = 0;
}
//procedimento para inserir no início
void inserirListaInicio(Lista *lista, int n){
    No *novo = malloc(sizeof(No));
    if(novo){
        novo->num = n;
        novo->proximo = lista->inicio;
        lista->inicio = novo;
        if(!lista->fim){ // lista->fim == NULL, caso não exista último elemento
            lista->fim = novo; //recebe o ponteiro dele msm, último elemento
//já que estava nulo, tinha q receber o ponteiro do lugar de memória da última posição
//e já q a lista estava vazia, a última posição é essa inserida(novo)
//depois só adicionaremos no início e então não precisaremos alterar o final
        }
        lista->fim->proximo = lista->inicio; //atualizando o ponteiro que aponta pro inicio e fecha o circulo
        lista->tam++;
    }else{
        printf("\nErro ao alocar memória.\n");
    }
}

//procedimento para inserir no fim
void inserirListaFim(Lista *lista, int n){
    No *novo = malloc(sizeof(No));
    No *aux;
    
    if(novo){
        novo->num = n;
        //novo->proximo = NULL; //não precisa mais, não entendi
        aux = lista->inicio;
        
        if(!lista->inicio){
            lista->inicio = novo;
            lista->fim = novo;
            lista->fim->proximo = lista->inicio;
        }else{
            lista->fim->proximo = novo; // colova o novo na última posição
            lista->fim = novo;
            //lista->fim->proximo = lista->inicio;
            novo->proximo = lista->inicio;
        }
        lista->tam++;
    }else{
        printf("\nErro ao alocar memória.\n");
    }
}

//procedimento para inserir no meio
void inserirListaMeio(Lista *lista, int n, int referencia){//se quer inserir após o valor de ref
    No *novo = malloc(sizeof(No));
    No *aux = lista->inicio;
    
    if(novo){
        novo->num = n;
        if(!lista->inicio){ // *lista = NULL
            inserirListaInicio(lista, n);
        }else{
            while(aux->proximo && aux->num != referencia){
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
        lista->tam++;
    }else{
        printf("\nErro ao alocar memória.\n");
    }
}

void inserirOrdenado(Lista *lista, int n){
    No *aux, *novo = malloc(sizeof(No));
    
    if(novo){
        novo->num = n;
        if(!lista->inicio){ // lista->inicio == NULL
            inserirListaInicio(lista, n); // pra q reinventar a roda, reutilize seus programas
        }else if(novo->num < lista->inicio->num){
            inserirListaInicio(lista, n); 
        }else{
            aux = lista->inicio;
            
            while(aux->proximo != lista->inicio && novo->num > aux->proximo->num){ //aux->proximo até voltar pro inicio do ciclo
                aux = aux->proximo;
            }
            
            if(aux->proximo == lista->inicio){
                inserirListaFim(lista, n); //já incrementa tam++
            }else{
                novo->proximo = aux->proximo;
                aux->proximo = novo;
                lista->tam++;
            }
        }
    }else{
        printf("\nErro ao alocar memória.\n");
    }
}

No* removerLista(Lista *lista, int n){
    No *aux, *remover = NULL;
    
    if(lista->inicio){
        if(lista->inicio == lista->fim && lista->inicio->num == n){
            remover = lista->inicio;
            lista->inicio = NULL;
            lista->fim = NULL;
            lista->tam--;
        }else if(lista->inicio->num == n){
            remover = lista->inicio;
            lista->inicio = remover->proximo;
            lista->fim->proximo = lista->inicio;
            lista->tam--;
        }else{
            aux = lista->inicio;
            while(aux->proximo !=lista->inicio && aux->proximo->num != n){
                aux = aux->proximo;
            }
 
            if(aux->proximo->num == n){
                if(lista->fim == aux->proximo){
                    remover = aux->proximo;
                    lista->fim = aux;
                }else{
                    remover = aux->proximo;
                    aux->proximo = remover->proximo;
                }
                lista->tam--;
            }
        }
    }else{
        printf("\nA lista está vazia.\n");
    }
    return remover;
}

No* buscarLista(Lista *lista, int n){
    No *aux = lista->inicio;
    
    if(aux){
        do{
            if(aux->num == n){
                return aux;
            }
            aux = aux->proximo;
        }while(aux != lista->inicio);
        
    }
    return NULL;
}

void imprimir(Lista lista){
    No *no = lista.inicio;
    printf("\n\t---------- LISTA %d -----------\n\t\t", lista.tam);

    if(no){
        do{
            printf("%d ", no->num);
            no = no->proximo;
        }while(no != lista.inicio);
    }
    printf("\n\t------------------------------\n");
}

int main(){
    Lista lista;
    No *remover, *buscar;
    int opcao, n, ref;
    
    criarLista(&lista);
    
    do{
        printf("\n\t0 - sair\n\t1 - inserir no início\n\t2 - inserir no meio\n\t3 - inserir no final");
        printf("\n\t4 - inserir ordenado\n\t5 - remover\n\t6 - buscar\n\t7 - imprimir\nR: ");
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
                buscar = buscarLista(&lista, n);
                if(buscar){
                    printf("\n\t%d achooo\n\n", buscar->num);
                }else{
                    printf("\n\tNão achooo %d\n\n", n);
                }
                break;
            case 7:
                imprimir(lista);
                break;
            default:
                printf("\nOpção inválida, tente novamente.\n\n");
        }
    }while(opcao != 0);

    return 0;
}