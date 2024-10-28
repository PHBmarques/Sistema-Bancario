/*Autor:Pedro Henrique Bernardo Marques
  Data:23/10/2024
  Objetivo:Sistema de contole Bancario*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>
#include "funcoes.c"
#include "tela.c"
/*Autor:Pedro
  criado a funcao de cadastrar as informacoes no final*/
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
/*Autor: Pedro
  Funcçao que ira posibilitar o cadastro de uma nova conta bancaria no inicio*/
void cadastrarinicio(tipolista *l)
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
            // Caso ele deseje salvar os dados ira cadastralos no inicio do sistema
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
                    p->proximo = l->primeiro;
                    l->primeiro = p;
                }
                gotoxy(07, 24);
                printf("Cadastro com Sucesso!                 ");
                getch();
            }
            gotoxy(7, 24);
            printf("Deseja cadastrar uma nova conta Bancaria (1 = sim / 2 = nao)? ");
            scanf("%d", &resp);
        }
    } while (resp == 1);
}
void cadastrar(tipolista *l)
{
    int opc = 0;
    do
    {
        tela();
        gotoxy(27, 03);
        printf("CADASTRO DE CONTAS");
        gotoxy(25, 6);
        printf("1 - Cadastro Contas Bancaria no Final");
        gotoxy(25, 8);
        printf("2 - Cadastro Contas Bancaria no Inicio");
        gotoxy(25, 10);
        printf("3 - Cadastro Contas Bancaria no Posicao");
        gotoxy(25, 12);
        printf("4 - Remover Contas Bancaria no Final");
        gotoxy(25, 14);
        printf("5 - Remover Contas Bancaria no Inicio");
        gotoxy(25, 16);
        printf("6 - Remover Contas Bancaria no Posicao");
        gotoxy(25, 18);
        printf("7 - Alteracao de conta bancario");
        gotoxy(25, 20);
        printf("8 - Consultar Contas Bancaria");
        gotoxy(25, 22);
        printf("9 - Retornar no Menu Princial");
        gotoxy(07, 24);
        printf("Digite a opcao:  ");
        scanf("%d", &opc);
        switch (opc)
        {
        case 1:
            cadastrofinal(l);
            break;
        case 2:
            cadastrarinicio(l);
            break;
        case 3:
            cadastrar(l);
            break;
        case 4:
            cadastrar(l);
            break;
        case 5:
            cadastrar(l);
            break;
        case 6:
            cadastrar(l);
            break;
        case 7:
            cadastrar(l);
            break;
        case 8:
            cadastrar(l);
            break;
        }
    } while (opc != 9);
}
void Movimentacao()
{
    int opc = 0;
    do
    {
        gotoxy(24, 03);
        printf("MOVIMENTACAO FINANCEIRA");
        gotoxy(30, 10);
        printf("1-Registrar Entrada");
        gotoxy(30, 12);
        printf("2-Registrar Saida");
        gotoxy(30, 14);
        printf("3-Consultar Movimentacao");
        gotoxy(30, 16);
        printf("4-Voltar");
        gotoxy(7, 24);
        printf("Digite a opcao: ");
        scanf("%d", &opc);
    } while (opc != 4);
}
int main()
{
    system("color 1F");
    int opc = 0;
    tipolista l;
    l.primeiro = NULL;
    l.ultimo = NULL;
    do
    {
        tela();
        gotoxy(28, 03);
        printf("MENU PRINCIPAL");
        gotoxy(30, 10);
        printf("1-Cadastro de Contas");
        gotoxy(30, 12);
        printf("2-Movimentacao Financeira");
        gotoxy(30, 14);
        printf("3-Sair");
        gotoxy(07, 24);
        printf("Digite a opcao:");
        scanf("%d", &opc);
        switch (opc)
        {
        case 1:
            cadastrar(&l);
            break;
        case 2:
            Movimentacao();
            break;
        }

    } while (opc != 3);
}