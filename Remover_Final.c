/*
Autor: Gustavo de Lima Sossai
Data: 08/11/2024
Equipe: RA: 173342-2024
        RA: 179427-2024
Obj:Função que permita que o usuario excluia um casdastro no final da lista
*/

#include "funcoes.h"

// Criando a função remover final da lista
void remover_final(tipolista *l)
{
    tipoapontador p;
    tipoapontador r;
    // Verificando se a lista possui algum cadastro
    if (l->primeiro->proximo == NULL)
    {
        free(l->primeiro);
        l->primeiro = NULL;
        l->ultimo = NULL;
        gotoxy(7, 24);
        printf("Cadastro removido com sucesso");
        getch();
    }
    else
    {
        // Caso a lista tenha mais de um elemento
        r = l->primeiro;
        p = r->proximo;

        // Percorre a lista até encontrar o penúltimo elemento
        while (p->proximo != NULL)
        {
            p = p->proximo;
            r = r->proximo;
        }

        // Quando encontrar o elemento da lista devera eliminar o espaço de memoria
        free(p);
        r->proximo = NULL;
        l->ultimo = r;
        gotoxy(7, 24);
        printf("Cadastro removido com sucesso");
        getch();
    }
}