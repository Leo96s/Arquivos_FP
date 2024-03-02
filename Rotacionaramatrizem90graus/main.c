/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leonardo
 *
 * Created on 6 de novembro de 2022, 20:09
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
    printf("Digite os valores a preencher a matriz:\n");
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("Elemento[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    printf("Matriz:\n");
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    //Operacoes a efetuar
    printf("Matriz rotacionada:\n");
    for (i = 2;i >= 0; i--){
        printf("%d ",matriz[i][0]);
    }
    printf("\n");
    for (i = 2;i >= 0; i--){
        printf("%d ",matriz[i][1]);
    }
    printf("\n");
    for (i = 2;i >= 0; i--){
        printf("%d ",matriz[i][2]);
    }
    
    return (EXIT_SUCCESS);
}

void funcao(){
    char array[6][6];
    int i, j;
    for(i = 0; i < 6; i++){
        for(j = 0; j < 6; j++){
            printf("Digite a letra: ");
            scanf("%c", array[i][j]);
        }
    }
    printf("Jogo");
    for(i = 0; i < 6; i++){
        for(j = 0; j < 6; j++){
            printf("%3c", array[i][j]);
        }
    }
}

