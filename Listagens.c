/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Listagens.c
 * Author: Leonardo
 *
 * Created on 11 de fevereiro de 2023, 17:54
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GestaodeComissoes.h"
#include "GestaodeMercados.h"
#include "AuxiliarGestaoComissoes.h"
#include "Listagens.h"
#include "Input.h"

/**
 * Funcao para ordenar os mercados de forma decrescente da quant_vend
 * @param comissoes
 * @param mercados
 * @param mercado
 */
void ordenarMercados(Comissoes *comissoes, Mercados *mercados, int *mercado) {
    int i, j, temp;

    for (i = 0; i < mercados->contador; i++) {
        mercado[i] = i; // inicializa o array de índices com os valores de 0 a tamanho-1
    }

    for (i = 0; i < comissoes->contador - 1; i++) {
        for (j = i + 1; j < comissoes->contador; j++) {
            if (comissoes->comissoes[i].cont_vend < comissoes->comissoes[j].cont_vend) {

                temp = mercado[i];
                mercado[i] = mercado[j];
                mercado[j] = temp;
            }

        }
    }
}

/**
 * Funcao para listar os mercados de forma decrescente da quant_vend existentes
 * @param comissoes
 * @param mercados
 */
void listarRankingMercados(Comissoes *comissoes, Mercados *mercados) {
    int mostrarcodigo = 1, i;
    int mercado[mercados->contador];
    ordenarMercados(comissoes, mercados, mercado);
    printf("Mercados em funcao da sua popularidade:");
    for (i = 0; i < mercados->contador; i++) {
        imprimirMercado(&mercados->mercados[mercado[i]], mostrarcodigo);
    }

}

/**
 * Funcao que lista quais os mercados que estao ativos
 * @param mercados
 */
void listarMercadosAtivos(Mercados *mercados) {
    int i, mostrarcodigo = 1;
    for (i = 0; i < mercados->contador; i++) {
        if (strcmp(mercados->mercados[i].estado, "ATIVO") == 0) {
            imprimirMercado(&mercados->mercados[i], mostrarcodigo);
        }
    }
}

/**
 * Funcao para listar os vendedores que estao ativos dentro de um mercado
 * @param comissoes
 * @param vendedores
 * @param mercados
 */
void listarVendedoresAtivosMercado(Comissoes *comissoes, Vendedores *vendedores, Mercados *mercados) {
    int i, j, mostrarcodigo = 1, mercado;
    mercado = obterInt(MIN_CODIGO_MERCADO, MAX_CODIGO_MERCADO, MSG_OBTER_CODIGO_MERCADO);
     
    if((mercado = procurarComissao(comissoes, mercado )) != -1){
        imprimirMercadoComissao(&comissoes->comissoes[mercado], mercados);
    for (i = 0; i < comissoes->comissoes[mercado].cont_vend; i++) {
        for (j = 0; j < vendedores->contador; j++) {
            if (comissoes->comissoes[mercado].quant_vend[i].codigo_vend == vendedores->vendedores[j].codigo_vend) {
                if (strcmp(vendedores->vendedores[i].estado, "ATIVO") == 0) {
                    imprimirVendedor(&vendedores->vendedores[j], mostrarcodigo);
                }
            }
        }
    }
    }else{
        puts(ERRO_MERCADO_NAO_EXISTE);
    }
}

