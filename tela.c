/*
Autor: Pedro Henrique Bernardo Marques
Data: 04/11/2024
Equipe: RA: 173342-2024
        RA: 179427-2024
Obj: tela principal e tela para inserir as infromacoes do cadastro
*/
#include "funcoes.h"
// Funcao que ira gerar a tela principal do programa
void tela()
{
    int lin;
    system("cls");
    for (lin = 1; lin < 26; lin++)
    {
        gotoxy(01, lin);
        printf("|");
        gotoxy(79, lin);
        printf("|");
    }
    gotoxy(01, 01);
    printf("+-----------------------------------------------------------------------------+");
    gotoxy(18, 02);
    printf("SISTEMA DE FOLHA DE CONTROLE BANCARIO");
    gotoxy(01, 05);
    printf("+-----------------------------------------------------------------------------+");
    gotoxy(01, 23);
    printf("+-----------------------------------------------------------------------------+");
    gotoxy(01, 25);
    printf("+-----------------------------------------------------------------------------+");
    gotoxy(04, 02);
    printf("UNICV");
    gotoxy(60, 02);
    printf("Estrutura de dados");
    gotoxy(65, 03);
    printf("Pedro");
    gotoxy(65, 04);
    printf("Gustavo");
    gotoxy(02, 24);
    printf("MSG:  ");
}
// Funcao que ira criar a tela para inserir as informações do cadastro
void telacadastro()
{
    gotoxy(05, 7);
    printf("Codigo da Conta...............................:");
    gotoxy(05, 9);
    printf("1-Banco.......................................:");
    gotoxy(05, 11);
    printf("2-Agencia.....................................:");
    gotoxy(05, 13);
    printf("3-Numero da Conta.............................:");
    gotoxy(05, 15);
    printf("4-Tipo da Conta(Corrente, Poupanca ou Credito):");
    gotoxy(5, 17);
    printf("5-Saldo.......................................:");
    gotoxy(5, 19);
    printf("6-Limite Permitido............................:");
    gotoxy(5, 21);
    printf("  Status da Conta.............................:");
}