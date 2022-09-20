#include <stdlib.h>
#include <stdio.h>

typedef struct ABP{
    int chave;
    struct ABP *esq, *dir;
}TNoABP;

/* 
1. Apresente um procedimento (ou função) para cada enunciado abaixo. Decida você mesmo a struct dos nós, 
os protótipos das funções procurando usar de bom senso. Se necessário, apresente outras suposições ao seu código.
a) imprime todos os nós de uma ABP - feita
b) conta o total de nós folhas de uma ABP
c) devolve o ponteiro do ponteiro do nó de menor valor chave de uma ABP - feito
d) insere um valor chave em uma dada ABP. - feita
e) procedimento que remove todos os nós de uma árvore binária de pesquisa dada. 
    Não permita vazamentos ou qualquer outro tipo de erro de ponteiros.
f) dado o ponteiro de ponteiro para um nó de uma ABP, remova tal nó. Assuma que o nó não é folha.
g) calcular a média dos valores chaves de uma ABP dada.
*/

TNoABP *alocaNo(int k);
TNoABP* insereNoRec(TNoABP **raiz, int k); //D
void imprimeABP(TNoABP *raiz); //A
TNoABP* menorNo(TNoABP *raiz); //C
void liberaABP(TNoABP **raiz); //E
void contaFolha(TNoABP *raiz, int *x); //B
void calculaMedia(TNoABP *raiz, double *k, double *x); //G
void removeNo(TNoABP **raiz, int k); //F


int main(){
    TNoABP *raiz = NULL;
    insereNoRec(&raiz, 10);
    insereNoRec(&raiz, 5);
    insereNoRec(&raiz, 3);
    insereNoRec(&raiz, 7);
    insereNoRec(&raiz, 2);
    insereNoRec(&raiz, 6);
    insereNoRec(&raiz, 8);
    insereNoRec(&raiz, 1);
    //imprimeABP(raiz);
    //TNoABP *novosla = menorNo(raiz);
    // liberaABP(&raiz);
    //int *n = NULL;
    int z = 0;
    contaFolha(raiz, &z);
    printf("\n%d", z);
    // imprimeABP(raiz);
    double k = 0, x = 0;
    calculaMedia(raiz, &k, &x);
    printf("\n%.2f", k/x);
    


    return 0;
}

TNoABP *alocaNo(int k){
    TNoABP *novo = (TNoABP *)malloc(sizeof(TNoABP));
    novo->esq = NULL;
    novo->dir = NULL;
    novo->chave = k;
    return novo;
}

TNoABP* insereNoRec(TNoABP **raiz, int k){
    if(*(raiz) == NULL){ //caso base = arvore vazia
        TNoABP *novo = alocaNo(k);
        *(raiz) = novo;
        return *raiz;
    }
    if(k > (*raiz)->chave){ //no passado é menor que o no atual
        insereNoRec(&(*raiz)->dir, k); //vai para a esquerda
    }
    else{
        insereNoRec(&(*raiz)->esq, k);
    }
    return *raiz;
}

void imprimeABP(TNoABP *raiz){
    if(raiz == NULL){
        printf("nada");
        return;
    }
    imprimeABP(raiz->esq);
    printf("\n%d", raiz->chave); //imprime abp em ordem, esq - raiz - dir
    imprimeABP(raiz->dir);
}

TNoABP* menorNo(TNoABP *raiz){
    TNoABP *aux = raiz;
    TNoABP *pant;
    if (raiz == NULL){
        return NULL;
    }
    while(aux->esq != NULL){
        pant = aux;
        aux = aux->esq; 
    }//chegou no menor no
    printf("\n%d", pant->chave);
    return &(*pant);
}

void liberaABP(TNoABP **raiz){
    if(*raiz != NULL){
        liberaABP(&(*raiz)->esq);
        liberaABP(&(*raiz)->dir);
        free(*raiz);
        *raiz = NULL;
    }
}

void contaFolha(TNoABP *raiz, int *x){
    if(raiz == NULL){
        return;
    }
    contaFolha(raiz->esq, x);
    contaFolha(raiz->dir, x);
    if((raiz->dir == NULL) != (raiz->esq == NULL)){
        *x += 1;
    }
}

// void removeNo(TNoABP **raiz, int k)
// {
//     TNoABP *filho = NULL;
//     if (raiz == NULL){
//         return;
//     }
//     if (*raiz == NULL){
//         return;
//     }
//     if (((*raiz)->dir == NULL) != ((*pp)->esq == NULL)){ //remover com 1 filho
//         filho = ((*raiz)->esq == NULL) ? (*pp)->dir : (*pp)->esq;
//         free(*raiz);
//         *raiz = filho;
//         return;
//     }
//     if(raiz->esq != NULL && raiz->dir != NULL){
//         TNoABP *aux = raiz->esq;
//         while(aux->dir != NULL){
//             aux = aux + aux->dir;
//         }
//         raiz->chave = aux->chave;
//         aux->chave =chave;
        
//     }

// }

void calculaMedia(TNoABP *raiz, double *k, double *x){
    if(raiz == NULL){
        return;
    }
    calculaMedia(raiz->esq, k, x);
    *k += raiz->chave;
    *x += 1;
    calculaMedia(raiz->dir, k, x);
}