/*
Autor: Pedro Henrique Bernardo Marques
Data: 04/11/2024
Equipe: RA: 173342-2024
        RA: 179427-2024
Obj: Ler os dados salvo no arquivo binnario
*/
#include "funcoes.h"
void ler_dados(tipolista *l){
    infocontas ContaBancaria;
    tipoapontador p;
    FILE *arq;
    arq=fopen("Contas.dat","rb");
    if(arq==NULL){
        printf("Erro ao abrir ou criar arquivo");
        getch();
    }
    while(fread(&ContaBancaria, sizeof(infocontas),1,arq)){
        p=(tipoapontador)malloc(sizeof(tipoitem));
        p->conteudo=ContaBancaria;
        p->proximo=NULL;
        if(l->primeiro==NULL){
            l->primeiro=p;
            l->ultimo=p;
        }else{
            l->ultimo->proximo=p;
            l->ultimo=p;
        }
    }
    fclose(arq);//fecha o arquivo
    gotoxy(7,24);
    printf("Contas bancarias restauradas com sucesso!");
    getch();
}