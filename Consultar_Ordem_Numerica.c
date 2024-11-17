/*
Autor: Gustavo de Lima Sossai
Data: 16/11/2024
Equipe: RA: 173342-2024
        RA: 179427-2024
Obj:Função de consulta casdastro em ordem de codigo
*/

#include "funcoes.h"

void consultar_ordem_numerica(tipolista *l)
{
    tela();
    tela_consultar_ordem_numerica();
    tipoapontador p;
    infocontas ContaBancaria;
    p = l->primeiro;
    int i = 0;
    int j;
    int tamanho = 0;
    tipoapontador  p = l ->primeiro->proximo;

    tamanho = contador(l);

    infocontas vetor[tamanho];
    p = l->primeiro->proximo;

    gotoxy(2, 8);
    printf("%d", p->conteudo.codigo_conta);
    gotoxy(6, 8);
    printf("%s", p->conteudo.banco);
    gotoxy(18, 8);
    printf("%s", p->conteudo.agencia);
    gotoxy(26, 8);
    printf("%s", p->conteudo.numero_conta);
    gotoxy(34, 8);
    printf("%s", p->conteudo.tipo_conta);
    if (p->conteudo.tipo_conta[0] == '1')
    {
        gotoxy(34, 8);
        printf("Corrente");
    }
    else if (p->conteudo.tipo_conta[0] == '2')
    {
        gotoxy(34, 8);
        printf("Poupanca");
    }
    else if (p->conteudo.tipo_conta[0] == '3')
    {
        gotoxy(34, 8);
        printf("Cartao credito");
    }
    gotoxy(50, 8);
    printf("%.2lf", p->conteudo.vl_saldo);
    gotoxy(65, 8);
    printf("%.2lf", p->conteudo.vl_limite);
    gotoxy(76, 8);
    printf("%s", p->conteudo.status);
    getch();
}