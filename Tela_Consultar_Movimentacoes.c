/*
Autor: Gustavo de Lima Sossai
Data: 20/11/2024
Equipe: RA: 173342-2024
        RA: 179427-2024
Obj:Tela padrão de consultar transferencias de contas
*/

#include "funcoes.h"

void tala_consultar()
{
    gotoxy(20, 3);
    printf("LISTA DE MOVIMENTACOES BANCARIAS");

    gotoxy(2, 6);
    printf("Codigo:");

    gotoxy(1, 7);
    printf("+-----------------------------------------------------------------------------+");

    gotoxy(2, 8);
    printf("Dt.Movim");

    gotoxy(13, 8);
    printf("Favorecido");

    gotoxy(40, 8);
    printf("TpMovim");

    gotoxy(55, 8);
    printf("Vl.Movim");

    gotoxy(70, 8);
    printf("Saldo");

    gotoxy(1, 9);
    printf("+-----------------------------------------------------------------------------+");
}