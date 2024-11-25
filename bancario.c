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
// Função que movimenta o cursor na tela para a posição(x,y)
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = (short)x;// Define a posição X do cursor
    coord.Y = (short)y;// Define a posição Y do cursor
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); // Aplica a posição ao cursor
}
int main()
{
    system("color 1F");
    int opc = 0;
    tipolista l;      // Lista de contas Bancarias
    tipolista_movi M; // Lista de movimentação bancaria
    // Inicializa as listas de contas e movimentações como vazias
    M.primeiro = NULL;
    M.ultimo = NULL;
    l.primeiro = NULL;
    l.ultimo = NULL;
    // Função para ler os dados de contas bancárias do arquivo ou de entrada
    ler_dados(&l);
    // Função para ler os dados de movimentações financeiras do arquivo ou de entrada
    ler_dados_movi(&M);
    do
    {
        tela();
        gotoxy(7, 24);
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
            cadastrar(&l, &M);// Chama a função de cadastro de contas
            break;
        case 2:
            Movimentacao(&l, &M);// Chama a função de movimentação financeira
            break;
        }

    } while (opc != 3);// O laço continua até que o usuário escolha a opção 3 (Sair)
    //Funções para gravar os dados em um arquivo
    //Ira gravar os dados da minha conta bancaria em um arquivo
    gravar_dados(&l);
    //Ira gravar os dados da minha movimentação em um arquivo
    gravar_movimento(&M);
}