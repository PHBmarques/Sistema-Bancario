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
    arq = fopen("Movimento.dat", "rb"); // Abre o arquivo binário para leitura
    tela(); // Chama a função para exibir a tela principal do programa
    if(arq==NULL){// Verifica se houve erro ao abrir o arquivo
        printf("Erro ao abrir ou criar arquivo");
        getch();
    }
    while (fread(&movi, sizeof(movimento), 1, arq) == 1) { // Lê cada registro
        p = (tipoapontador_movi)malloc(sizeof(tipoitem_movi));// Aloca memória para um novo nó
        if (p == NULL) {// Verifica se a alocação falhou
            gotoxy(7,24);
            printf("Erro ao alocar memória para movimentacao.\n");
            fclose(arq);
            return; // Sai da função se a alocação falhar
        }

        p->conteudo = movi; // Copia os dados lidos para o novo nó
        p->proximo = NULL;
        p->anterior = NULL;

        if (M->primeiro == NULL) { // Se a lista está vazia, o novo nó será o primeiro
            M->primeiro = p;
            M->ultimo = p;
        } else { // Caso contrário, insere o nó no final da lista
            M->ultimo->proximo = p; // O último nó aponta para o novo nó
            p->anterior = M->ultimo; // O novo nó aponta para o antigo último nó
            M->ultimo = p; // O novo nó agora é o último
        }
    }
    fclose(arq);//fecha o arquivo
    gotoxy(7,24);
    printf("Movimentacoes restauradas com sucesso !");
    getch();
}