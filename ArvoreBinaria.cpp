#include "ArvoreBinaria.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

   struct NO{
      char info;
      struct NO *esq;
      struct NO *dir;
    };

ArvBin* cria_ArvBin(){
        ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
        if(raiz != NULL)
            *raiz = NULL;
        return raiz;
}

void libera_NO(struct NO* no){
    if(no == NULL)
        return;
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}

void libera_ArvBin(ArvBin* raiz){
    if(raiz == NULL)
        return;
    libera_NO(*raiz); // libera cada nó
    free(raiz); // libera a raiz
}

int estaVazia_ArvBin(ArvBin *raiz){
    if(raiz==NULL)
        return 1;
    if(*raiz==NULL)
        return 1;
    return 0;
}

int altura_ArvBin(ArvBin *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = altura_ArvBin(&((*raiz)->esq));
    int alt_dir = altura_ArvBin(&((*raiz)->dir));
    if (alt_esq > alt_dir)
        return(alt_esq + 1);
    else
        return(alt_dir + 1);
}

int totalNO_ArvBin(ArvBin *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = totalNO_ArvBin(&((*raiz)->esq));
    int alt_dir = totalNO_ArvBin(&((*raiz)->dir));
        return(alt_esq + alt_dir + 1);
};

void preOrdem_ArvBin(ArvBin *raiz){
    if (raiz == NULL)
        return;
    if (*raiz != NULL){
        cout << (*raiz)->info << endl;
        preOrdem_ArvBin(&((*raiz)->esq));
        preOrdem_ArvBin(&((*raiz)->dir));

    }
}

void emOrdem_ArvBin(ArvBin *raiz){
    if (raiz == NULL)
        return;
    if (*raiz != NULL){
        emOrdem_ArvBin(&((*raiz)->esq));
        cout << (*raiz)->info << endl;
        emOrdem_ArvBin(&((*raiz)->dir));
    }
}

void posOrdem_ArvBin(ArvBin *raiz){
    if (raiz == NULL)
        return;
    if (*raiz != NULL){
        posOrdem_ArvBin(&((*raiz)->esq));
        posOrdem_ArvBin(&((*raiz)->dir));
        cout << (*raiz)->info << endl;
    }
}

int insere_ArvBin(ArvBin *raiz, char simbol){
        if(raiz == NULL)
            return 0;
        struct NO* novo;
        novo = (struct NO*) malloc(sizeof(NO));
        if(novo == NULL)
            return 0;
        novo->info = simbol;
        novo->dir = NULL;
        novo->esq = NULL;
        if (*raiz == NULL)
            *raiz = novo;
        else {
                struct NO* atual = *raiz;
                struct NO* ant = NULL;
                while(atual !=NULL)
                {
                    ant = atual;
                    if(simbol == atual->info)
                    {
                        free(novo);
                        return 0;
                    }
                    if(simbol != atual->info)
                        atual = atual->dir;
                    else
                        atual = atual->esq;
                }
                if(simbol == ant->info)
                    ant->dir = novo;
                else
                    ant->esq = novo;
                }
return 1;
}

int consulta_ArvBin(ArvBin *raiz, char simbol){
    if(raiz == NULL)
        return 0;
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(simbol == atual->info){
            return 1;
        }
        if(simbol != atual->info)
            atual = atual->dir;
        else
            atual = atual->esq;
    };
    return 0;
}
