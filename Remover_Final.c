/*
Autor: Gustavo de Lima Sossai
Data: 08/11/2024
Equipe: RA: 173342-2024
        RA: 179427-2024
Obj:Função que permita que o usuario excluia um casdastro no final da lista
*/

#include "funcoes.h"

// Criando a função remover final da lista
void remover_final(tipolista *l)
{
    tipoapontador p;
    tipoapontador r;
    int opc;
    


    p = l->ultimo;
    
        tela();
        telacadastro();
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
        
        if(opc == 1){         
        // Verificando se a lista possui algum cadastro
        if (l->primeiro->proximo == NULL)
        {
            free(l->primeiro);
            l->primeiro = NULL;
            l->ultimo = NULL;
            gotoxy(7, 24);
            printf("Cadastro removido com sucesso                                        ");
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

            // Quando encontrar o elemento da lista devera eliminar o espaço de memoria
            free(p);
            r->proximo = NULL;
            l->ultimo = r;
            
        }
        } 
}