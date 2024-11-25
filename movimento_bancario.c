/*
Autor: Pedro Henrique Bernardo Marques
Data: 04/11/2024
Equipe: RA: 173342-2024
        RA: 179427-2024
Obj: Cadastrar uma nova movimentação bancaria
*/
#include "funcoes.h"
void cadastro_movi(tipolista *l, tipolista_movi *M)
{
    tipoapontador aux2;             // Ponteiro auxiliar para encontrar a conta bancária
    movimento movi;                 // Estrutura para armazenar informações da movimentação
    infocontas ContaBancaria;       // Estrutura para armazenar informações da conta bancária
    tipoapontador p;                // Ponteiro para navegação na lista de contas
    tipoapontador_movi q;           // Ponteiro para criação de nova movimentação
    int resp;                       // Variável para armazenar resposta do usuário
    do
    {
        tela();//função que chama a tela principal
        tela_movi(); // Função para configurar a tela específica de movimentação
        gotoxy(20,03);
        printf("CADASTRAR MOVIMENTACOES BANCARIAS");
        //verifica se a lista esta vazia caso ela esteja vazia o contador sera igual a 1
        if (M->primeiro == NULL)
        {
            movi.sequencial = 1;
        }
        //Agora caso a lista não esteja vazia ela ira somar +1 na sequencia de movimentação da conta
        else
        {
            movi.sequencial = M->ultimo->conteudo.sequencial + 1;
        }
        gotoxy(33, 6);
        printf("%d", movi.sequencial);
        // Loop para verificar e solicitar código da conta bancária
        do
        {
            gotoxy(7, 24);
            printf("Digite 0 para sair");
            gotoxy(33, 7);
            scanf("%d", &ContaBancaria.codigo_conta);
            // Pesquisa na lista de contas pelo código fornecido
            aux2 = pesquisa(l, ContaBancaria.codigo_conta);
            // Exibe erro se a conta não existir
            if (aux2 == NULL && ContaBancaria.codigo_conta != 0)
            {
                gotoxy(7, 24);
                printf("Cadastro nao existe");
                getch();
            }
        } while (aux2 == 0 && ContaBancaria.codigo_conta != 0);
        // Caso o código fornecido não seja 0 (sair), processa a conta bancária
        if (ContaBancaria.codigo_conta != 0)
        {
            ContaBancaria = aux2->conteudo;// Obtém os dados da conta bancária
            gotoxy(33, 8);
            printf("%s", ContaBancaria.banco);
            gotoxy(33, 9);
            printf("%s", ContaBancaria.agencia);
            gotoxy(33, 10);
            printf("%s", ContaBancaria.numero_conta);
            gotoxy(33, 11);
            printf("%s", ContaBancaria.tipo_conta);
            gotoxy(33, 12);
            printf("%.2lf", ContaBancaria.vl_saldo);
            gotoxy(33, 13);
            printf("%.2lf", ContaBancaria.vl_limite);
            gotoxy(32, 14);
            printf("%9.2f", ContaBancaria.vl_limite + ContaBancaria.vl_saldo);
            getch();
            // Cadastrar Movimentação Bancaria
            movi.codigo_conta = ContaBancaria.codigo_conta;
            strcpy(movi.dt_movimento, lerData(movi.codigo_conta,33,16));// Lê a data da movimentação
            strcpy(movi.to_movimento, ler_tipo_movimento()); // Lê o tipo de movimentação
            strcpy(movi.ds_favorecido, ler_movi_favorecido());// Lê o favorecido da movimentação
            movi.vl_movimento = ler_valor(ContaBancaria.vl_saldo, ContaBancaria.vl_limite);// Lê o valor da movimentação

            // Atualiza o saldo dependendo do tipo de movimentação (débito ou crédito)
            if (strcmp(movi.to_movimento, "Debito") == 0)
            {
                movi.vl_saldo = ContaBancaria.vl_saldo - movi.vl_movimento;
                movi.vl_saldo = ContaBancaria.vl_saldo - movi.vl_movimento;
            }
            else if (strcmp(movi.to_movimento, "Credito") == 0)
            {
                movi.vl_saldo = ContaBancaria.vl_saldo + movi.vl_movimento;
                movi.vl_saldo = ContaBancaria.vl_saldo + movi.vl_movimento;
            }
            gotoxy(33, 20);
            printf("%9.2lf", movi.vl_saldo);// Exibe o saldo atualizado
            // Pergunta se o usuário deseja gravar a movimentação
            gotoxy(7, 24);
            printf("Deseja gravar a movimentacao(1-SIM/2-NAO):");
            scanf("%d", &resp);
            if (resp == 1)
            {
                aux2->conteudo.vl_saldo=movi.vl_saldo;// Atualiza o saldo na conta bancária
                q = (tipoapontador_movi)malloc(sizeof(tipoitem_movi));// Criação de um novo nó para a movimentação
                q->conteudo = movi;
                q->proximo = NULL;
                q->anterior = NULL;
                // Adiciona a movimentação na lista de movimentações
                if (M->primeiro == NULL)// Caso a lista esteja vazia
                {
                    M->primeiro = q;
                    M->ultimo = q;
                }
                else
                {
                    M->ultimo->proximo = q;// Adiciona ao final da lista
                    q->anterior = M->ultimo;
                    M->ultimo = q;
                }
                gotoxy(07, 24);
                printf("Movimentacao cadastrada com sucesso             ");
                getch();
            }
        }
        // Pergunta se o usuário deseja cadastrar outro movimento
        gotoxy(07, 24);
        printf("Gostaria de cadastrar um novo movimento(1-SIM/2-NAO):");
        scanf("%d", &resp);
    } while (resp == 1);// Repete o processo caso o usuário deseje continuar
}
