/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Mercados.c
 * Author: Leonardo
 *
 * Created on 11 de fevereiro de 2023, 18:32
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GestaodeMercados.h"
#include "Input.h"

/**
 * Funcao para imprimir os dados de um mercado
 * @param mercado
 * @param mostrarcodigo
 */
void imprimirMercado(Mercado *mercado, int mostrarcodigo) {
    if (mostrarcodigo == 0) {
        printf("\n************Mercado******************");
        printf("\nCodigo: %d\nNome: %s\nEstado: %s", mercado->codigo_mercado,
                mercado->nome, mercado->estado);
        printf("\n*******************************\n");
    } else {
        printf("\nCodigo: %d | Nome: %s | Estado: %s", mercado->codigo_mercado,
                mercado->nome, mercado->estado);
    }
}

/**
 * Funcao para apagar os dados atribuidos a um mercado
 * @param mercado
 */
void apagarDadosMercado(Mercado *mercado) {
    mercado->codigo_mercado = 0;
    strcpy(mercado->nome, "");
    strcpy(mercado->estado, "");

}

/**
 * Funcao para carregar os dados de um ficheiro relativos ao mercado
 * @param mercados
 * @param ficheiro
 */
void carregarMercados(Mercados *mercados, char *ficheiro) {
    int i;

    FILE *fp = fopen(ficheiro, "rb");
    if (fp != NULL) {

        fread(&mercados->contador, sizeof (int), 1, fp);

        if (mercados->contador > 0) {
            mercados->tamanho = mercados->contador;
            mercados->mercados = (Mercado*) malloc(mercados->contador * sizeof (Mercado));
            for (i = 0; i < mercados->contador; i++) {
                fread(&mercados->mercados[i], sizeof (Mercado), 1, fp);
            }
        }
        fclose(fp);
    }
}

/**
 * Funcao para atribuir memoria aos mercados
 * @param mercados
 */
void memoriaMercados(Mercados *mercados) {

    mercados->mercados = (Mercado*) malloc(MERCADO_TAM_INICIAL * sizeof (Mercado));
    mercados->contador = 0;
    mercados->tamanho = MERCADO_TAM_INICIAL;
}

/**
 * Funcao para guardar os dados relativos aos mercados dentro de um ficheiro
 * @param mercados
 * @param ficheiro
 */
void guardarMercados(Mercados *mercados, char *ficheiro) {
    int i;

    FILE *fp = fopen(ficheiro, "wb");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }

    fwrite(&mercados->contador, sizeof (int), 1, fp);

    for (i = 0; i < mercados->contador; i++) {
        fwrite(&mercados->mercados[i], sizeof (Mercado), 1, fp);
    }

    fclose(fp);
}

/**
 * Funcao para procurar um mercado existente
 * @param mercados
 * @param codigo
 * @return 
 * Retorna -1 se nao existir o mercado e i se existir o mercado
 */
int procurarMercado(Mercados *mercados, int codigo) {
    int i;
    for (i = 0; i < mercados->contador; i++) {
        if (mercados->mercados[i].codigo_mercado == codigo) {
            return i;
        }
    }

    return -1;
}

/**
 * Funcao para verificar o estado do mercado
 * @param mercados
 * @param codigo
 * @return 
 * Retorna -1 se estiver inativo e i se estiver ativo
 */
int verificarEstadoMercado(Mercados *mercados, int codigo){
    int i;
    for (i = 0; i < mercados->contador; i++) {
        if (mercados->mercados[i].codigo_mercado == codigo && 
                strcmp(mercados->mercados[i].estado, "ATIVO") == 0) {
            return i;
        }
    }

    return -1;
}

/**
 * Funcao para libertar a memoria atribuida dinamicamente aos mercados
 * @param mercados
 */
void libertarMercados(Mercados *mercados) {
    if (mercados->mercados) {
        free(mercados->mercados);
        mercados->mercados = NULL;
    }

    mercados = NULL;
}

/**
 * Funcao para inserir os dados de um mercado
 * @param mercados
 * @return 
 * Retorna -1 se o mercado ja existir e retorna mercados->contador++ se o 
 * mercado nao existir
 */
int inserirMercado(Mercados *mercados) {
    int codigo;

    codigo = obterInt(MIN_CODIGO_MERCADO, MAX_CODIGO_MERCADO, MSG_OBTER_CODIGO_MERCADO);

    if (procurarMercado(mercados, codigo) == -1) {

        mercados->mercados[mercados->contador].codigo_mercado = codigo;

        lerString(mercados->mercados[mercados->contador].nome,
                MAX_NOME_MERCADO, MSG_OBTER_NOME_MERCADO);

        strlcpy(mercados->mercados[mercados->contador].estado, "ATIVO", MAX_ESTADO_MERCADO);

        return mercados->contador++;
    }

    return -1;
}

/**
 * Funcao para atualizar os dados do mercado
 * @param mercado
 */
void atualizarMercado(Mercado *mercado) {
    lerString((*mercado).nome, MAX_NOME_MERCADO, MSG_OBTER_NOME_MERCADO);
    //strlcpy((*mercado).estado, "ATIVO", MAX_ESTADO_MERCADO);
}

/**
 * Funcao para expandir a memoria dada aos mercados quando atinge o limite 
 * atribuido
 * @param mercados
 */
void expandirMercados(Mercados *mercados) {
    int tam = (mercados->tamanho) == 0 ? MERCADO_TAM_INICIAL : mercados->tamanho * 2;
    Mercado *temp = (Mercado*) realloc(mercados->mercados, sizeof (Mercado) * (tam));
    if (temp != NULL) {
        mercados->tamanho = tam;
        mercados->mercados = temp;
    }
}

/**
 * Funcao para validar a insercao de um mercado
 * @param mercados
 */
void inserirMercados(Mercados *mercados) {
    if (mercados->contador == mercados->tamanho) {
        expandirMercados(mercados);
    }

    if (mercados->contador < mercados->tamanho) {
        if (inserirMercado(mercados) == -1) {
            puts(ERRO_MERCADO_EXISTE);
        }
    } else {
        puts(ERRO_LISTA_MERCADOS_CHEIA);
    }
}

/**
 * Funcao para verificar se existe o mercado que se procura
 * @param mercados
 * @param mostrarcodigo
 */
void procurarMercados(Mercados *mercados, int mostrarcodigo) {
    int codigo = procurarMercado(mercados,
            obterInt(MIN_CODIGO_MERCADO, MAX_CODIGO_MERCADO, MSG_OBTER_CODIGO_MERCADO));

    if (codigo != -1) {
        imprimirMercado(&mercados->mercados[codigo], mostrarcodigo);
    } else {
        puts(ERRO_MERCADO_NAO_EXISTE);
    }
}

/**
 * Funcao para verificar se existe o mercado que se quer atualizar
 * @param mercados
 */
void atualizarMercados(Mercados *mercados) {
    int codigo = procurarMercado(mercados, obterInt(MIN_CODIGO_MERCADO, MAX_CODIGO_MERCADO, MSG_OBTER_CODIGO_MERCADO));

    if (codigo != -1) {
        atualizarMercado(&(*mercados).mercados[codigo]);

    } else {
        puts(ERRO_MERCADO_NAO_EXISTE);
    }
}

/**
 * Funcao para listar todos os mercados existentes
 * @param mercados
 * @param mostrarcodigo
 */
void listarMercados(Mercados *mercados, int mostrarcodigo) {
    int i;
    if (mercados->contador > 0) {
        for (i = 0; i < mercados->contador; i++) {
            imprimirMercado(&mercados->mercados[i], mostrarcodigo);
        }
    } else {
        puts(ERRO_LISTA_MERCADOS_VAZIA);
    }
}

