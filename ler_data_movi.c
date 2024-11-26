/*
Autor: Pedro Henrique Bernardo Marques
Data: 04/11/2024
Equipe: RA: 173342-2024
        RA: 179427-2024
Obj: Função que ira verificar se a data inserida é menor que a data já cadastrada
*/
#include "funcoes.h"
// Converte data no formato DD/MM/AAA para AAAMMDD
int DataparaNumero(char *data)
{
    int dia, mes, ano;
    if (sscanf(data, "%d/%d/%d", &dia, &mes, &ano) != 3)
    {
        return -1; // Formato inválido
    }
    if (mes < 1 || mes > 12)
    {
        return -1; // Mês inválido
    }
    if (dia < 1 || dia > 31)
    {
        return -1; // Dia inválido
    }
    return (ano * 10000) + (mes * 100) + dia; // Retorna como número no formato AAAAMMDD
}

char *lerData(int codigo_conta,int x,int y)
{
    static char data[11];             // Usando static para garantir que o buffer sobreviva fora do escopo da função
    static int ultima_conta = -1;     // Armazena o código da última conta registrada
    static int dataultima = -1;       // Armazena a última data registrada para a mesma conta
    int datanova;

    // Verificar se estamos usando a mesma conta
    if (ultima_conta != codigo_conta)
    {
        ultima_conta = codigo_conta;
        dataultima = -1; // Reseta a última data para uma conta diferente
    }

    // Loop para solicitar uma nova data até ser válida
    while (1)
    {
        gotoxy(7, 24);
        printf("Data de Movimento (DD/MM/AAAA):           ");
        gotoxy(x, y);
        scanf("%s", data);

        // Verifica o formato e a validade da data
        datanova = DataparaNumero(data);
        if (datanova == -1)
        {
            gotoxy(7, 24);
            printf("Formato invalido ou data invalida.");
            getch();
            gotoxy(7,24);
            printf("                                   ");
            gotoxy(x, y);
            printf("                   "); // Limpa a entrada anterior
            continue;                  // Continua o loop para solicitar uma nova data
        }

        // Verifica se a data é maior ou igual à última para a mesma conta ou se é uma nova conta
        if (dataultima == -1 || datanova >= dataultima) 
        {
            dataultima = datanova; // Atualiza a última data para a conta
            break; // Sai do loop se a data for válida
        }

        // Se a data for menor que a última para a mesma conta, mostra mensagem de erro
        gotoxy(7, 24);
        printf("A data %s e menor que a ultima cadastrada!", data);
        getch();
        gotoxy(7, 24);
        printf("                                                                 "); // Limpa a linha
        gotoxy(x, y);
        printf("               "); // Limpa o campo da data
    }

    return data; // Retorna a data válida
}

