/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Input.c
 * Author: Leonardo
 *
 * Created on 11 de fevereiro de 2023, 17:49
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tools.h"

#define VALOR_INVALIDO "O valor inserido é inválido."

/**
 * Limpa o buffer
 */
void cleanInputBuffer() {
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

/**
 * Funcao para validar o email
 * @param email
 * @return 
 * Retorna 0 se o formato estiver incorreto e retorna 1 se estiver correto
 */
int validar_email(const char *email) {
    int len = strlen(email);
    if (len < 6) {
        return 0;
    }
    int at_pos = -1;
    int dot_pos = -1;
    for (int i = 0; i < len; i++) {
        if (email[i] == '@') {
            at_pos = i;
            break;
        }
    }
    if (at_pos == -1 || at_pos == 0) {
        return 0;
    }
    for (int i = at_pos; i < len; i++) {
        if (email[i] == '.') {
            dot_pos = i;
            break;
        }
    }
    if (dot_pos == -1 || dot_pos == len - 1) {
        return 0;
    }
    if (dot_pos - at_pos <= 1) {
        return 0;
    }
    for (int i = at_pos + 1; i < dot_pos; i++) {
        if (email[i] != '.') {
            return 1;
        }
    }
    return 0;
}

/**
 * Funcao para obter um valor do tipo int
 * @param minValor
 * @param maxValor
 * @param msg
 * @return
 * Retorna o valor atribuido à variavel int 
 */
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

/**
 * Funcao para obter um valor do tipo float
 * @param minValor
 * @param maxValor
 * @param msg
 * @return
 * Retorna o valor a que foi atribuido à variavel 
 */
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

/**
 * Funcao para obter um valor do tipo double
 * @param minValor
 * @param maxValor
 * @param msg
 * @return 
 * Retorna o valor atribuido à variavel do tipo double
 */
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

/**
 * Funcao para obter um caracter
 * @param msg
 * @return 
 * Retorna o caracter associado à variavel do tipo char
 */
char obterChar(char *msg) {
    char valor;
    printf(msg);
    valor = getchar();
    cleanInputBuffer();
    return valor;
}

/**
 * Funcao para obter uma string
 * @param string
 * @param tamanho
 * @param msg
 */
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



