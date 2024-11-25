/*
Autor: Gustavo de Lima Sossai
Data: 08/11/2024
Equipe: RA: 173342-2024
        RA: 179427-2024
Obj:Função que permita que o usuario excluia um casdastro no final da lista
*/

#include "funcoes.h"

// Criando a função remover final da lista
void remover_final(tipolista *l,tipolista_movi *M)
{
    tipoapontador p;// Ponteiro para o último elemento da lista.
    tipoapontador r;// Ponteiro auxiliar para o penúltimo elemento da lista.
    int opc;        // Armazena a escolha do usuário sobre a remoção.

    p = l->ultimo;// Inicializa o ponteiro com o último elemento da lista.

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
    gotoxy(7, 24);
    // Verifica se a conta possui movimentações financeiras associadas.
    if(verifica_movimento(M->primeiro,p->conteudo.codigo_conta)){
        gotoxy(07,24);
        printf("Nao e possivel remover a conta ela esta em movimentacao");
        getch();
        return;// Sai da função se a conta estiver em movimentação.
    }
    gotoxy(7, 24);
    printf("Deseja realmente remover esse banco(1-SIM/2-NAO):");
    scanf("%d", &opc);

    if (opc == 1)
    {
        // Verificando se a lista possui algum cadastro
        if (l->primeiro->proximo == NULL)
        {
            free(l->primeiro);// Libera o espaço de memória da conta.
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
            // Caso a lista tenha mais de um elemento
            r = l->primeiro;
            p = r->proximo;

            // Percorre a lista até encontrar o penúltimo elemento
            while (p->proximo != NULL)
            {
                p = p->proximo;
                r = r->proximo;
            }
            gotoxy(7, 24);
            printf("                                                    ");
            gotoxy(7, 24);
            printf("Cadastro removido com sucesso");
            getch();
            // Remove o último elemento.
            free(p);           // Libera o espaço de memória do último elemento.
            r->proximo = NULL;// Atualiza o penúltimo elemento como último.
            l->ultimo = r;   // Atualiza o ponteiro do último na lista.
        }
    }
}