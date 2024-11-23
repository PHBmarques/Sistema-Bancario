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
    tipoapontador aux2;
    movimento movi;
    infocontas ContaBancaria;
    tipoapontador p;
    tipoapontador_movi q;
    int resp;
    int qtd;
    int x;
    do
    {
        tela();
        tela_movi();
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
        gotoxy(7, 24);
        do
        {
            printf("Digite 0 para sair");
            gotoxy(33, 7);
            scanf("%d", &ContaBancaria.codigo_conta);
            aux2 = pesquisa(l, ContaBancaria.codigo_conta);
            if (aux2 == NULL && ContaBancaria.codigo_conta != 0)
            {
                gotoxy(7, 24);
                printf("Cadastro nao existe");
                getch();
            }
        } while (aux2 == 0 && ContaBancaria.codigo_conta != 0);
        if (ContaBancaria.codigo_conta != 0)
        {
            ContaBancaria = aux2->conteudo;
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
            strcpy(movi.dt_movimento, lerData(movi.codigo_conta));
            strcpy(movi.to_movimento, ler_tipo_movimento());
            strcpy(movi.ds_favorecido, ler_movi_favorecido());
            movi.vl_movimento = ler_valor(ContaBancaria.vl_saldo, ContaBancaria.vl_limite);
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
            printf("%9.2lf", movi.vl_saldo);
            gotoxy(7, 24);
            printf("Deseja gravar a movimentacao(1-SIM/2-NAO):");
            scanf("%d", &resp);
            if (resp == 1)
            {
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
                gotoxy(07, 24);
                printf("Movimentacao cadastrada com sucesso             ");
                getch();
            }
        }
        gotoxy(07, 24);
        printf("Gostaria de cadastrar um novo movimento(1-SIM/2-NAO):");
        scanf("%d", &resp);
    } while (resp == 1);
}
