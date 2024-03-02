/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leonardo
 *
 * Created on 10 de novembro de 2022, 14:24
 */

#include <stdio.h>
#include <stdlib.h>

void asteriscos(int valor, int i) {
    scanf("%d", &valor);
    for (i = 1; i <= valor; i++) {
        printf("*");
    }
}

/*
 * 
 */
int main() {
    //Declaracao de variaveis
    int valor, i;

    //Interpretacao de variaveis
    printf("Digite um valor: ");
   
    asteriscos(valor, i);
    
    return (EXIT_SUCCESS);
}

