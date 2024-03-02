/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leonardo
 *
 * Created on 5 de novembro de 2022, 17:14
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    //Declaracao de variaveis
    int i, j, matriz[3][3], maior = matriz[0][0], menor = matriz[0][0];
    
    //Interpretacao de variaveis
    printf("Digite os valores para preencher a matriz.\n");
    for(i = 0; i <3; i++){
        for(j = 0; j <3; j++){
            printf ("Elemtendo[%d][%d] = ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    printf("Matriz.\n");
    for(i = 0; i <3; i++){
        for(j = 0; j <3; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    for(i = 0; i <3; i++){
        for(j = 0; j <3; j++){
            if (maior < matriz[i][j] || i == 0 && j == 0){
                maior = matriz[i][j];
                }
            if (menor > matriz [i][j] || i == 0 && j == 0){
                menor = matriz[i][j];
            }
        }
    }
    printf("O maior valor da matriz e: %d", maior);
    printf("\nO menor valor da matriz e: %d", menor);
    
    return (EXIT_SUCCESS);
}

