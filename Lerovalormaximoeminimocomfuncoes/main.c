/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leonardo
 *
 * Created on 12 de novembro de 2022, 19:23
 */

#include <stdio.h>
#include <stdlib.h>
#include "myIntLab.h"
/*
 * 
 */
int main(int argc, char** argv) {
    //Declaracao de variaveis
    int n1, n2;
    
    //Interpretacao das variaveis
    printf("Digite um valor inteiro: ");
    scanf("%d", &n1);
    
    printf("Digite um outro valor inteiro: ");
    scanf("%d", &n2);
    
    valormaximo(n1, n2);
    valorminimo(n1, n2);
    return (EXIT_SUCCESS);
}

