/*Autor:Pedro Henrique Bernardo Marques
  Data:23/10/2024
  Objetivo:Sistema de contole Bancario*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = (short)x;
    coord.Y = (short)y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void tela(){
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
    gotoxy(66, 03);
    printf("Aluno.Pedro");
    gotoxy(66,04);
    printf("Aluno.Gustavo");
    gotoxy(02, 24);
    printf("MSG: ");
}
void cadastrar(){
    int opc=0;
    do{
        gotoxy(27,03);
        printf("CADASTRO DE CONTAS");
        gotoxy(25,10);
        printf("1-Incluir Conta");
        gotoxy(25,12);
        printf("2-Alterar Conta");
        gotoxy(25,14);
        printf("3-Consultar Conta");
        gotoxy(25,16);
        printf("4-Remover Conta");
        gotoxy(25,18);
        printf("5-Voltar");
        gotoxy(07,24);
        printf("Digite a opcao:");
        scanf("%d",&opc);
    }while(opc != 5);
}
void Movimentacao(){
    int opc=0;
    do{
        gotoxy(24,03);
        printf("MOVIMENTACAO FINANCEIRA");
        gotoxy(25,10);
        printf("1-Registrar Entrada");
        gotoxy(25,12);
        printf("2-Registrar Saida");
        gotoxy(25,14);
        printf("3-Consultar Movimentacao");
        gotoxy(25,16);
        printf("4-Voltar");
        gotoxy(7,24);
        printf("Digite a opcao:");
        scanf("%d",&opc);
    }while(opc != 4);
}
int main(){
    system("color 1F");
    int opc=0;
    do{
        tela();
        gotoxy(28, 03);
        printf("MENU PRINCIPAL");
        gotoxy(25,12);
        printf("1-Cadastro de Contas");
        gotoxy(25,14);
        printf("2-Movimentacao Financeira");
        gotoxy(25,16);
        printf("3-Sair");
        gotoxy(07,24);
        printf("Digite a opcao:");
        scanf("%d",&opc);
        switch(opc){
            case 1:
            cadastrar();
            break;
            case 2:
            Movimentacao();
            break;
        }
    }while(opc!=3);
}
