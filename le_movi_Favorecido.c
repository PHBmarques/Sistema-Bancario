/*
Autor: Pedro Henrique Bernardo Marques
Data: 04/11/2024
Equipe: RA: 173342-2024
        RA: 179427-2024
Obj: Função que ira inserir se a movimentação é de Debito ou Credito
*/
#include "funcoes.h"
char *ler_movi_favorecido()
{
        static char favo[50]; // Declara um array estático para armazenar o nome do favorecido.
        int i = 0;            // Variável de índice para percorrer o array.
        int vazio = 1;        // Flag para indicar se o nome é composto apenas por espaços.
        while (favo[0] == '\0')// Loop para garantir que o nome inserido seja válido.
        {
                gotoxy(33, 18);    
                scanf("%s", favo); // Lê a entrada do usuário e armazena em `favo`.

                // Verifica se o nome contém apenas espaços.
                while (favo[i] != '\0')
                {
                        if (favo[i] != ' '){// Se encontrar um caractere diferente de espaço
                                vazio = 0; // Atualiza a flag indicando que o nome não é vazio.
                                break;     // Interrompe o loop, pois o nome é válido.
                        }
                        i++; // Incrementa o índice para verificar o próximo caractere.
                }

                // Se o nome for vazio (ou apenas espaços), exibe uma mensagem de erro.
                if (favo[0] == '\0' || vazio)
                {
                        gotoxy(7, 24); 
                        printf("O nome do favorecido nao pode ser vazio e nem composto por apenas espaco");
                }
        }

        return favo; // Retorna o nome do favorecido.
}