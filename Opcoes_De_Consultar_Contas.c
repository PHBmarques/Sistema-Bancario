/*
Autor: Gustavo de Lima Sossai
Data: 04/11/2024
Equipe: RA: 173342-2024
        RA: 179427-2024
Obj:Consulta os dados que ja foram cadastrados
*/

#include "funcoes.h"

void opcoes_de_consultar(tipolista *l)
{

    int opc;

    do
    {
        tela();
        gotoxy(28, 04);
        printf("MANEIRAS DE CONSULTAR");
        gotoxy(25, 10);
        printf("1-Consulta Geral Contas Cadastradas");
        gotoxy(25, 12);
        printf("2-Consultar por Codigo Contas Bancarias");
        gotoxy(25, 14);
        printf("3-Consultar em Ordem Codigo Bancarias");
        gotoxy(25, 16);
        printf("4-Consultar em Ordem Alfabetica");
        gotoxy(25, 18);
        printf("5-Retornar ao menu anterior");
        gotoxy(07, 24);
        printf("Digite a opcao:");
        scanf("%d", &opc);

        if (opc >= 6 || opc <= 0)
        {
            gotoxy(07, 24);
            printf("Digite apenas opcoes existentes");
            getch();
        }
        else
        {

            switch (opc)
            {
            case 1:
                consultar_cadastro(l);
                break;
            case 2:
                Consulta_por_Codigo(l);
                break;
            case 3:
                consultar_ordem_numerica(l);
                break;
            case 4:
                break;
            }
        }
    } while (opc != 5);
}