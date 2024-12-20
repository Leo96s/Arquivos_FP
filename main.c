/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leonardo
 *
 * Created on 11 de fevereiro de 2023, 17:47
 */

#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "GestaodeVendedores.h"
#include "GestaodeMercados.h"
#include "GestaodeComissoes.h"

int main(int argc, char** argv) {
    int opcao, carregardados = 0, guardardados = 0;
    int carregar_dados = 0, guardar_dados = 0;

    Vendedores vendedores = {.contador = 0};
    Mercados mercados = {.contador = 0};
    Comissoes comissoes = {.contador = 0};
    
    do {
        if (carregardados != 0 && carregardados != 1 || 
                carregar_dados != 0 && carregar_dados != 1) {
            puts("Digite uma das opcoes disponiveis!");
        }
        printf("Pretende carregar os dados utilizados na ultima sessao?(0-Nao)(1-Sim): ");
        scanf("%d", &carregardados);
        if (carregardados == 0) {
            puts("Tem mesmo a certeza? Os dados anteriores serao perdidos!");
            printf("(0-Nao)(1-Sim): ");
            scanf("%d", &carregar_dados);
        }
    } while (carregardados != 0 && carregardados != 1 ||
            carregar_dados != 0 && carregar_dados != 1);

    if (carregardados == 1 || carregar_dados == 0) {
        carregarVendedores(&vendedores, VENDEDORES_DB_FILE);
        carregarMercados(&mercados, MERCADOS_DB_FILE);
        carregarComissoes(&comissoes, &vendedores, COMISSOES_DB_FILE);
    }
    
    //Menu principal
    do {
        printf("-------------------Menu------------------\n");
        printf("\n1 - Gestao de Vendores");
        printf("\n2 - Gestao de Mercados");
        printf("\n3 - Gestao de Comissoes");
        printf("\n4 - Listagens");
        printf("\n0 - Sair");
        printf("\n-----------------------------------------\n");

        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 0:
                break;
            case 1:
                menudeVendedores(&vendedores, &comissoes); // Submenu de vendedores
                break;
            case 2:
                menudeMercados(&mercados, &comissoes); // Submenu de mercados
                break;
            case 3:
                menudeComissoes(&comissoes, &vendedores, &mercados); //Submenu de comissoes
                break;
            case 4:
                listagens(&comissoes, &vendedores, &mercados); // Submenu de listagens
                break;
            default:
                printf("\nDigitou uma opcao que nao existe!\n");
                break;
        }
    } while (opcao != 0);
    
    do {
        if (guardardados != 0 && guardardados != 1 ||
                guardar_dados != 0 && guardar_dados != 1) {
            puts("Digite uma das opcoes disponiveis!");
        }
        printf("Pretende guardar os dados utilizados nesta sessao?(0-Nao)(1-Sim): ");
        scanf("%d", &guardardados);
        if (guardardados == 0) {
            puts("Tem mesmo a certeza? Os dados serao perdidos!");
            printf("(0-Nao)(1-Sim): ");
            scanf("%d", &guardar_dados);
        }
    } while (guardardados != 0 && guardardados != 1 ||
            guardar_dados != 0 && guardar_dados != 1);

    if (guardardados == 1 || guardar_dados == 0) {
        guardarVendedores(&vendedores, VENDEDORES_DB_FILE);
        guardarMercados(&mercados, MERCADOS_DB_FILE);
        guardarComissoes(&comissoes, &vendedores, COMISSOES_DB_FILE);
    }
    
    libertarVendedores(&vendedores);
    libertarMercados(&mercados);
    libertarComissoes(&comissoes);
    return (EXIT_SUCCESS);
}

