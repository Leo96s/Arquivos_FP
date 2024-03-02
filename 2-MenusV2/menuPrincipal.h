/*
 * File:   main.c
 * Author: ESTG
 */

#include "menu1.h"
#include "menu2.h"
#include "menu3.h"

#ifndef MENUPRINCIPAL_H
#define MENUPRINCIPAL_H

void menuPrincipal() {
    int opcao;

    do {
        puts("--------------------");
        puts("Menu Principal");
        puts("--------------------");
        printf("1. %s\n", TITLE_1);
        printf("2. %s\n", TITLE_2);
        printf("3. %s\n", TITLE_3);
        puts("0. Sair");
        puts("--------------------");

        puts("Insira a sua opção [1-4]:");
        scanf("%d", &opcao);

        switch (opcao) {
            case 0:
                break;
            case 1:
                menu1(); // com validacao de input
                break;
            case 2:
                menu2(); // sem validacao de input
                break;
            case 3:
                menu3();
                break;
            default:
                puts("Opção inválida!");
                break;
        }

    } while (opcao != 0);
}

#endif /* MENUPRINCIPAL_H */

