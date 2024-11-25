/*
Autor: Gustavo de Lima Sossai
Data: 24/11/2024
Equipe: RA: 173342-2024
        RA: 179427-2024
Obj:Transferencia entre contas de movimento
*/

#include "Funcoes.h"

int Trans_Conta(tipolista *l, tipolista_movi *M)
{
    int codigo;
    int codigo2;
    int teste;
    tipoapontador aux;
    tipoapontador aux2;
    movimento conta;
    movimento conta2;

    if (l->primeiro == NULL)
    {
        gotoxy(8, 24);
        printf("Nenhuma conta encontrada para efetuar a transferencia");
        getch();
        return 0;
    }

    tela();
    tela_transferencia_contas();

    gotoxy(8, 24);
    printf("Digite \"0\" para sair");

    gotoxy(19, 8);
    scanf("%d", &codigo);

    if (codigo == 0)
    {

        gotoxy(8, 24);
        printf("Deseja realmente sair (1 = SIM / 2 = NAO): ");
        scanf("%d", &teste);
        gotoxy(8, 24);
        printf("                                            ");
        gotoxy(8, 24);

        if (teste == 1)
        {
            return 0;
        }
    }

    aux = pesquisa(l, codigo);

    do
    {
        if (aux == NULL)
        {
            gotoxy(8, 24);
            printf("Conta nao encontrada ou inexistente");
            getch();
        }
        else if (strcmp(aux->conteudo.status, "Inativa") == 0)
        {
            gotoxy(8, 24);
            printf("Conta inativa");
            getch();
        }
    } while (aux == NULL || strcmp(aux->conteudo.status, "Inativa") == 0);

    gotoxy(19, 9);
    printf("%s", aux->conteudo.banco);
    gotoxy(19, 10);
    printf("%s", aux->conteudo.agencia);
    gotoxy(19, 11);
    printf("%s", aux->conteudo.tipo_conta);
    gotoxy(19, 12);
    printf("%.2lf", aux->conteudo.vl_saldo);
    gotoxy(19, 13);
    printf("%.2lf", aux->conteudo.vl_limite);
    gotoxy(19, 14);
    printf("%.2lf", aux->conteudo.vl_saldo + aux->conteudo.vl_limite);

    gotoxy(56, 8);
    scanf("%d", &codigo2);
    aux2 = pesquisa(l, codigo2);

    do
    {
        if (aux2 == NULL)
        {
            gotoxy(8, 24);
            printf("Conta nao encontrada ou inexistente");
            getch();
        }
        else if (strcmp(aux2->conteudo.status, "Inativa") == 0)
        {
            gotoxy(8, 24);
            printf("Conta inativa");
            getch();
        }
    } while (aux2 == NULL || strcmp(aux2->conteudo.status, "Inativa") == 0);

    gotoxy(56, 9);
    printf("%s", aux2->conteudo.banco);
    gotoxy(56, 10);
    printf("%s", aux2->conteudo.agencia);
    gotoxy(56, 11);
    printf("%s", aux2->conteudo.tipo_conta);
    gotoxy(56, 12);
    printf("%.2lf", aux2->conteudo.vl_saldo);
    gotoxy(56, 13);
    printf("%.2lf", aux2->conteudo.vl_limite);
    gotoxy(56, 14);
    printf("%.2lf", aux2->conteudo.vl_saldo + aux2->conteudo.vl_limite);

    gotoxy(44, 19);
    printf("");
    scanf("%f", &conta.vl_movimento);

    if (conta.vl_movimento <= 0 || conta.vl_movimento > (aux->conteudo.vl_saldo + aux->conteudo.vl_limite))
    {
        gotoxy(8, 24);
        printf("Saldo insuficiente para realizar a transferencia");
        getch();
        return 0;
    }

    
    strcpy(conta2.dt_movimento, lerData(conta2.codigo_conta,44,20));

    aux->conteudo.vl_saldo -= conta.vl_movimento;
    aux2->conteudo.vl_saldo += conta.vl_movimento;

    gotoxy(19, 15);
    printf("%.2lf", aux->conteudo.vl_saldo);

    gotoxy(56, 15);
    printf("%.2lf", aux2->conteudo.vl_saldo);

    gotoxy(8, 24);
    printf("Transferencia realizada com sucesso em %s", conta.dt_movimento);
    getch();

    conta.codigo_conta = codigo;
    strcpy(conta.ds_favorecido, "Transferencia Entre Contas");

    if (M->ultimo == NULL)
    {
        conta.sequencial = 1;
    }
    else
    {
        conta.sequencial = M->ultimo->conteudo.sequencial + 1;
    }

    strcpy(conta.to_movimento, "Debito");

    conta.vl_saldo = aux->conteudo.vl_saldo;

    inserirMovim(M, conta);

    conta2.codigo_conta = codigo2;
    strcpy(conta2.ds_favorecido, "Transferencia Entre Contas");

    if (M->ultimo == NULL)
    {
        conta2.sequencial = 1;
    }
    else
    {
        conta2.sequencial = M->ultimo->conteudo.sequencial + 1;
    }

    strcpy(conta2.to_movimento, "Credito");

    conta2.vl_saldo = aux2->conteudo.vl_saldo;

    strcpy(conta2.dt_movimento, conta.dt_movimento);

    conta2.vl_movimento = conta.vl_movimento;

    inserirMovim(M, conta2);

    return 1;
}