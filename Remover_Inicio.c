/*
Autor: Gustavo de Lima Sossai
Data: 08/11/2024
Equipe: RA: 173342-2024
        RA: 179427-2024
Obj:Função que permita que o usuario excluia um casdastro no inicio da lista
*/

#include "funcoes.h"

void remover_inicio(tipolista *l)
{
    tipoapontador p;
    // Verifica se a lista possui apenas um cadastro
    if (l->primeiro->proximo == NULL)
    {
        // Se a lista tem apenas um cadastro irá removelo
        free(l->primeiro);
        l->primeiro = NULL;
        l->ultimo = NULL;
        gotoxy(7, 24);
        printf("Cadastro removido com sucesso");
        getch();
    }
    else
    {
        // Caso a lista tenha mais de um cadasrtro
        p = l->primeiro;
        l->primeiro = p->proximo;
        free(p);
        gotoxy(7, 24);
        printf("Cadastro removida com sucesso");
        getch();
    }
}