/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leonardo
 *
 * Created on 6 de novembro de 2022, 12:36
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    //Declaracao de variaveis
    int matriz[3][3], i, j;

    //Interpretacao de variaveis
    printf("Digite os valores a preencher a matriz: \n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("Elemento[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    printf("Matriz.\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("Matriz inversa.\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", matriz[j][i]);
        }
        printf("\n");
    }
    return (EXIT_SUCCESS);
}

