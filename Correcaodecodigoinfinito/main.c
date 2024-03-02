/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leonardo
 *
 * Created on 27 de outubro de 2022, 14:54
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main() {
    int num, i, resultado = 0;

    printf("Digite um número: ");
    scanf("%d", &num);

    for (i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            resultado++;
            break;
        }
    }

    if (resultado == 0)
        printf("%d é um número primo\n", num);
    else
        printf("%d não é um número primo\n", num);

    return 0;
}

