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
    int linha = 8;
    int troca;
    tipoapontador x;
    // ordenação simples pela comparação do código da conta
    p = l->primeiro;
    while (troca)
    {
        troca=0;
        p=l->primeiro;
        while (p != NULL && p->proximo != NULL)
        {
            if (p->conteudo.codigo_conta > p->proximo->conteudo.codigo_conta)
            {
                // troca o conteudo entre p e p de proximo
                x = p->proximo;
                p->proximo = x->proximo;
                x->proximo = p;

                if (p == l->primeiro)
                {

                    l->primeiro = x; // atualiza o ponteiro para o proximo item
                }
                troca=1;//marca que ouve troca
            }
            p = p->proximo; // move para o proximo item
        }
    }
    // exibe os dados rodenados
    p = l->primeiro;
    while (p != NULL)
    {
        gotoxy(2, linha);
        printf("%d", p->conteudo.codigo_conta);
        gotoxy(6, linha);
        printf("%s", p->conteudo.banco);
        gotoxy(18, linha);
        printf("%s", p->conteudo.agencia);
        gotoxy(26, linha);
        printf("%s", p->conteudo.numero_conta);
        gotoxy(34, linha);
        printf("%s", p->conteudo.tipo_conta);
        if (p->conteudo.tipo_conta[0] == '1')
        {
            gotoxy(34, linha);
            printf("Corrente");
        }
        else if (p->conteudo.tipo_conta[0] == '2')
        {
            gotoxy(34, linha);
            printf("Poupanca");
        }
        else if (p->conteudo.tipo_conta[0] == '3')
        {
            gotoxy(34, linha);
            printf("Cartao credito");
        }
        gotoxy(50, linha);
        printf("%.2lf", p->conteudo.vl_saldo);
        gotoxy(65, linha);
        printf("%.2lf", p->conteudo.vl_limite);
        gotoxy(76, linha);
        printf("%s", p->conteudo.status);
        linha++;
        p = p->proximo; // avança para o proximo nó
    }
    gotoxy(7, 24);
    printf("Pressione qualquer tecla para continuar...");
    getch();
}