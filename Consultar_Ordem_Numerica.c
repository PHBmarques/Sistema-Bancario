/*
Autor: Gustavo de Lima Sossai
Data: 16/11/2024
Equipe: RA: 173342-2024
        RA: 179427-2024
Obj:Função de consulta casdastro em ordem de codigo
*/

#include "funcoes.h"

void consultar_ordem_numerica(tipolista *l)
{
    tela();
    tela_consultar_ordem_numerica();
    tipoapontador p;
    infocontas ContaBancaria;
    double soma_saldo;
    double soma_limite;
    int linha = 8;
    int troca;
    tipoapontador x;
    // ordenação simples pela comparação do código da conta
    p = l->primeiro;
    while (troca) // Serve para trocar o codigo de posição(indicação)
    {
        troca = 0;       // Esta marcando que não ouve troca
        p = l->primeiro; // apontar para o primeiro codigo da lista
        while (p != NULL && p->proximo != NULL)
        {
            if (p->conteudo.codigo_conta > p->proximo->conteudo.codigo_conta)
            {
                // troca o conteudo entre p e p de proximo
                x = p->proximo;
                p->proximo = x->proximo;
                x->proximo = p;

                if (p == l->primeiro)
                {

                    l->primeiro = x; // atualiza o ponteiro para o proximo item
                }
                troca = 1; // marca que ouve troca
            }
            p = p->proximo; // move para o proximo item
        }
    }
    // exibe os dados rodenados
    p = l->primeiro;

    do

    {
        // Exibe as informações da conta na posição atual
        gotoxy(2, linha);
        printf("%d", p->conteudo.codigo_conta);
        gotoxy(6, linha);
        printf("%s", p->conteudo.banco);
        gotoxy(18, linha);
        printf("%s", p->conteudo.agencia);
        gotoxy(26, linha);
        printf("%s", p->conteudo.numero_conta);
        // Determina o tipo de conta
        gotoxy(34, linha);
        printf("%s", p->conteudo.tipo_conta);
        if (p->conteudo.tipo_conta[0] == '1')
        {
            gotoxy(34, linha);
            printf("Corrente");
        }
        else if (p->conteudo.tipo_conta[0] == '2')
        {
            gotoxy(34, linha);
            printf("Poupanca");
        }
        else if (p->conteudo.tipo_conta[0] == '3')
        {
            gotoxy(34, linha);
            printf("Cartao credito");
        }
        // Exibe saldo, limite e status
        gotoxy(50, linha);
        printf("R$ %.2lf", p->conteudo.vl_saldo);
        gotoxy(65, linha);
        printf("R$ %.2lf", p->conteudo.vl_limite);
        gotoxy(76, linha);
        printf("%d", p->conteudo.status);
        // Acumula o saldo e limite para exibição ao final
        soma_saldo += p->conteudo.vl_saldo;
        soma_limite += p->conteudo.vl_limite;
        linha++;//incrementa a linha para a proxima conta
        p = p->proximo; // avança para o proximo nó
    } while (p != NULL);// O loop continua até que não haja mais contas para exibir (quando p é NULL)
    //exibe o total de saldo e limite
    gotoxy(42,linha);
    printf("+-----------------------------------+");
    gotoxy(42, linha+1);
    printf("total:");
    gotoxy(48,linha+1);
    printf("%9.2f",soma_saldo);
    gotoxy(63,linha+1);
    printf("%9.2f",soma_limite);
    gotoxy(7, 24);
    printf("Pressione qualquer tecla para continuar...");
    getch();
}