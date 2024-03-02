/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leonardo
 *
 * Created on 24 de novembro de 2022, 16:11
 */

#include <stdio.h>
#include <stdio.h>
void foo(int a, int *aPtr) {
    printf("\n%d", a);// imprimir o valor de a
    printf("\n%p", &a);// imprimir o endereço de a
    printf("\n%d", *aPtr);// imprimir o valor de aPtr
    printf("\n%p", *(&aPtr));// imprimir o endereço de aPtr
    printf("\n%d", ++a);// somar um ao valor de a
    printf("\n%d", ++(*aPtr)); // somar um ao valor apontado por de aPtr
}
int main() {
 int a = 0;
 printf("%d", a);// imprimir o valor de a
 printf("\n%p", &a);// imprimir o endereço de a
 foo(a, &a);
 printf("\n%d", a);// imprimir o valor de a
 return 0;
}

