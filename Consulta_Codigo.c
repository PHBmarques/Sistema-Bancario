/*
Autor: Pedro Henrique Bernardo Marques
Data: 04/11/2024
Equipe: RA: 173342-2024
        RA: 179427-2024
Obj: Permitir a alteração dos dados já inseridos
*/
#include "funcoes.h"
void Consulta_por_Codigo(tipolista *l)
{
    tipoapontador aux2;       // Ponteiro auxiliar para encontrar a conta
    infocontas ContaBancaria; // Estrutura para armazenar temporariamente os dados da conta consultada
    int resp;                 // Variável para controlar a repetição da consulta
    do
    {
        do
        {
            tela();//exibe a tela principal
            telacadastro();//exibe o cabeçalho da tela de cadastro
            gotoxy(14, 03);
            printf("Consulta de uma Conta Expecifica pelo Codigo");
            gotoxy(7, 24);
            printf("Digite 0 para sair");
            gotoxy(52, 7);
            scanf("%d", &ContaBancaria.codigo_conta);
            // Procura a conta na lista
            aux2 = pesquisa(l, ContaBancaria.codigo_conta);
            // Verifica se a conta foi encontrada
            if (aux2 == NULL && ContaBancaria.codigo_conta != 0)
            {
                //exibe uma mensagem de erro
                gotoxy(7, 24);
                printf("Cadastro nao existe");
                getch();
            }
        } while (aux2 == NULL && ContaBancaria.codigo_conta != 0);//repete até encontrar uma conta cadastrada ou até o código for igual a 0
        //caso o código for diferente de 0 ele ira mostrar os dados da conta solicitada
        if (ContaBancaria.codigo_conta != 0)
        {
            ContaBancaria = aux2->conteudo;//carrega os dados da conta encontrada
            //exibe os detalhes da conta
            gotoxy(52, 9);
            printf("%s", aux2->conteudo.banco);
            gotoxy(52, 11);
            printf("%s", aux2->conteudo.agencia);
            gotoxy(52, 13);
            printf("%s", aux2->conteudo.numero_conta);
            gotoxy(52, 15);
            printf("%s", aux2->conteudo.tipo_conta);
            gotoxy(52, 17);
            printf("%.2lf", aux2->conteudo.vl_saldo);
            gotoxy(52, 19);
            printf("%.2lf", aux2->conteudo.vl_limite);
            gotoxy(52, 21);
            printf("%d", aux2->conteudo.status);
            //pergutna se deseja consultar outro cadastro
            gotoxy(7, 24);
            printf("Deseja consultar outro Cadastro? (1-SIM/2-NAO)");
            scanf("%d", &resp);
        }
    } while (resp == 1);//ira repetir enquanto o usuario escolher "SIM"
}