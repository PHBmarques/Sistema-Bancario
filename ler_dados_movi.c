/*
Autor: Pedro Henrique Bernardo Marques
Data: 04/11/2024
Equipe: RA: 173342-2024
        RA: 179427-2024
Obj: A função ira gravar ler os dados da minha movimentação bancaria
*/
#include "funcoes.h"
void ler_dados_movi(tipolista_movi *M){
    movimento movi;
    tipoapontador_movi p;
    FILE *arq;
    arq=fopen("Movimento.dat","rb");
    if(arq==NULL){
        printf("Erro ao abrir ou criar arquivo");
        getch();
    }
    while (fread(&movi, sizeof(movimento), 1, arq) == 1) { // Lê cada registro
        p = (tipoapontador_movi)malloc(sizeof(tipoitem_movi));
        if (p == NULL) {
            printf("Erro ao alocar memória para movimentação.\n");
            fclose(arq);
            return;
        }

        p->conteudo = movi; // Copia os dados lidos para o novo nó
        p->proximo = NULL;
        p->anterior = NULL;

        if (M->primeiro == NULL) {
            M->primeiro = p;
            M->ultimo = p;
        } else {
            M->ultimo->proximo = p;
            p->anterior = M->ultimo;
            M->ultimo = p;
        }
    }
    fclose(arq);//fecha o arquivo
    gotoxy(7,24);
    printf("Contas bancarias restauradas com sucesso!");
    getch();
}