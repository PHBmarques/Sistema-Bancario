/*
Autor: Pedro Henrique Bernardo Marques
Data: 04/11/2024
Equipe: RA: 173342-2024
        RA: 179427-2024
Obj: Função que ira inserir se a movimentação é de Debito ou Credito
*/
#include "funcoes.h"
char *ler_movi_favorecido(){
   static char favo[50];
    gotoxy(7,24);
    printf("                                          ");
    gotoxy(33,18);
    scanf("%s",&favo);
    return favo;
}