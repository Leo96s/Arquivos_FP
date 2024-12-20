/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mercados.h
 * Author: Leonardo
 *
 * Created on 11 de fevereiro de 2023, 18:32
 */

#ifndef MERCADOS_H
#define MERCADOS_H

#define MAX_CODIGO_MERCADO 1000
#define MIN_CODIGO_MERCADO 1
#define MSG_OBTER_CODIGO_MERCADO "\nDigite o codigo do mercado: "

#define MAX_NOME_MERCADO 101
#define MSG_OBTER_NOME_MERCADO "Digite o nome do mercado: "

#define ERRO_MERCADO_EXISTE "O mercado ja existe."
#define ERRO_MERCADO_NAO_EXISTE "O mercado nao existe."

#define ERRO_LISTA_MERCADOS_VAZIA "A lista de marcados encontra-se vazia."
#define ERRO_LISTA_MERCADOS_CHEIA "A lista de marcados encontra-se cheia."

#define MERCADO_TAM_INICIAL 12

#define MAX_ESTADO_MERCADO 11

typedef struct{
    int codigo_mercado;
    char nome[MAX_NOME_MERCADO];
    char estado[MAX_ESTADO_MERCADO];
}Mercado;

typedef struct{
    int contador, tamanho;
    Mercado *mercados;
}Mercados;

void memoriaMercados(Mercados *mercados);
void guardarMercados(Mercados *mercados, char *ficheiro);
void carregarMercados(Mercados *mercados, char *ficheiro);

void inserirMercados(Mercados *mercados);
void procurarMercados(Mercados *mercados, int mostrarcodigo);
void atualizarMercados(Mercados *mercados);
void listarMercados(Mercados *mercados, int mostrarcodigo);
void libertarMercados(Mercados *mercados);

int verificarEstadoMercado(Mercados *mercados, int codigo);
int procurarMercado(Mercados *mercados, int codigo);
void apagarDadosMercado(Mercado *mercado);
void imprimirMercado(Mercado *mercado, int mostrarcodigo);

#endif /* MERCADOS_H */

