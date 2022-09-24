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
TNoABP* removeNo(TNoABP *raiz, int chave); //F

void removeNo2Filhos(TNoABP **raiz, int k);


int main(){
    TNoABP *raiz = NULL;
    // insereNoRec(&raiz, 10);
    // insereNoRec(&raiz, 5);
    // insereNoRec(&raiz, 3);
    // insereNoRec(&raiz, 7);
    // insereNoRec(&raiz, 2);
    // insereNoRec(&raiz, 6);
    // insereNoRec(&raiz, 8);
    // insereNoRec(&raiz, 1);
    insereNoRec(&raiz, 100);
    insereNoRec(&raiz, 50);
    insereNoRec(&raiz, 25);
    insereNoRec(&raiz, 75);
    insereNoRec(&raiz, 60);
    insereNoRec(&raiz, 80);
    insereNoRec(&raiz, 90);
    insereNoRec(&raiz, 55);
    insereNoRec(&raiz, 65);
    insereNoRec(&raiz, 150);
    imprimeABP(raiz);
    raiz = removeNo(raiz, 75);
    //imprimeABP(raiz);
    //TNoABP *novosla = menorNo(raiz);
    // liberaABP(&raiz);
    //int *n = NULL;
    // int z = 0;
    // contaFolha(raiz, &z);
    // printf("\n%d", z);
    printf("\nimpressao");
    imprimeABP(raiz);
    // double k = 0, x = 0;
    // calculaMedia(raiz, &k, &x);
    // printf("\n%.2f", k/x);
    


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
        //printf("nada");
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
//     if(raiz == NULL){
//         return;
//     }
//     if(*raiz == NULL){
//         return;
//     }
//     if (((*raiz)->dir == NULL) != ((*raiz)->esq == NULL)){ //remover com 1 filho
//         filho = ((*raiz)->esq == NULL) ? (*raiz)->dir : (*raiz)->esq;
//         free(*raiz);
//         *raiz = filho;
//         return;
//     }
//     if((*raiz)->esq != NULL && (*raiz)->dir != NULL){
//         TNoABP *aux = (*raiz)->esq;
//         while(aux->dir != NULL){
//             aux = aux + aux->dir;
//         }
//         (*raiz)->chave = aux->chave;
//         aux->chave = chave;
//     }
// }

// TNoABP* removeNo(TNoABP *raiz, int k){
//     TNoABP *pant = NULL;
//     pant = raiz;
//     if(raiz == NULL){ //se a arvore estiver vazia
//         printf("\nO valor nao encontrado!");
//         return NULL;
//     }
//     else{
//         //procura o no para remover
//         if(raiz->chave == k){
//             //remocao de no folha
//             if(raiz->esq == NULL && raiz->dir == NULL){ //no folha
//                 free(raiz);
//                 return NULL;
//             }
//             else{
//                 //remocao de nos com 2 filhos
//                 if(raiz->esq != NULL && raiz->dir != NULL){ //se tem 2 filhos
//                     TNoABP *aux = raiz->esq; //vou pegar o maior dos menores
//                     while(aux->dir != NULL){ //enquanto tiver alguem maior
//                         aux = aux->dir; //percorre ate encontrar o maior
//                      //o maior da subarvore, vai estar o maximo a direita possivel,
//                     }//aqui pegou o maior no da subarvore e botou em aux
//                     raiz->chave = aux->chave; //a chave do meu no q vai ser removido passa a ser
//                     aux->chave = k;
//                     raiz->esq = removeNo(raiz->esq, k);
//                     return raiz;
//                 }
//                 else{
//                     //remocao de no com 1 filho
//                     TNoABP *aux;
//                     if(raiz->esq != NULL){
//                         aux = raiz->esq;
//                     }
//                     else{
//                         aux = raiz->dir;
//                     }
//                     free(raiz);
//                     return aux;
//                 }
//             }
//         }
//         else{
//             if(k < raiz->chave){
//                 raiz->esq = removeNo(raiz->esq, k);
//             }
//             else{
//                 raiz->dir = removeNo(raiz->dir, k);
//             }
//             return raiz;
//         }
//     }
// }

/*
        função para remover nós da Árvore binária
*/
TNoABP* removeNo(TNoABP *raiz, int chave) {
    if(raiz == NULL){
        printf("Valor nao encontrado!\n");
        return NULL;
    } else { // procura o nó a remover
        if(raiz->chave == chave) {
            // remove nós folhas (nós sem filhos)
            if(raiz->esq == NULL && raiz->dir == NULL) {
                free(raiz);
                printf("\nNo folha removido: %d\n", chave);
                return NULL;
            }
            else{
                // remover nós que possuem 2 filhos
                if(raiz->esq != NULL && raiz->dir != NULL){
                    TNoABP *aux = raiz->esq;
                    while(aux->dir != NULL)
                        aux = aux->dir;
                    raiz->chave = aux->chave;
                    aux->chave = chave;
                    printf("\nElemento trocado: %d\n", chave);
                    raiz->esq = removeNo(raiz->esq, chave);
                    return raiz;
                }
                else{
                    // remover nós que possuem apenas 1 filho
                    TNoABP *aux;
                    if(raiz->esq != NULL)
                        aux = raiz->esq;
                    else
                        aux = raiz->dir;
                    free(raiz);
                    printf("\nNo com 1 filho removido: %d\n", chave);
                    return aux;
                }
            }
        } else {
            if(chave < raiz->chave)
                raiz->esq = removeNo(raiz->esq, chave);
            else
                raiz->dir = removeNo(raiz->dir, chave);
            return raiz;
        }
    }
}

// void removeNo2Filhos(TNoABP **raiz, int k){
//     //MAIOR DOS MENORES
//     if((*raiz) == NULL){
//         printf("A arvore esta vazia!");
//         return;
//     }
//     TNoABP *paux = (*raiz)->esq; //substituto
//     TNoABP *pant = paux; //pai do substituto
//     while(paux->dir != NULL){
//         pant = paux;
//         paux = paux->dir; //achar o maior no da subarvore esquerda
//     } //achou
//     (*raiz)->chave = paux->chave;
//     pant->dir = NULL;
//     free(paux);
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