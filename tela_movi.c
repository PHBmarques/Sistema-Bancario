/*
Autor: Pedro Henrique Bernardo Marques
Data: 04/11/2024
Equipe: RA: 173342-2024
        RA: 179427-2024
Obj: tela da movimentação bancaria
*/
#include "funcoes.h"
void tela_movi(){
    gotoxy(10,6);
    printf("Sequencia Movimentacao:");
    gotoxy(10,7);
    printf("Codigo conta..........:");
    gotoxy(10,8);
    printf("Agencia...............:");
    gotoxy(10,9);
    printf("Numero da Conta.......:");
    gotoxy(10,10);
    printf("Tipo da Conta.........:");
    gotoxy(10,11);
    printf("Saldo.................:");
    gotoxy(10,12);
    printf("Limite................:");
    gotoxy(10,13);
    printf("Total Saldo + Limite..:");
    gotoxy(2,14);
    printf("------------------------------------------------------------------------");
}