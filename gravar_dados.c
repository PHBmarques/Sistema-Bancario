/*
Autor: Pedro Henrique Bernardo Marques
Data: 04/11/2024
Equipe: RA: 173342-2024
        RA: 179427-2024
Obj: gravar os dados apos sair do programa
*/
#include "funcoes.h"
void gravar_dados(tipolista *l){
    FILE *arq;
    infocontas ContaBanco;
    tipoapontador p;
    arq = fopen("Contas.dat", "wb");//abre ou cria um arquivo em formato binario
    if(arq==NULL){
        printf("Erro ao abrir arquivo.");
        getch();
        return;
    }
    p=l->primeiro;//inicia o ponteiro no primeiro item da lista
    while(p!=NULL){
    fwrite(&p->conteudo, sizeof(infocontas), 1, arq);
    p=p->proximo;//faz com que o ponteiro percorra toda a lista
    }
    fclose(arq);//fecha o arquivo
    gotoxy(7,24);
    printf("Dados salvos com sucesso");
    getch();
}