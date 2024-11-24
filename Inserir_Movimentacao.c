#include "Funcoes.h"

void inserirMovim(tipolista_movi *l, movimento cont)
{
    tipoapontador_movi p;
    tipoapontador_movi f;
    tipoapontador_movi F;

   
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