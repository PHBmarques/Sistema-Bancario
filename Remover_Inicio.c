/*
Autor: Gustavo de Lima Sossai
Data: 08/11/2024
Equipe: RA: 173342-2024
        RA: 179427-2024
Obj:Função que permita que o usuario excluia um casdastro no inicio da lista
*/

#include "funcoes.h"

void remover_inicio(tipolista *l, tipolista_movi *M)
{
   tipoapontador p; // Ponteiro para o primeiro elemento da lista.
    int opc;         // Armazena a escolha do usuário sobre a remoção.
    p = l->primeiro; // Inicializa o ponteiro com o primeiro elemento da lista.
    tela();
    telacadastro();
    gotoxy(18, 03);
    printf("REMOCAO DE CONTAS BANCARIAS NO FINAL");
    // Exibe os dados da conta bancária a ser removida.
    gotoxy(52, 7);
    printf("%d", p->conteudo.codigo_conta);
    gotoxy(52, 9);
    printf("%s", p->conteudo.banco);
    gotoxy(52, 11);
    printf("%s", p->conteudo.agencia);
    gotoxy(52, 13);
    printf("%s", p->conteudo.numero_conta);
    gotoxy(52, 15);
    printf("%s", p->conteudo.tipo_conta);
    // Identifica o tipo de conta bancária e exibe.
    if (p->conteudo.tipo_conta[0] == '1')
    {
        gotoxy(52, 15);
        printf("Corrente");
    }
    else if (p->conteudo.tipo_conta[0] == '2')
    {
        gotoxy(52, 15);
        printf("Poupanca");
    }
    else if (p->conteudo.tipo_conta[0] == '3')
    {
        gotoxy(52, 15);
        printf("Cartao credito");
    }
    // Exibe saldo, limite e status da conta.
    gotoxy(52, 17);
    printf("%.2lf", p->conteudo.vl_saldo);
    gotoxy(52, 19);
    printf("%.2lf", p->conteudo.vl_limite);
    gotoxy(52, 21);
    printf("%d", p->conteudo.status);
    // Verifica se a conta possui movimentações financeiras associadas.
    gotoxy(7, 24);
    if (verifica_movimento(M->primeiro, p->conteudo.codigo_conta))
    {
        gotoxy(07, 24);
        printf("Nao e possivel remover a conta ela esta em movimentacao");
        getch();
        return;// Sai da função se a conta estiver em movimentação.
    }
    // Confirmação da remoção pelo usuário.
    gotoxy(7, 24);
    printf("Deseja realmente remover esse banco(1-SIM/2-NAO):");
    scanf("%d", &opc);
    if (opc == 1)
    {
        // Verifica se a lista possui apenas um cadastro
        if (l->primeiro->proximo == NULL)
        {
            // Se a lista tem apenas um cadastro irá removelo
            free(l->primeiro);
            l->primeiro = NULL;
            l->ultimo = NULL;
            gotoxy(7, 24);
            printf("                                                    ");
            gotoxy(7, 24);
            printf("Cadastro removido com sucesso");
            getch();
        }
        else
        {
            // Caso a lista tenha mais de um cadasrtro
            p = l->primeiro;          // Ponteiro aponta para o primeiro elemento.
            l->primeiro = p->proximo; // Atualiza o primeiro elemento da lista.
            free(p);                  // Libera o espaço de memória do antigo primeiro elemento.
            gotoxy(7, 24);
            printf("                                                    ");
            gotoxy(7, 24);
            printf("Cadastro removida com sucesso");
            getch();
        }
    }
}