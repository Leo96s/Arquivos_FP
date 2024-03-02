/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leonardo
 *
 * Created on 21 de outubro de 2022, 12:15
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main() {
    //Declaração de variáveis
    int opção;
    
    //Interpretação de variáveis
    printf("Escolha uma das opções a baixo: \n");
    printf("1. Criar\n");
    printf("2. Atualizar\n");
    printf("3. Eliminar\n");
    printf("4. Sair\n");
    
    printf("Opção escolhida: ");
    scanf("%d", &opção);
    
    //Operações a efetuar
    switch (opção) {
        case 1:
            printf("Criar");
            break;
        case 2:
            printf("Atualizar");
            break;
        case 3:
            printf("Eliminar");
            break;
        case 4:
            printf("");
            break;
        default:
            printf("Não é possível efetuar a operação");
    }
    
    return 0;
}

