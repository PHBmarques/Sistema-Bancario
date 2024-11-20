/*
Autor: Pedro Henrique Bernardo Marques
Data: 04/11/2024
Equipe: RA: 173342-2024
        RA: 179427-2024
Obj: Função que ira verificar se a data inserida é menor que a data já cadastrada
*/
#include "funcoes.h"
//Converte data no formato DD/MM/AAA para AAAMMDD
int DataparaNumero(char *data){
    int dia;
    int mes;
    int ano;
    sscanf(data,"%d/%d/%d",&dia,&mes,&ano);
    return(ano *1000) + (mes * 100) +dia;
}
//função para ler uma data e verificar a validade
char *lerData(tipolista_movi *M){
    static char data[11];
    int datanova;
    int dataultima;
    //leitura da data
    gotoxy(7,24);
    printf("Data de Movimento (DD/MM/AAA)");
    gotoxy(33,16);
    scanf("%s",data);
    //converte data para o formato numerico
    datanova=DataparaNumero(data);
    //verifica se a lista já tem movimentação
    if(M->ultimo !=NULL){
        //obtem a ultima data da lista
        dataultima=DataparaNumero(M->ultimo->conteudo.dt_movimento);
        //verifica se a nova data é menor que a ultima
        if(datanova<dataultima){
            gotoxy(7,24);
            printf("A %s e menor que a ultima data cadastrada %s!",data,M->ultimo->conteudo.dt_movimento);
            //retorna NULL se a data for invalida
            return NULL;
        }
    }
    //se tudo estiver certo, retorna a data lida
    return data;
}