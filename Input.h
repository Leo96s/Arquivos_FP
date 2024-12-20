/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Input.h
 * Author: Leonardo
 *
 * Created on 11 de fevereiro de 2023, 17:49
 */

#ifndef INPUT_H
#define INPUT_H

int obterInt(int minValor, int maxValor, char *msg);

long int obterlongInt(long int minValor, long int maxValor, char *msg);

float obterFloat(float minValor, float maxValor, char *msg);

double obterDouble(double minValor, double maxValor, char *msg);

char obterChar(char *msg);

void lerString(char *string, unsigned int tamanho, char *msg);

void cleanInputBuffer();

int validar_email(const char *email);

#endif /* INPUT_H */

