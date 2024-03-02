/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leonardo
 *
 * Created on 3 de novembro de 2022, 17:23
 */

#include <stdio.h>
#include <stdlib.h>
#define TAMANHO_TEXTO 6
#define QTD_LETRAS 26

/*
 * 
 */
int main() {

    //Declaracao de variaveis
    int i = 0;
    char texto[TAMANHO_TEXTO];

    for (i = 0; i < TAMANHO_TEXTO; i++) {
        scanf("%c", &texto[i]);
    }

    for (i = 0; i < TAMANHO_TEXTO; i++) {
        texto[i] = 'A' + (texto[i] - 'A' + 3) % QTD_LETRAS;
    }

    for (i = 0; i < TAMANHO_TEXTO; i++) {
        printf("%c", texto[i]);
    }

    //Interpretacao de variaveis

    return 0;
}

