/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GestaodeComissoes.h
 * Author: Leonardo
 *
 * Created on 11 de fevereiro de 2023, 19:02
 */

#ifndef GESTAODECOMISSOES_H
#define GESTAODECOMISSOES_H

#include "GestaodeVendedores.h"
#include "GestaodeMercados.h"

#define MIN_CODIGO 0
#define MAX_CODIGO 1000
#define MSG_OBTER_CODIGO "\nDigite o codigo de vendedor (Aperte 0 para sair): "

#define MIN_PERCENT_COMISSAO 0
#define MAX_PERCENT_COMISSAO 100
#define MSG_OBTER_PERCENT_COMISSAO "Digite a percentagem de comissao desejada (0 a 100): "

#define ERRO_VENDEDOR_ATRIBUIDO_MERCADO "O vendedor ja se encontra atribuido ao mercado."

#define ERRO_VENDEDOR_INATIVO "O vendedor encontra-se inativo."
#define ERRO_MERCADO_INATIVO "O mercado encotra-se inativo."

#define ERRO_COMISSAO_EXISTE "A comissao ja existe."
#define ERRO_COMISSAO_NAO_EXISTE "A comissao nao existe"

#define ERRO_LISTA_COMISSOES_CHEIA "A lista de comissoes esta cheia."
#define ERRO_LISTA_COMISSOES_VAZIA "A lista de comissoes esta vazia"

#define COMISSOES_TAM_INICIAL 20

typedef struct{
    int dia, mes, ano;
}Data;

typedef struct{
    int codigo_vend;
    int percent_comissoes;
    Data data_registo;
    Data data_fim;
}Quant_vend;

typedef struct{
    int codigoMercado;
    int tam_vend, cont_vend; 
    Quant_vend *quant_vend;
}Comissao;

typedef struct{
    int contador, tamanho;
    Comissao *comissoes;
}Comissoes;

void memoriaComissoes(Comissoes *comissoes);
void carregarComissoes(Comissoes *comissoes, Vendedores *vendedores, char *ficheiro);
void guardarComissoes(Comissoes *comissoes, Vendedores *vendedores, char *ficheiro);

void inserirComissoes(Comissoes *comissoes, Vendedores *vendedores, Mercados *mercados);
void procurarComissoes(Comissoes *comissoes, Vendedores *vendedores, Mercados *mercados);
void listarComissoes(Comissoes *comissoes, Vendedores *vendedores, Mercados *mercados);
void libertarComissoes(Comissoes *comissoes);

void removerMercados(Mercados *mercados, Comissoes *comissoes);
void removerVendedores(Vendedores *vendedores, Comissoes *comissoes);

#endif /* GESTAODECOMISSOES_H */

