/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leonardo
 *
 * Created on 5 de novembro de 2022, 17:50
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    //Declaracao de variaveis
    char objeto[20];
    char objeto2[20];
    int a = 0;
    
    //Interpratacao de variaveis
    puts("insira o nome de um objeto:");
    scanf("%s", objeto);

    puts("insira um outro nome e um objeto:");
    scanf("%s", objeto2);
    
    //Operacoes a efetuar
    while (objeto[a] == objeto2[a] && objeto[a] != '\0' && objeto2[a] != '0'){
        a++;
    }
    if (objeto[a] == '\0' && objeto2[a] == '\0'){
        printf("As duas strings sao iguais");
    } else {
        printf("As duas string nao sao iguais");
    }

    return (EXIT_SUCCESS);
}

