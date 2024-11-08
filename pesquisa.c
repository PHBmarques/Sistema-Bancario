/*
Autor: Pedro Henrique Bernardo Marques
Data: 04/11/2024
Equipe: RA: 173342-2024
        RA: 179427-2024
Obj: Funcao que ira permitir o código percorrer a lista 
*/
#include "funcoes.h"
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