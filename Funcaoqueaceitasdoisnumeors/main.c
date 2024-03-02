/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leonardo
 *
 * Created on 12 de novembro de 2022, 20:40
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "myIntLib.h"
/*
 * 
 */
int main(int argc, char** argv) {
    //Declaracao de variaveis
    int x, y;
    
    //Interpretacao das variaveis
    printf("Digite o valor de x: ");
    scanf("%d", &x);
    
    printf("Digite o valor de y: ");
    scanf("%d", &y);
    
    //Operacoes a efetuar
    potencia(x, y);
    printf("O resultado e: %d", potencia(x, y));
    
    return (EXIT_SUCCESS);
}

