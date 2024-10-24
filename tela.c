#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<locale.h>
void gotoxy(int x, int y){
    COORD coord;
    coord.X=(short)x;
    coord.Y=(short)y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
//Função que ira criar a tela para ficar o menu e suas opções
void tela(){
    int lin;
    system("cls");
    for(lin=1;lin<26;lin++){
        gotoxy(01,lin);
        printf("|");
        gotoxy(79,lin);
        printf("|");
    }
    gotoxy(01,01);
    printf("+-----------------------------------------------------------------------------+");
    gotoxy(32,02);
    printf("SISTEMA BANCARIO");
    gotoxy(01,05);
    printf("+-----------------------------------------------------------------------------+");
    gotoxy(01,23);
    printf("+-----------------------------------------------------------------------------+");
    gotoxy(01,25);
    printf("+-----------------------------------------------------------------------------+");
    gotoxy(04,02);
    printf("UNICV");
    gotoxy(61,02);
    printf("Estrutura de dados");
    gotoxy(66,03);
    printf("ALuno.Pedro");
    gotoxy(66,04);
    printf("Aluno.Gustavo");
    gotoxy(03,24);
    printf("MSG:");
}
//tela que ira mostrar as opcoes de cadastro
void cadastro_contas(){
    int opc=0;
    do{
        tela();
        gotoxy(31,04);
        printf("Cadastro de Contas");
        gotoxy(28,10);
        printf("1-Incluir Conta");
        gotoxy(28,12);
        printf("2-Aalterar Conta");
        gotoxy(28,14);
        printf("3-Consultar Conta");
        gotoxy(28,16);
        printf("4-Remover Conta");
        gotoxy(28,18);
        printf("5-voltar");
        gotoxy(07,24);
        printf("Digite a opcao:");
        scanf("%d",&opc);
    }while(opc !=5 );
}
//tela que ira mostrar as opçoes de registrar a movimentacao da sua conta
void movimentacao(){
    int opc;
    do{
        tela();
        gotoxy(28,04);
        printf("Movimentacao Financeira");
        gotoxy(28,10);
        printf("1-Registrar entrada");
        gotoxy(28,12);
        printf("2-Registrar saida");
        gotoxy(28,14);
        printf("3-Consultar movimento");
        gotoxy(28,16);
        printf("4-voltar");
        gotoxy(07,24);
        printf("Digite a opcao:");
        scanf("%d",&opc);
    }while(opc !=4);
}
int main(){
    system("color 1F");
    int opc=0;
    do{
    tela();
    gotoxy(33,04);
    printf("MENU DE OPCOES");
    gotoxy(28,11);
    printf("1-Cadastro de Contas");
    gotoxy(28,13);
    printf("2-Movimentacao Financeira");
    gotoxy(28,15);
    printf("3-SAIR");
    gotoxy(07,24);
    printf("Digite a opcao:");
    scanf("%d",&opc);
    switch(opc){
        case 1:
        cadastro_contas();
        break;
        case 2:
        movimentacao();
        break;
    }
    }while(opc !=3);
}