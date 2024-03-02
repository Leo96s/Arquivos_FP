/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   alunos.h
 * Author: Leonardo
 *
 * Created on 12 de janeiro de 2023, 15:36
 */
#ifndef ALUNOS_H
#define ALUNOS_H

#include "input.h"

#define ALUNOS_TAM_INICIAL      5

#define ERRO_ALUNO_NAO_EXISTE   "O aluno não existe na lista."
#define ERRO_LISTA_VAZIA        "A lista de alunos está vazia."
#define ERRO_LISTA_CHEIA        "A lista de alunos está cheia."
#define ERRO_ALUNO_EXISTE       "O número de aluno já se encontra atribuído."

#define MIN_NUM_ALUNO           0
#define MAX_NUM_ALUNO           1000
#define MSG_OBTER_NUM_ALUNO     "Insira um número de aluno [0-1000]: "

#define MAX_NOME_ALUNO          31
#define MSG_OBTER_NOME          "Insira o nome do aluno: "

#define MIN_DIA                 0
#define MAX_DIA                 31
#define OBTER_DIA_NASC          "Insira o dia de nascimento: "

#define MIN_MES                 1
#define MAX_MES                 12
#define OBTER_MES_NASC          "Insira o mês de nascimento: "

#define MIN_ANO                 1990
#define MAX_ANO                 2021
#define OBTER_ANO_NASC          "Insira o ano de nascimento: "

typedef struct {
    int ano, mes, dia;
} Data;

typedef struct {
    int numero;
    char nome[MAX_NOME_ALUNO];
    Data data_nascimento;
} Aluno;

typedef struct {
    int contador, tamanho;
    Aluno *alunos;
} Alunos;

int carregarAlunos(Alunos *alunos, char* ficheiro);

void inserirAlunos(Alunos *alunos, char *ficheiro);
void procurarAlunos(Alunos alunos);
void atualizarAlunos(Alunos *alunos, char *ficheiro);
void removerAlunos(Alunos *alunos, char *ficheiro);
void listarAlunos(Alunos alunos);

void libertarAlunos(Alunos *alunos);

#endif /* ALUNOS_H */



