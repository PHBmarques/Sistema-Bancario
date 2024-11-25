/*
Autor: Pedro Henrique Bernardo Marques
Data: 04/11/2024
Equipe: RA: 173342-2024
        RA: 179427-2024
Obj: funcoes utilizadas no programa
*/
#ifndef funcoes_h
#define funcoes_h
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
// Inclusão de bibliotecas padrão para entrada/saída, alocação dinâmica,
// manipulação de strings e controle do console.
typedef struct
{
    int codigo_conta;
    char banco[50];
    char agencia[10];
    char numero_conta[20];
    char tipo_conta[20];
    double vl_saldo;
    double vl_limite;
    int status;
} infocontas;
// Estrutura que representa uma conta bancária, com informações como código,
// banco, agência, número, tipo de conta, saldo, limite e status (ativo/inativo).

typedef struct tipoitem *tipoapontador;
typedef struct tipoitem
{
    infocontas conteudo;
    tipoapontador proximo;
} tipoitem;
// Estruturas para implementar uma lista encadeada de contas bancárias.
// Cada item da lista contém uma conta e um ponteiro para o próximo item.
typedef struct
{
    tipoapontador primeiro;
    tipoapontador ultimo;
} tipolista;
// Estrutura que representa a lista de contas, contendo ponteiros para o 
// primeiro e último elementos.

// Funçoes da moviemtação da conta
typedef struct
{
    int sequencial;
    int codigo_conta;
    char dt_movimento[11];
    char to_movimento[15];
    double vl_movimento;
    double vl_saldo;
    char ds_favorecido[50];
} movimento;
// Estrutura que representa uma movimentação bancária, com informações como
// código, data, tipo de movimento (saque, depósito, transferência), valor, 
// saldo após o movimento e favorecido.
typedef struct tipoitem_movi *tipoapontador_movi;
typedef struct tipoitem_movi
{
    movimento conteudo;
    tipoapontador_movi proximo;
    tipoapontador_movi anterior;
} tipoitem_movi;
// Estruturas para implementar uma lista duplamente encadeada de movimentações 
// bancárias.
typedef struct
{
    tipoapontador_movi primeiro;
    tipoapontador_movi ultimo;
} tipolista_movi;
// Estrutura que representa a lista de movimentações, com ponteiros para o
// primeiro e último elementos.

// Declaração de funções para manipular contas e movimentações bancárias.
// Procura uma conta na lista com base no código.
tipoapontador pesquisa(tipolista *L, int cod);
// Menu da movimentação financeira
void Movimentacao(tipolista *l, tipolista_movi *M);
// Menu de cadastro de Contas
void cadastrar(tipolista *l,tipolista_movi *M);
// Função que ira contar quantos elementos já foram cadastrados na lista
int contador(tipolista *l);
// Permite o cadastro de uma conta no final da lista
void cadastrofinal(tipolista *l);
// Permite o cadastro de uma conta no inicio da lista
void cadastrarinicio(tipolista *l);
// Permite o cadastro de uma conta em uma posição determinada na lista
void casdastrar_posicao(tipolista *l);
// Permite Consultar todas as contas Bancaria já cadastradas
void consultar_cadastro(tipolista *l);
// Permite a alteração de informações da conta escolhida
void alterar_conta_bancaria(tipolista *l);
// Permite que o usuario possa remover o cadastro no incio da lista
void remover_inicio(tipolista *l,tipolista_movi *M);
// Permite que o usuario possa remover o cadastro no final da lista
void remover_final(tipolista *l,tipolista_movi *M);
// Permite que o usuario possa remover o cadastro no em qualquer lugar da lista
void remover_posicao(tipolista *l,tipolista_movi *M);
// Sera as opções em que consultaremos as contas
void opcoes_de_consultar(tipolista *l);
// sera usado para consultar uma conta bancaria especifica pelo código
void Consulta_por_Codigo(tipolista *l);
void gotoxy(int x, int y);
// Função que ira criar a tela principal do programa
void tela();
// Função que ira criar a tela para inserir os dados necessarios
void telacadastro();
// Funcao que ira gravar os dados em um arquivo apos sair do código
void gravar_dados(tipolista *l);
// Funcao que ira ler os dados que foram salvos no arquivo binario
void ler_dados(tipolista *l);
// Função que tera papel de ser a tela de consulta de dados em ordem por codigo
void tela_consultar_ordem_numerica();
// Função de consultar o codigo em ordem numerica
void consultar_ordem_numerica(tipolista *l);
// Função que cria a tela para o cadastro de novas movimentações
void tela_movi();
// função que ira cadastrar um novo movimento bancario
void cadastro_movi(tipolista *l, tipolista_movi *M);
// Função que permite que mostre as funções em ordem alfabetica
void ordem_alfabetica(tipolista *l);
// função para ler uma data e verificar a validade
char *lerData(int codigo_conta,int x, int y);
// Função que ira criar a tela de tranferencia de contas
void tela_transferencia_contas();
// Função que ira criar a tela de consultar contas
void tela_consultar_mov();
// Função para ler o tipo de movimentação da conta
char *ler_tipo_movimento();
// Função que le a movimentação do favorecido
char *ler_movi_favorecido();
// Função que ira ler o valor solicitado e verificar se ele não ultrapassa o saldo
double ler_valor(double saldo, double limite);
// Função para Consultar as movimentações Bancaria de uma Conta
void consultar_mov(tipolista *l, tipolista_movi * M);
//Verifica se a conta esta em movimentação
int verifica_movimento(tipoapontador_movi M, int cod);
//verifica se a conta esta ativa=1 ou inativa=0
int verificar_status( infocontas ContaBAncaria);
//Função que ira permitir fazer a transferencia entre contas
void Trans_Conta(tipolista *l, tipolista_movi *M);
//Ele ira ler os dados salvos do movimento que estão armazenados em disco
void ler_dados_movi(tipolista_movi *M);
//Função que ira gravar os dados do meu movimento em um arquivo
void gravar_movimento(tipolista_movi *M);
#endif