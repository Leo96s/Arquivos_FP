/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leo
 *
 * Created on 20 de outubro de 2022, 16:00
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main() {
    
    //Declaração de variáveis
    int n1, n2, resultado, a;

    //Interpretação de variáveis
    printf("Digite um número inteiro: ");
    scanf("%d", &n1);
    
    printf("\nDigite um outro número inteiro: ");
    scanf("%d", &n2);
    
    printf("\nDigite a operação desejada: ");
    scanf("%d", &a);
    
    //Opções
    printf("Escolha uma das opções a baixo: \n");
    printf("1 - Subtração");
    printf("2 - Multiplicação");
    printf("3 - Divisão");
    
    //Calculos a efetuar
    switch (a) {
        case 1: 
            resultado = n1 - n2;
            printf("%d - %d = %d", n1, n2, resultado);

    return 0;
}

