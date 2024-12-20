/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   menus.h
 * Author: Leonardo
 *
 * Created on 11 de fevereiro de 2023, 17:48
 */

#ifndef MENUS_H
#define MENUS_H

#include "GestaodeVendedores.h"
#include "GestaodeMercados.h"
#include "GestaodeComissoes.h"
#include "Listagens.h"

#define VENDEDORES_DB_FILE "vendedores.bin"
#define MERCADOS_DB_FILE "mercados.bin"
#define COMISSOES_DB_FILE "comissoes.bin"

/**
 * Menu de vendedores
 * @param vendedores
 * @param comissoes
 * Contem todas as fucoes disponiveis para os vendedores
 */
void menudeVendedores(Vendedores *vendedores, Comissoes *comissoes) {
    int opcao, mostrarcodigo = 0;

    if (vendedores->vendedores == 0) {
        memoriaVendedores(vendedores);
    }

    do {
        printf("\n----------------Vendedores---------------");
        printf("\n1 - Inserir");
        printf("\n2 - Procurar");
        printf("\n3 - Atualizar");
        printf("\n4 - Remover");
        printf("\n5 - Listar");
        printf("\n0 - Sair");
        printf("\n-----------------------------------------\n");
        printf("\nVendedores: %d/%d\n", vendedores->contador, vendedores->tamanho);

        printf("Opcao: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 0:
                break;
            case 1:
                inserirVendedores(vendedores);
                break;
            case 2:
                procurarVendedores(vendedores, mostrarcodigo);
                break;
            case 3:
                atualizarVendedores(vendedores);
                break;
            case 4:
                removerVendedores(vendedores, comissoes);
                break;
            case 5:
                listarVendedores(vendedores, mostrarcodigo);
                break;
            default:
                printf("\nEscolheu uma opcao que nao existe!\n");
                break;
        }
    } while (opcao != 0);
}

/**
 * Menu de Mercados
 * @param mercados
 * @param comissoes
 * Contem todas as funcoes de um mercado
 */
void menudeMercados(Mercados *mercados, Comissoes *comissoes) {
    int opcao, mostrarcodigo = 0;

    if (mercados->mercados == 0) {
        memoriaMercados(mercados);
    }
    do {
        printf("----------------Mercados---------------\n");
        printf("\n1 - Inserir");
        printf("\n2 - Procurar");
        printf("\n3 - Atualizar");
        printf("\n4 - Remover");
        printf("\n5 - Listar");
        printf("\n0 - Sair");
        printf("\nMercados: %d/%d", mercados->contador, mercados->tamanho);
        printf("\n-----------------------------------------\n");

        printf("Opcao: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 0:
                break;
            case 1:
                inserirMercados(mercados);
                break;
            case 2:
                procurarMercados(mercados, mostrarcodigo);
                break;
            case 3:
                atualizarMercados(mercados);
                break;
            case 4:
                removerMercados(mercados, comissoes);
                break;
            case 5:
                listarMercados(mercados, mostrarcodigo);
                break;
            default:
                printf("\nEscolheu uma opcao que nao existe!\n");
                break;
        }
    } while (opcao != 0);
}

/**
 * Menu de comissoes
 * @param comissoes
 * @param vendedores
 * @param mercados
 * Permite adicionar vendedores aos mercados
 */
void menudeComissoes(Comissoes *comissoes, Vendedores *vendedores,
        Mercados *mercados) {
    int opcao;

    if (comissoes->comissoes == 0) {
        memoriaComissoes(comissoes);
    }

    do {
        printf("----------------Comissoes---------------\n");
        printf("\n1 - Inserir");
        printf("\n2 - Procurar");
        printf("\n3 - Listar");
        printf("\n0 - Sair");
        printf("\nComissoes: %d/%d", comissoes->contador, comissoes->tamanho);
        printf("\n-----------------------------------------\n");

        printf("Opcao: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 0:
                break;
            case 1:
                inserirComissoes(comissoes, vendedores, mercados);
                break;
            case 2:
                procurarComissoes(comissoes, vendedores, mercados);
                break;
            case 3:
                listarComissoes(comissoes, vendedores, mercados);
                break;
            default:
                printf("\nEscolheu uma opcao que nao existe!\n");
                break;
        }
    } while (opcao != 0);
}

/**
 * Enumeracao das listagens criadas
 * @param comissoes
 * @param vendedores
 * @param mercados
 * Listagens em que eu pensei
 */
void listagens(Comissoes *comissoes, Vendedores *vendedores,
        Mercados *mercados) {
    int opcao;
    do {
        printf("\n------------------Listagens----------------\n");
        printf("\n1 - Listar vendedores ativos no mercado");
        printf("\n2 - Ranking Melhores Mercados");
        printf("\n3 - Listar mercados ativos");
        printf("\n0 - Sair");
        printf("\n-------------------------------------------\n");

        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 0:
                break;
            case 1:
                listarVendedoresAtivosMercado(comissoes, vendedores, mercados);
                break;
            case 2:
                listarRankingMercados(comissoes, mercados);
                break;
            case 3:
                listarMercadosAtivos(mercados);
                break;
            default:
                printf("\nEscolheu uma opcao que nao existe!");
                break;
        }
    } while (opcao != 0);
}

#endif /* MENUS_H */

