/*
 * File:   main.c
 * Author: ESTG
 */

#include <stdio.h>

#include "menu2.h"

void menu2_1() {
    puts("Acedeu à opção 1.1");
}

void menu2_2() {
    puts("Acedeu à opção 1.2");
}

void menu2() {
    int opcao;

    do {
        puts("----------");
        puts(TITLE_2);
        puts("----------");
        puts("1. Opção 2.1");
        puts("2. Opção 2.2");
        puts("0. Voltar");

        do {
            puts("Insira a sua opção:");
            scanf("%d", &opcao);
        } while (opcao < 0 || opcao > 2);

        switch (opcao) {
            case 0:
                break;
            case 1:
                menu2_1();
                break;
            case 2:
                menu2_2();
                break;
        }

    } while (opcao != 0);

}
