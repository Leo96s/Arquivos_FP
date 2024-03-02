/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leonardo
 *
 * Created on 24 de novembro de 2022, 17:17
 */

#include <stdio.h>
#include <stdlib.h>
void ordenar(int *v1, int *v2, int *v3){
    printf("Valores ordenados do menor para o maior:\n");
    
    if(*v1 > *v2){
    int temp = *v2;
    *v2 = *v1;
    *v1 = temp;
    }
    if(*v2 > *v3){
    int temp1 = *v3;
    *v3 = *v2;
    *v2 = temp1;       
    }
    if(*v1 > *v3){
    int temp2 = *v1;
    *v1 = *v3;
    *v3 = temp2;     
    }
}
/*
 * 
 */
int main(int argc, char** argv) {
    int v1, v2, v3;
    
    printf("Digite o valor1: ");
    scanf("%d", &v1);
    
    printf("Digite o valor2: ");
    scanf("%d", &v2);
    
    printf("Digite o valor3: ");
    scanf("%d", &v3);
    
    ordenar( &v1, &v2, &v3);
    printf("%d %d %d", v1, v2, v3);
    return (EXIT_SUCCESS);
}

