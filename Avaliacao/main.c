/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leonardo
 *
 * Created on 21 de outubro de 2022, 12:28
 */

#include <stdio.h>
#include <stdlib.h>
#define teste1 0.40
#define teste2 0.60
/*
 * 
 */
int main() {
    
    //Declaração de variáveis
    int n1, n2;
    float mediaponderada;
    
    //Interpretação de variáveis
    printf("Digite o valor obtido no primeiro teste: ");
    scanf("%d", &n1);

    printf("Digite o valor obtido no segundo teste: ");
    scanf("%d", &n2);
    
    if (n1 >= 20 ) {
        printf("Calculo não é possível");
    }
    if (n2 >= 20) {
        printf("\nCalculo não é possível");
    }
    //Operações a efetuar 
    mediaponderada = ((n1 * teste1) + (n2 * teste2));
    printf("((%d * teste1) + (%d * teste2)) = %0.2f ", n1, n2, mediaponderada);
    
    if (mediaponderada >= 9.5) {
        printf("\nEstá aprovado");     
    } else
        printf("\nEstá reprovado");
    
    return (EXIT_SUCCESS);
}

