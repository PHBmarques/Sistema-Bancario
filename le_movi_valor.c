/*
Autor: Pedro Henrique Bernardo Marques
Data: 04/11/2024
Equipe: RA: 173342-2024
        RA: 179427-2024
Obj: Função que ira ler o valor da movimentação
*/
#include "funcoes.h"
double ler_valor(double saldo, double limite){
    double soma;
    double valor_solicitado;
    soma=saldo + limite;
    do{
        gotoxy(7,24);
        printf("                                      ");
        gotoxy(7,24);
        printf("Digite o valor solicitado");
        gotoxy(33,19);
        scanf("%lf",&valor_solicitado);
        if(valor_solicitado>soma){
            gotoxy(7,24);
            printf("Valor invalido ou saldo insuficiente");
            getch();
            gotoxy(33,19);
            printf("                   ");
        }
    }while(valor_solicitado>soma);
    return valor_solicitado;
}