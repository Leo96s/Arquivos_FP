/*
 * File:   main.c
 * Author: ESTG
 */

#include <stdio.h>
#include <stdlib.h>

#include "tools.h"

/*
 * Demonstração de Memória dinámica
 */
void criarVetor(int **vetor, int *tamanho) {
    scanf("%d", tamanho);
    *vetor = (int *)calloc(*tamanho, sizeof(int));
    if (*tamanho < 0 || *vetor == NULL) {
        *tamanho = 0;
    }
}

void demo1() {
    int tamanho, *vetor = NULL;

    criarVetor(&vetor, &tamanho);

    if (tamanho > 0) {
        printf("\nt: %d p: %p", tamanho, vetor);
        free(vetor);
        vetor = NULL;
    } else {
        puts("vetor nao criado");
    }
}

void demo2(int tamanho)
{
    int i, *a = alloc_int_array(tamanho);

    for (i = 0; i < tamanho; i++) {
        a[i] = i;
    }

    print_int_array(a, tamanho, "vetor a:");

    free(a);
    a = NULL;
}

void demo3(int linhas, int colunas)
{
    int i, j, **a = alloc_int_matrix(linhas, colunas);

    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++)        {
            a[i][j] = i * j;
        }
    }

    print_int_matrix(a, linhas, colunas, "vetor a:");

    free_int_matrix(a, linhas);
}

int main()
{
    int tamanho, *vetor = NULL;
    criarVetor(&vetor, &tamanho);
    demo1();
    demo2(tamanho);
    demo3(tamanho, tamanho);
}
