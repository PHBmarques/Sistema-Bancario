#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>
typedef struct{
    int codigo_conta;
    char banco[50];
    char agencia[10];
    char umero_conta[20];
    char tipo_conta[20];
    double vl_saldo;
    double vl_limite;
    char status[10];
}infocontas;

typedef struct tipoitem *tipoapontador;

typedef struct tipoitem{
    tipoapontador conteudo;
    tipoapontador proximo;
}tipoitem;

typedef struct{
    tipoapontador  primeiro;
    tipoapontador ultimo;
}tipolista;