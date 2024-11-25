/*
Autor: Gustavo de Lima Sossai
Data: 21/11/2024
Equipe: RA: 173342-2024
        RA: 179427-2024
Obj:Consultar as movimentações Bancarias
*/
#include "funcoes.h"

void consultar_mov(tipolista *l, tipolista_movi *M)
{
    tipoapontador aux2; // Ponteiro para localizar a conta na lista principal
    tipoapontador_movi aux3; // Ponteiro para percorrer a lista de movimentações
    infocontas ContaBancaria; // Estrutura para armazenar temporariamente os dados da conta consultada
    movimento mov; // Estrutura de movimentação (não usada diretamente neste código)
    int linha; // Linha da tela onde as movimentações serão exibidas
    int movimentacoesexibidas; // Contador de movimentações exibidas
    int resp; // Controle de repetição
    do
    {
        //repetição apara encontrar a conta
        do
        {
            tela();//exibe a tela padrão
            tela_consultar_mov();//exibe a interface de consulta da moviemtação
            gotoxy(14, 03);
            printf("Consulta de movimentacao");
            gotoxy(7, 24);
            printf("Digite 0 para sair");
            //solicita o código da conta
            gotoxy(9, 6);
            scanf("%d", &ContaBancaria.codigo_conta);
            // Busca a conta na lista principal
            aux2 = pesquisa(l, ContaBancaria.codigo_conta);
            // Verifica se a conta foi encontrada
            if (aux2 == NULL && ContaBancaria.codigo_conta != 0)
            {
                //exibe uma mensagem de erro
                gotoxy(7, 24);
                printf("Cadastro nao existe");
                getch();
            }
        } while (aux2 == NULL && ContaBancaria.codigo_conta != 0);//repete até ser digitado um código valido ou 0(para sair)
        if (ContaBancaria.codigo_conta != 0)//se o código for valido
        {
            ContaBancaria = aux2->conteudo;// Armazena os dados da conta encontrada
            linha=10;// Define a linha inicial para exibição das movimentações
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
            movimentacoesexibidas = 0; // Inicializa o contador de movimentações exibidas
            aux3 = M->primeiro; // Inicia a busca pelas movimentações
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
                    
                    linha++; // Incrementa a linha para a próxima exibição
                    movimentacoesexibidas++; // Incrementa o contador de movimentações exibidas
                }

                aux3 = aux3->proximo; // Move para a próxima movimentação
            }
            //pergunta se deseja cpnsultar outro cadastro
            gotoxy(7, 24);
            printf("Deseja consultar outro Cadastro? (1-SIM/2-NAO)");
            scanf("%d", &resp);
        }
    } while (resp == 1);//Ira continuar se repetendi enquanto a decisão escolhida for "1=SIM"
}