/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leonardo
 *
 * Created on 1 de novembro de 2022, 15:44
 */

#include <stdio.h>
#include <stdlib.h>
#define Empregado E
#define Chefe C
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
int main() {
    //Declaracao de variaveis
    int funcionario, dias, cargo, vencimento, continuar;
    float recebe, subsidioalimentacao, totalrecebe, irs, ss, ssp, valorfinal, bonus;
    float totalqueempresagasta;
    //Operaces a efetuar
    do {
        printf("Digite o seu codigo de funcionario: ");
        scanf("%d", &funcionario);

        printf("Digite quantos dias trabalhou este mes: ");
        scanf("%d", &dias);
        do {
            printf("\nOpcoes de cargos:\n");
            printf("1 - Empregado\n");
            printf("2 - Chefe\n");
            printf("3 - Administrador\n");
            printf("Digite o seu cargo dentro dos que estao disponiveis: ");
            scanf("%d", &cargo);
            if (cargo != 1 && cargo != 2 && cargo != 3) {
                printf("Por Favor digite um das opcoes disponiveis.");
            }
        } while (cargo != 1 && cargo != 2 && cargo != 3);

        switch (cargo) {
            case 1:
                printf("\nO valor a receber fruto vencimento e: ");
                vencimento = E * dias;
                printf("E * %d = %d$", dias, vencimento);

                if (dias > 20) {
                    printf("\nO valor a receber de bonus e: ");
                    bonus = vencimento * Bonus20dias;
                    printf("%d * Bonus20dias = %0.2f$", vencimento, bonus);
                } else if (dias > 17) {
                    printf("\nO valor a receber de bonus e: ");
                    bonus = vencimento * Bonus17dias;
                    printf("%d * Bonus17dias = %0.2f$", vencimento, bonus);
                }
                if(dias > 17){
                printf("\nO valor a receber fruto vencimento mais o bonus e: ");
                recebe = vencimento + bonus;
                printf("%d + %0.2f = %0.2f", vencimento, bonus, recebe);
                }
                
                printf("\nTotal a receber do subsidio de alimentacao e: ");
                subsidioalimentacao = dias * SAE;
                printf("%d * SAE = %0.2f$", dias, subsidioalimentacao);

                totalrecebe = recebe + subsidioalimentacao;

                printf("\nTotal a reter pelo estado: ");
                if (totalrecebe < 1000) {
                    irs = totalrecebe * IRSinf;
                    printf("%0.2f * IRSinf = %0.2f$", totalrecebe, irs);
                } else if (1000 <= totalrecebe < 2500) {
                    irs = totalrecebe * IRSinfesup;
                    printf("%0.2f * IRSinfesup = %0.2f$", totalrecebe, irs);
                } else if (totalrecebe >= 2500) {
                    irs = totalrecebe * IRSsup;
                    printf("%0.2f * IRSsup = %0.2f$", totalrecebe, irs);
                }

                printf("\nValor total a entregar a Seguranca Social pelo Funcionario: ");
                ss = totalrecebe * SSE;
                printf("%0.2f * SSE = %02.f$", totalrecebe, ss);

                printf("\nValor total a entregar a Seguranca Social pela entidade patronal: ");
                ssp = totalrecebe * SSCEP;
                printf("%0.2f * SSCEP = %0.2f$", totalrecebe, ssp);

                printf("\nValor liquido a receber pelo funcionario: ");
                valorfinal = totalrecebe - irs - ss;
                printf("%0.2f - %0.2f - %0.2f = %0.2f$", totalrecebe, irs, ss, valorfinal);

                break;
            case 2:
                printf("\nO valor a receber fruto vencimento e: ");
                vencimento = C * dias;
                printf("C * %d = %d$", dias, vencimento);

                if (dias > 20) {
                    printf("\nO valor a receber fruto vencimento mais o bonus e: ");
                    bonus = vencimento * Bonus20dias;
                    printf("%d * Bonus20dias = %0.2f$", vencimento, bonus);
                } else if (dias > 17) {
                    printf("\nO valor a receber fruto vencimento mais o bonus e: ");
                    bonus = vencimento * Bonus17dias;
                    printf("%d * Bonus17dias = %0.2f$", vencimento, bonus);
                }

                if(dias > 17){
                printf("\nO valor a receber fruto vencimento mais o bonus e: ");
                recebe = vencimento + bonus;
                printf("%d + %0.2f = %0.2f", vencimento, bonus, recebe);
                }
                printf("\nTotal a receber do subsidio de alimentacao e: ");
                subsidioalimentacao = dias * SAC;
                printf("%d * SAC = %0.2f$", dias, subsidioalimentacao);

                totalrecebe = recebe + subsidioalimentacao;

                printf("\nTotal a reter pelo estado: ");
                if (totalrecebe < 1000) {
                    irs = totalrecebe * IRSinf;
                    printf("%0.2f * IRSinf = %0.2f$", totalrecebe, irs);
                } else if (1000 <= totalrecebe < 2500) {
                    irs = totalrecebe * IRSinfesup;
                    printf("%0.2f * IRSinfesup = %0.2f$", totalrecebe, irs);
                } else if (totalrecebe >= 2500) {
                    irs = totalrecebe * IRSsup;
                    printf("%0.2f * IRSsup = %0.2f$", totalrecebe, irs);
                }

                printf("\nValor total a entregar a Seguranca Social pelo Funcionario: ");
                ss = totalrecebe * SSC;
                printf("%0.2f * SSC = %02.f$", totalrecebe, ss);

                printf("\nValor total a entregar a Seguranca Social pela entidade patronal: ");
                ssp = totalrecebe * SSCEP;
                printf("%0.2f * SSCEP = %0.2f$", totalrecebe, ssp);

                printf("\nValor liquido a receber pelo funcionario: ");
                valorfinal = totalrecebe - irs - ss;
                printf("%0.2f - %0.2f - %0.2f = %0.2f$", totalrecebe, irs, ss, valorfinal);

                break;
            case 3:
                printf("\nO valor a receber fruto vencimento e: ");
                vencimento = A * dias;
                printf("A * %d = %d$", dias, vencimento);

                if (dias > 20) {
                    printf("\nO valor a receber de bonus e: ");
                    bonus = vencimento * Bonus20dias;
                    printf("%d * Bonus20dias = %0.2f$", vencimento, bonus);
                } else if (dias > 17) {
                    printf("\nO valor a receber de bonus e: ");
                    bonus = vencimento * Bonus17dias;
                    printf("%d * Bonus17dias = %0.2f$", vencimento, bonus);
                }

                if(dias > 17){
                printf("\nO valor a receber fruto vencimento mais o bonus e: ");
                bonus = vencimento;
                printf("%d + %0.2f = %0.2f", vencimento, bonus);
                }
                
                printf("\nO valor a receber fruto vencimento mais o bonus e: ");
                recebe = vencimento + bonus;
                printf("%d + %0.2f = %0.2f", vencimento, bonus, recebe);

                printf("\nTotal a receber do subsidio de alimentacao e: ");
                subsidioalimentacao = dias * SAA;
                printf("%d * SAA = %0.2f$", dias, subsidioalimentacao);

                totalrecebe = recebe + subsidioalimentacao;

                printf("\nTotal a reter pelo estado: ");
                if (totalrecebe < 1000) {
                    irs = totalrecebe * IRSinf;
                    printf("%0.2f * IRSinf = %0.2f$", totalrecebe, irs);
                } else if (1000 <= totalrecebe < 2500) {
                    irs = totalrecebe * IRSinfesup;
                    printf("%0.2f * IRSinfesup = %0.2f$", totalrecebe, irs);
                } else if (totalrecebe >= 2500) {
                    irs = totalrecebe * IRSsup;
                    printf("%0.2f * IRSsup = %0.2f$", totalrecebe, irs);
                }

                printf("\nValor total a entregar a Seguranca Social pelo Funcionario: ");
                ss = totalrecebe * SSA;
                printf("%0.2f * SSA = %02.f$", totalrecebe, ss);

                printf("\nValor total a entregar a Seguranca Social pela entidade patronal: ");
                ssp = totalrecebe * SSAp;
                printf("%0.2f * SSAp = %0.2f$", totalrecebe, ssp);

                printf("\nValor liquido a receber pelo funcionario: ");
                valorfinal = totalrecebe - irs - ss;
                printf("%0.2f - %0.2f - %0.2f = %0.2f$", totalrecebe, irs, ss, valorfinal);

                break;

        }
        printf("Encargos totais da empresa: \n");
        totalqueempresagasta = totalrecebe + ssp;
        printf("%d", totalqueempresagasta);
        
        do{
        printf("\nDeseja continuar? 1-Sim ou 0-Nao:\n");
        scanf("%d", &continuar);
        if(continuar != 1 && continuar != 0){
            printf("Nao e uma opcao escolha de novo.");
        }
        }while (continuar != 1 && continuar != 0);
        
    } while (continuar == 1);

    return (EXIT_SUCCESS);
}

