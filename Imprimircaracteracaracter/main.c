/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leonardo
 *
 * Created on 1 de dezembro de 2022, 18:37
 */

#include <stdio.h>
#include <stdlib.h>

void printFirst(char *str[], int n) {
    n = 0;
    while (*str[n] != '\0') {
        printf("%c", *str[n]);
        n++;
    }
    printf("\n");
}

/*
 * 
 */
int main() {
    int n;
    char str[20];

    printf("Digite uma Palavra: ");
    scanf("%s", str);

    printFirst(&str, n);
    
    return (EXIT_SUCCESS);
}

