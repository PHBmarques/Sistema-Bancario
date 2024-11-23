/*
Autor: Pedro Henrique Bernardo Marques
Data: 04/11/2024
Equipe: RA: 173342-2024
        RA: 179427-2024
Obj: Função que ira inserir se a movimentação é de Debito ou Credito
*/
#include "funcoes.h"
char *ler_tipo_movimento(){
    int opc;
    static char tipo[10];
    do{
    gotoxy(7,24);
    printf("Utilizar (1=Debito/2-Credito)");
    gotoxy(33,17);
    scanf("%d",&opc);
    if(opc==1){
        strcpy(tipo, "Debito");
        gotoxy(33,17);
        printf("%s",tipo);
    }else if(opc==2){
        strcpy(tipo, "Credito");
        gotoxy(33,17);
        printf("%s",tipo);
    }else{
        gotoxy(7,24);
        printf("Digite um tipo de movimentacao valido");
    }
    }while(opc !=1 && opc!=2);
    return tipo;
}