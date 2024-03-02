/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leonardo
 *
 * Created on 27 de outubro de 2022, 16:17
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main() {
    //Declaracao de variaveis
    int n, somat, media, ntotal;
    
    //Interpretacao de variaveis
    do {
        printf("\nDigite um numero: ");
        scanf("%d", &n);
        
        somat = somat + n;
      
    } while (n > 0); 
      //Operacoes a efetuar
    printf("Digite a quantidade de numeros usados: ");
    scanf("%d", &ntotal);
    
    media = somat / ntotal;
    printf("A media e: %d / %d = %d", somat, ntotal, media);
    
    return 0;
}

