/*
Autor: Gustavo de Lima Sossai
Data: 04/11/2024
Equipe: RA: 173342-2024
        RA: 179427-2024
Obj:Consulta os dados que ja foram cadastrados
*/
#include "funcoes.h"
void consultar_cadastro(tipolista *l)
{
    tipoapontador p;
    p = l->primeiro;
    //Verificação se algum cadastro feito
    if (p == NULL)
    {
        gotoxy(7, 24);
        printf("Nao a cadastro colocado");
        getch();
    }
    else
    {
        //Laço de repetição para apresentar a tela
        while (p != NULL)
        {
            tela();
            telacadastro();
            gotoxy(20, 03);
            printf("Consulta de Contas Cadastradas");
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

            //Verificação para tipo de conta inserida
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
            printf("%d", p->conteudo.status);
            gotoxy(7, 24);
            printf("Pressione qualquer botao para continuar");
            getch();
            p = p->proximo;
        }
    }
}