/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   AuxiliarGestaoComissoes.c
 * Author: Leonardo
 *
 * Created on 18 de fevereiro de 2023, 19:21
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GestaodeComissoes.h"
#include "GestaodeVendedores.h"
#include "Tools.h"
#include "Input.h"
#include "AuxiliarGestaoComissoes.h"

/**
 * Funcao para impirimir os dados relativos as comissoes
 * @param comissao
 * @param vendedores
 * @param mercados
 */
void imprimirComissao(Comissao *comissao, Vendedores *vendedores, Mercados *mercados) {
    int i, j, k;
    printf("\n**************Comissao*******************\n");
    for (k = 0; k < mercados->contador; k++) {
        if (mercados->mercados[k].codigo_mercado ==
                comissao->codigoMercado) {
            printf("Codigo Mercado: %d\nNome Mercado: %s",
                    mercados->mercados[k].codigo_mercado,
                    mercados->mercados[k].nome);

            printf("\nVendedores associados:");
            for (i = 0; i < vendedores->contador; i++) {
                for (j = 0; j < comissao->cont_vend; j++) {
                    if (vendedores->vendedores[i].codigo_vend ==
                            comissao->quant_vend[j].codigo_vend) {
                        printf("\nDe[%02d / %02d / %d] ate [%02d / %02d / %d]\t",
                                comissao->quant_vend[j].data_registo.dia,
                                comissao->quant_vend[j].data_registo.mes,
                                comissao->quant_vend[j].data_registo.ano,
                                comissao->quant_vend[j].data_fim.dia,
                                comissao->quant_vend[j].data_fim.mes,
                                comissao->quant_vend[j].data_fim.ano);
                        printf("\nCodigo Vendedor: %d | Nome Vendedor: %s\nPercentagem de Comissao: %d %%"
                                "\nEstado: %s",
                                vendedores->vendedores[i].codigo_vend,
                                vendedores->vendedores[i].nome, comissao->quant_vend[j].percent_comissoes,
                                vendedores->vendedores[i].estado);
                    }
                }
            }
        }
    }
    printf("\n*********************************\n");
}

/**
 * Imprimir mercado da comissao
 * @param comissao
 * @param mercados
 */
void imprimirMercadoComissao(Comissao *comissao, Mercados *mercados) {
    int i;
    for (i = 0; i < mercados->contador; i++) {
        if (mercados->mercados[i].codigo_mercado ==
                comissao->codigoMercado) {
            printf("Codigo Mercado: %d\nNome Mercado: %s",
                    mercados->mercados[i].codigo_mercado,
                    mercados->mercados[i].nome);
        }
    }
}

/**
 * Funcao para atribuir memoria dinamica as comissoes
 * @param comissoes
 */
void memoriaComissoes(Comissoes *comissoes) {

    comissoes->comissoes = (Comissao*) malloc(COMISSOES_TAM_INICIAL * sizeof (Comissao));
    comissoes->contador = 0;
    comissoes->tamanho = COMISSOES_TAM_INICIAL;
}

/**
 * Funcao para atribuir memoria dinamica aos vendedores
 * @param comissoes
 * @param vendedores
 */
void adicionarmemoria_vend(Comissoes *comissoes, Vendedores *vendedores) {
    comissoes->comissoes[comissoes->contador].quant_vend = (Quant_vend*)
            calloc(vendedores->contador, sizeof (Quant_vend));
    comissoes->comissoes[comissoes->contador].tam_vend = vendedores->contador;
    comissoes->comissoes[comissoes->contador].cont_vend = 0;
}

/**
 * Funcao para procurar uma comissao existente
 * @param comissoes
 * @param codigo
 * @return
 * Retorna -1 se nao existir a comissao e i se existir comissao
 */
int procurarComissao(Comissoes *comissoes, int codigo) {
    int i;
    for (i = 0; i < comissoes->contador; i++) {
        if (comissoes->comissoes[i].codigoMercado == codigo) {
            return i;
        }
    }
    return -1;

}

/**
 * Funcao para procurar um vendedor dentro das comissoes
 * @param comissoes
 * @param codigo
 * @param pos_vend
 * @param pos_comissao
 */
void procurar_vendcomissao(Comissoes *comissoes, int codigo, int *pos_vend,
        int *pos_comissao) {
    int i, j;
    *pos_vend = -1;
    *pos_comissao = -1;
    for (i = 0; i < comissoes->contador + 1; i++) {
        for (j = 0; j < comissoes->comissoes[i].cont_vend; j++) {
            if (comissoes->comissoes[i].quant_vend[j].codigo_vend == codigo) {
                *pos_vend = j;
                *pos_comissao = i;
            }
        }
    }
}

/**
 * Funcao para expandir a memoria da quantidade de vendedores
 * @param comissoes
 * @param vendedores
 * @param n_comissao
 */
void expandir_mem_vend(Comissoes *comissoes, Vendedores *vendedores, int n_comissao) {
    int tam = (comissoes->comissoes[n_comissao].tam_vend) == 0 ?
            vendedores->contador : comissoes->comissoes[n_comissao].cont_vend * 2;
    Quant_vend *temp = (Quant_vend*) realloc(comissoes->comissoes[n_comissao].quant_vend, sizeof (Quant_vend) * (tam));
    if (temp != NULL) {
        comissoes->comissoes[n_comissao].tam_vend = tam;
        comissoes->comissoes[n_comissao].quant_vend = temp;
    }
}

/**
 * Funcao para adicionar vendedores a uma comissao ja existente
 * @param comissoes
 * @param vendedores
 * @param n_comissao
 * @param mostrarcodigo
 */
void adicionarVendedores(Comissoes *comissoes, Vendedores *vendedores,
        int n_comissao, int mostrarcodigo) {
    int codvend, pos_vend, pos_comissao, i;

    if (comissoes->comissoes[n_comissao].cont_vend == comissoes->comissoes[n_comissao].tam_vend) {
        expandir_mem_vend(comissoes, vendedores, n_comissao);
    }
    puts("----------------------Vendedores-------------------");
    listarVendedores(vendedores, mostrarcodigo);
    codvend = obterInt(MIN_CODIGO, MAX_CODIGO, MSG_OBTER_CODIGO);

    if (verificarEstadoVend(vendedores, codvend) != -1) {
        inserirDataRegisto(&comissoes->comissoes[n_comissao].
                quant_vend[comissoes->comissoes[n_comissao].cont_vend].data_registo.dia,
                &comissoes->comissoes[n_comissao].
                quant_vend[comissoes->comissoes[n_comissao].cont_vend].data_registo.mes,
                &comissoes->comissoes[n_comissao].
                quant_vend[comissoes->comissoes[n_comissao].cont_vend].data_registo.ano);

        procurar_vendcomissao(comissoes, codvend, &pos_vend, &pos_comissao);

        if (pos_vend == -1) {
            pos_vend = comissoes->comissoes[n_comissao].cont_vend;
            pos_comissao = comissoes->contador;
        }

        if (compararDatas(comissoes, &comissoes->comissoes[n_comissao].
                quant_vend[pos_vend].data_registo,
                &comissoes->comissoes[pos_comissao].
                quant_vend[pos_vend].data_fim, n_comissao, codvend) > 0) {

            comissoes->comissoes[n_comissao].quant_vend[pos_vend].codigo_vend = codvend;

            comissoes->comissoes[n_comissao].quant_vend[pos_vend].percent_comissoes =
                    obterInt(MIN_PERCENT_COMISSAO, MAX_PERCENT_COMISSAO, MSG_OBTER_PERCENT_COMISSAO);

            inserirDataFim(&comissoes->comissoes[n_comissao].
                    quant_vend[pos_vend].data_fim.dia,
                    &comissoes->comissoes[n_comissao].
                    quant_vend[pos_vend].data_fim.mes,
                    &comissoes->comissoes[n_comissao].
                    quant_vend[pos_vend].data_fim.ano);

        } else {
            puts(ERRO_VENDEDOR_ATRIBUIDO_MERCADO);
        }

    } else if (codvend != 0) {
        puts(ERRO_VENDEDOR_INATIVO);
    }

}

