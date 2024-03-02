/*
 * File:   main.c
 * Author: ESTG
 */

#include <stdio.h>

#include "menu1.h"

void menu1_1() {
    puts("Acedeu à opção 1.1");
}

void menu1_2() {
    puts("Acedeu à opção 1.2");
}

void menu1() {
    int opcao;

    do {
        puts("----------");
        puts(TITLE_1);
        puts("----------");
        puts("1. Opção 1.1");
        puts("2. Opção 1.2");
        puts("0. Voltar");

        puts("Insira a sua opção:");
        scanf("%d", &opcao);

        switch (opcao) {
            case 0:
                break;
            case 1:
                menu1_1();
                break;
            case 2:
                menu1_2();
                break;
            default:
                puts("Opção inválida!");
                break;
        }

    } while (opcao != 0);

}
