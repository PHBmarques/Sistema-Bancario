/*
Autor: Pedro Henrique Bernardo Marques
Data: 04/11/2024
Equipe: RA: 173342-2024
        RA: 179427-2024
Obj: Verifica se o código solicitado esta em uma movimentação ou não
*/
#include "funcoes.h"
int verifica_movimento(tipoapontador_movi M, int cod){
    tipoapontador_movi temp=M; // Inicializa o ponteiro 'temp' para percorrer a lista de movimentações
    // Percorre toda a lista de movimentações
    while(temp !=NULL){
        // Verifica se o código da conta na movimentação atual é igual ao 'cod' fornecido
        if (temp->conteudo.codigo_conta== cod){
            return 1;//encontrou movimento para a conta
        }
        // Avança para o próximo nó na lista de movimentações
        temp=temp->proximo;
    }
    // Caso não tenha encontrado nenhuma movimentação para a conta
    return 0;//Nenjuma movimentação encontrada
}