/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leonardo
 *
 * Created on 30 de outubro de 2022, 14:04
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main() {

    //Declaracao de variaveis
    int n1, n2, operacao, subtracao, divisao, multiplicacao, continuar, soma;

    //Operacoes a efetuar
    while (continuar != 0) {
        printf("Digite um numero inteiro: ");
        scanf("%d", &n1);

        printf("Digite um outro numero inteiro: ");
        scanf("%d", &n2);

        printf("\nOpcoes de operacoes: \n");
        printf("1 - Subtracao\n");
        printf("2 - Multiplicacao\n");
        printf("3 - Divisao\n");
        printf("4 - Soma\n");
        printf("Digite a operacao desejada: ");
        scanf("%d", &operacao);

        switch (operacao) {
            case 1:
                subtracao = n1 - n2;
                printf("%d - %d = %d", n1, n2, subtracao);
                break;
            case 2:
                multiplicacao = n1 * n2;
                printf("%d * %d = %d", n1, n2, multiplicacao);
                break;
            case 3:
                divisao = n1 / n2;
                printf("%d / %d = %d", n1, n2, divisao);
                break;
            default:
                soma = n1 + n2;
                printf("%d + %d = %d", n1, n2, soma);
                break;
        }
        printf("\nDeseja continuar? 1-Sim ou 0-Nao \n");
        scanf("%d", &continuar);
        if (continuar != 1 && continuar != 0) {
            printf("Digitou um numero que nao esta entre as opcoes.");
            break;
        }
    }
    return (EXIT_SUCCESS);
}

