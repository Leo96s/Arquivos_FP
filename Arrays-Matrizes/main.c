/*
 * File:   main.c
 * Author: ESTG
 */

#include <stdio.h>

#define NUM_ALUNOS 2
#define NUM_TESTES 3

/*
 * Demonstração de Arrays e Matrizes
 */
int main() {
    int i, j;
    float media[NUM_ALUNOS], notas[NUM_ALUNOS][NUM_TESTES];

    // Leitura dos valores
    for (i = 0; i < NUM_ALUNOS; i++) {
        printf("\nAluno %d -------------------\n", i);
        for (j = 0; j < NUM_TESTES; j++) {
            printf("Insira a nota do teste %d: ", j);
            scanf("%f", &notas[i][j]);
        }
    }

    // Calculo da media
    for (i = 0; i < NUM_ALUNOS; i++) {
        media[i] = 0;
        for (j = 0; j < NUM_TESTES; j++) {
            media[i] += notas[i][j];
        }
        media[i] /= NUM_TESTES;
    }

    // Apresentação de resultados
    puts("\nResumo da turma -------------------------------------------------");
    for (i = 0; i < NUM_ALUNOS; i++) {

        printf("\nAluno %d | media: %2.2f", i, media[i]);
        for (j = 0; j < NUM_TESTES; j++) {
            printf("\n Nota do teste %d: %2.2f", j, notas[i][j]);
        }

        if (media[i] >= 9.5) {
            printf(" \nO aluno passou");
        } else {
            printf(" \nO aluno reprovou");
        }

    }

    return 0;
}
