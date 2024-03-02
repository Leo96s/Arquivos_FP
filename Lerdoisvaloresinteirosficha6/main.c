/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leonardo
 *
 * Created on 24 de novembro de 2022, 16:52
 */

#include <stdio.h>
#include <stdlib.h>
void somar(int num1, int num2, long *resultado){
    *resultado = num1 + num2;
}
/*
 * 
 */
int main(int argc, char** argv) {
    int num1, num2;
    long resultado;
    
    printf("Valor1: ");
    scanf("%d", &num1);
    
    printf("Valor2: ");
    scanf("%d", &num2);
    
    somar(num1, num2, &resultado);
    printf("O resultado e: %ld", resultado);
    return (EXIT_SUCCESS);
}

