/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   utils.h
 * Author: Leonardo
 *
 * Created on 21 de janeiro de 2023, 18:12
 */

#include <string.h>

#ifndef UTILS_H
#define UTILS_H


void clean_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void lerString(char *string, int max) {
    clean_buffer();
    if (fgets(string, max, stdin) != NULL) {
        int tamanho = strlen(string) - 1;
        if (string[tamanho] == '\n') {
            string[tamanho] = '\0';
        } else {
            clean_buffer();
        }
    }
}

#endif /* UTILS_H */


