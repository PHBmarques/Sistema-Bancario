/*
Autor: Pedro Henrique Bernardo Marques
Data: 04/11/2024
Equipe: RA: 173342-2024
        RA: 179427-2024
Obj: Cadastrar os dados no incio
*/
#include "funcoes.h"
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
            gotoxy(18, 03);
            printf("Cadastro de Contas Bancarias-No Inicio");
            gotoxy(7, 24);
            printf("Digite 0 para sair");
            gotoxy(52, 7);
            scanf("%d", &ContaBancaria.codigo_conta);
            // limpa o buffer apos o uso do scanf
            while (getchar() != '\n');
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
            gotoxy(52, 9);
            fflush(stdin);
            fgets(ContaBancaria.banco, 50, stdin);
            gotoxy(52, 11);
            fflush(stdin);
            fgets(ContaBancaria.agencia, 10, stdin);
            gotoxy(52, 13);
            fflush(stdin);
            fgets(ContaBancaria.numero_conta, 20, stdin);
            do
            {
                gotoxy(07, 24);
                printf("Utilizar: 1=Corrente/2=Poupanca/3=Cartao Credito");
                gotoxy(52, 15);
                fflush(stdin);
                fgets(ContaBancaria.tipo_conta, 20, stdin);
                if (ContaBancaria.tipo_conta[0] == '1')
                {
                    gotoxy(53, 15);
                    printf("-Corrente");
                }
                else if (ContaBancaria.tipo_conta[0] == '2')
                {
                    gotoxy(53, 15);
                    printf("-Poupanca");
                }
                else if (ContaBancaria.tipo_conta[0] == '3')
                {
                    gotoxy(53, 15);
                    printf("-Cartao Credito");
                }
                else
                {
                    gotoxy(7, 24);
                    printf("                                            ");
                    gotoxy(7, 24);
                    printf("Tipo de Conta invalido");
                    getch();
                    gotoxy(52, 15);
                    printf("  ");
                }
            } while (ContaBancaria.tipo_conta[0] != '1' && ContaBancaria.tipo_conta[0] != '2' && ContaBancaria.tipo_conta[0] != '3');
            gotoxy(7, 24);
            printf("                                                        ");
            gotoxy(52, 17);
            scanf("%lf", &ContaBancaria.vl_saldo);
            gotoxy(52, 19);
            scanf("%lf", &ContaBancaria.vl_limite);
            gotoxy(52, 21);
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
            printf("Deseja cadastrar uma nova conta Bancaria (1=SIM / 2=NAO)? ");
            scanf("%d", &resp);
        }
    } while (resp == 1);
}