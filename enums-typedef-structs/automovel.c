
#include <stdio.h>
#include <stdlib.h>

#include "automovel.h"

char *combustivelToString(Combustivel comb) {
    switch (comb) {
        case GASOLINA:
            return "GASOLINA";
            break;
        case DIESEL:
            return "DIESEL";
            break;
        default:
            return "Outro";
    }
}

void imprimirAbastecimento(int i, Abastecimento abastecimento) {
    printf("\nAbastecimento %d: %f %f %d ", i, abastecimento.preco, abastecimento.quantidade, abastecimento.kms);
}

void imprimirCarro(Automovel automovel) {
    int i;
    printf("\nMatricula: %s", automovel.matricula);
    printf("\nCilindrada: %f", automovel.cilindrada);
    printf("\nPotencia: %d", automovel.potencia);
    printf("\nCombustivel: %s", combustivelToString(automovel.comb));
    printf("\nNum. Velocidades: %d", automovel.numeroVelocidades);
    printf("\nAno: %d", automovel.ano);
    puts("\nAbastecimentos: ");
    for (i = 0; i < ABASTECIMENTOS_TAM; i++) {
        imprimirAbastecimento(i + 1, automovel.ultimosAbastecimentos[i]);
    }
}

void lerAbastecimento(int i, Abastecimento *abastecimento) {
    printf("\nAbastecimento %d:", i + 1);
    printf("\n-Preco:");
    scanf("%f", &abastecimento->preco);
    printf("-Quantidade:");
    scanf("%f", &abastecimento->quantidade);
    printf("-Kms:");
    scanf("%d", &abastecimento->kms);
}

void lerCarro(Automovel *automovel) {
    int i;
    puts("Matricula: ");
    scanf("%s", automovel->matricula);
    puts("Cilindrada: ");
    scanf("%f", &automovel->cilindrada);
    puts("Potencia: ");
    scanf("%d", &automovel->potencia);
    puts("Combustivel: [0-GASOLINA, 1-DIESEL, 2-OUTRO]");
    scanf("%d", &automovel->comb);
    puts("NumeroVelocidades: ");
    scanf("%d", &automovel->numeroVelocidades);
    puts("Ano: ");
    scanf("%d", &automovel->ano);
    for (i = 0; i < ABASTECIMENTOS_TAM; i++) {
        lerAbastecimento(i, &automovel->ultimosAbastecimentos[i]);
    }
}