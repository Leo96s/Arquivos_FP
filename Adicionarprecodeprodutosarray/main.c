/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leonardo
 *
 * Created on 3 de novembro de 2022, 16:06
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main() {

    //Declaracao de variaveis
    int i;
    float produto[10], somadeprodutos;

    //Interpretacao de variaveis

    for(i = 0; i < 10; i++){
        printf("Digite o preco do produto %d: ", i);
        scanf("%f", &produto[i]);
        produto[i] = i + 1;
    }
    for(i = 0; i < 10; i++){
    somadeprodutos = somadeprodutos + produto[i];
    }
     printf("A soma de produtos e: %0.2f\n", somadeprodutos);
     
    return 0;
}

