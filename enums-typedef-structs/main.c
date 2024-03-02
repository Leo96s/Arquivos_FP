/*
 * File:   main.c
 * Author: ESTG
 */

#include <stdio.h>

#include "automovel.h"

/*
 * Demonstração de registos
 */
int main() {
    Automovel carro;

    lerCarro(&carro);

    imprimirCarro(carro);

    return 0;
}
