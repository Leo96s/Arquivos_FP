/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leonardo
 *
 * Created on 30 de outubro de 2022, 18:48
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main() {
    //Interpretacao de variaveis
    int valor, valor2, jogador1, jogador2, tentativas = 0;

    //Operacoes a efetuar
    printf("Jogador1:\n");
    printf("Digite um valor entre 0 e 100: ");
    scanf("%d", &valor);
    if (valor > 100) {
        printf("Por favor verifique o valor digitado.\n");
    } else if (valor < 0) {
        printf("Por favor verifique o valor digitado.\n");
    } else {
        do {

            printf("Jogador2: \n");
            printf("Adivinhe o valor escolhido pelo Jogador1: ");
            scanf("%d", &valor2);

            if (valor2 > valor) {
                printf("O valor inserido e superior ao valor escolhido pelo Jogador1.\n");
            }
            if (valor2 < valor) {
                printf("O valor inserido e inferior ao valor escolhido pelo Joagador1.\n");
            }
            tentativas++;
        } while (valor != valor2);
        printf("O numero de tentativas foi %d.", tentativas);
    }


    return (EXIT_SUCCESS);
}

