/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leonardo
 *
 * Created on 12 de novembro de 2022, 12:54
 */

#include <stdio.h>
#include <stdlib.h>
#include "myIntLib.h"

/*
 * 
 */
int main(int argc, char** argv) {
    //Declaracao de variaveis
    int alunos, i;
    float nota, media, soma;
    
    //Interpretação de variaveis
    printf("Digite de quantos alunos pretende fazer a media: ");
    scanf("%d", &alunos);
    for(i = 0; i < alunos; i++){
    printf("Digite a nota do aluno: ");
    scanf("%f", &nota);
    while (nota > 20 || nota < 0){
        printf("Por favor digite um valor de 0 a 20.");
        printf("Digite a nota do aluno: ");
    }
    soma = soma + nota;
    }
    printf("A media dos alunos e: ");
    mediadosalunos(media, soma, alunos);
    
    return (EXIT_SUCCESS);
}

