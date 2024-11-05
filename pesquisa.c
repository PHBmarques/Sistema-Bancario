#include "funcoes.h"
#include<stdio.h>
#include<stdlib.h>
tipoapontador pesquisa(tipolista *L, int cod){
    tipoapontador aux;
     aux = L->primeiro;
     while (aux != NULL){
        if (aux->conteudo.codigo_conta==cod){
            return aux;
        }
        aux = aux ->proximo;
     }
     return NULL;
}