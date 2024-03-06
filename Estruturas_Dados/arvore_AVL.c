#include <stdio.h>
#include <stdlib.h>

    //  Árvore Binária Balanceada ( AVL )
 // Implementação
// O que pode desbalancear sua árvore binária? inserção, remoção, altura
// Uma nova inserção pode tornar sua árvore desbalanceada, mesma coisa para uma remoção
//  toda vez que você remove um nó você está alterando a altura de uma subárvore, a esquerda ou a direita
 // Alteração 
// Os nós agora precisam do campo/da informação altura, devido ao fator de balanceamento
//  fb = altura_esq - altura_dir

typedef struct no{
    int valor;
    struct no *esq, *dir;
    short altura; // short ocupa 2 bnrtes, pra aula é melhor
}No;

/*
    Função que cria um novo nó; x -> valor a ser inserido no nó; Retorna: o endereço do nó criado
*/
No* novoNo(int x){ // apenas cria, não insere ainda, estamos diluindo as funções
    No *novo = malloc(sizeof(No));
    
    if(novo){
        novo->valor = x;
        novo->esq = NULL;
        novo->dir = NULL;
        novo->altura = 0;
    }else{
        printf("\nErro ao alocar nó em nonoNo.");
    }
    return novo;
}

/*
    Retorna o maior dentre dois valores; a, b -> altura de dois nós da árvore
*/
short maior(short a, short b){
    return (a > b)? a: b;
}

/*
    Retorna a altura de um nó ou -1 caso ele seja NULL
*/
short alturaDoNo(No *no){
    return (no)? no->altura: -1;
}

/*
    Calcula e retorna o fator de balanceamento de um nó
*/
short fatorDeBalanceamento(No *no){
    return (no)? (alturaDoNo(no->esq) - alturaDoNo(no->dir)): 0;
}

/*
    Função para a rotação à esquerda, se rotaciona a esquerda quando está pendendo a direita( fb < 0)
*/
No* rotacaoEsquerda(No *r){ // r -> raíz que está desbalanceada
    No *nr, *f; 
// nr -> filho da raíz (vai se tornar a nova raiz)
// f -> filho à esquerda de nr(pode ser nulo ou n)

    nr = r->dir;
    f = nr->esq;
// primeiro só estamos atribuindo os respectivos ponteiros a essas variáveis criadas

    nr->esq = r;
    r->dir = f;
// o ponteiro à esquerda de nr vai ser atribuido o ponteiro da raiz r, fazendo o nr passar a ser a raiz
//   consequentemente r é o novo filho a esq de nr
// e o ponteiro a direita de r agora vai apontar pra o ponteiro filho f que ele usurpou o lugar
//   já que se f estava a direita de r, ele deve continuar lá, pois é maior que r 

    r->altura = maior(alturaDoNo(r->esq), alturaDoNo(r->dir)) + 1;
    nr->altura = maior(alturaDoNo(nr->esq), alturaDoNo(nr->dir)) + 1;
// atualizando as alturas
    return nr; // retorna o ponteiro dessa nova raiz
}

/*
    Função para a rotação à direita, se rotaciona a direita quando está pendendo a esquerda( fb > 0)
*/
No* rotacaoDireita(No *r){ // r -> raíz que está desbalanceada
    No *nr, *f; 
// nr -> filho da raíz (vai se tornar a nova raiz)
// f -> filho à esquerda de nr(pode ser nulo ou n)

    nr = r->esq;
    f = nr->dir;
// primeiro só estamos atribuindo os respectivos ponteiros a essas variáveis criadas

    nr->dir = r;
    r->esq = f;
// análogo a rotação à esquerda, apenas inverte-se os sentidos dos ponteiros

    r->altura = maior(alturaDoNo(r->esq), alturaDoNo(r->dir)) + 1;
    nr->altura = maior(alturaDoNo(nr->esq), alturaDoNo(nr->dir)) + 1;
    
    return nr;
}

/*
    Função para a rotação direita esquerda (fb > 0)
*/
No* rotacaoDireitaEsquerda(No *r){
    r->dir = rotacaoDireita(r->dir);
// r está pendendo pra direita, porém sua subárvore está pendendo para a esquerda
//   portanto rotacionamos sua subárvore a direita(que é o lado que está pendendo) à direita
// pegamos a subárvore do filho a direita da raiz e como essa subárvore está pendendo à esquerda, rotacionamos à direita
//   ao fim toda a árvore está pendendo a direita, então basta rotacionar a raíz para a esquerda 
    return rotacaoEsquerda(r);
}

/*
    Função para a rotação esquerda direita (fb < 0)
*/
No* rotacaoEsquerdaDireita(No *r){
    r->esq = rotacaoEsquerda(r->esq);
// r está pendendo pra esquerda, porém sua subárvore está pendendo para a direita
// processo análogo à rotação direita esquerda, apenas inverte-s e as operações e ponteiros
    return rotacaoDireita(r);
}

/*
    Função para realizar o balanceamento da árvore após uma inserção ou remoção
    Recebe o nó que está desbalanceado e retorna a nova raiz após o balanceamento 
*/
No* balancear(No *raiz){
    short fb = fatorDeBalanceamento(raiz);
    
    // Rotação à esquerda
    if(fb < -1 && fatorDeBalanceamento(raiz->dir) <= 0)
        raiz = rotacaoEsquerda(raiz);
    
    // Rotação à direita 
    if(fb > 1 && fatorDeBalanceamento(raiz->esq) >= 0)
        raiz = rotacaoDireita(raiz);
    
    // Rotação dupla à esquerda 
    if(fb > 1 && fatorDeBalanceamento(raiz->esq) < 0)
        raiz = rotacaoEsquerdaDireita(raiz);
    
    // Rotação dupla à direita
    if(fb < -1 && fatorDeBalanceamento(raiz->dir) > 0)
        raiz = rotacaoDireitaEsquerda(raiz);
    
    return raiz;
}

/*
    Insere um novo nó na árvore; raiz -> raiz da árvore; x -> valor a ser inserido; 
    Retorno: endereço do novo nó ou nova raiz após o balanceamento
*/
No* inserir(No *raiz, int x){
    if(!raiz){
        return novoNo(x);
    }else{
        if(x < raiz->valor){
            raiz->esq = inserir(raiz->esq, x);
        }else if(x > raiz->valor){
            raiz->dir = inserir(raiz->dir, x);
        }else{
            printf("\nInserção não realizada, elemento %d já existe", x);
        }
    }
// Recalcula a altura de todos os nós entre a raiz e o novo nó inserido
    raiz->altura = maior(alturaDoNo(raiz->esq), alturaDoNo(raiz->dir)) + 1;
    
// Verifica a necessidade de rebalancear a árvore 
    raiz = balancear(raiz);
    
    return raiz;
}

/*
    Função para remover um nó da árvore binária balanceada
    Pode ser necessário rebalancear a árvore e a raiz pode ser alterada, por isso precisamos retornar a raiz
*/
No* remover(No *raiz, int chave){
    if(!raiz){
        printf("\nValor não encontrado.\n");
        return NULL;
    }else{ // procura o nó a remover
        if(raiz->valor == chave){ 
            if(!raiz->esq && !raiz->dir){   // remove nós folhas (nós sem filhos)
               free(raiz);
               printf("\nElemento folha removido: %d\n", chave);
               return NULL;
            }else if(raiz->esq && raiz->dir){   // remove nós que possuem 2 filhos
                No *aux = raiz->esq; // escolhemos colocar o filho mais a dir da raiz->esq no lugar do nó removido
                while(aux->dir){
                    aux = aux->dir;
                }
                raiz->valor = aux->valor;
                aux->valor = chave;
                printf("\x1b[38;5;16m");
                //printf("\nElemento trocado: %d", chave)
                raiz->esq = remover(raiz->esq, chave);
                printf("\x1b[0mElemento com 2 filhos removido: %d\n", chave);
                
                return raiz;
            }else{  // remove nós que possuem apenas 1 filho
                No *aux;
                if(raiz->esq){
                    aux = raiz->esq;
                }else{
                    aux = raiz->dir;
                }
                free(raiz);
                printf("\nElemento com 1 filho removido: %d\n", chave);
                return aux;
// mine version //NoArv *aux = raiz; //(raiz->esquerda)? (raiz = raiz->esquerda): (raiz = raiz->direita); //free(aux); //return raiz;
            }
        }else{
            if(chave < raiz->valor){
                raiz->esq = remover(raiz->esq, chave);
            }else{
                raiz->dir = remover(raiz->dir, chave);
            }
        }
    }
// Recalcula a altura de todos os nós entre a raiz e o novo nó inserido
    raiz->altura = maior(alturaDoNo(raiz->esq), alturaDoNo(raiz->dir)) + 1;
// Verifica a necessidade de rebalancear a árvore
    raiz = balancear(raiz);
    
    return raiz;
}

/*
    Procedimento para imprimir uma árvore AVL
*/
void imprimir(No *raiz, int nivel){ // imprime a árvore deitada de lado, na horizontal
    int i;
    if(raiz){
        imprimir(raiz->dir, nivel + 1);
        printf("\n\n");
        for(i = 0; i < nivel; i++){
            printf("\t");
        }
        printf("%3d", raiz->valor);
        imprimir(raiz->esq, nivel + 1);
    }
}

int main(){
    int opcao, valor;
    No *raiz = NULL;
    
    do{
        printf("\n\n\t0 - sair\n\t1 - inserir\n\t2 - remover\n\t3 - imprimir\nR: ");
        scanf("%d", &opcao);
        
        switch(opcao){
            case 0:
                printf("\nSaindo...");
            break;
            case 1:
                printf("\nDigite o valor a ser inserido: ");
                scanf("%d", &valor);
                raiz = inserir(raiz, valor);
            break;
            case 2:
                printf("\nDigite o valor a ser removido: ");
                scanf("%d", &valor);
                raiz = remover(raiz, valor);
            break;
            case 3:
                imprimir(raiz, 1);
            break;
            default:
                printf("\nOpção inválida, tente novamente.");
        }
    }while(opcao);

    return 0;
}