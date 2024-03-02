/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leonardo
 *
 * Created on 28 de novembro de 2022, 16:34
 */

#include <stdio.h>
int len(char *str){
     int len1 = 0;
  while(*str++ != '\0')
      len1++;
  return len1; 
}
/*
 * 
 */
int main(int argc, char** argv) {
    char str[22];
    
    printf("Digite uma frase: ");
    fgets(str, sizeof(str), stdin); 

    printf("O Tamnho da string e: %d", len(&str));

    return 0;
}

