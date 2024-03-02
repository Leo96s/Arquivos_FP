/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leo
 *
 * Created on 20 de outubro de 2022, 15:11
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main() {
    
    //Declaração de variáveis
    int n1;
    
    //Interpratação de variáveis
    printf("Digite um número inteiro: ");
    scanf("%d", &n1);
    //Calculos a fazer
    
    if ((n1 % 2) == 0) {
        printf("\n O número %d é par", n1);    
    } 
    else {
        printf("\n O número %d é impar", n1);
    }    
    return 0;
}

