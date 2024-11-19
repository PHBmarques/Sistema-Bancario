/*
Autor: Pedro Henrique Bernardo Marques
Data: 04/11/2024
Equipe: RA: 173342-2024
        RA: 179427-2024
Obj: Cadastrar uma nova movimentação bancaria
*/
#include "funcoes.h"
void cadastro_movi(tipolista*l){
    tipoapontador aux2;
    movimento movi;
    infocontas ContaBancaria;
    tipoapontador p;
    tipoapontador_movi q;
    int resp;
    int qtd;   
    int x; 
    do{
    tela();
    tela_movi();
    gotoxy(7, 24);
        do{
            printf("Digite 0 para sair");
            gotoxy(33, 7);
            scanf("%d", &ContaBancaria.codigo_conta);
            aux2 = pesquisa(l, ContaBancaria.codigo_conta);
            if (aux2 == NULL && ContaBancaria.codigo_conta != 0)
            {
                gotoxy(7, 24);
                printf("Cadastro nao existe");
                getch();
            }
        } while (aux2 == 0 && ContaBancaria.codigo_conta != 0);
        if(ContaBancaria.codigo_conta !=0){
            ContaBancaria = aux2->conteudo;
            gotoxy(33, 8);
            printf("%s", aux2->conteudo.banco);
            gotoxy(33, 9);
            printf("%s", aux2->conteudo.agencia);
            gotoxy(33, 10);
            printf("%s", aux2->conteudo.numero_conta);
            gotoxy(33, 11);
            printf("%s", aux2->conteudo.tipo_conta);
            gotoxy(33, 12);
            printf("%.2lf", aux2->conteudo.vl_saldo);
            gotoxy(33, 13);
            printf("%.2lf", aux2->conteudo.vl_limite);
            gotoxy(33, 14);
            printf("%9.2f",aux2->conteudo.vl_limite+aux2->conteudo.vl_saldo);
            getch();

        }
    }while(resp==1);
}
