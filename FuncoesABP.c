#include <stdlib.h>
#include <stdio.h>

typedef struct ABP
{
    int chave;
    struct ABP *esq, *dir;
} TNoABP;

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
TNoABP *insereNoRec(TNoABP **raiz, int k);             // D
void imprimeABP(TNoABP *raiz);                         // A
TNoABP *menorNo(TNoABP *raiz);                         // C
TNoABP *liberaABP(TNoABP **raiz);                      // E
void contaFolha(TNoABP *raiz, int *x);                 // B
void calculaMedia(TNoABP *raiz, double *k, double *x); // G

TNoABP *removeNo(TNoABP *raiz, int chave); // F

void removeNo2Filhos(TNoABP **raiz, int k);

int main()
{
    TNoABP *raiz = NULL;
    // int op = 0;
    // while (op != 8)
    // {
    //     printf("\nMENU:\n1 - Inserir no\n2 - Remover no\n3 - Imprimir ABP");
    //     printf("\n4 - Achar o menor no\n5 - Contar nos folha\n6 - Calcular media dos nos");
    //     printf("\n7 - Limpar ABP\n8 - Sair\n");
    //     scanf("%d", &op);
    //     switch (op)
    //     {
    //     case 1:
    //         printf("\noi\n");
    //         break;

    //     default:
    //         break;
    //     }
    // }

    insereNoRec(&raiz, 10);
    insereNoRec(&raiz, 7);
    insereNoRec(&raiz, 5);
    insereNoRec(&raiz, 20);
    insereNoRec(&raiz, 15);
    insereNoRec(&raiz, 30);
    insereNoRec(&raiz, 12);
    insereNoRec(&raiz, 17);
    insereNoRec(&raiz, 25);
    insereNoRec(&raiz, 35);
    printf("\nPrimeira insercao: ");
    imprimeABP(raiz);
    TNoABP *novosla = menorNo(raiz);
    int *n = NULL;
    int z = 0;
    contaFolha(raiz, &z);
    printf("\nA arvore tem %d no(s) folha", z);
    double k = 0, x = 0;
    calculaMedia(raiz, &k, &x);
    printf("\nA media de todos os nos da arvore eh: %.2f", k / x);

    raiz = removeNo(raiz, 10);
    printf("\nNo retornado: %d", raiz->chave);
    printf("\nSegunda impressao: ");
    imprimeABP(raiz);

    printf("\nRemovendo todos os nos... ");
    raiz = liberaABP(&raiz);
    imprimeABP(raiz);

    return 0;
}

TNoABP *alocaNo(int k)
{
    TNoABP *novo = (TNoABP *)malloc(sizeof(TNoABP));
    novo->esq = NULL;
    novo->dir = NULL;
    novo->chave = k;
    return novo;
}

TNoABP *insereNoRec(TNoABP **raiz, int k)
{
    if (*(raiz) == NULL)
    { // caso base = arvore vazia
        TNoABP *novo = alocaNo(k);
        *(raiz) = novo;
        return *raiz;
    }
    if (k > (*raiz)->chave)
    {                                  // no passado é menor que o no atual
        insereNoRec(&(*raiz)->dir, k); // vai para a esquerda
    }
    else
    {
        insereNoRec(&(*raiz)->esq, k);
    }
    return *raiz;
}

void imprimeABP(TNoABP *raiz)
{
    if (raiz == NULL)
    {
        printf("\nA arvore esta vazia!");
        return;
    }
    if (raiz->esq != NULL)
    {
        imprimeABP(raiz->esq);
    }
    printf("\n%d", raiz->chave); // imprime abp em ordem, esq - raiz - dir
    if (raiz->dir != NULL)
    {
        imprimeABP(raiz->dir);
    }
}

TNoABP *menorNo(TNoABP *raiz)
{
    TNoABP *aux = raiz;
    if (raiz == NULL)
    {
        return NULL;
    }
    while (aux->esq != NULL)
    {
        aux = aux->esq;
    } // chegou no menor no
    printf("\nO menor no eh: %d", aux->chave);
    return aux;
}

TNoABP *liberaABP(TNoABP **raiz)
{
    if (*raiz != NULL)
    {
        liberaABP(&(*raiz)->esq);
        liberaABP(&(*raiz)->dir);
        free(*raiz);
        // *raiz = NULL;
    }
    return NULL;
}

void contaFolha(TNoABP *raiz, int *x)
{
    if (raiz == NULL)
    {
        return;
    }
    contaFolha(raiz->esq, x);
    contaFolha(raiz->dir, x);
    if ((raiz->dir == NULL) && (raiz->esq == NULL))
    {
        *x += 1;
    }
}

void calculaMedia(TNoABP *raiz, double *k, double *x)
{
    if (raiz == NULL)
    {
        return;
    }
    calculaMedia(raiz->esq, k, x);
    *k += raiz->chave;
    *x += 1;
    calculaMedia(raiz->dir, k, x);
}

TNoABP *buscaNo(TNoABP **raiz, int k)
{
    if ((*raiz) == NULL)
    {
        return NULL;
    }
    if ((*raiz)->chave == k)
    {
        return raiz; // achou
    }
    if ((*raiz)->chave > k)
    {
        return buscaNo(&(*raiz)->esq, k);
    }
    else
    {
        return buscaNo(&(*raiz)->dir, k);
    }
}

TNoABP *auxMenor(TNoABP **raiz) // achar o menor dos maiores
{
    if (*raiz == NULL)
        return NULL;

    if ((*raiz)->esq == NULL)
        return raiz;
    return auxMenor(&(*raiz)->esq);
}

TNoABP *removeNo(TNoABP *raiz, int chave) // nesta funcao, trocamos o valor do no substituto no no a ser removido e removemos o substituto
{
    if (raiz == NULL)
    {
        printf("Valor nao encontrado!\n");
        return NULL;
    }
    else
    {                             // procura o nó a remover
        if (raiz->chave == chave) // se encontrou o no que vai ser removido
        {
            if (raiz->esq == NULL && raiz->dir == NULL) // se esse no eh folha
            {
                printf("\nNo folha removido: %d\n", raiz->chave);
                free(raiz);
                return NULL;
            }
            else // se nao for no folha
            {
                if (raiz->esq != NULL && raiz->dir != NULL) // se o no tiver dois filhos
                {
                    TNoABP *aux = raiz->esq;
                    while (aux->dir != NULL)
                        aux = aux->dir;
                    raiz->chave = aux->chave;
                    printf("\nElemento trocado: %d", chave);
                    raiz->esq = removeNo(raiz->esq, aux->chave);
                    return raiz;
                }
                else // se o no tiver apenas um filho
                {
                    TNoABP *aux;
                    if (raiz->esq != NULL)
                        aux = raiz->esq;
                    else
                        aux = raiz->dir;
                    free(raiz);
                    printf("\nNo com 1 filho removido: %d\n", chave);
                    return aux;
                }
            }
        }
        else
        {
            if (chave < raiz->chave) // procura o no na esquerda caso seja menor
            {
                raiz->esq = removeNo(raiz->esq, chave);
            }
            else // caso contrario vai pra direita
            {
                raiz->dir = removeNo(raiz->dir, chave);
            }
            return raiz;
        }
    }
}
