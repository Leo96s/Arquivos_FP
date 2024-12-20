/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Auxilio.c
 * Author: Leonardo
 *
 * Created on 14 de fevereiro de 2023, 23:45
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "GestaodeComissoes.h"

/**
 * Funcao para inserir a data de registo a um vendedor
 * @param comissoes
 * @param i
 * @param n_comissao
 */
void inserirDataRegisto(int *dia, int *mes, int *ano) {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    *dia = tm->tm_mday;
    *mes = tm->tm_mon + 1;
    *ano = tm->tm_year + 1900;
}

/**
 * Funcao para verificar se um ano e bissexto ou nao
 * @param ano
 * @return 
 * Retorna 0 se nao for bissexto e 1 se for bissexto
 */
int anobissexto(int ano) {
    if (ano % 400 == 0) {
        return 1;
    }
    if (ano % 100 == 0) {
        return 0;
    }
    if (ano % 4 == 0) {
        return 1;
    }
    return 0;
}
/**
 * Funcao para inserir a data final de um vendedor
 * @param comissoes
 * @param i
 * @param n_comissao
 */
void inserirDataFim(int *dia, int *mes, int *ano) {
    time_t t = time(NULL);

    struct tm *tm = localtime(&t);

    tm->tm_mon += 1;
    if (tm->tm_mon >= 12) {
        tm->tm_year += 1;
        tm->tm_mon -= 12;
    }
    int anobi = anobissexto(tm->tm_year + 1900);
    int fev_dias = (anobi ? 29 : 28);
    // Ajustar o número de dias do mês de fevereiro
    int max_dias = 31;
    switch (tm->tm_mon) {
        case 1: // fevereiro
            max_dias = fev_dias;
            break;
        case 3: case 5: case 8: case 10: // abril, junho, setembro, novembro
            max_dias = 30;
            break;
    }
    if (tm->tm_mday > max_dias) {
        tm->tm_mday = max_dias;
    }

    *dia = tm->tm_mday;
    *mes = tm->tm_mon + 1;
    *ano = tm->tm_year + 1900;
}

/**
 * Funcao para comparar duas datas
 * @param data1
 * @param data2
 * @return 
 */
int compararDatas(Comissoes *comissoes, Data *data1, Data *data2, int n_comissao, int codvend) {
    for (int i = 0; i < comissoes->contador + 1; i++) {
        for (int j = 0; j < comissoes->comissoes[i].cont_vend; j++) {
            if (comissoes->comissoes[i].quant_vend[j].codigo_vend == codvend) {
                if (data1->ano != data2->ano) {
                    return (data1->ano < data2->ano) ? -1 : 1;
                }
                if (data1->mes != data2->mes) {
                    return (data1->mes < data2->mes) ? -1 : 1;
                }
                if (data1->dia != data2->dia) {
                    return (data1->dia < data2->dia) ? -1 : 1;
                }
                return 0;
            }
        }
    }
    return 1;
}






