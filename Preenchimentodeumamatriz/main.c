/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leonardo
 *
 * Created on 3 de novembro de 2022, 23:58
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(){

    //Declaracao de variaveis
    int i, j, matriz[4][5], n1, repete, k, w;

    //Operacoes a efetuar
    printf("Digite os valores para preencher a matriz\n");
    for ( i=0; i<4; i++ ){
        for ( j=0; j<5; j++ ){
            printf ("Elemento[%d][%d] = ", i, j);
            scanf ("%d", &matriz[ i ][ j ]);
    }
    }
    printf("Matriz: \n");
    for ( i=0; i<4; i++ ){
        for ( j=0; j<5; j++ ){
            printf ("%d ",matriz[ i ][ j ]);
    }
        printf("\n");
    }
    printf("Digite o valor que deseja verificar se este repte-se: ");
    scanf("%d", &n1);
    for (i=0; i <4; i++){
        for (j=0; j <5; j++){
            if (matriz[i][j] == n1){
            repete++; 
            }
        }
    }
    printf("O valor repete-se %d vezes.", repete);
    
          
    return (EXIT_SUCCESS);
}

