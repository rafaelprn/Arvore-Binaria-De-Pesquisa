#include <stdlib.h>
#include <stdio.h>

typedef struct ABP{
    int chave;
    struct ABP *esq, *dir;
}TNoABP;

/* 
1. Apresente um procedimento (ou função) para cada enunciado abaixo. Decida você mesmo a struct dos nós, 
os protótipos das funções procurando usar de bom senso. Se necessário, apresente outras suposições ao seu código.
a) imprime todos os nós de uma ABP
b) conta o total de nós folhas de uma ABP
c) devolve o ponteiro do ponteiro do nó de menor valor chave de uma ABP
d) insere um valor chave em uma dada ABP.
e) procedimento que remove todos os nós de uma árvore binária de pesquisa dada. Não permita vazamentos ou qualquer outro tipo de erro de ponteiros.
f) dado o ponteiro de ponteiro para um nó de uma ABP, remova tal nó. Assuma que o nó não é folha.
g) calcular a média dos valores chaves de uma ABP dada.
*/

int main(){
    TNoABP *raiz = NULL;
    raiz = insereNoRec(&raiz, 10);
    insereNoRec(&raiz, 5);
    insereNoRec(&raiz, 15);
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
    TNoABP *novo = alocaNo(k);
    if(*(raiz) == NULL){ //caso base = arvore vazia
        *(raiz) = novo;
        return raiz;
    }
    if(k < (*raiz)->chave){ //no passado é menor que o no atual
        (*raiz)->esq = insereNoRec(((*raiz)->esq), novo); //vai para a esquerda
    }
    if(k > (*raiz)->chave){ //no passado é maior que o n´atual
        (*raiz)->dir = insereNoRec(((*raiz)->dir), novo); //vai para a direita
    }
}

void insereNo(TNoABP **raiz, int k){
    TNoABP *novo = alocaNo(k);
    //TNoABP *paux = *raiz;

    if(*raiz == NULL){ //a arvore esta vazia?
        *raiz = novo;
        return;
    }
    else{
        TNoABP *atual = *raiz;
        TNoABP *anterior = *raiz;
        while(atual != NULL){
            anterior = atual;
            if(k < atual->chave){//o novo nó é menor que o no atual
                atual = atual->esq;
            }
            if(k > atual->chave){//o novo nó é maior que o nó atual
                atual = atual->dir;
            }
        }
        if(k < anterior->chave){//se o novo nó é menor que o pai dele
            anterior->esq = novo;
        }
        else{//se o novo nó é maior que o pai dele
            anterior->dir = novo;
        }
        return;
    }
}

void imprimeABP(TNoABP *raiz){
    if(raiz == NULL){
        return;
    }
    printf("%d", raiz->chave);
    imprimeABP(raiz->esq);
    imprimeABP(raiz->dir);
}

TNoABP *buscaABPRec(TNoABP *raiz, int k){
    if(raiz == NULL){//caso base
        return NULL;
    }
    if(k == raiz->chave){ //se achou a chave
        return raiz;
    }
    if(k < raiz->chave){ //se esta na esquerda
        return buscaABPRec(raiz->esq, k);
    }
    else{ //se nao ta na esquerda ta na direita
        return buscaABPRec(raiz->dir, k);
    }
}

int buscaABPRec(TNoABP *raiz){
    if(raiz == NULL){//caso base
        return NULL;
    }
    if(raiz->esq == NULL && raiz->dir == NULL){ //se achou o folha
        return 1;
    }
    else{ 
        return 0;
    }
}