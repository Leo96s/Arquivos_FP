/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leonardo
 *
 * Created on 5 de novembro de 2022, 20:30
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    //Declaracao de variaveis
    int primos[6], x, nprimos = 0, i, contador = 0;
    float primo;

    //Interpretacao de variaveis
    printf("Digite 6 valores inteiros: \n");
    for (x = 0; x < 6; x++) {
        printf("Elemento[%d]: ", x);
        scanf("%d", &primos[x]);
    }
    printf("Valores:\n");
    for (x = 0; x < 6; x++) {
        printf("%d, ", primos[x]);
    }

    //Operacoes a efetuar
    printf("\nOs numeros primos sao: \n");
    for (x = 0; x < 6; x++) {
        for (i = 2; i <= primos[x]; i++) {
            if (primos[x] % i == 0) {
                contador++;
                break;
            }
        }
        if (contador == 0) {
            printf("%d", primos[x]);
        }
    }
    return (EXIT_SUCCESS);
}

