/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leonardo
 *
 * Created on 23 de outubro de 2022, 12:50
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main() {
    
    //Declaração de variáveis
    int x, y, qua1, qua2, qua3, qua4;
    
    //Interpretação de variáveis
    printf("Digite o valor da coordenada x: ");
    scanf("%d", &x);
    
    printf("Digite o valor da coordenada y: ");
    scanf("%d", &y);
    
    printf("\nPar de coordenandas: (%d, %d)", x, y);
    
    //Operações a efetuar
    if( x > 0, y > 0){
        printf("\nO ponto pertence ao 1ºQuadrante");        
    } else if (x > 0, y < 0){
        printf("\nO ponto pertence ao 4ºQuadrante");
    } else if ( x < 0, y < 0){
        printf("\nO ponto pertence ao 3ºQuadrante");
    } else if (x < 0, y > 0){
        printf("\nO pponto pertence ao 2ºQuadrante");
    } else if (x = 0, y = 0){
        printf("\nO ponto é a origem");
    } else if (x = 0, y <= 0 >= y ){
        printf("\nO ponto está sobre o eixo x");        
    } else if (y = 0, x <= 0 >= y ){
        printf("\nO ponto está sobre o eixo y");
    }   
    return 0;
}

