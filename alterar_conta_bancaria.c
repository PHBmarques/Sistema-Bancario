/*
Autor: Pedro Henrique Bernardo Marques
Data: 04/11/2024
Equipe: RA: 173342-2024
        RA: 179427-2024
Obj: Permitir a alteração dos dados já inseridos
*/
#include "funcoes.h"
// Funcao que ira permitir alterar o dado desejado
void alterar_conta_bancaria(tipolista *l)
{
    tipoapontador aux;
    infocontas ContaBancaria;
    int resp;
    int opc;
    do
    {
        do
        {
            tela();
            telacadastro();
            gotoxy(7, 24);
            printf("Digite 0 para sair");
            gotoxy(52, 7);
            scanf("%d", &ContaBancaria.codigo_conta);
            aux = pesquisa(l, ContaBancaria.codigo_conta);
            if (aux == NULL && ContaBancaria.codigo_conta != 0)
            {
                gotoxy(7, 24);
                printf("Cadastro nao Existe");
                getch();
            }
        } while (aux != 0 && ContaBancaria.codigo_conta != 0);
        if (ContaBancaria.codigo_conta != 0)
        {
            gotoxy(52, 7);
            printf("%d", aux->conteudo.codigo_conta);
            gotoxy(52, 9);
            printf("%s", aux->conteudo.banco);
            gotoxy(52, 11);
            printf("%s", aux->conteudo.agencia);
            gotoxy(52, 13);
            printf("%s", aux->conteudo.numero_conta);
            gotoxy(52, 15);
            printf("%s", aux->conteudo.tipo_conta);
            gotoxy(52, 17);
            printf("%.2lf", aux->conteudo.vl_saldo);
            gotoxy(52, 19);
            printf("%.2lf", aux->conteudo.vl_limite);
            gotoxy(52, 21);
            printf("%s", aux->conteudo.status);
            do
            {
                do
                {
                    gotoxy(7, 24);
                    printf("                                         ");
                    gotoxy(7, 24);
                    printf("Qual informacao deseja alterar:");
                    scanf("%d", &opc);
                    if (opc < 0 || opc > 8)
                    {
                        gotoxy(7, 24);
                        printf("                               ");
                        printf("Campo invalido");
                    }
                } while (opc < 0 || opc > 8);
                // ira alterar o campo desejado
                switch (opc)
                {
                case 2:
                    gotoxy(52, 9);
                    printf("                   ");
                    fflush(stdin);
                    fgets(ContaBancaria.banco, 50, stdin);
                case 3:
                    gotoxy(52, 11);
                    printf("                   ");
                    fflush(stdin);
                    fgets(ContaBancaria.agencia, 10, stdin);
                case 4:
                    gotoxy(52, 13);
                    printf("                   ");
                    fflush(stdin);
                    fgets(ContaBancaria.numero_conta, 20, stdin);
                case 5:
                    gotoxy(52, 15);
                    printf("                  ");
                    fflush(stdin);
                    fgets(ContaBancaria.tipo_conta, 20, stdin);
                case 6:
                    gotoxy(52, 17);
                    printf("                 ");
                    scanf("%lf", &ContaBancaria.vl_saldo);
                case 7:
                    gotoxy(52, 19);
                    printf("                ");
                    scanf("%lf", &ContaBancaria.vl_limite);
                case 8:
                    gotoxy(52, 21);
                    printf("                ");
                    fflush(stdin);
                    fgets(ContaBancaria.status, 10, stdin);
                }
            } while (opc != 0);
            gotoxy(7, 24);
            printf("Deseja salvar os dados (1-SIM/2-NAO)");
            scanf("%d", &resp);
            if (resp == 1)
            {
                aux->conteudo = ContaBancaria;
            }
            gotoxy(7, 24);
            printf("Deseja alterar outro Cadastro (1-SIM/2-NAO)");
            scanf("%d", &resp);
        }
    } while (resp == 1);
}