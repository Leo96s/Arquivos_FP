/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leo
 *
 * Created on 20 de outubro de 2022, 14:55
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main() {
    
    //Declaração de variáveis
    
    int n1, n2, n3, menor;
    
    //Interpretação das variáveis
   
    printf("Digite um numero inteiro: \n");
    scanf("%d", &n1);
    
    printf("Digite um outro numero inteiro: \n");
    scanf("%d", &n2);
    
    printf("Digite um outro numero interio: \n");
    scanf("%d", &n3);
    
    //Calculo a fazer
    
    if (n1 < n2) {
        if (n1 < n3)
            menor = n1;    
        else
            menor = n3;
    }
    else {
        if (n2 < n3)
            menor = n2;
        else 
            menor = n3;
    }
    printf("O menor número é: %d", menor);
    return 0;
}

