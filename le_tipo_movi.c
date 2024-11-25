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
    static char tipo[10];// Array para armazenar o tipo de movimento.
    do{
    gotoxy(7,24);
    printf("Utilizar (1=Debito/2-Credito)"); // Exibe as opções para o usuário.
    gotoxy(33,17);
    scanf("%d",&opc);//le a opção digitada pelo usuario
    // Verifica se a opção é válida (1 ou 2)
    if(opc==1){
        strcpy(tipo, "Debito");// Se for 1, armazena "Debito" na variável tipo.
        gotoxy(33,17);
        printf("%s",tipo);
    }else if(opc==2){
        strcpy(tipo, "Credito");// Se for 2, armazena "Credito" na variável tipo.
        gotoxy(33,17);
        printf("%s",tipo);
    }else{
        gotoxy(7,24);
        printf("Digite um tipo de movimentacao valido");// Mensagem de erro para entradas inválidas.
    }
    }while(opc !=1 && opc!=2);// Repete o loop até que a entrada seja válida (1 ou 2).
    return tipo;// Retorna o tipo de movimento selecionado.
}