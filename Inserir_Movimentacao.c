/*
Autor: Gustavo de Lima Sossai
Data: 24/11/2024
Equipe: RA: 173342-2024
        RA: 179427-2024
Obj:Função auxiliar da tela transferencia entre contas de movimento
*/

#include "Funcoes.h"

void inserirMovim(tipolista_movi *l, movimento cont)
{
    tipoapontador_movi p;

   
    cont.dt_movimento[strcspn(cont.dt_movimento, "\n")] = '\0';
    cont.ds_favorecido[strcspn(cont.ds_favorecido, "\n")] = '\0';


    // cria o no p
    p = (tipoapontador_movi)malloc(sizeof(tipoitem_movi));

   p -> conteudo = cont;
   p ->proximo = NULL;
   p ->anterior = NULL;

    // adiciona no final

    if (l->primeiro == NULL)
    {
        l->primeiro = p;
        l->ultimo = p;
    }
    else
    {
        l -> ultimo -> proximo = p;
        p->anterior = l ->ultimo;
        l -> ultimo = p;
    }
}