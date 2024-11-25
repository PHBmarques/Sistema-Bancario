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
    // Laço principal para a alteração dos dados da conta
    do
    {
         // Laço para realizar a pesquisa da conta a ser alterada
        do
        {
            tela();//Função que exibe a tela inicial
            telacadastro();//Função ira criar a tela para inserir os dados necessarios
            gotoxy(7, 24);
            printf("Digite 0 para sair");
            gotoxy(52, 7);
            scanf("%d", &ContaBancaria.codigo_conta);//Le o cófigo da conta
            //pesquisa se a conta existe
            aux = pesquisa(l, ContaBancaria.codigo_conta);
            //caso não exista a conta pesquiida uma mensagem ira aparecer
            if (aux == NULL && ContaBancaria.codigo_conta != 0)
            {
                gotoxy(7, 24);
                printf("Cadastro nao Existe");
                getch();
            }
        } while (aux == NULL && ContaBancaria.codigo_conta != 0);//ira repetir até digitar uma conta existente
        //Se a conta for encontrada ira mostrar os dados na tela
        if (ContaBancaria.codigo_conta != 0)
        {
            ContaBancaria = aux->conteudo;//atribui os dados da conta encontrada
            //exibe os dados da conta
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
            printf("%d", aux->conteudo.status);
            //repetição para selecionar o campo a ser alterado
            do
            {
                do
                {
                    gotoxy(7, 24);
                    printf("                                         ");
                    gotoxy(7, 24);
                    printf("Qual informacao deseja alterar:");
                    scanf("%d", &opc);//le a opção desejada
                    //caso selecione uma opção maior que as disponiveis ira mostrar uma mensagem de erro
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
                    fgets(ContaBancaria.banco, 50, stdin);//altera o banco
                    break;
                case 3:
                    gotoxy(52, 11);
                    printf("                   ");
                    fflush(stdin);
                    fgets(ContaBancaria.agencia, 10, stdin);//altera a agencia 
                    break;
                case 4:
                    gotoxy(52, 13);
                    printf("                   ");
                    fflush(stdin);
                    fgets(ContaBancaria.numero_conta, 20, stdin);//altera o numero da conta
                    break;
                case 5:
                    gotoxy(52, 15);
                    printf("                  ");
                    fflush(stdin);
                    fgets(ContaBancaria.tipo_conta, 20, stdin);//altera o tipo da conta
                    break;
                case 6:
                    gotoxy(52, 17);
                    printf("                 ");
                    scanf("%lf", &ContaBancaria.vl_saldo);//altera o saldo da conta
                    break;
                case 7:
                    gotoxy(52, 19);
                    printf("                ");
                    scanf("%lf", &ContaBancaria.vl_limite);//altera o limite da conta
                    break;
                }
            } while (opc != 0);//ira repritr até o usuario digitar 0
            //pergunta se o usuario quer ou não salvar os dados
            gotoxy(7, 24);
            printf("Deseja salvar os dados (1-SIM/2-NAO)");
            //se sim ele ira salvar as alterações feitas
            scanf("%d", &resp);
            if (resp == 1)
            {
                aux->conteudo = ContaBancaria;
            }
            //pergunta se voce quer alterar outro cadastro
            gotoxy(7, 24);
            printf("Deseja alterar outro Cadastro (1-SIM/2-NAO)");
            scanf("%d", &resp);
        }
    } while (resp == 1);//ira repetir até voce digitar 2
}