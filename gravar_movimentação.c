/*
Autor: Pedro Henrique Bernardo Marques
Data: 04/11/2024
Equipe: RA: 173342-2024
        RA: 179427-2024
Obj: A função ira gravar os dados da movimentação
*/
#include "funcoes.h"
void gravar_movimento(tipolista_movi *M) {
    FILE *arq;
    tipoapontador_movi p;

    arq = fopen("Movimento.dat", "wb"); // Abre/cria o arquivo binário
    if (arq == NULL) {
        printf("Erro ao abrir arquivo de movimentações.\n");
        getch();
        return;
    }

    p = M->primeiro; // Começa pelo primeiro nó da lista
    while (p != NULL) {
        fwrite(&p->conteudo, sizeof(movimento), 1, arq); // Escreve o conteúdo do nó
        p = p->proximo; // Move para o próximo nó
    }

    fclose(arq); // Fecha o arquivo
    gotoxy(7, 24);
    printf("Movimentações salvas com sucesso.\n");
    getch();
}

