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
    // Abre ou cria um arquivo binário chamado "Contas.dat" no modo de escrita ("wb").
    // O modo "wb" apaga qualquer conteúdo anterior no arquivo.
    arq = fopen("Contas.dat", "wb");//abre ou cria um arquivo em formato binario
    // Verifica se o arquivo foi aberto com sucesso.
    if(arq==NULL){
        gotoxy(7,24);
        printf("Erro ao abrir arquivo.");
        getch();
        return;// Sai da função, pois o arquivo não pôde ser criado.
    }
    p=l->primeiro;//inicia o ponteiro no primeiro item da lista
    //percorre toda a lista 
    while(p!=NULL){
    fwrite(&p->conteudo, sizeof(infocontas), 1, arq);
    p=p->proximo;//faz com que o ponteiro percorra toda a lista
    }
    fclose(arq);//fecha o arquivo
    gotoxy(7,24);
    printf("Dados salvos com sucesso");
    getch();
}