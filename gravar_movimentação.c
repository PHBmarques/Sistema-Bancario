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
    // Abre ou cria um arquivo binário chamado "Movimento.dat" no modo de escrita ("wb").
    // O modo "wb" substitui o conteúdo existente no arquivo.
    arq = fopen("Movimento.dat", "wb"); // Abre/cria o arquivo binário
    if (arq == NULL) {
        gotoxy(7,24);
        printf("Erro ao abrir arquivo de movimentacoes.\n");
        getch();
        return;// Retorna da função, pois não foi possível abrir o arquivo.
    }

    p = M->primeiro; // Começa pelo primeiro nó da lista
    //Percorre toda a lista encadeada
    while (p != NULL) {
        fwrite(&p->conteudo, sizeof(movimento), 1, arq); // Escreve o conteúdo do nó
        p = p->proximo; // Move para o próximo nó
    }

    fclose(arq); // Fecha o arquivo
    //exibe uma mensagem de que o  movimentação foi salva com sucesso
    gotoxy(7, 24);
    printf("Movimentacoes salvas com sucesso.\n");
    getch();
}

