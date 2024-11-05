/*
Autor: Pedro Henrique Bernardo Marques
Data: 04/11/2024
Equipe: RA: 173342-2024
        RA: 179427-2024
Obj: funcoes utilizadas no programa
*/
#ifndef funcoes_h
#define funcoes_h

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

tipoapontador pesquisa(tipolista *L, int cod);

void Movimentacao();

void cadastrar(tipolista *l);

int contador(tipolista *l);

void cadastrofinal(tipolista *l);

void cadastrarinicio(tipolista *l);

void casdastrar_posicao(tipolista *l);

void consultar_cadastro(tipolista *l);

void gotoxy(int x, int y);

void tela();
#endif 