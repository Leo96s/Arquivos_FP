/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.c
 * Author: Leonardo
 *
 * Created on 14 de novembro de 2022, 17:29
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include "EmpresaXPTO.h"
#define Adiministrador A
#define E 40
#define C 60
#define A 80
#define Bonus20dias 0.05
#define Bonus17dias 0.02
#define Sembonus 
#define SAE 5
#define SAC 7.5
#define SAA 7.5
#define IRSinf 0.10
#define IRSinfesup 0.20
#define IRSsup 0.30
#define SSA 0.09
#define SSC 0.11
#define SSE 0.11
#define SSAp 0.21
#define SSCEP 0.2375

/*
 *
 */
int main(int argc, char** argv) {
    //Declaracao de variaveis
    int funcionario, dias, cargo, vencimento, continuar, mes[12], x, novovalordias;
    float recebe, subsidioalimentacao, totalrecebe, irs, ss, ssp, valorfinal, bonus, totalqueempresagasta;
    float valordos12meses = 0, total12empresagasta;

    //Operacoes a efetuar
    printf("Encargos totais da empresa\n");
    do {
        printf("\nDigite o seu codigo de funcionario: ");
        scanf("%d", &funcionario);
        do {
            printf("Opcoes de cargos:\n");
            printf("1 - Empregado\n");
            printf("2 - Chefe\n");
            printf("3 - Administrador\n");
            printf("Digite o seu cargo dentro dos que estao disponiveis: ");
            scanf("%d", &cargo);
            if (cargo != 1 && cargo != 2 && cargo != 3) {
                printf("Por Favor digite um das opcoes disponiveis.");
            }
        } while (cargo != 1 && cargo != 2 && cargo != 3);
        for (x = 0; x < 12; x++) {
            printf("Mes %d\n", x);
            printf("Digite quantos dias trabalhou no mes %d: ", x);
            scanf("%d", &dias);
            dias = validacao(funcionario, x, dias);
            
            valorfinal = contas(dias, cargo, x);
            
            printf("\nValor liquido a receber pelo funcionario no mes %d e: ", x);
            printf("%0.2lf$", valorfinal);

            valordos12meses = valordos12meses + valorfinal;
            
            totalrecebe = lertotalrecebe(cargo, dias);
            ssp = lerssp(totalrecebe, cargo);
            printf("\nEncargos totais da empresa: \n");
            totalqueempresagasta = totalrecebe + ssp;
            printf("%0.2lf", totalqueempresagasta);

            total12empresagasta = total12empresagasta + totalqueempresagasta;

            do {
                printf("\nDeseja continuar? 1-Sim ou 0-Nao:\n");
                scanf("%d", &continuar);
                if (continuar != 1 && continuar != 0) {
                    printf("Nao e uma opcao escolha de novo.");
                }
            } while (continuar != 1 && continuar != 0);
        }
        printf("Total recebido pelo funcionario dos 12 meses: \n");
        printf("%0.2lf€", valordos12meses);

        printf("\nTotal do encargo da empresa nos 12 meses: \n");
        printf("%0.2lf", total12empresagasta);
    } while (continuar == 1);


    return (EXIT_SUCCESS);
}

