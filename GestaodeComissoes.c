/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GestaodeComissoes.c
 * Author: Leonardo
 *
 * Created on 11 de fevereiro de 2023, 19:02
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GestaodeComissoes.h"
#include "AuxiliarGestaoComissoes.h"
#include "Input.h"
#include "Tools.h"

/**
 * Funcao para carregar os dados guardados dentro de um ficheiro relativo as 
 * comissoes
 * @param comissoes
 * @param vendedores
 * @param ficheiro
 */
void carregarComissoes(Comissoes *comissoes, Vendedores *vendedores, char *ficheiro) {
    int i, j;

    FILE *fp = fopen(ficheiro, "rb");
    if (fp != NULL) {

        fread(&comissoes->contador, sizeof (int), 1, fp);

        if (comissoes->contador > 0) {
            comissoes->tamanho = comissoes->contador;
            comissoes->comissoes = (Comissao*) malloc(comissoes->contador * sizeof (Comissao));

            for (i = 0; i < comissoes->contador; i++) {
                fread(&comissoes->comissoes[i], sizeof (Comissao), 1, fp);
                
                comissoes->comissoes[i].tam_vend = comissoes->comissoes[i].cont_vend;                
                comissoes->comissoes[i].quant_vend =
                        (Quant_vend*) calloc(comissoes->comissoes[i].cont_vend, sizeof (Quant_vend));

                for (j = 0; j < comissoes->comissoes[i].cont_vend; j++) {
                                       
                    fread(&comissoes->comissoes[i].quant_vend[j].codigo_vend, sizeof (int), 1, fp);
                    fread(&comissoes->comissoes[i].quant_vend[j].data_registo, sizeof (Data), 1, fp);
                    fread(&comissoes->comissoes[i].quant_vend[j].data_fim, sizeof (Data), 1, fp);
                    fread(&comissoes->comissoes[i].quant_vend[j].percent_comissoes, sizeof (int), 1, fp);
                }
            }
        }
        fclose(fp);
    }
}

/**
 * Funcao para guardar os dados relativos as comissoes dentro de um ficheiro
 * @param comissoes
 * @param vendedores
 * @param ficheiro
 */
void guardarComissoes(Comissoes *comissoes, Vendedores *vendedores, char *ficheiro) {
    int i, j;

    FILE *fp = fopen(ficheiro, "wb");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }

    fwrite(&comissoes->contador, sizeof (int), 1, fp);

    for (i = 0; i < comissoes->contador; i++) {
        fwrite(&comissoes->comissoes[i], sizeof (Comissao), 1, fp);

        for (j = 0; j < comissoes->comissoes[i].cont_vend; j++) {

            fwrite(&comissoes->comissoes[i].quant_vend[j].codigo_vend, sizeof (int), 1, fp);
            fwrite(&comissoes->comissoes[i].quant_vend[j].data_registo, sizeof (Data), 1, fp);
            fwrite(&comissoes->comissoes[i].quant_vend[j].data_fim, sizeof (Data), 1, fp);
            fwrite(&comissoes->comissoes[i].quant_vend[j].percent_comissoes, sizeof (int), 1, fp);

        }
    }

    fclose(fp);
}

/**
 * Funcao para limpar a memoria que nao e necessaria
 * @param comissoes
 */
void libertarComissoes(Comissoes *comissoes) {
    if (comissoes->comissoes) {
        free(comissoes->comissoes);
        comissoes->comissoes = NULL;
    }

    comissoes = NULL;
}

/**
 * Funcao para inserir uma comissao
 * @param comissoes
 * @param vendedores
 * @param mercados
 * @return 
 * comissoes->contador++ se adicionar uma comissao sem problemas, retorna
 * n_comissao se apenas adicionar um vendedor a um mercado e -1 se nao funcionar
 */
int inserirComissao(Comissoes *comissoes, Vendedores *vendedores,
        Mercados *mercados) {
    int codvend, codmercado, mostrarcodigo = 1, i = 0, n_comissao, j = 0;
    int pos_vend, pos_comissao;

    printf("------------------Mercados----------------");
    listarMercados(mercados, mostrarcodigo);

    codmercado = obterInt(MIN_CODIGO_MERCADO, MAX_CODIGO_MERCADO, MSG_OBTER_CODIGO_MERCADO);

    if ((n_comissao = procurarComissao(comissoes, codmercado)) == -1) {
        n_comissao = comissoes->contador;

        if (verificarEstadoMercado(mercados, codmercado) != -1) {

            adicionarmemoria_vend(comissoes, vendedores);
            comissoes->comissoes[comissoes->contador].codigoMercado = codmercado;

            printf("-------------------Vendedores-----------------");
            listarVendedores(vendedores, mostrarcodigo);
            codvend = obterInt(MIN_CODIGO, MAX_CODIGO, MSG_OBTER_CODIGO);

            if (verificarEstadoVend(vendedores, codvend) != -1) {
                inserirDataRegisto(&comissoes->comissoes[comissoes->contador].
                        quant_vend[comissoes->comissoes[comissoes->contador].cont_vend].data_registo.dia,
                        &comissoes->comissoes[comissoes->contador].
                        quant_vend[comissoes->comissoes[comissoes->contador].cont_vend].data_registo.mes,
                        &comissoes->comissoes[comissoes->contador].
                        quant_vend[comissoes->comissoes[comissoes->contador].cont_vend].data_registo.ano);

                procurar_vendcomissao(comissoes, codvend, &pos_vend, &pos_comissao);

                if (pos_vend == -1) {
                    pos_vend = comissoes->comissoes[comissoes->contador].cont_vend;
                    pos_comissao = comissoes->contador;
                }
                if (compararDatas(comissoes, &comissoes->comissoes[comissoes->contador].
                        quant_vend[pos_vend].data_registo,
                        &comissoes->comissoes[pos_comissao].
                        quant_vend[pos_vend].data_fim, n_comissao, codvend) > 0) {

                    comissoes->comissoes[comissoes->contador].
                            quant_vend[pos_vend].codigo_vend = codvend;

                    comissoes->comissoes[comissoes->contador].quant_vend[pos_vend].percent_comissoes =
                            obterInt(MIN_PERCENT_COMISSAO, MAX_PERCENT_COMISSAO, MSG_OBTER_PERCENT_COMISSAO);

                    inserirDataFim(&comissoes->comissoes[comissoes->contador].
                            quant_vend[pos_vend].data_fim.dia,
                            &comissoes->comissoes[comissoes->contador].
                            quant_vend[pos_vend].data_fim.mes,
                            &comissoes->comissoes[comissoes->contador].
                            quant_vend[pos_vend].data_fim.ano);

                } else {
                    puts(ERRO_VENDEDOR_ATRIBUIDO_MERCADO);
                }

            } else if (codvend != 0) {
                puts(ERRO_VENDEDOR_INATIVO);
            }

            comissoes->comissoes[comissoes->contador].cont_vend++;

            return comissoes->contador++;

        } else {
            puts(ERRO_MERCADO_INATIVO);
        }
    } else {
        adicionarVendedores(comissoes, vendedores, n_comissao, mostrarcodigo);
        
        return comissoes->comissoes[n_comissao].cont_vend++;

    }
    return -1;
}

/**
 * Funcao para aumentar a memoria dinamica atribuida as comissoes
 * @param comissoes
 */
void expandirComissoes(Comissoes *comissoes) {
    int tam = (comissoes->tamanho) == 0 ? COMISSOES_TAM_INICIAL : comissoes->tamanho * 2;
    Comissao *temp = (Comissao*) realloc(comissoes->comissoes, sizeof (Comissao) * (tam));
    if (temp != NULL) {
        comissoes->tamanho = tam;
        comissoes->comissoes = temp;
    }
}

/**
 * Funcao para validar a insercao de uma comissao
 * @param comissoes
 * @param vendedores
 * @param mercados
 */
void inserirComissoes(Comissoes *comissoes, Vendedores *vendedores, Mercados *mercados) {
    if (comissoes->contador == comissoes->tamanho) {
        expandirComissoes(comissoes);
    }

    if (comissoes->contador < comissoes->tamanho) {
        if (inserirComissao(comissoes, vendedores, mercados) == -1) {
            puts(ERRO_COMISSAO_EXISTE);
        }
    } else {
        puts(ERRO_LISTA_COMISSOES_CHEIA);
    }
}

/**
 * Funcao para verificar se existe a comissao que se procura
 * @param comissoes
 * @param vendedores
 * @param mercados
 */
void procurarComissoes(Comissoes *comissoes, Vendedores *vendedores,
        Mercados *mercados) {
    int codigo = procurarComissao(comissoes,
            obterInt(MIN_CODIGO_MERCADO, MAX_CODIGO_MERCADO, MSG_OBTER_CODIGO_MERCADO));

    if (codigo != -1) {
        imprimirComissao(&comissoes->comissoes[codigo], vendedores, mercados);
    } else {
        puts(ERRO_COMISSAO_NAO_EXISTE);
    }
}

/**
 * Funcao para listar todas as comissoes existentes
 * @param comissoes
 * @param vendedores
 * @param mercados
 */
void listarComissoes(Comissoes *comissoes, Vendedores *vendedores,
        Mercados *mercados) {
    int i;
    if (comissoes->contador > 0) {
        for (i = 0; i < comissoes->contador; i++) {
            imprimirComissao((&comissoes->comissoes[i]), vendedores, mercados);
        }
    } else {
        puts(ERRO_LISTA_COMISSOES_VAZIA);
    }
}

/**
 * Funcao para remover Mercados
 * @param mercados
 * @param comissoes
 */
void removerMercados(Mercados *mercados, Comissoes *comissoes) {
    int i, j, senha, codigo = obterInt(MIN_CODIGO_MERCADO, MAX_CODIGO_MERCADO, MSG_OBTER_CODIGO_MERCADO);

    senha = procurarMercado(mercados, codigo);

    for (i = 0; i < comissoes->contador; i++) {
        if (comissoes->comissoes[i].codigoMercado == codigo) {
            puts("Nao e possivel remover o departamento portanto ficara inativo!");
            strlcpy(mercados->mercados[senha].estado, "INATIVO", MAX_ESTADO_MERCADO);
        }
    }
    if (strcmp(mercados->mercados[senha].estado, "INATIVO") != 0) {
        for (j = codigo; j < mercados->contador - 1; j++) {
            mercados->mercados[j] = mercados->mercados[j + 1];
        }

        apagarDadosMercado(&mercados->mercados[j]);
        mercados->contador--;

    }
    if (senha == -1) {
        puts(ERRO_MERCADO_NAO_EXISTE);
    }

}

/**
 * Funcao para remover vendedores
 * @param vendedores
 * @param comissoes
 */
void removerVendedores(Vendedores *vendedores, Comissoes *comissoes) {
    int i, j, k, senha, codigo = obterInt(MIN_CODIGO_VEND, MAX_CODIGO_VEND, MSG_OBTER_CODIGO_VEND);

    senha = procurarVendedor(vendedores, codigo);

    for (i = 0; i < comissoes->contador; i++) {
        for (j = 0; j < comissoes->comissoes[i].cont_vend; j++) {
            if (comissoes->comissoes[i].quant_vend[j].codigo_vend == codigo) {
                puts("Nao e possivel remover o funcionario portanto ficara inativo!");
                strlcpy(vendedores->vendedores[senha].estado, "INATIVO", MAX_ESTADO_VEND);

            }
        }
    }
    if (strcmp(vendedores->vendedores[senha].estado, "INATIVO") != 0) {
        for (k = senha; k < vendedores->contador - 1; k++) {
            vendedores->vendedores[k] = vendedores->vendedores[k + 1];
        }

        apagarDadosVendedor(&vendedores->vendedores[k]);
        vendedores->contador--;

    }
    if (senha == -1) {
        puts(ERRO_VENDEDOR_NAO_EXISTE);
    }
}

