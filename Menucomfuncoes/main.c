/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leonardo
 *
 * Created on 14 de novembro de 2022, 16:59
 */

#include <stdio.h>
#include <stdlib.h>
#include "myIntLib.h"
/*
 * 
 */
int main(int argc, char** argv) {
    //Declaracao de variaveis
    int n1, n2, operacoes;
    
    //Interpretacao de variaveis
    printf("Digite um valor: ");
    scanf("%d", &n1);
    
    printf("Digite um outro valor: ");
    scanf("%d", &n2);
    
    printf("Escolha uma das opcoes:\n");
    printf("1 - Soma\n");
    printf("2 - Subtracao\n");
    printf("3 - Multiplicacao\n");
    printf("4 - Divisao\n");
    printf("5 - Potencia\n");
    printf("Digite a opcao desejada: ");
    scanf("%d", &operacoes);
    
    while(operacoes != 1 && operacoes != 2 && operacoes != 3 && operacoes != 4 && operacoes != 5){
        printf("Por favor, digitar um valor dentro das opcoes.\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &operacoes);
    }
    
    //Operacoes a efetuar
    switch(operacoes){
        case 1:
            printf("Resultado: %ld", somar(n1, n2));
            return 0;

            break;
        case 2:
            printf("Resultado: %ld", subtrair(n1, n2));
            break;
            
        case 3:
            printf("Resultado: %ld", multiplicar(n1, n2));
            break;
            
        case 4:
            printf("Resultado: %0.2lf", dividir(n1, n2));
            break;
        case 5:
            printf("Resultado: %d", potencia(n1, n2));
    }

    return (EXIT_SUCCESS);
}
    

