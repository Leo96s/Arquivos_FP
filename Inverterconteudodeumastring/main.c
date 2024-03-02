/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leonardo
 *
 * Created on 6 de novembro de 2022, 23:16
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    //Declaracao de variaveis
    char texto[22], textoinv[22], i, j, fim = 0;
    
    //Interpretacao de variaveis
    printf("Digite uma frase: ");
    fgets(texto, 22, stdin);
    while(texto[fim] != '\0' && texto[fim] != '\n'){
        fim++;
    }
    
    //Operacoes a efetuar 
    i = fim -1;
    j = 0;
    while(j<fim){
        textoinv[j] = texto[i];
        i--;
        j++;
    }
    texto[fim] ='\0';
    printf("Inversa:\n %s\n", textoinv);
    return (EXIT_SUCCESS);
}

