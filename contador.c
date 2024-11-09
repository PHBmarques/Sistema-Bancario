/*
Autor: Gustavo de Lima Sossai
Data: 04/11/2024
Equipe: RA: 173342-2024
        RA: 179427-2024
Obj: Criar um contador que auxilia o codigo escrevido
*/

#include "funcoes.h"
int contador(tipolista *l)
{
    tipoapontador aux;
    int cont = 0;
    aux = l->primeiro;

    // Percorre a lista até que o ponteiro aux aponte para NULL
    while (aux != NULL)
    {
        cont++;
        aux = aux->proximo;
    }
    //Retorna os elementos contados na lista
    return cont;
}