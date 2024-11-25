/*
Autor: Pedro Henrique Bernardo Marques
Data: 04/11/2024
Equipe: RA: 173342-2024
        RA: 179427-2024
Obj: Menus de cadastro Bancario e Moviemntacao de Contas
*/
#include "funcoes.h"
//Menu de Cadastro de Contas
void cadastrar(tipolista *l,tipolista_movi *M)
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
            casdastrar_posicao(l);
            break;
        case 4:
            remover_final(l,M);
            break;
        case 5:
            remover_inicio(l,M);
            break;
        case 6:
            remover_posicao(l,M);
            break;
        case 7:
            alterar_conta_bancaria(l);
            break;
        case 8:
            opcoes_de_consultar(l);
            break;
        }
    } while (opc != 9);
}
//Menu de movimentacao financeira
void Movimentacao(tipolista *l,tipolista_movi *M){
    int opc = 0;
    do
    {
        tela();
        gotoxy(24, 03);
        printf("MOVIMENTACAO FINANCEIRA");
        gotoxy(30, 10);
        printf("1-Movimentacao de Debito e Credito");
        gotoxy(30, 12);
        printf("2-Transferencia entre contas Bancarias");
        gotoxy(30, 14);
        printf("3-Consultar de Movimentacao");
        gotoxy(30, 16);
        printf("4-Voltar");
        gotoxy(7, 24);
        printf("Digite a opcao: ");
        scanf("%d", &opc);
        switch(opc){
            case 1:
            cadastro_movi(l, M);
            break;
            case 2:
            Trans_Conta(l, M);
            break;
            case 3:
            consultar_mov(l, M);
            break;
        }
    } while (opc != 4);
}