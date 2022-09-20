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


int main(){
    TNoABP *raiz = NULL;
    // insereNoRec(&raiz, 10);
    // insereNoRec(&raiz, 5);
    // insereNoRec(&raiz, 3);
    // insereNoRec(&raiz, 7);
    // insereNoRec(&raiz, 2);
    // insereNoRec(&raiz, 6);
    // insereNoRec(&raiz, 8);
    //imprimeABP(raiz);
    //TNoABP *novosla = menorNo(raiz);
    //liberaABP(raiz);
    imprimeABP(raiz);
    


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
        return &raiz;
    }
    if(k > (*raiz)->chave){ //no passado é menor que o no atual
        insereNoRec(&(*raiz)->dir, k); //vai para a esquerda
    }
    else
        insereNoRec(&(*raiz)->esq, k);
}

void imprimeABP(TNoABP *raiz){
    if(raiz == NULL){
        printf("nada");
        return;
    }
    printf("\n%d", raiz->chave);
    imprimeABP(raiz->esq);
    imprimeABP(raiz->dir);
}

TNoABP* menorNo(TNoABP *raiz){
    TNoABP *aux = raiz;
    TNoABP *pant;
    if (raiz == NULL){
        return;
    }
    while(aux->esq != NULL){
        pant = aux;
        aux = aux->esq; 
    }//chegou no menor no
    printf("\n%d", pant->chave);
    return &(*pant);
}

void liberaABP(TNoABP **raiz){
    TNoABP *paux = *raiz;
    if(paux != NULL){
        liberaABP(paux->esq);
        liberaABP(paux->dir);
        free(paux);
    }
    *raiz = NULL;
}

// TNoABP *buscaABPRec(TNoABP *raiz, int k){
//     if(raiz == NULL){//caso base
//         return NULL;
//     }
//     if(k == raiz->chave){ //se achou a chave
//         return raiz;
//     }
//     if(k < raiz->chave){ //se esta na esquerda
//         return buscaABPRec(raiz->esq, k);
//     }
//     else{ //se nao ta na esquerda ta na direita
//         return buscaABPRec(raiz->dir, k);
//     }
// }

// int buscaABPRec2(TNoABP *raiz){
//     if(raiz == NULL){//caso base
//         return NULL;
//     }
//     if(raiz->esq == NULL && raiz->dir == NULL){ //se achou o folha
//         return 1;
//     }
//     else{ 
//         return 0;
//     }
// }