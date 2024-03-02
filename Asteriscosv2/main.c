/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leonardo
 *
 * Created on 12 de novembro de 2022, 12:44
 */

#include <stdio.h>
#include <stdlib.h>
#include "myIntLib.h"


/*
 * 
 */
int main() {
    //Declaracao de variaveis
    int valor, i;

    //Interpretacao de variaveis
    printf("Digite um valor entre 1 e 20: ");
    scanf("%d", &valor);
    
    asteriscos(valor, i);
    
    return (EXIT_SUCCESS);
}

