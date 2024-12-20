/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GestaodeVendedores.c
 * Author: Leonardo
 *
 * Created on 11 de fevereiro de 2023, 17:55
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Input.h"
#include "GestaodeVendedores.h"

/**
 * Funcao que imprime os valores associados ás variaveis incluidas na estrutura 
 * vendedor
 * @param vendedor
 * @param mostrarcodigo
 */
void imprimirVendedor(Vendedor *vendedor, int mostrarcodigo) {
    if (mostrarcodigo == 0) {
        printf("\n*****************Vendedor******************");
        printf("\nCodigo: %d\nNome: %s\nTelefone: %d\nEmail: %s\nEstado: %s", 
                vendedor->codigo_vend, vendedor->nome, vendedor->telefone,
                vendedor->email, vendedor->estado);
        printf("\n**********************************************\n");
    } else {
        printf("\nCodigo: %d | Nome: %s", vendedor->codigo_vend,
                vendedor->nome);
    }
}

/**
 * Funcao que apagas os dados atribuidos ás variaveis
 * @param vendedor
 */
void apagarDadosVendedor(Vendedor *vendedor) {
    vendedor->codigo_vend = 0;
    strcpy(vendedor->nome, "");
    vendedor->telefone = 0;
    strcpy(vendedor->email, "");
    strcpy(vendedor->estado, "");
}

/**
 * Funcao para carregar os dados guardados dos vendedores dentro de um ficheiro
 * @param vendedores
 * @param ficheiro
 */
void carregarVendedores(Vendedores *vendedores, char *ficheiro) {
    int i;

    FILE *fp = fopen(ficheiro, "rb");
    if (fp != NULL) {

        fread(&vendedores->contador, sizeof (int), 1, fp);

        if (vendedores->contador > 0) {
            vendedores->tamanho = vendedores->contador;
            vendedores->vendedores = (Vendedor*) malloc(vendedores->contador * sizeof (Vendedor));
            for (i = 0; i < vendedores->contador; i++) {
                fread(&vendedores->vendedores[i], sizeof (Vendedor), 1, fp);

            }
        }
        fclose(fp);
    }
}

/**
 * Funcao para atribuir memoria dinamica aos vendedores
 * @param vendedores
 */
void memoriaVendedores(Vendedores *vendedores) {

    vendedores->vendedores = (Vendedor*) malloc(VEND_TAM_INICIAL * sizeof (Vendedor));
    vendedores->contador = 0;
    vendedores->tamanho = VEND_TAM_INICIAL;

}

/**
 * Funcao para guardar os dados dos vendedores dentro de um ficheiro
 * @param vendedores
 * @param ficheiro
 */
void guardarVendedores(Vendedores *vendedores, char *ficheiro) {
    int i;

    FILE *fp = fopen(ficheiro, "wb");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }

    fwrite(&vendedores->contador, sizeof (int), 1, fp);

    for (i = 0; i < vendedores->contador; i++) {
        fwrite(&vendedores->vendedores[i], sizeof (Vendedor), 1, fp);
    }
    fclose(fp);
}

/**
 * Funcao para procurar um vendedor existente
 * @param vendedores
 * @param codigo
 * @return 
 * Retorna -1 se nao existir o vendedor e i se existir vendedor
 */
int procurarVendedor(Vendedores *vendedores, int codigo) {
    int i;
    for (i = 0; i < vendedores->contador; i++) {
        if (vendedores->vendedores[i].codigo_vend == codigo) {
            return i;
        }
    }

    return -1;
}

/**
 * Funcao para verificar o estado do vendedor
 * @param vendedores
 * @param codigo
 * @return 
 * Retorna -1 se estiver inativo e i se estiver ativo
 */
int verificarEstadoVend(Vendedores *vendedores, int codigo){
    int i;
    for (i = 0; i < vendedores->contador; i++) {
        if (vendedores->vendedores[i].codigo_vend == codigo &&
                strcmp(vendedores->vendedores[i].estado, "ATIVO") == 0) {
            return i;
        }
    }

    return -1;
}

/**
 * Funcao para libertar a memoria utilizada pelos vendedores
 * @param vendedores
 */
void libertarVendedores(Vendedores *vendedores) {
    if (vendedores->vendedores) {
        free(vendedores->vendedores);
        vendedores->vendedores = NULL;
    }

    vendedores = NULL;
}

/**
 * Funcao para inserir os dados do vendedor
 * @param vendedores
 * @return 
 * Retorna -1 se o vendedor ja existir e retorna vendedores->contador++ se o 
 * vendedor nao existir
 */
int inserirVendedor(Vendedores *vendedores) {
    int codigo;
    char email[MAX_EMAIL];

    codigo = obterInt(MIN_CODIGO_VEND, MAX_CODIGO_VEND, MSG_OBTER_CODIGO_VEND);

    if (procurarVendedor(vendedores, codigo) == -1) {

        vendedores->vendedores[vendedores->contador].codigo_vend = codigo;

        lerString(vendedores->vendedores[vendedores->contador].nome,
                MAX_NOME_VEND, MSG_OBTER_NOME_VEND);

        vendedores->vendedores[vendedores->contador].telefone =
                obterInt(MIN_NUM_TELEF, MAX_NUM_TELEF, MSG_OBTER_TELEF);

        lerString(email, MAX_EMAIL, MSG_OBTER_EMAIL);
        while(validar_email(email) == 0){
            puts("Digite um formato de email valido!");
            lerString(email, MAX_EMAIL, MSG_OBTER_EMAIL);
        }
        strcpy(vendedores->vendedores[vendedores->contador].email, email);

        strlcpy(vendedores->vendedores[vendedores->contador].estado, "ATIVO", MAX_ESTADO_VEND);

        return vendedores->contador++;
    }

    return -1;
}

/**
 * Funcao para atualizar os dados do vendedor
 * @param vendedor
 */
void atualizarVendedor(Vendedor *vendedor) {
    lerString((*vendedor).nome, MAX_NOME_VEND, MSG_OBTER_NOME_VEND);
    (*vendedor).telefone = obterInt(MIN_NUM_TELEF, MAX_NUM_TELEF, MSG_OBTER_TELEF);
    lerString((*vendedor).email, MAX_EMAIL, MSG_OBTER_EMAIL);
    //strlcpy((*vendedor).estado, "ATIVO", MAX_ESTADO_FUNC);
}

/**
 * Funcao para expandir a memoria dada aos vendedores quando atinge o limite 
 * atribuido
 * @param vendedores
 */
void expandirVendedores(Vendedores *vendedores) {
    int tam = (vendedores->tamanho) == 0 ? VEND_TAM_INICIAL : vendedores->tamanho * 2;
    Vendedor *temp = (Vendedor*) realloc(vendedores->vendedores, sizeof (Vendedor) * (tam));
    if (temp != NULL) {
        vendedores->tamanho = tam;
        vendedores->vendedores = temp;
    }
}

/**
 * Funcao para validar a insercao de um vendedor
 * @param vendedores
 */
void inserirVendedores(Vendedores *vendedores) {
    if (vendedores->contador == vendedores->tamanho) {
        expandirVendedores(vendedores);
    }

    if (vendedores->contador < vendedores->tamanho) {
        if (inserirVendedor(vendedores) == -1) {
            puts(ERRO_VENDEDOR_EXISTE);
        }
    } else {
        puts(ERRO_LISTA_CHEIA);
    }
}

/**
 * Funcao para verificar se existe o vendedor que se procura
 * @param vendedores
 * @param mostrarcodigo
 */
void procurarVendedores(Vendedores *vendedores, int mostrarcodigo) {
    int codigo = procurarVendedor(vendedores,
            obterInt(MIN_CODIGO_VEND, MAX_CODIGO_VEND, MSG_OBTER_CODIGO_VEND));

    if (codigo != -1) {
        imprimirVendedor(&vendedores->vendedores[codigo], mostrarcodigo);
    } else {
        puts(ERRO_VENDEDOR_NAO_EXISTE);
    }
}

/**
 * Funcao para verificar se existe o vendedor que se quer atualizar
 * @param vendedores
 */
void atualizarVendedores(Vendedores *vendedores) {
    int codigo = procurarVendedor(vendedores, obterInt(MIN_CODIGO_VEND, MAX_CODIGO_VEND, MSG_OBTER_CODIGO_VEND));

    if (codigo != -1) {
        atualizarVendedor(&(*vendedores).vendedores[codigo]);

    } else {
        puts(ERRO_VENDEDOR_NAO_EXISTE);
    }
}

/**
 * Funcao para listar todos os vendedores existentes
 * @param vendedores
 * @param mostrarcodigo
 */
void listarVendedores(Vendedores *vendedores, int mostrarcodigo) {
    int i;
    if (vendedores->contador > 0) {
        for (i = 0; i < vendedores->contador; i++) {
            imprimirVendedor(&vendedores->vendedores[i], mostrarcodigo);
        }
    } else {
        puts(ERRO_LISTA_VAZIA);
    }
}


