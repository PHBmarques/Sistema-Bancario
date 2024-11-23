/*
Autor: Gustavo de Lima Sossai
Data: 16/11/2024
Equipe: RA: 173342-2024
        RA: 179427-2024
Obj:Função para efetuar a soma de Saldo e Limite de todas as contas bancarias para tela de consultar contas
*/

#include "funcoes.h"

void soma_contas_bancarias(tipolista *l)
{   
    tipoapontador p = l->primeiro;
    double soma_saldos = 0;
    double soma_limites = 0;

    // Percorre toda a lista enquanto o ponteiro 'p' não for NULL (enquanto houver elementos na lista)
    while (p != NULL)
    {
        soma_saldos += p->conteudo.vl_saldo;
        soma_limites += p->conteudo.vl_limite;
        p = p->proximo;
    }

}
