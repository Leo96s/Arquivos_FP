/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>

#include "alunos.h"
#include "logs.h"

#define LOGS_FILE       "logs.txt"
#define ALUNOS_DB_FILE  "alunos.bin"

/*
 * Demonstração de gestão de registos
 */
int main() {
    int opcao;
    Alunos alunos;

    if (carregarAlunos(&alunos, ALUNOS_DB_FILE)) {

        do {
            printf("\nAlunos------------------------------------------------------");
            printf("\n1 - Inserir");
            printf("\n2 - Procurar");
            printf("\n3 - Atualizar");
            printf("\n4 - Remover");
            printf("\n5 - Listar");
            printf("\n0 - Sair");
            printf("\n------------------------------------------------------------");
            printf("\nAlunos: %d/%d", alunos.contador, alunos.tamanho);

            printf("\nOpcão: ");
            scanf("%d", &opcao);

            switch (opcao) {
                case 0:
                    break;
                case 1:
                    inserirAlunos(&alunos, ALUNOS_DB_FILE);
                    logMsg("Inserir", LOGS_FILE);
                    break;
                case 2:
                    procurarAlunos(alunos);
                    logMsg("Procurar", LOGS_FILE);
                    break;
                case 3:
                    atualizarAlunos(&alunos, ALUNOS_DB_FILE);
                    logMsg("Actualizar", LOGS_FILE);
                    break;
                case 4:
                    removerAlunos(&alunos, ALUNOS_DB_FILE);
                    logMsg("Remover", LOGS_FILE);
                    break;
                case 5:
                    listarAlunos(alunos);
                    logMsg("Listar", LOGS_FILE);
                    break;
                default:
                    printf("\nOpcão invalida!");
            }

        } while (opcao != 0);

        libertarAlunos(&alunos);

    } else {
        puts("Não foi possível criar o ficheiro de armazenamento.");
    }

    return 0;
}

