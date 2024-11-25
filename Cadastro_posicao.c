/*
Autor: Gustavo de Lima Sossai
Data: 04/11/2024
Equipe: RA: 173342-2024
        RA: 179427-2024
Obj:Permite o cadastro dos dados em uma determinada posicao
*/
#include "funcoes.h"
void casdastrar_posicao(tipolista *l)
{
    int resp = 0;
    infocontas ContaBancaria;// Estrutura que armazenará os dados de uma conta bancária
    tipoapontador p;// Ponteiro para um item da lista
    tipoapontador aux; // Ponteiro auxiliar para verificar se a conta já está cadastrada
    tipoapontador r;  // Ponteiro para o novo item a ser inserido
    int pos;  // Variável para armazenar a posição onde o usuário deseja inserir a conta
    int x;  // Variável de controle para percorrer a lista de contas
    int qtde;  // Variável para armazenar a quantidade de contas cadastradas
    do
    {
        do
        {
            tela();
            telacadastro();
            gotoxy(15, 03);
            printf("Cadastro de Contas-Em uma Posicao");
            gotoxy(7, 24);
            printf("Digite 0 para sair");
            gotoxy(52, 7);
            scanf("%d", &ContaBancaria.codigo_conta);
            // limpa o buffer apos o uso do scanf
            while (getchar() != '\n');
            // Verifica se já existe uma conta cadastrada com o mesmo código
            aux = pesquisa(l, ContaBancaria.codigo_conta);
            if (aux != NULL)
            {
                gotoxy(7, 24);
                printf("Codigo ja cadastrado");
                getch();
            }
        } while (aux != NULL);//repete o loop até encontrar um código não cadastrado
        if (ContaBancaria.codigo_conta != 0)// Se o código da conta for diferente de 0 
        {
            // Coleta os dados da conta bancária
            gotoxy(52, 9);
            fflush(stdin);
            fgets(ContaBancaria.banco, 50, stdin);
            gotoxy(52, 11);
            fflush(stdin);
            fgets(ContaBancaria.agencia, 10, stdin);
            gotoxy(52, 13);
            fflush(stdin);
            fgets(ContaBancaria.numero_conta, 20, stdin);
            do
            {
                //Pergunta qual tipo de conta sera cadastrada
                gotoxy(07, 24);
                printf("Utilizar: 1=Corrente/2=Poupanca/3=Cartao Credito");
                gotoxy(52, 15);
                fflush(stdin);
                // Verifica qual tipo de conta foi escolhido
                fgets(ContaBancaria.tipo_conta, 20, stdin);
                if (ContaBancaria.tipo_conta[0] == '1')
                {
                    gotoxy(53, 15);
                    printf("-Corrente");
                }
                else if (ContaBancaria.tipo_conta[0] == '2')
                {
                    gotoxy(53, 15);
                    printf("-Poupanca");
                }
                else if (ContaBancaria.tipo_conta[0] == '3')
                {
                    gotoxy(53, 15);
                    printf("-Cartao Credito");
                }
                //Caso insira um valor invalido uma mensagem de erro ira aparecer
                else
                {
                    gotoxy(7, 24);
                    printf("                                            ");
                    gotoxy(7, 24);
                    printf("Tipo de Conta invalido");
                    getch();
                    gotoxy(52, 15);
                    printf("  ");
                }
            } while (ContaBancaria.tipo_conta[0] != '1' && ContaBancaria.tipo_conta[0] != '2' && ContaBancaria.tipo_conta[0] != '3');//ele ira repetir até que o valor seja valido
            gotoxy(7, 24);
            printf("                                                        ");
            gotoxy(52, 17);
            scanf("%lf", &ContaBancaria.vl_saldo);
            gotoxy(52, 19);
            scanf("%lf", &ContaBancaria.vl_limite);
            gotoxy(52, 21);
            //Verifica se o status da conta é valido ou invalido
            ContaBancaria.status = verificar_status(ContaBancaria);
            gotoxy(52, 21);
            printf("%d", ContaBancaria.status);
            gotoxy(7, 24);
            // Ira perguntar se o usuario deseja salvar esses dados ou não
            printf("Deseja Salvar os dados(1-SIM/2-NAO):");
            scanf("%d", &resp);

            if (resp == 1)
            {
                //ira perguntar em qual posição deseja inserir o dado escolhido
                do
                {
                    gotoxy(7, 24);
                    printf("Em qual posicao deseja gravar os dados:");
                    scanf("%d", &pos);
                    qtde = contador(l);
                    if (pos > qtde)
                    {
                        gotoxy(7, 24);
                        printf("Posicao invalida                         ");
                        getch();
                    }
                } while (pos > qtde);
                r = (tipoapontador)malloc(sizeof(tipoitem));
                r->proximo = NULL;
                r->conteudo = ContaBancaria;
                p = l->primeiro;
                if (pos == 1)
                {
                    r->proximo = l->primeiro;
                    l->primeiro = r;
                }
                else if (pos == qtde)
                {
                    l->ultimo->proximo = r;
                    l->ultimo = r;
                    return;
                }
                else
                {
                    for (x = 1; x <= pos - 2; x++)
                    {
                        p = p->proximo;
                    };
                    r->proximo = p->proximo;
                    p->proximo = r;
                }
                gotoxy(7, 24);
                printf("Cadastro concluido                      ");
                getch();
            }
            gotoxy(7, 24);
            printf("Cadastrar novo funcionario (1-SIM/2-NAO)");
            scanf("%d", &resp);
        }
    } while (resp == 1);
}