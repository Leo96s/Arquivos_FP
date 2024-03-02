/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leonardo
 *
 * Created on 5 de janeiro de 2023, 12:18
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    char array[6][6];
    int i, j;
    for(i = 0; i < 6; i++){
        for(j = 0; j < 6; j++){
            printf("Digite a letra: ");
            scanf("%s", &array[i][j]);
        }
    }
    printf("Jogo\n");
    for(i = 0; i < 6; i++){
        for(j = 0; j < 6; j++){
            printf("%c ", array[i][j]);
        }
        printf("\n");
    }
    return (EXIT_SUCCESS);
}

