/*
 * File:   main.c
 * Author: ESTG
 */

#include <stdio.h>

#include "alunos.h"
#include "input.h"

/*
 * Demonstração de gestão de registos
 */
int main() {
    int opcao;
    Alunos alunos = {.contador = 0};

    do {
        printf("\nAlunos------------------------------------------------------");
        printf("\n1 - Inserir");
        printf("\n2 - Procurar");
        printf("\n3 - Atualizar");
        printf("\n4 - Remover");
        printf("\n5 - Listar");
        printf("\n0 - Sair");
        printf("\n------------------------------------------------------------");
        printf("\nAlunos: %d/%d", alunos.contador, MAX_ALUNOS);

        printf("\nOpcão: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 0:
                break;
            case 1:
                inserirAlunos(&alunos);
                break;
            case 2:
                procurarAlunos(alunos);
                break;
            case 3:
                atualizarAlunos(&alunos);
                break;
            case 4:
                removerAlunos(&alunos);
                break;
            case 5:
                listarAlunos(alunos);
                break;
            default:
                printf("\nOpcão invalida!");
        }

    } while (opcao != 0);

    return 0;
}
