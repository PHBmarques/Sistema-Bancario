/*
Autor: Pedro Henrique Bernardo Marques
Data: 04/11/2024
Equipe: RA: 173342-2024
        RA: 179427-2024
Obj: Verifica se a conta esta ativa ou inativa
*/
#include"funcoes.h"
int verificar_status(infocontas ContaBAncaria){
    if(ContaBAncaria.vl_saldo>0 ){
        return 1;//A conta esta ativada
    }else{
        return 0;//A conta esta inativa
    }
}