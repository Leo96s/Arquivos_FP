/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leonardo
 *
 * Created on 10 de novembro de 2022, 15:29
 */

#include <stdio.h>
#include <stdlib.h>

void soma_matrizes(int matriz1[2][2], int matriz2[2][2], int matriz3[2][2]){
    int i, j;
    int valor;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            valor = matriz1[i][j] + matriz2[i][j];
            matriz3[i][j] = valor;
        }
    }
}
void soma_dos_elementos(int m1[2][2]){
    int i, j;
    int soma;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            soma = soma + m1[i][j];
        }
    }   
}


/*
 * 
 */
int main(int argc, char** argv) {
    //Declaracao de variaveis
    int matriz1[2][2], matriz2[2][2], i, j, matriz3[2][2];
    int valor, soma;
    //Interpretacao de variaveis
    printf("Digite os valores a preencher a matriz 1:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("Elemento[%d][%d]: ", i, j);
            scanf("%d", &matriz1[i][j]);
        }
    }
    printf("Digite os valores a preencher a matriz 2:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("Elemento[%d][%d]: ", i, j);
            scanf("%d", &matriz2[i][j]);
        }
    }

    printf("Matriz1\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d, ", matriz1[i][j]);
        }
        printf("\n");
    }

    printf("Matriz2\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d, ", matriz2[i][j]);
        }
        printf("\n");
    }
    //Operacoes a efetuar
    printf("Soma das Matrizes:\n");
    soma_matrizes(matriz1, matriz2, matriz3);
        for (i = 0; i < 2; i++) {
            for (j = 0; j < 2; j++) {
                valor = matriz3[i][j];
                
                printf("%d ", valor);
        }
            printf("\n");
    }
    
    printf("Soma dos elemtentos da matriz1:\n");
    soma_dos_elementos(matriz1);
        for (i = 0; i < 2; i++) {
            for (j = 0; j < 2; j++) {
                soma = soma + matriz1[i][j];              
            }
        }
    printf("%d", soma);
    
    soma = 0;
    printf("\nSoma dos elemtentos da matriz2:\n");
    soma_dos_elementos(matriz2);
        for (i = 0; i < 2; i++) {
            for (j = 0; j < 2; j++) {
                soma = soma + matriz2[i][j];              
            }
        }
    printf("%d", soma);
     
    return (EXIT_SUCCESS);
}

