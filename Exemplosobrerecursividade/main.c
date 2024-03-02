/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leonardo
 *
 * Created on 10 de novembro de 2022, 17:27
 */

#include <stdio.h>
#include <stdlib.h>
int factorial(int valor) {
        if (valor == 0) {
            return 1;
        }
        return valor * factorial(valor - 1);
    }
/*
 * 
 */
int main(int argc, char** argv) {
    int valor;
    printf("Digite um valor: ");
    scanf("%d", valor);
   
    factorial(valor);
    
    return (EXIT_SUCCESS);
}

