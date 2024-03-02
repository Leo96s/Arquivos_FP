/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leonardo
 *
 * Created on 6 de janeiro de 2023, 12:09
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    int a;
    int arr[10];
    int *ap;
    printf("Quanto elementos? ");
    scanf("%d", &a);
    
    ap = (int *)malloc(sizeof(int) *a);
    ap[0] = 5;
    *ap = 5;
    ap[1]=10;
    *(ap +1) = 10;
    
    ap = realloc(ap, 10 * sizeof(int));
    
    free(ap);
    
    printf("%d", a);
    return (EXIT_SUCCESS);
}

