/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leo
 *
 * Created on 14 de outubro de 2022, 11:53
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main() {
    
    //Apresentação das variaveis
    int minutos1,minutos2, minutos3, minutos4, minutos5, segundos1, segundos2, segundos3, segundos4, segundos5;
    int m, st, s, h, resto, mt;
    
    //Interpretação das variaveis
    printf ("Quantos minutos tem a canção1: ");
    scanf("%d", &minutos1);   
    printf ("Quantos segundos tem a canção1: ");
    scanf("%d", &segundos1);

    printf("Quantos minutos tem a canção2: ");
    scanf("%d", &minutos2);   
    printf("Quantos segundos tem a canção2: ");
    scanf("%d", &segundos2);
    
    printf("Quantos minutos dura a canção3: ");
    scanf("%d", &minutos3);   
    printf("Quantos segundos dura a canção3: ");
    scanf("%d", &segundos3);
    
    printf("Quantos minutos tem a canção4: ");
    scanf("%d", &minutos4);
    printf("Quantos segundos tem a canção4: ");
    scanf("%d", &segundos4);
    
    printf("Quantos minutos tem a canção5: ");
    scanf("%d", &minutos5);   
    printf("Quanto segundos tem a canção5: ");
    scanf("%d", &segundos5);
  
    //Calculo total de tempo do album
    
    printf("Tempo total do album: \n");
    
    mt = minutos1 + minutos2 + minutos3 + minutos4 + minutos5;
    
    st = segundos1 + segundos2 + segundos3 + segundos4 + segundos5;
    
    h = st / 3600;
    resto = st % 3600;
    m = (resto / 60) + mt;
    s = resto % 60;
                            
    printf("%d:%d:%d", h, m, s);
    
    return 0;
}

