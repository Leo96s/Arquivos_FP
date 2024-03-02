/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leonardo
 *
 * Created on 21 de janeiro de 2023, 18:10
 */

#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

#define MAX_NOME        11
#define MAX_ALUNOS      2

#define INSERCAO_ERRO   "\nAtingido o maximo de alunos."
#define INSERCAO_OK     "\nO aluno foi inserido com sucesso."

typedef struct {
    int ano, mes, dia;
} Data;

typedef struct aluno {
    int numero;
    char nome[MAX_NOME];
    Data data_nascimento;
} Aluno;

void imprimirAluno(Aluno aluno) {
    printf("\n%-20d | %-30s | %d/%d/%d", aluno.numero, aluno.nome, aluno.data_nascimento.ano, aluno.data_nascimento.mes, aluno.data_nascimento.dia);
}

int listarAlunos(Aluno alunos[], int count) {
    int i;
    printf("\n%-20s | %-30s | %-20s", "Numero", "Nome", "Data de nascimento");
    for (i = 0; i < count; ++i) {
        imprimirAluno(alunos[i]);
    }
}

void obterAluno(Aluno *aluno) {
    printf("\nNumero: ");
    scanf("%d", &aluno->numero);
    printf("Nome: ");
    lerString(aluno->nome, MAX_NOME);
    printf("Dia de nascimento: ");
    scanf("%d", &aluno->data_nascimento.dia);
    printf("Mes de nascimento: ");
    scanf("%d", &aluno->data_nascimento.mes);
    printf("Ano de nascimento: ");
    scanf("%d", &aluno->data_nascimento.ano);
}

int inserirAluno(Aluno alunos[], int *count) {
    if (*count < MAX_ALUNOS) {
        obterAluno(&alunos[*count]);
        return ++(*count);
    }
    return 0;
}

int menu(Aluno alunos[], int *count) {
    int opcao;

    do {
        printf("\n-----------------------------------------------------------");
        printf("\n1 - Inserir");
        printf("\n2 - Listar");
        printf("\n0 - Sair");
        printf("\n------------------------------------------------------------");
        printf("\nElementos: %d", *count);

        printf("\nOpcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 0:
                break;
            case 1:
                inserirAluno(alunos, count) ?
                        puts(INSERCAO_OK) :
                        puts(INSERCAO_ERRO);
                break;
            case 2:
                listarAlunos(alunos, *count);
                break;
            default:
                printf("\nOpcao invalida!");
        }

    } while (opcao != 0);
}

int main() {
    Aluno alunos[MAX_ALUNOS];
    int count = 0;

    menu(alunos, &count);

    return 0;
}

