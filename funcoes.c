/*Autor:Pedro Henrique Bernardo Marques
  Data26/10/24*/
 
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>
typedef struct{
    int codigo_conta;
    char banco[50];
    char agencia[10];
    char numero_conta[20];
    char tipo_conta[20];
    double vl_saldo;
    double vl_limite;
    char status[10];
}infocontas;
typedef struct tipoitem *tipoapontador;
typedef struct tipoitem{
    infocontas conteudo;
    tipoapontador proximo;
}tipoitem;
typedef struct{
    tipoapontador  primeiro;
    tipoapontador ultimo;
}tipolista;
//metodo criado para verificar se esse codigo já existe
tipoapontador pesquisa(tipolista *L, int cod){
    tipoapontador aux;
     aux = L->primeiro;
     while (aux != NULL){
        if (aux->conteudo.codigo_conta==cod){
            return aux;
        }
        aux = aux ->proximo;
     }
     return NULL;
}