/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leonardo
 *
 * Created on 21 de outubro de 2022, 10:50
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main() {
    //Declaração de variaveis
    int num1, num2, operação, resultado;
    
    //Interpretação de variáveis
    printf("\nDigite um número inteiro: ");
    scanf("%d", &num1);
    
    printf("\nDigite um outro número inteiro: ");
    scanf("%d", &num2);
    
    //Opções
    printf("Escolha uma das opções a baixo: \n");
    printf("1 - Subtração\n");
    printf("2 - Multiplicação\n");
    printf("3 - Divisão\n");
    
    printf("Digite a operação desejada: ");
    scanf("%d", &operação);
    
    //Calculos a efetuar
    switch (operação) {
        case 1: 
            resultado = num1 - num2;
            printf("%d - %d = %d", num1, num2, resultado);
            break;
        case 2: 
            resultado = num1 * num2;
            printf("%d * %d = %d", num1, num2, resultado);
            break;
        case 3:
            resultado = num1 / num2;
            printf("%d / %d = %d", num1, num2, resultado);
            break;
        default:
            resultado = num1 + num2;
            printf("%d + %d = %d", num1, num2, resultado);     
    }
    
    return 0 ;
}

