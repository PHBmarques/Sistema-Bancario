/*
Autor: Gustavo de Lima Sossai
Data: 24/11/2024
Equipe: RA: 173342-2024
        RA: 179427-2024
Obj:Transferencia entre contas de movimento
*/

#include "Funcoes.h"

void Trans_Conta(tipolista *l, tipolista_movi *M)
{
    // Declaração das variáveis
    int codigo;           // Código da conta de origem
    int codigo2;          // Código da conta de destino
    int teste;            // Variável auxiliar (não utilizada)
    int resp;             // Resposta para confirmação
    movimento movi;       // Estrutura para movimentação de conta
    infocontas ContaBancaria; // Estrutura para informações de contas bancárias
    tipoapontador aux;    // Apontador para a conta de origem
    tipoapontador aux2;   // Apontador para a conta de destino
    movimento conta;      // Movimentação da conta de origem
    movimento conta2;     // Movimentação da conta de destino
    tipoapontador_movi q; // Apontador para movimentações no histórico
    double soma1 = 0;     // Variável para saldo atualizado da conta de origem
    double soma2 = 0;     // Variável para saldo atualizado da conta de destino
    // Loop principal que permite múltiplas transferências
    do
    {
        tela();
        tela_transferencia_contas();// Exibe a tela de transferência de contas
        // Solicita o código da conta de origem
        do
        {
            gotoxy(7, 24);
            printf("Digite 0 para sair");
            gotoxy(19, 8);
            scanf("%d", &ContaBancaria.codigo_conta);
            aux = pesquisa(l, ContaBancaria.codigo_conta);// Pesquisa a conta
            if (aux == NULL && ContaBancaria.codigo_conta != 0)
            {
                gotoxy(7, 24);
                printf("Cadastro nao existe");// Exibe erro caso a conta não exista
                getch();
            }
        } while (aux == 0 && ContaBancaria.codigo_conta != 0);// Repete até encontrar uma conta válida
        // Exibe os dados da conta de origem
        gotoxy(19, 9);
        printf("%s", aux->conteudo.banco);
        gotoxy(19, 10);
        printf("%s", aux->conteudo.agencia);
        gotoxy(19, 11);
        printf("%s", aux->conteudo.numero_conta);
        gotoxy(19, 12);
        printf("%s", aux->conteudo.tipo_conta);
        // Verificação para tipo de conta inserida
        if (aux->conteudo.tipo_conta[0] == '1')
        {
            gotoxy(19, 12);
            printf("Corrente");
        }
        else if (aux->conteudo.tipo_conta[0] == '2')
        {
            gotoxy(19, 12);
            printf("Poupanca");
        }
        else if (aux->conteudo.tipo_conta[0] == '3')
        {
            gotoxy(19, 12);
            printf("Cartao credito");
        }
        // Exibe os saldos das contas de origem
        gotoxy(19, 13);
        printf("%.2lf", aux->conteudo.vl_saldo);
        gotoxy(19, 14);
        printf("%.2lf", aux->conteudo.vl_limite);
        gotoxy(19, 15);
        printf("%.2lf", aux->conteudo.vl_saldo + aux->conteudo.vl_limite);
        // Solicita o código da conta de destino
        do
        {
            gotoxy(7, 24);
            printf("Digite 0 para sair");
            gotoxy(56, 8);
            scanf("%d", &ContaBancaria.codigo_conta);
            aux2 = pesquisa(l, ContaBancaria.codigo_conta);// Pesquisa a conta de destino
            if (aux2 == NULL && ContaBancaria.codigo_conta != 0)
            {
                gotoxy(7, 24);
                printf("Cadastro nao existe");// Exibe erro caso a conta não exista
                getch();
            }
        } while (aux2 == 0 && ContaBancaria.codigo_conta != 0);// Repete até encontrar uma conta válida
        // Verifica se a conta de destino está inativa ou inexistente
        do
        {
            if (aux2 == NULL)
            {
                gotoxy(7, 24);
                printf("Conta nao encontrada ou inexistente");// Mensagem de erro
                getch();
            }
            else if (aux2->conteudo.status == 0)
            {
                gotoxy(7, 24);
                printf("Conta inativa");// Mensagem se a conta estiver inativa
                getch();
            }
        } while (aux2 == NULL || aux2->conteudo.status == 0);// Continua até encontrar uma conta ativa

        gotoxy(56, 9);
        printf("%s", aux2->conteudo.banco);
        gotoxy(56, 10);
        printf("%s", aux2->conteudo.agencia);
        gotoxy(56, 11);
        printf("%s", aux2->conteudo.numero_conta);
        gotoxy(56, 12);
        printf("%s", aux2->conteudo.tipo_conta);
        // Verificação para tipo de conta inserida
        if (aux2->conteudo.tipo_conta[0] == '1')
        {
            gotoxy(56, 12);
            printf("Corrente");
        }
        else if (aux2->conteudo.tipo_conta[0] == '2')
        {
            gotoxy(56, 12);
            printf("Poupanca");
        }
        else if (aux2->conteudo.tipo_conta[0] == '3')
        {
            gotoxy(56, 12);
            printf("Cartao credito");
        }
        // Exibe os saldos das contas de origem
        gotoxy(56, 13);
        printf("%.2lf", aux2->conteudo.vl_saldo);
        gotoxy(56, 14);
        printf("%.2lf", aux2->conteudo.vl_limite);
        gotoxy(56, 15);
        printf("%.2lf", aux2->conteudo.vl_saldo + aux2->conteudo.vl_limite);
        gotoxy(7, 24);
        printf("Digite o valor a ser transferido");
        do{
        gotoxy(44, 19);
        scanf("%lf", &conta.vl_movimento);
       // Verifica se o valor da movimentação é válido
        if(conta.vl_movimento<0 || conta.vl_movimento>=(aux->conteudo.vl_saldo+aux->conteudo.vl_limite)){
            gotoxy(7,24);
            printf("Valor invalido! Insira um valor positivo e dentro do limite.");
            getch();
            gotoxy(44,19);
            printf("                      ");
        }
        }while(conta.vl_movimento<0 || conta.vl_movimento>=(aux->conteudo.vl_saldo+aux->conteudo.vl_limite));// Repete até o valor ser válido
        gotoxy(7,24);
        printf("                                                                     ");
        while (getchar() != '\n');// Limpa o buffer de entrada
        strcpy(conta.dt_movimento, lerData(conta2.codigo_conta, 44, 20));// Obtém a data da movimentação
         // Calcula os novos saldos após a transferência
        soma1 = aux->conteudo.vl_saldo - conta.vl_movimento;
        soma2 = aux2->conteudo.vl_saldo  + conta.vl_movimento;
        // Exibe os saldos atualizados das contas
        gotoxy(19, 16);
        printf("%.2lf", soma1);

        gotoxy(56, 16);
        printf("%.2lf", soma2);
        // Solicita confirmação para realizar a transferência
        gotoxy(7, 24);
        printf("Confitmar gravacao da movimentacao(1=SIM/2=NAO):");
        scanf("%d", &resp);
        if (resp == 1)
        {
            // Atualiza os saldos das contas
            aux->conteudo.vl_saldo = soma1;
            aux2->conteudo.vl_saldo = soma2;
            // Cria a movimentação de débito na conta de origem
            movi.codigo_conta = aux->conteudo.codigo_conta;
            strcpy(movi.dt_movimento, conta.dt_movimento);
            strcpy(movi.ds_favorecido, aux2->conteudo.numero_conta);
            strcpy(movi.to_movimento, "Debito");
            movi.vl_movimento = conta.vl_movimento;
            movi.vl_saldo = soma1;
            // Registra a movimentação no histórico
            q = (tipoapontador_movi)malloc(sizeof(tipoitem_movi));
            q->conteudo = movi;
            q->proximo = NULL;
            q->anterior = NULL;
            // adição no final
            if (M->primeiro == NULL)
            {
                M->primeiro = q;
                M->ultimo = q;
            }
            else
            {
                M->ultimo->proximo = q;
                q->anterior = M->ultimo;
                M->ultimo = q;
            }
            // Cria a movimentação de crédito na conta de destino
            movi.codigo_conta = aux2->conteudo.codigo_conta;
            strcpy(movi.dt_movimento, conta.dt_movimento);
            strcpy(movi.ds_favorecido, aux->conteudo.numero_conta);
            strcpy(movi.to_movimento, "Credito");
            movi.vl_movimento = conta.vl_movimento;
            movi.vl_saldo = soma2;
            // Registra a movimentação no histórico
            q = (tipoapontador_movi)malloc(sizeof(tipoitem_movi));
            q->conteudo = movi;
            q->proximo = NULL;
            q->anterior = NULL;
            // adição no final
            if (M->primeiro == NULL)
            {
                M->primeiro = q;
                M->ultimo = q;
            }
            else
            {
                M->ultimo->proximo = q;
                q->anterior = M->ultimo;
                M->ultimo = q;
            }
            gotoxy(8, 24);
            printf("Transferencia realizada com sucesso para a conta");
            getch();
        }
        gotoxy(7, 24);
        printf("Gostaria de cadastrar outra movimentacao (1=SIM/2=NAO)");
        scanf("%d", &resp);
    } while (resp == 1);// Continua até a resposta ser 'Não'
}