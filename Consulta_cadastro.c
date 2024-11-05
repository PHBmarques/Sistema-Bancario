/*
Autor: Gustavo de Lima Sossai
 RData: 04/11/2024
Equipe:A: 173342-2024
        RA: 179427-2024
Obj:Consulta os dados que ja foram cadastrados
*/
#include "funcoes.h"
#include<stdio.h>
#include<stdlib.h>
void consultar_cadastro(tipolista *l)
{
    tipoapontador p;
    p = l->primeiro;
    while (p != NULL)
    {
        tela();
        telacadastro();
        gotoxy(50, 7);
        printf("%d", p->conteudo.codigo_conta);
        gotoxy(50, 9);
        printf("%s", p->conteudo.banco);
        gotoxy(50, 11);
        printf("%s", p->conteudo.agencia);
        gotoxy(50, 13);
        printf("%s", p->conteudo.numero_conta);
        gotoxy(50, 15);
        printf("%s", p->conteudo.tipo_conta);
        gotoxy(50, 17);
        printf("%.2lf", p->conteudo.vl_saldo);
        gotoxy(50, 19);
        printf("%.2lf", p->conteudo.vl_limite);
        gotoxy(50, 21);
        printf("%s", p ->conteudo.status);
        gotoxy(7, 24);
        printf("Pressione qualquer botao para continuar");
        getch();
        p = p->proximo;
    }
}