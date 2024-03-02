/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leonardo
 *
 * Created on 23 de outubro de 2022, 14:35
 */

#include <stdio.h>
#include <stdlib.h>
#define Empregado E
#define Chefe C
#define Adiministrador A
#define E 40
#define C 60
#define A 80
#define SAE 5
#define SAC 7.5
#define SAA 7.5
#define IRSinf 0.1
#define IRSsup 0.2
#define SSA 0.9
#define SSC 0.11
#define SSE 0.11
#define SSAP 0.21
#define SSCP 0.2375
#define SSEP 0.2375
/*
 * 
 */
int main() {
    
    //Declaração de variáveis
    int funcionario, cargo, diastrabalhados;
    float valorfrutovencimento, subsidiodealimentação, irs, valortotal, ss, pagamento, ssp;
    
    //Interpretação de variáveis
    printf("Código do funcionário: ");
    scanf("%d", &funcionario);
    
    printf("Dias que trabalhou este mês: ");
    scanf("%d", &diastrabalhados);
    
    printf("Cargos disponivéis: \n");
    printf("1 - Empregado\n");
    printf("2 - Chefe\n");
    printf("3 - Administrador\n");
    
    printf("Escolha um dos cargos a cima disponivéis: ");
    scanf("%d", &cargo);
    
    //Operações a efetuar
    switch (cargo) {
        case 1:
            printf("\nValor liquido a receber fruto do vencimento: ");
            valorfrutovencimento = diastrabalhados * E;
            printf("%d * E = %0.2f$", diastrabalhados, valorfrutovencimento);
            
            printf("\nTotal do subsidio de alimentação: ");
            subsidiodealimentação = diastrabalhados * SAE;
            printf("%d * SAE = %0.2f$", diastrabalhados, subsidiodealimentação);
             
            valortotal = valorfrutovencimento + subsidiodealimentação;
            
            printf("\nValor de retenção do IRS a entregar ao estado: ");
            if(valortotal <1000 ){
                irs = valortotal * IRSinf;
                printf("%0.2f * IRSinf = %0.2f$", valortotal, irs);
            } else if (valortotal >= 1000 ){
                irs = valortotal * IRSsup;
                printf("%0.2f * IRSsup = %0.2f$", valortotal, irs);
            }
            
            printf("\nValor total a entregar à Segurança Social: ");
            ss = valortotal * SSE;
            printf("%0.2f * SSE = %0.2f$", valortotal, ss);
            
            printf("\nValor total a entregar à Segurança Social da entidade patronal: ");
            ssp = valortotal * SSEP;
            printf("%0.2f * SSEP = %0.2f$", valortotal, ssp);
            
            printf("\nValor liquido a receber pelo funcionário: ");
            pagamento = valortotal - irs - ss;
            printf("%0.2f - %0.2f - %0.2f = %0.2f$", valortotal, irs, ss, pagamento);
                    
            break;
            
        case 2: 
            printf("\nValor liquido a receber fruto do vencimento: ");
            valorfrutovencimento = diastrabalhados * C;
            printf("%d * C = %0.2f$", diastrabalhados, valorfrutovencimento);
            
            printf("\nTotal do subsidio de alimentação: ");
            subsidiodealimentação = diastrabalhados * SAC;
            printf("%d * SAC = %0.2f$", diastrabalhados, subsidiodealimentação);
            
            valortotal = valorfrutovencimento + subsidiodealimentação;
            
            printf("\nValor de retenção do IRS a entregar ao estado: ");
            if(valortotal <1000 ){
                irs = valortotal * IRSinf;
                printf("%0.2f * IRSinf = %0.2f$", valortotal, irs);
            } else if (valortotal >= 1000 ){
                irs = valortotal * IRSsup;
                printf("%0.2f * IRSsup = %0.2f$", valortotal, irs);
            }
            
            printf("\nValor total a entregar à Segurança Social: ");
            ss = valortotal * SSC;
            printf("%0.2f * SSC = %0.2f$", valortotal, ss);
            
            printf("\nValor total a entregar à Segurança Social da entidade patronal: ");
            ssp = valortotal * SSCP;
            printf("%0.2f * SSCP = %0.2f$", valortotal, ssp);
            
            printf("\nValor liquido a receber pelo funcionário: ");
            pagamento = valortotal - irs - ss;
            printf("%0.2f - %0.2f - %0.2f = %0.2f$", valortotal, irs, ss, pagamento);
            break;
            
        case 3:
            printf("\nValor liquido a receber fruto do vencimento: ");
            valorfrutovencimento = diastrabalhados * A;
            printf("%d * A = %0.2f$", diastrabalhados, valorfrutovencimento);
            
            printf("\nTotal do subsidio de alimentação: ");
            subsidiodealimentação = diastrabalhados * SAA;
            printf("%d * SAA = %0.2f$", diastrabalhados, subsidiodealimentação);
            
            valortotal = valorfrutovencimento + subsidiodealimentação;
            
            printf("\nValor de retenção do IRS a entregar ao estado: ");
            if(valortotal <1000 ){
                irs = valortotal * IRSinf;
                printf("%0.2f * IRSinf = %0.2f$", valortotal, irs);
            } else if (valortotal >= 1000 ){
                irs = valortotal * IRSsup;
                printf("%0.2f * IRSsup = %0.2f$", valortotal, irs);
            }
            
            printf("\nValor total a entregar à Segurança Social: ");
            ss = valortotal * SSA;
            printf("%0.2f * SSA = %0.2f$", valortotal, ss);
            
            printf("\nValor total a entregar à Segurança Social da entidade patronal: ");
            ssp = valortotal * SSAP;
            printf("%0.2f * SSAP = %0.2f$", valortotal, ssp);
         
            printf("\nValor liquido a receber pelo funcionário: ");
            pagamento = valortotal - irs - ss;
            printf("%0.2f - %0.2f - %0.2f = %0.2f$", valortotal, irs, ss, pagamento);
            break;                    
    }
    
    return (EXIT_SUCCESS);
}

