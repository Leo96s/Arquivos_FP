/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leonardo
 *
 * Created on 5 de novembro de 2022, 18:21
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    //Declaracao de variaveis
    int valores[10], x, maior = valores[0];
    
    //Interpretacao de valores
    printf("Digite os valores pretendidos:\n");
    for (x = 0; x < 10; x++){
        printf("Elemento %d: ", x);
        scanf("%d", &valores[x]);
    }
    for (x = 0; x < 10; x++){
        printf("%d, ", valores[x]);
    }
    for (x = 0; x < 10; x++){
        if(valores[x] % 2 == 0 || valores[0] % 2 == 0){
            if(valores[x] > maior){
                maior = valores[x];               
            }
        }
    }
    printf("\nO maior valor par e: %d", maior );
    return (EXIT_SUCCESS);
}

