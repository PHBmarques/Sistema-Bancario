/*
Autor: Pedro Henrique Bernardo Marques
Data: 04/11/2024
Equipe: RA: 173342-2024
        RA: 179427-2024
Obj: funções utilizada na movimentação
*/
#include "funcoes.h"
void insereMovimento(tipolista_movi *l, movimento mov) {
    tipoapontador_movi novo = (tipoapontador_movi)malloc(sizeof(tipoitem_movi));
    if (novo == NULL) {
        printf("Erro ao alocar memória!\n");
        return;
    }

    novo->conteudo = mov;
    novo->proximo = NULL;
    novo->anterior = NULL;

    if (l->primeiro == NULL) {
        // Lista vazia: o novo elemento será o primeiro
        l->primeiro = novo;
        l->ultimo = novo;
    } else {
        // Inserir no final da lista
        l->ultimo->proximo = novo;
        novo->anterior = l->ultimo;
        l->ultimo = novo;
    }
}