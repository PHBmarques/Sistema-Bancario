/*
Autor: Gustavo de Lima Sossai
Data: 08/11/2024
Equipe: RA: 173342-2024
        RA: 179427-2024
Obj:Função que permita que o usuario excluia um casdastro no inicio da lista
*/

#include "funcoes.h"

void remover_posicao(tipolista *l)
{
    tipoapontador p;
    tipoapontador r;
    int pos = 0;
    int cont;
    int opc;
    do
    {
        gotoxy(07, 24);
        printf("Digite a posicao que deseja remover:");
        scanf("%d", &pos);

        r = l->primeiro;
        p = r->proximo;
        cont = 1;
        // Verifica se ele ira remover o primeiro cadastro da lista
        if (pos == 1)
        {
            p = l->primeiro;
            tela();
            telacadastro();
            gotoxy(18, 03);
            printf("REMOCAO DE CONTAS BANCARIAS E UMA POSICAO");
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
            gotoxy(52, 17);
            printf("%.2lf", p->conteudo.vl_saldo);
            gotoxy(52, 19);
            printf("%.2lf", p->conteudo.vl_limite);
            gotoxy(52, 21);
            printf("%s", p->conteudo.status);
            gotoxy(7, 24);

            gotoxy(7, 24);
            printf("Deseja realmente remover esse banco(1-SIM/2-NAO):");
            scanf("%d", &opc);
            if (opc == 1)
            {
                l->primeiro = p->proximo;
                free(p);
                gotoxy(7, 24);
                printf("Cadastro Removido com sucesso");
            }
        }
        else
        {
            // Caso não queira remover o primeiro cadastro ele ira remover outro elemento selecionado da lista
            while (cont < pos - 1)
            {
                cont = cont + 1;
                p = p->proximo;
                r = r->proximo;
            };
            tela();
            telacadastro();
            gotoxy(18, 3);
            printf("REMOCAO DE CONTAS BANCARIAS EM UMA POSICAO");
            gotoxy(52, 7);
            printf("%d", r->proximo->conteudo.codigo_conta);
            gotoxy(52, 9);
            printf("%s", r->proximo->conteudo.banco);
            gotoxy(52, 11);
            printf("%s", r->proximo->conteudo.agencia);
            gotoxy(52, 13);
            printf("%s", r->proximo->conteudo.numero_conta);
            gotoxy(52, 15);
            printf("%s", r->proximo->conteudo.tipo_conta);
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
            gotoxy(52, 17);
            printf("%.2lf", p->conteudo.vl_saldo);
            gotoxy(52, 19);
            printf("%.2lf", p->conteudo.vl_limite);
            gotoxy(52, 21);
            printf("%s", p->conteudo.status);
            gotoxy(7, 24);

            gotoxy(7, 24);
            printf("Deseja realmente remover esse banco(1-SIM/2-NAO):");
            scanf("%d", &opc);

            if (opc == 1)
            {
                r->proximo = p->proximo;
                free(p);
                gotoxy(7, 24);
                printf("Cadastro removido com sucesso!");
            }
        }
        gotoxy(7, 24);
        printf("                                                  ");
        gotoxy(7, 24);
        printf("Deseja Remover outro Cadastro(1-SIM/1-NAO):");
        scanf("%d", &opc);
    } while (opc == 1);
}