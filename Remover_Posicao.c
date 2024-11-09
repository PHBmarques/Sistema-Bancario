/*
Autor: Gustavo de Lima Sossai
Data: 08/11/2024
Equipe: RA: 173342-2024
        RA: 179427-2024
Obj:Função que permita que o usuario excluia um casdastro no inicio da lista
*/

#include "funcoes.h"

void remover_posicao(tipolista *l)
{
    tipoapontador p;
    tipoapontador r;
    int pos = 0;
    int cont;
    gotoxy(07, 23);
    printf("Digite a posicao que deseja remover:");
    scanf("%d", &pos);

    r = l->primeiro;
    p = r->proximo;
    cont = 1;
    // Verifica se ele ira remover o primeiro cadastro da lista
    if (pos == 1)
    {
        p = l->primeiro;
        l->primeiro = p->proximo;
    }
    else
    {
        // Caso não queira remover o primeiro cadastro ele ira remover outro elemento selecionado da lista
        while (cont < pos - 1)
        {
            cont = cont + 1;
            p = p->proximo;
            r = r->proximo;
        };
    }
    r->proximo = p->proximo;
    free(p);
    gotoxy(07, 23);
    printf("                                           ");
    gotoxy(07, 23);
    printf("Lista removida com sucesso");
    getch();
}