/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   alunos.c
 * Author: Leonardo
 *
 * Created on 12 de janeiro de 2023, 15:37
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "alunos.h"

void listarAlunos(Alunos alunos);

void imprimirAluno(Aluno aluno) {
    printf("\n%3d %-30s %d-%d-%d", aluno.numero, aluno.nome, aluno.data_nascimento.dia, aluno.data_nascimento.mes, aluno.data_nascimento.ano);
}

void apagarDadosAluno(Aluno *aluno) {
    aluno->numero = 0;
    strcpy(aluno->nome, "");
    aluno->data_nascimento.dia = aluno->data_nascimento.mes = aluno->data_nascimento.ano = 0;
}

int procurarAluno(Alunos alunos, int numero) {
    int i;
    for (i = 0; i < alunos.contador; i++) {
        if (alunos.alunos[i].numero == numero) {
            return i;
        }
    }
    return -1;
}

int obtemContadorFX(char *ficheiro) {
    int contador;
    FILE *fp = fopen(ficheiro, "rb");
    if (fp != NULL) {
        fread(&contador, sizeof (int), 1, fp);
        fclose(fp);
    }
    return contador;
}

int carregarAlunos(Alunos *alunos, char *ficheiro) {
    int sucesso = 0;

    FILE *fp = fopen(ficheiro, "rb");
    if (fp != NULL) {

        fread(&alunos->contador, sizeof (int), 1, fp);

        if (alunos->contador > 0) {
            alunos->alunos = (Aluno*) malloc(alunos->contador * sizeof (Aluno));
            fread(alunos->alunos, sizeof (Aluno), alunos->contador, fp);

            alunos->tamanho = alunos->contador;

            sucesso = 1;
        }
        fclose(fp);
    }

    if (!sucesso) {
        fp = fopen(ficheiro, "wb");
        if (fp != NULL) {
            alunos->alunos = (Aluno*) malloc(ALUNOS_TAM_INICIAL * sizeof (Aluno));
            alunos->contador = 0;
            alunos->tamanho = ALUNOS_TAM_INICIAL;
            fclose(fp);

            sucesso = 1;
        }
    }

    return sucesso;
}

void libertarAlunos(Alunos * alunos) {
    free(alunos->alunos);
}

void atualizarContadorFX(int contador, char *ficheiro) {
    FILE *fp = fopen(ficheiro, "r+b");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }
    fwrite(&contador, sizeof (int), 1, fp);
    fclose(fp);
}

void inserirAlunoFX(Alunos alunos, char *ficheiro) {
    atualizarContadorFX(alunos.contador, ficheiro);

    FILE *fp = fopen(ficheiro, "ab");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }

    /*
        imprimirAluno(alunos.alunos[alunos.contador - 1]);
     */

    fwrite(&alunos.alunos[alunos.contador - 1], sizeof (Aluno), 1, fp);

    fclose(fp);
}

void atualizarAlunoFX(Alunos alunos, int indice, char *ficheiro) {
    FILE *fp = fopen(ficheiro, "rb+");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }

    fseek(fp, sizeof (int), SEEK_SET);

    fseek(fp, sizeof (Aluno) * indice, SEEK_CUR);

    fwrite(&alunos.alunos[indice], sizeof (Aluno), 1, fp);
}

void removerAlunoFX(Alunos alunos, char *ficheiro) {
    FILE *fp = fopen(ficheiro, "wb");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }
    fwrite(&alunos.contador, sizeof (int), 1, fp);
    fwrite(alunos.alunos, sizeof (Aluno), alunos.contador, fp);
}

int inserirAluno(Alunos *alunos) {
    int numero = obterInt(MIN_NUM_ALUNO, MAX_NUM_ALUNO, MSG_OBTER_NUM_ALUNO);

    if (procurarAluno(*alunos, numero) == -1) {

        alunos->alunos[alunos->contador].numero = numero;

        lerString(alunos->alunos[alunos->contador].nome, MAX_NOME_ALUNO, MSG_OBTER_NOME);

        alunos->alunos[alunos->contador].data_nascimento.dia = obterInt(MIN_DIA, MAX_DIA, OBTER_DIA_NASC);
        alunos->alunos[alunos->contador].data_nascimento.mes = obterInt(MIN_MES, MAX_MES, OBTER_MES_NASC);
        alunos->alunos[alunos->contador].data_nascimento.ano = obterInt(MIN_ANO, MAX_ANO, OBTER_ANO_NASC);

        return alunos->contador++;
    }
    return -1;
}

void atualizarAluno(Aluno *aluno) {
    lerString((*aluno).nome, MAX_NOME_ALUNO, MSG_OBTER_NOME);
    (*aluno).data_nascimento.dia = obterInt(MIN_DIA, MAX_DIA, OBTER_DIA_NASC);
    (*aluno).data_nascimento.mes = obterInt(MIN_MES, MAX_MES, OBTER_MES_NASC);
    (*aluno).data_nascimento.ano = obterInt(MIN_ANO, MAX_ANO, OBTER_ANO_NASC);
}

void expandirAlunos(Alunos *alunos) {
    Aluno *temp = (Aluno*) realloc(alunos->alunos, sizeof (Aluno) * (alunos->tamanho * 2));
    if (temp != NULL) {
        alunos->tamanho *= 2;
        alunos->alunos = temp;
    }
}

void inserirAlunos(Alunos *alunos, char *ficheiro) {
    if (alunos->contador == alunos->tamanho) {
        expandirAlunos(alunos);
    }

    if (alunos->contador < alunos->tamanho) {
        if (inserirAluno(alunos) == -1) {
            puts(ERRO_ALUNO_EXISTE);
        } else {
            inserirAlunoFX(*alunos, ficheiro);
        }
    } else {
        puts(ERRO_LISTA_CHEIA);
    }
}

void procurarAlunos(Alunos alunos) {
    int numero = procurarAluno(alunos, obterInt(MIN_NUM_ALUNO, MAX_NUM_ALUNO, MSG_OBTER_NUM_ALUNO));

    if (numero != -1) {
        imprimirAluno(alunos.alunos[numero]);
    } else {
        puts(ERRO_ALUNO_NAO_EXISTE);
    }
}

void atualizarAlunos(Alunos *alunos, char *ficheiro) {
    int numero = procurarAluno(*alunos, obterInt(MIN_NUM_ALUNO, MAX_NUM_ALUNO, MSG_OBTER_NUM_ALUNO));

    if (numero != -1) {
        atualizarAluno(&(*alunos).alunos[numero]);

        atualizarAlunoFX(*alunos, numero, ficheiro);
    } else {
        puts(ERRO_ALUNO_NAO_EXISTE);
    }
}

void removerAlunos(Alunos *alunos, char *ficheiro) {
    int i, numero = procurarAluno(*alunos, obterInt(MIN_NUM_ALUNO, MAX_NUM_ALUNO, MSG_OBTER_NUM_ALUNO));

    if (numero != -1) {
        for (i = numero; i < alunos->contador - 1; i++) {
            alunos->alunos[i] = alunos->alunos[i + 1];
        }

        apagarDadosAluno(&alunos->alunos[i]);
        alunos->contador--;

        removerAlunoFX(*alunos, ficheiro);
    } else {
        puts(ERRO_ALUNO_NAO_EXISTE);
    }
}

void listarAlunos(Alunos alunos) {
    if (alunos.contador > 0) {
        int i;
        for (i = 0; i < alunos.contador; i++) {
            imprimirAluno(alunos.alunos[i]);
        }
    } else {
        puts(ERRO_LISTA_VAZIA);
    }
}
