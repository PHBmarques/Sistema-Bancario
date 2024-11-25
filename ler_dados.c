/*
Autor: Pedro Henrique Bernardo Marques
Data: 04/11/2024
Equipe: RA: 173342-2024
        RA: 179427-2024
Obj: Ler os dados salvo no arquivo binnario
*/
#include "funcoes.h"
void ler_dados(tipolista *l)
{
    infocontas ContaBancaria;
    tipoapontador p;
    FILE *arq;
    arq = fopen("Contas.dat", "rb"); // Abre o arquivo binário para leitura
    tela();                          // Exibe a tela principal do programa
    if (arq == NULL)
    { // Verifica se houve erro ao abrir o arquivo
        gotoxy(7, 24);
        printf("Erro ao abrir ou criar arquivo");
        getch();
    }
    while (fread(&ContaBancaria, sizeof(infocontas), 1, arq))
    {                                                // Lê cada registro de conta bancária
        p = (tipoapontador)malloc(sizeof(tipoitem)); // Aloca memória para um novo nó
        p->conteudo = ContaBancaria;                 // Copia os dados lidos para o nó
        p->proximo = NULL;                           // O próximo nó será NULL inicialmente
        if (l->primeiro == NULL)
        { // Se a lista está vazia, o novo nó será o primeiro
            l->primeiro = p;
            l->ultimo = p;
        }
        else
        {                           // Caso contrário, insere o nó no final da lista
            l->ultimo->proximo = p; // O último nó aponta para o novo nó
            l->ultimo = p;          // O novo nó agora é o último
        }
    }
    fclose(arq); // fecha o arquivo
    gotoxy(7, 24);
    printf("Contas bancarias restauradas com sucesso!");
    getch();
}