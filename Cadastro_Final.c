/*
Autor: Pedro Henrique Bernardo Marques
 RData: 04/11/2024
Equipe:A: 173342-2024
        RA: 179427-2024
Obj: Cadastrar os dados no incio


*/

#include "funcoes.h"
#include<stdio.h>
#include<stdlib.h>
void cadastrofinal(tipolista *l)
{
    int resp;
    infocontas ContaBancaria;
    tipoapontador p;
    tipoapontador aux;

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
            // Se ele quiser salvar ele ira salvar os dados no final
            if (resp == 1)
            {
                p = (tipoapontador)malloc(sizeof(tipoitem));
                p->proximo = NULL;
                p->conteudo = ContaBancaria;
                if (l->primeiro == NULL)
                {
                    l->primeiro = p;
                    l->ultimo = p;
                }
                else
                {
                    l->ultimo->proximo = p;
                    l->ultimo = p;
                }
                gotoxy(07, 24);
                printf("Cadastro com Sucesso!                 ");
                getch();
            }
            // caso ele não queira cadastrar uma nova Conta ira voltar para a tela de inicio
            gotoxy(7, 24);
            printf("Deseja cadastrar uma nova conta Bancaria (1 = sim / 2 = nao)? ");
            scanf("%d", &resp);
        }
    } while (resp == 1);
}