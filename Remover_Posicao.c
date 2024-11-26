/*
Autor: Gustavo de Lima Sossai
Data: 08/11/2024
Equipe: RA: 173342-2024
        RA: 179427-2024
Obj:Função que permita que o usuario excluia um casdastro no inicio da lista
*/

#include "funcoes.h"

void remover_posicao(tipolista *l, tipolista_movi *M)
{
    tipoapontador p; // Ponteiro auxiliar para percorrer a lista.
    tipoapontador r; // Ponteiro para o elemento anterior ao que será removido.
    int pos = 0;     // Armazena a posição a ser removida.
    int cont;        // Contador para localizar a posição na lista.
    int opc;         // Armazena a escolha do usuário sobre a remoção.

    do
    {
        // Solicita a posição do elemento a ser removido.
        gotoxy(07, 24);
        printf("Digite a posicao que deseja remover:");
        scanf("%d", &pos);

        r = l->primeiro;// Inicializa `r` com o primeiro elemento da lista.
        p = r->proximo;// `p` aponta para o próximo elemento.
        cont = 1;      // Inicializa o contador com 1.
        // Verifica se ele ira remover o primeiro cadastro da lista
        if (pos == 1)
        {
            p = l->primeiro;// `p` aponta para o primeiro elemento.
            // Exibe os dados do elemento a ser removido.
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
            // Exibe o tipo de conta com base no código.
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
            // Exibe saldo, limite e status da conta.
            gotoxy(52, 17);
            printf("%.2lf", p->conteudo.vl_saldo);
            gotoxy(52, 19);
            printf("%.2lf", p->conteudo.vl_limite);
            gotoxy(52, 21);
            printf("%d", p->conteudo.status);
            gotoxy(7, 24);
            // Verifica se há movimentações financeiras associadas à conta.
            if (verifica_movimento(M->primeiro, p->conteudo.codigo_conta))
            {
                gotoxy(07, 24);
                printf("Nao e possivel remover a conta ela esta em movimentacao");
                getch();
                return;// Sai da função se a conta estiver em movimentação.
            }
            // Confirmação do usuário para remoção.
            gotoxy(7, 24);
            printf("Deseja realmente remover esse banco(1-SIM/2-NAO):");
            scanf("%d", &opc);
            if (opc == 1)
            {
                l->primeiro = p->proximo;// Atualiza o ponteiro para o próximo elemento.
                free(p);                 // Libera a memória do elemento removido.
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
            // Exibe os dados do elemento a ser removido.
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
            printf("%d", p->conteudo.status);
            gotoxy(7, 24);
            // Confirmação do usuário para remoção.
            gotoxy(7, 24);
            printf("Deseja realmente remover esse banco(1-SIM/2-NAO):");
            scanf("%d", &opc);

            if (opc == 1)
            {
                r->proximo = p->proximo;// Atualiza o ponteiro para ignorar o elemento removido
                free(p);                // Libera a memória do elemento removido.
                gotoxy(7, 24);
                printf("Cadastro removido com sucesso!");
            }
        }
        // Pergunta se o usuário deseja remover outro elemento.
        gotoxy(7, 24);
        printf("                                                  ");
        gotoxy(7, 24);
        printf("Deseja Remover outro Cadastro(1-SIM/1-NAO):");
        scanf("%d", &opc);
    } while (opc == 1);
}