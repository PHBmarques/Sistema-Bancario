/*
Autor: Gustavo de Lima Sossai
Data: 16/11/2024
Equipe: RA: 173342-2024
        RA: 179427-2024
Obj:Tela de consulta casdastro em ordem de codigo
*/

#include "funcoes.h"

void tela_consultar_ordem_numerica(){
    
    gotoxy(2, 6);
    printf("Cd");

    gotoxy(6, 6);
    printf("Banco");

    gotoxy(18, 6);
    printf("Agencia");

    gotoxy(26, 6);
    printf("Conta");

    gotoxy(34, 6);
    printf("Tipo Conta");

    gotoxy(50, 6);
    printf("Saldo");

    gotoxy(65, 6);
    printf("Limite");

    gotoxy(76, 6);
    printf("St");

    gotoxy(1, 7);
    printf("+-----------------------------------------------------------------------------+");

}