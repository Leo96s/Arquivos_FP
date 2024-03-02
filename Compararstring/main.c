/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leonardo
 *
 * Created on 28 de novembro de 2022, 17:25
 */

#include <stdio.h>
#include <stdlib.h>
int equal(char *str1[], char *str2[]){
    int n = 0;
    char str3, str4;
    while(*str3 != '\0' && *str1 == *str2) {
        n++;
        *str3++;
        *str4++;
    }
    *str1 = str3;
    *str2 = str4;
    return (*str1 == *str2);
}
/*
 * 
 */
int main(int argc, char** argv) {
    char str1[20], str2[20];
    
    puts("Digite uma palavra: ");
    scanf("%s", str1);
    
    puts("Digite uma outra palavra: ");
    scanf("%s", str2);
    
    equal(&str1, &str2);
    
    return (EXIT_SUCCESS);
}

