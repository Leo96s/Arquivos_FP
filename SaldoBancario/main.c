/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leonardo
 *
 * Created on 21 de outubro de 2022, 11:41
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main() {
    //Declaração de variáveis
    int saldo, débito, resultado;
    
    //Interprtação de variáveis
    printf("Digite o saldo da conta Bancária: ");
    scanf("%d", &saldo);
    
    printf("Montante a debitar: ");
    scanf("%d", &débito);
    
    //Operações a efetuar
    resultado = saldo - débito;
            
    if (resultado >= 0){        
        printf("O Saldo fica positivo.");
    } else {
        printf("Não é possivel fazer a operação.");
    }
    
    return 0;
}

