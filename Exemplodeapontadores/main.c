/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leonardo
 *
 * Created on 24 de novembro de 2022, 16:07
 */

#include <stdio.h>
#include <stdlib.h>
void incrementar (int valor){
    printf("\nvalor: %d", ++valor);
}
/*
 * 
 */
int main(int argc, char** argv) {
    int valor = 0;
    
    incrementar(valor);
    
    printf("\nvalor: %d", valor);
    

    return (EXIT_SUCCESS);
}

