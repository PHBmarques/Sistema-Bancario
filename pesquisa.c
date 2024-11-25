/*
Autor: Pedro Henrique Bernardo Marques
Data: 04/11/2024
Equipe: RA: 173342-2024
        RA: 179427-2024
Obj: Funcao que ira permitir o código percorrer a lista 
*/
#include "funcoes.h"
tipoapontador pesquisa(tipolista *L, int cod){
    tipoapontador aux;// Variável auxiliar para percorrer a lista.
     aux = L->primeiro;// Inicializa com o primeiro elemento da lista.
    // Percorre a lista até o final (aux == NULL) ou até encontrar a conta desejada.
    while (aux != NULL){
        // Verifica se o código da conta atual é igual ao código pesquisado.
        if (aux->conteudo.codigo_conta==cod){
            return aux;// Retorna o ponteiro para o nó encontrado.
        }
        aux = aux ->proximo;// Avança para o próximo elemento da lista.
     }
     // Retorna NULL se não encontrar nenhuma conta com o código fornecido.
    return NULL;
}