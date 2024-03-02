#ifndef AUTOMOVEL_H
#define AUTOMOVEL_H

#define ABASTECIMENTOS_TAM 3

typedef enum {
    GASOLINA, DIESEL, OUTRO
} Combustivel;

typedef struct {
    float quantidade, preco;
    int kms;
} Abastecimento;

typedef struct {
    char matricula[9];
    int ano, potencia, numeroVelocidades;
    float cilindrada;
    Combustivel comb;
    Abastecimento ultimosAbastecimentos[ABASTECIMENTOS_TAM];
} Automovel;

void lerCarro(Automovel *automovel);
void imprimirCarro(Automovel automovel);

#endif /* AUTOMOVEL_H */

