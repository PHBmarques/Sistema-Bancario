/*
Autor: Pedro Henrique BErnardo Marques
Data: 04/11/2024
Equipe: RA: 173342-2024
        RA: 179427-2024
Obj: Ser nosso programa principal
*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>
#include "funcoes.h"
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = (short)x;
    coord.Y = (short)y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
int main()
{
    system("color 1F");
    int opc = 0;
    tipolista l;
    tipolista_movi M;
    l.primeiro = NULL;
    l.ultimo = NULL;
    do
    {
        tela();
        ler_dados(&l);
        gotoxy(7,24);
        printf("                                            ");
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
            Movimentacao(&l);
            break;
        }

    } while (opc != 3);
    gravar_dados(&l);
}