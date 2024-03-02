#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define FILENAME "alunos.bin"
#define LOG_FILE "log.txt"

#define ALUNOS_MAX 10
#define STRING_MAX 40

typedef struct {
    char nome[STRING_MAX];
    int num;
} ALUNO;

void logMsg(char *msg, char *filename) {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    FILE *fp = fopen(filename, "a");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }

    fprintf(fp, "%d-%02d-%02d %02d:%02d:%02d - %s\n", tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec, msg);

    fclose(fp);
}

void escrever() {
    int i;
    ALUNO aluno;

    FILE *fp = fopen(FILENAME, "wb");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < ALUNOS_MAX; i++) {
        aluno.num = i;
        sprintf(aluno.nome, "Aluno %d", i);
        fwrite(&aluno, sizeof (ALUNO), 1, fp);
    }

    fclose(fp);
}

void lerV1() {
    int i;
    ALUNO aluno;

    FILE *fp = fopen(FILENAME, "rb");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < ALUNOS_MAX; ++i) {
        fread(&aluno, sizeof (ALUNO), 1, fp);
        printf("\nLido: %d - %s", aluno.num, aluno.nome);
    }

    fclose(fp);
}

void lerV2() {
    int i;
    ALUNO aluno[ALUNOS_MAX];

    FILE *fp = fopen(FILENAME, "rb");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }

    fread(&aluno, sizeof (ALUNO), ALUNOS_MAX, fp);

    for (i = 0; i < ALUNOS_MAX; ++i) {
        printf("\nLido: %d - %s", aluno[i].num, aluno[i].nome);
    }

    fclose(fp);
}

void lerV3() {
    int i;
    ALUNO aluno;

    FILE *fp = fopen(FILENAME, "rb");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }

    while (fread(&aluno, sizeof (ALUNO), 1, fp)) {
        printf("\nLido: %d - %s", aluno.num, aluno.nome);
    }

    fclose(fp);
}

void consultar(int indice) {
    ALUNO aluno;

    FILE *fp = fopen(FILENAME, "rb");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }

    if (fseek(fp, sizeof (ALUNO) * indice, SEEK_SET) == 0) {
        if (fread(&aluno, sizeof (ALUNO), 1, fp)) {
            printf("\nLido: %d - %s ", aluno.num, aluno.nome);
        }
    }

    fclose(fp);
}

void atualizar(int indice, char *nome) {
    ALUNO aluno;

    FILE *fp = fopen(FILENAME, "rb+");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }

    if (fseek(fp, sizeof (ALUNO) * indice, SEEK_SET) == 0) {
        if (fread(&aluno, sizeof (ALUNO), 1, fp)) {
            strcpy(aluno.nome, nome);

            fseek(fp, sizeof (ALUNO) * -1, SEEK_CUR);

            fwrite(&aluno, sizeof (ALUNO), 1, fp);
        }
    }

    fclose(fp);
}

void eliminar(int indice) {
    int i = 0;
    ALUNO aluno;

    FILE *fp = fopen(FILENAME, "rb");
    FILE *fp_tmp = fopen("tmp.bin", "wb");

    if (fp == NULL || fp_tmp == NULL) {
        exit(EXIT_FAILURE);
    }

    while (fread(&aluno, sizeof (ALUNO), 1, fp)) {
        if (i++ != indice) {
            fwrite(&aluno, sizeof (ALUNO), 1, fp_tmp);
        }
    }

    fclose(fp);
    fclose(fp_tmp);

    remove(FILENAME);
    rename("tmp.bin", FILENAME);

    fclose(fp);
}

int main() {

    escrever();
    logMsg("Adicionar", LOG_FILE);

    lerV1();
    logMsg("Listar", LOG_FILE);

    puts("");

    consultar(0);
    logMsg("Consultar", LOG_FILE);

    consultar(4);
    logMsg("Consultar", LOG_FILE);

    puts("");

    atualizar(2, "John Doe");
    logMsg("Atualizar", LOG_FILE);

    lerV2();
    logMsg("Listar2", LOG_FILE);

    puts("");

    eliminar(3);
    logMsg("Eliminar", LOG_FILE);

    lerV3();
    logMsg("Listar3", LOG_FILE);

    return 0;
}
