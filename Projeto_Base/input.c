/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   input.c
 * Author: Leonardo
 *
 * Created on 12 de janeiro de 2023, 15:37
 */

#include <stdio.h>
#include <string.h>

#define VALOR_INVALIDO "O valor inserido é inválido."

void cleanInputBuffer() {
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

int obterInt(int minValor, int maxValor, char *msg) {
    int valor;
    printf(msg);
    while (scanf("%d", &valor) != 1 || valor < minValor || valor > maxValor) {
        puts(VALOR_INVALIDO);
        cleanInputBuffer();
        printf(msg);
    }
    cleanInputBuffer();
    return valor;
}

float obterFloat(float minValor, float maxValor, char *msg) {
    float valor;
    printf(msg);
    while (scanf("%f", &valor) != 1 || valor < minValor || valor > maxValor) {
        puts(VALOR_INVALIDO);
        cleanInputBuffer();
        printf(msg);
    }
    cleanInputBuffer();
    return valor;
}

double obterDouble(double minValor, double maxValor, char *msg) {
    double valor;
    printf(msg);
    while (scanf("%lf", &valor) != 1 || valor < minValor || valor > maxValor) {
        puts(VALOR_INVALIDO);
        cleanInputBuffer();
        printf(msg);
    }
    cleanInputBuffer();
    return valor;
}

char obterChar(char *msg) {
    char valor;
    printf(msg);
    valor = getchar();
    cleanInputBuffer();
    return valor;
}

void lerString(char *string, unsigned int tamanho, char *msg) {
    printf(msg);
    if (fgets(string, tamanho, stdin) != NULL) {
        unsigned int len = strlen(string) - 1;
        if (string[len] == '\n') {
            string[len] = '\0';
        } else {
            cleanInputBuffer();
        }
    }
}

