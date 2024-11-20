/*
Autor: Gustavo de Lima Sossai
Data: 20/11/2024
Equipe: RA: 173342-2024
        RA: 179427-2024
Obj:Tela padrão transferencias de contas
*/

#include "funcoes.h"

void tela_transferencia_contas()
{
    int lin;
    int meio_coluna = 38;
    gotoxy(15, 3);
    printf("TRANSFERENCIAS DE VALORES ENTRE CONTAS BANCARIAS");

    gotoxy(1, 7);
    printf("+------------------------------------+----------------------------------------+");

    gotoxy(8, 7);
    printf("C O N T A  O R I G E M");

    gotoxy(3, 8);
    printf("Conta de Origem: ");

    gotoxy(3, 9);
    printf("Banco..........: ");

    gotoxy(3, 10);
    printf("Agencia........: ");

    gotoxy(3, 11);
    printf("Numero da Conta: ");

    gotoxy(3, 12);
    printf("Tipo da Conta..: ");

    gotoxy(3, 13);
    printf("Saldo..........: ");

    gotoxy(3, 14);
    printf("Limite.........: ");

    gotoxy(3, 15);
    printf("Saldo + Limite.: ");

    gotoxy(3, 16);
    printf("Novo Saldo.....: ");

    gotoxy(1, 17);
    printf("+------------------------------------+----------------------------------------+");

    for (lin = 8; lin < 17; lin++)
    {
        gotoxy(meio_coluna, lin);
        printf("|");
    }

    gotoxy(47, 7);
    printf("C O N T A  D E S T I N O");

    gotoxy(40, 8);
    printf("Conta de Origem: ");

    gotoxy(40, 9);
    printf("Banco..........: ");

    gotoxy(40, 10);
    printf("Agencia........: ");

    gotoxy(40, 11);
    printf("Numero da Conta: ");

    gotoxy(40, 12);
    printf("Tipo da Conta..: ");

    gotoxy(40, 13);
    printf("Saldo..........: ");

    gotoxy(40, 14);
    printf("Limite.........: ");

    gotoxy(40, 15);
    printf("Saldo + Limite.: ");

    gotoxy(40, 16);
    printf("Novo Saldo.....: ");

    gotoxy(20, 19);
    printf("Valor a Ser Tranferido:");

    gotoxy(20, 20);
    printf("Data da Transferencia.:");
}