/*
Autor: Pedro Henrique Bernardo Marques
Data: 04/11/2024
Equipe: RA: 173342-2024
        RA: 179427-2024
Obj: Função que ira ler o valor da movimentação
*/
#include "funcoes.h"

double ler_valor(double saldo, double limite)
{
    double valor_solicitado;
    double max_disponivel = saldo + limite; // Soma do saldo e limite disponíveis.

    while (1)
    { // Loop até que o usuário insira um valor válido.
        gotoxy(33, 19);
        scanf("%lf", &valor_solicitado); // Lê o valor solicitado.

        // Verifica se o valor solicitado é válido.
        if (valor_solicitado > 0 && valor_solicitado <= max_disponivel)
        {
            break; // Valor válido, sai do loop.
        }
        else
        {
            gotoxy(7, 24);
            printf("Valor invalido! Insira um valor positivo e dentro do limite.");
        }
    }

    return valor_solicitado; // Retorna o valor solicitado.
}
