/*
Autor: Gustavo de Lima Sossai
Data: 04/11/2024
Equipe: RA: 173342-2024
        RA: 179427-2024
Obj: Criar um contador que auxilia o codigo escrevito
*/

#include "funcoes.h"
#include<stdio.h>
#include<stdlib.h>
int contador(tipolista *l)
{
    tipoapontador aux;
    int cont = 0;
    aux = l->primeiro;
    while (aux != NULL)
    {
        cont++;
        aux = aux->proximo;
    }
    return cont;
}