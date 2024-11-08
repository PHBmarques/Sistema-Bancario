/*
Autor: Pedro Henrique Bernardo Marques
Data: 04/11/2024
Equipe: RA: 173342-2024
        RA: 179427-2024
Obj: funcoes utilizadas no programa
*/
#ifndef funcoes_h
#define funcoes_h
#include<stdio.h>
#include<stdlib.h>
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
//menu da movimentação financeira
void Movimentacao();
//menu de cadastro de Contas
void cadastrar(tipolista *l);
//Função que ira contar quantos elementos já foram cadastrados na lista
int contador(tipolista *l);
//Permite o cadastro de uma conta no final da lista
void cadastrofinal(tipolista *l);
//Permite o cadastro de uma conta no inicio da lista
void cadastrarinicio(tipolista *l);
//Permite o cadastro de uma conta em uma posição determinada na lista
void casdastrar_posicao(tipolista *l);
//Permite Consultar todas as contas Bancaria já cadastradas
void consultar_cadastro(tipolista *l);
//Permite a alteração de informações da conta escolhida
void alterar_conta_bancaria(tipolista *l);

void gotoxy(int x, int y);
//Função que ira criar a tela principal do programa
void tela();
//Função que ira cirar a tela para inserir os dados necessarios
void telacadastro();
#endif 