/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GestaodeVendedores.h
 * Author: Leonardo
 *
 * Created on 11 de fevereiro de 2023, 17:55
 */

#ifndef GESTAODEVENDEDORES_H
#define GESTAODEVENDEDORES_H

#define MAX_CODIGO_VEND 1000
#define MIN_CODIGO_VEND 1
#define MSG_OBTER_CODIGO_VEND "Digite o seu codigo de vendedor: "

#define MAX_NOME_VEND 101
#define MSG_OBTER_NOME_VEND "Digite o seu nome: "

#define MAX_NUM_TELEF 999999999
#define MIN_NUM_TELEF 100000000
#define MSG_OBTER_TELEF "Digite o seu numero de telefone: "

#define MAX_EMAIL 101
#define MSG_OBTER_EMAIL "Digite o seu email: "

#define MAX_ESTADO_VEND 11

#define ERRO_VENDEDOR_EXISTE "O vendedor já existe."
#define ERRO_VENDEDOR_NAO_EXISTE "O vendedor não existe na lista."

#define ERRO_LISTA_CHEIA     "A lista de vendedores está cheia."
#define ERRO_LISTA_VAZIA     "A lista de vendedores está vazia."

#define VEND_TAM_INICIAL 10

typedef struct{
    int codigo_vend;
    char nome[MAX_NOME_VEND];
    int telefone;
    char email[MAX_EMAIL];  
    char estado[MAX_ESTADO_VEND];
}Vendedor;

typedef struct{
    int contador, tamanho;
    Vendedor *vendedores;
}Vendedores;

void memoriaVendedores(Vendedores *vendedores);
void guardarVendedores(Vendedores *vendedores, char *ficheiro);
void carregarVendedores(Vendedores *vendedores, char *ficheiro);

void inserirVendedores(Vendedores *vendedores);
void procurarVendedores(Vendedores *vendedores, int mostrarcodigo);
void atualizarVendedores(Vendedores *vendedores);
void listarVendedores(Vendedores *vendedores, int mostrarcodigo);
void libertarVendedores(Vendedores *vendedores);

int verificarEstadoVend(Vendedores *vendedores, int codigo);
int procurarVendedor(Vendedores *vendedores, int codigo);
void apagarDadosVendedor(Vendedor *vendedor);
void imprimirVendedor(Vendedor *vendedor, int mostrarcodigo);



#endif /* GESTAODEVENDEDORES_H */

