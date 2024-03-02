/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leonardo
 *
 * Created on 30 de outubro de 2022, 18:34
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main() {
    //Declaracao de variaveis
    int continuar = 1, operacao;

    //Operacoes a efetuar
    while (continuar != 0) {
        printf("\nOpcoes disponiveis: \n");
        printf("1 - Criar\n");
        printf("2 - Atualizar\n");
        printf("3 - Eliminar\n");
        printf("4 - Sair\n");
        printf("Escolha a operacao desejada: ");
        scanf("%d", &operacao);
        if (operacao != 1 && operacao != 2 && operacao != 3 && operacao != 4) {
            printf("Por favor verifique a opcao entre as disponiveis.");
            break;
        }
        switch (operacao) {
            case 1:
                printf("\nCriar");
                break;
            case 2:
                printf("\nAtualizar");
                break;
            case 3:
                printf("\nEliminar");
                break;
            case 4:
                printf("\nSair");
                break;
        }
        if (operacao == 4) {
            break;

        }
    }
    return (EXIT_SUCCESS);
}

