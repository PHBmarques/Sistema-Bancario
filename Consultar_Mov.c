/*
Autor: Gustavo de Lima Sossai
Data: 21/11/2024
Equipe: RA: 173342-2024
        RA: 179427-2024
Obj:
*/
#include "funcoes.h"

void consultar_mov(tipolista *l, tipolista_movi *M)
{
    tipoapontador aux2;
    tipoapontador_movi aux3;
    infocontas ContaBancaria;
    movimento mov;
    int linha = 10;
    int resp;
    int opc;
    int numero = 1;
    do
    {
        do
        {
            tela();
            tela_consultar_mov();
            gotoxy(14, 03);
            printf("Consulta de movimentacao");
            gotoxy(7, 24);
            printf("Digite 0 para sair");
            gotoxy(9, 6);
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
            gotoxy(13, 6);
            printf("%s", aux2->conteudo.banco);
            gotoxy(30, 6);
            printf("Agencia:");
            gotoxy(38, 6);
            printf("%s", aux2->conteudo.agencia);
            gotoxy(47, 6);
            printf("Cta:");
            gotoxy(51, 6);
            printf("%s", aux2->conteudo.numero_conta);
            gotoxy(60, 6);
            printf("Conta:");
            gotoxy(67, 6);
            printf("%s", aux2->conteudo.tipo_conta);
            // Verificação para tipo de conta inserida
            if (aux2->conteudo.tipo_conta[0] == '1')
            {
                gotoxy(67, 6);
                printf("Corrente");
            }
            else if (aux2->conteudo.tipo_conta[0] == '2')
            {
                gotoxy(67, 6);
                printf("Poupanca");
            }
            else if (aux2->conteudo.tipo_conta[0] == '3')
            {
                gotoxy(67, 6);
                printf("Cartao credito");
            }
            aux3 = M->primeiro;
            while (aux3 != NULL)
            {
                // Verifica se a movimentação pertence à conta pesquisada
                if (aux3->conteudo.codigo_conta == ContaBancaria.codigo_conta)
                {
                    gotoxy(2, linha);
                    printf("%s", aux3->conteudo.dt_movimento);

                    gotoxy(13, linha);
                    printf("%s", aux3->conteudo.ds_favorecido);

                    gotoxy(40, linha);
                    printf("%s", aux3->conteudo.to_movimento);

                    gotoxy(55, linha);
                    printf("%9.2f", aux3->conteudo.vl_movimento);

                    gotoxy(70, linha);
                    printf("%9.2f", aux3->conteudo.vl_saldo);

                    linha ++; // Incrementa a linha para a próxima exibição
                }

                aux3 = aux3->proximo; // Move para a próxima movimentação
            }
            gotoxy(7, 24);
            printf("Deseja consultar outro Cadastro? (1-SIM/2-NAO)");
            scanf("%d", &resp);
        }
    } while (resp == 1);
}