/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leonardo
 *
 * Created on 27 de outubro de 2022, 14:58
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main() {
    //Declaração de variáveis
    int a, m, M;

    //Interpretação de variáveis
    printf("Abecedário: \n");
    printf("Opcoes: \n");
    printf("1 - Maiusculas\n");
    printf("2 - Minusculas\n");
    printf("Escolha a operacao desejada: ");
    scanf("%d", &a);

    //Operações a efetuar
    switch (a) {
        case 1:
                for (M = 'A'; M <= 'Z'; M++) {
                    printf("%c", M);
                    
                }
                break;
        case 2:
                for (m = 'a'; m <= 'z'; m++) {
                    printf("%c", m);
                   
                }
                break;
    }
    return 0;
}

