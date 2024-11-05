/* 
Autor: Gustavo de Lima Sossai
Data: 04/11/2024
Equipe: RA: 173342-2024
        RA: 179427-2024
Obj:Permite o cadastro dos dados em uma determinada posicao
*/
#include "funcoes.h"
#include<stdio.h>
#include<stdlib.h>
void casdastrar_posicao(tipolista *l)
{
    int resp = 0;
    infocontas ContaBancaria;
    tipoapontador p;
    tipoapontador aux;
    tipoapontador r;
    int pos;
    int x;
    int qtde;

    do
    {
        do
        {
            tela();
            telacadastro();
            gotoxy(7, 24);
            printf("Digite 0 para sair");
            gotoxy(50, 7);
            scanf("%d", &ContaBancaria.codigo_conta);
            aux = pesquisa(l, ContaBancaria.codigo_conta);
            if (aux != NULL)
            {
                gotoxy(7, 24);
                printf("Codigo ja cadastrado");
                getch();
            }
        } while (aux != NULL);
        if (ContaBancaria.codigo_conta != 0)
        {
            gotoxy(50, 9);
            fflush(stdin);
            fgets(ContaBancaria.banco, 50, stdin);
            gotoxy(50, 11);
            fflush(stdin);
            fgets(ContaBancaria.agencia, 10, stdin);
            gotoxy(50, 13);
            fflush(stdin);
            fgets(ContaBancaria.numero_conta, 20, stdin);
            gotoxy(50, 15);
            fflush(stdin);
            fgets(ContaBancaria.tipo_conta, 20, stdin);
            gotoxy(50, 17);
            scanf("%lf", &ContaBancaria.vl_saldo);
            gotoxy(50, 19);
            scanf("%lf", &ContaBancaria.vl_limite);
            gotoxy(50, 21);
            fflush(stdin);
            fgets(ContaBancaria.status, 10, stdin);
            gotoxy(7, 24);
            // Ira perfuntar se o usuario deseja salvar esses dados ou não
            printf("Deseja Salvar os dados(1-SIM/2-NAO):");
            scanf("%d", &resp);

            if (resp == 1)
            {
                do
                {
                    gotoxy(07, 23);
                    printf("Em qual posicao deseja gravar os dados:");
                    scanf("%d", &pos);
                    qtde = contador(l);
                    if (pos > qtde)
                    {
                        gotoxy(07, 23);
                        printf("Posicao invalida                         ");
                        getch();
                    }
                } while (pos > qtde);
                r = (tipoapontador)malloc(sizeof(tipoitem));
                r->proximo = NULL;
                r->conteudo = ContaBancaria;
                p = l->primeiro;
                if (pos == 1)
                {
                    r->proximo = l->primeiro;
                    l->primeiro = r;
                }
                else if (pos == qtde)
                {
                    l->ultimo->proximo = r;
                    l->ultimo = r;
                    return;
                }
                else
                {
                    for (x = 1; x <= pos - 2; x++)
                    {
                        p = p->proximo;
                    };
                    r->proximo = p->proximo;
                    p->proximo = r;
                }
                gotoxy(7, 24);
                printf("Cadastro concluido                      ");
                getch();
            }
            gotoxy(7, 24);
            printf("Cadastrar novo funcionario (1-SIM/2-NAO)");
            scanf("%d", &resp);
        }
    } while (resp == 1);
}