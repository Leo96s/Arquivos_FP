/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leonardo
 *
 * Created on 27 de outubro de 2022, 17:11
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main() {

    //Declaracao de variaveis
    int num, impar;

    // Operacoes a efetuar
    printf("Digite um numero inteiro: ");
    scanf("%d", &num);
    if (num != 0) {
        if (num % 2 == 0) {
            impar = num - 1;
            while (impar > 0) {
                printf("%d, ", impar);
                impar = impar - 2;
            }
        } else {
            while (num > 0) {
                printf("%d, ", num);
                num = num - 2;
            }
        }
    } else{
        printf("Nao e possivel efetuar a operacao.");
    }

    return (EXIT_SUCCESS);
}

