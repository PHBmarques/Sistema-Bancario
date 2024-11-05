/*Autor:Pedro Henrique Bernardo Marques
  Data26/10/24*/

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
//metodo criado para verificar se esse codigo já existe
tipoapontador pesquisa(tipolista *L, int cod);
/*
Autor: Gustavo
Função que conta quantos elementos tem na lista de cadastros
*/
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