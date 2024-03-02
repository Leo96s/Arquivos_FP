/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Leonardo
 *
 * Created on 31 de outubro de 2022, 17:16
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main() {

    //Declaracao de variaveis
    int voto, ntotalvotos, votoscand1=0, votoscand2=0, votoscand3=0, votoscand4=0, votoscand5=0, votobranco=0, votonulo=0;
    float percentagemvotos;
    //Operacoes a efetuar
    do{
        printf("\nOpcoes de candidatos: \n");
        printf("0 - Voto em branco\n");
        printf("1 - Candidato1\n");
        printf("2 - Candidato2\n");
        printf("3 - Candidato3\n");
        printf("4 - Candidato4\n");
        printf("5 - Candidato5\n");
        printf("9 - Voto Nulo\n");
        printf("Digite o numero do candidato em que vai votar: ");
        scanf("%d", &voto);

        while (voto != 0 && voto != 1 && voto != 2 && voto != 3 && voto != 4 && voto != 5 && voto != 9 && voto != -1) {
            printf("Nao e uma das opcoes, por favor verifique as opcoes disponiveis.");
            printf("\nDigite o numero do candidato em que vai votar: ");
            scanf("%d", &voto);
        }
        switch (voto) {
            case 0:
                votobranco = votobranco + 1;
                break;
            case 1:
                printf("Obrigado por votar no candidato1\n");
                votoscand1++;
                break;
            case 2:
                printf("Obrigado por votar no candidato2\n");
                votoscand2++;
                break;
            case 3:
                printf("Obrigado por votar no candidato3\n");
                votoscand3++;
                break;
            case 4:
                printf("Obrigado por votar no candidato4\n");
                votoscand4++;
                break;
            case 5:
                printf("Obrigado por votar no candidato5\n");
                votoscand5 = votoscand5 + 1;
                break;
            case 9:
                votonulo++;
                break;
        }
    } while (voto != -1);
    
    ntotalvotos = votoscand1 + votoscand2 + votoscand3 + votoscand4 + votoscand5 + votonulo + votobranco;
    printf("Numero total de votos e: %d ", ntotalvotos);

    percentagemvotos = votoscand1 * 100;
    percentagemvotos = percentagemvotos / ntotalvotos;
    printf("\nO total de votos para o cadidato1 e: %d \n", votoscand1);
    printf("Tem uma percentagem de votos de: %0.2f \n ", percentagemvotos);

    percentagemvotos = votoscand2 * 100;
    percentagemvotos = percentagemvotos / ntotalvotos;
    printf("O total de votos para o cadidato2 e: %d \n", votoscand2);
    printf("Tem uma percentagem de votos de: %0.2f \n ", percentagemvotos);

    percentagemvotos = votoscand3 * 100;
    percentagemvotos = percentagemvotos / ntotalvotos;
    printf("O total de votos para o cadidato3 e: %d \n", votoscand3);
    printf("Tem uma percentagem de votos de: %0.2f \n ", percentagemvotos);

    percentagemvotos = votoscand4 * 100;
    percentagemvotos = percentagemvotos / ntotalvotos;
    printf("O total de votos para o cadidato4 e: %d \n", votoscand4);
    printf("Tem uma percentagem de votos de: %0.2f \n ", percentagemvotos);

    percentagemvotos = votoscand5 * 100;
    percentagemvotos = percentagemvotos / ntotalvotos;;
    printf("O total de votos para o adidato5 e: %d \n", votoscand5);
    printf("Tem uma percentagem de votos de: %0.2f \n ", percentagemvotos);

    percentagemvotos = votonulo * 100;
    percentagemvotos = percentagemvotos / ntotalvotos;
    printf("A percentagem de votos nulos e: %0.2f \n ", percentagemvotos);

    percentagemvotos = votobranco * 100;
    percentagemvotos = percentagemvotos / ntotalvotos;
    printf("A percentagem de votos em branco e: %0.2f \n ", percentagemvotos);


    return 0;
}

