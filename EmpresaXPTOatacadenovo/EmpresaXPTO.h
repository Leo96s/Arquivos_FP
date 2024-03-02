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
long contas(int dias, int cargo, int x){
    int vencimento;
    float recebe, subsidioalimentacao, totalrecebe, irs, ss, ssp, bonus, valorfinal;
    switch (cargo) {
                case 1:
                    printf("\nO valor a receber fruto vencimento no mes %d e: ", x);
                    vencimento = E * dias;
                    printf("E * %d = %d$", dias, vencimento);

                    if (dias > 20) {
                        printf("\nO valor a receber de bonus no mes %d e: ", x);
                        bonus = vencimento * Bonus20dias;
                        printf("%d * Bonus20dias = %0.2f$", vencimento, bonus);
                    } else if (dias > 17) {
                        printf("\nO valor a receber de bonus no mes %d e: ", x);
                        bonus = vencimento * Bonus17dias;
                        printf("%d * Bonus17dias = %0.2f$", vencimento, bonus);
                    } else if (dias < 17) {
                        bonus = vencimento;
                    }
                    recebe = bonus + vencimento;
                    
                    printf("\nTotal a receber do subsidio de alimentacao no mes %d e: ", x);
                    subsidioalimentacao = dias * SAE;
                    printf("%d * SAE = %0.2f$", dias, subsidioalimentacao);

                    totalrecebe = recebe + subsidioalimentacao;
                    
                    printf("\nTotal a reter pelo estado no mes %d: ", x);
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

                    printf("\nValor total a entregar a Seguranca Social pela entidade patronal no mes %d: ", x);
                    ssp = totalrecebe * SSCEP;
                    printf("%0.2f * SSCEP = %0.2f$", totalrecebe, ssp);
                    break;
                case 2:
                    printf("\nO valor a receber fruto vencimento no mes %d e: ", x);
                    vencimento = C * dias;
                    printf("C * %d = %d$", dias, vencimento);

                    if (dias > 20) {
                        printf("\nO valor a receber fruto vencimento mais o bonus no mes %d e: ", x);
                        bonus = vencimento * Bonus20dias;
                        printf("%d * Bonus20dias = %0.2f$", vencimento, bonus);
                    } else if (dias > 17) {
                        printf("\nO valor a receber fruto vencimento mais o bonus no mes %d e: ", x);
                        bonus = vencimento * Bonus17dias;
                        printf("%d * Bonus17dias = %0.2f$", vencimento, bonus);
                    } else if (dias < 17) {
                        bonus = vencimento;
                    }
                    recebe = bonus + vencimento;
                    
                    printf("\nTotal a receber do subsidio de alimentacao no mes %d e: ", x);
                    subsidioalimentacao = dias * SAC;
                    printf("%d * SAC = %0.2f$", dias, subsidioalimentacao);

                    totalrecebe = recebe + subsidioalimentacao;
                    
                    printf("\nTotal a reter pelo estado no mes %d: ", x);
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

                    printf("\nValor total a entregar a Seguranca Social pelo Funcionariono mes %d: ", x);
                    ss = totalrecebe * SSC;
                    printf("%0.2f * SSC = %02.f$", totalrecebe, ss);

                    printf("\nValor total a entregar a Seguranca Social pela entidade patronal no mes %d: ", x);
                    ssp = totalrecebe * SSCEP;
                    printf("%0.2f * SSCEP = %0.2f$", totalrecebe, ssp);
                    break;
                case 3:
                    printf("\nO valor a receber fruto vencimento no mes %d: ", x);
                    vencimento = A * dias;
                    printf("A * %d = %d$", dias, vencimento);

                    if (dias > 20) {
                        printf("\nO valor a receber de bonus no mes %d e: ", x);
                        bonus = vencimento * Bonus20dias;
                        printf("%d * Bonus20dias = %0.2f$", vencimento, bonus);
                    } else if (dias > 17) {
                        printf("\nO valor a receber de bonus no mes %d e: ", x);
                        bonus = vencimento * Bonus17dias;
                        printf("%d * Bonus17dias = %0.2f$", vencimento, bonus);
                    } else if (dias < 17) {
                        bonus = vencimento;
                    }
                    recebe = bonus + vencimento;
                    
                    printf("\nO valor a receber fruto vencimento mais o bonus no mes %d e: ", x);
                    recebe = vencimento + bonus;
                    printf("%d + %0.2f = %0.2f", vencimento, bonus, recebe);

                    printf("\nTotal a receber do subsidio de alimentacao no mes %d e: ", x);
                    subsidioalimentacao = dias * SAA;
                    printf("%d * SAA = %0.2f$", dias, subsidioalimentacao);

                    totalrecebe = recebe + subsidioalimentacao;
                    
                    printf("\nTotal a reter pelo estado no mes %d: ", x);
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

                    printf("\nValor total a entregar a Seguranca Social pelo Funcionario no mes %d: ", x);
                    ss = totalrecebe * SSA;
                    printf("%0.2f * SSA = %02.f$", totalrecebe, ss);

                    printf("\nValor total a entregar a Seguranca Social pela entidade patronal no mes %d: ", x);
                    ssp = totalrecebe * SSAp;
                    printf("%0.2f * SSAp = %0.2f$", totalrecebe, ssp);
                    break;
    }
    return totalrecebe - irs - ss;
}
long lertotalrecebe(int cargo, int dias){
    int vencimento;
    float bonus, subsidioalimentacao, recebe;
    switch (cargo) {
                case 1:
                    vencimento = E * dias;
                    if (dias > 20) {
                        bonus = vencimento * Bonus20dias;
                    } else if (dias > 17) {
                        bonus = vencimento * Bonus17dias;
                    } else if (dias < 17) {
                        bonus = vencimento;
                    }   
                    subsidioalimentacao = dias * SAE;

                    break;
                case 2:
                    vencimento = C * dias;


                    if (dias > 20) {
                        bonus = vencimento * Bonus20dias;
                    } else if (dias > 17) {
                       bonus = vencimento * Bonus17dias;
                    } else if (dias < 17) {
                        recebe = vencimento;
                    }
                    subsidioalimentacao = dias * SAC;
                    break;
                case 3:
                    vencimento = A * dias;

                    if (dias > 20) {
                        bonus = vencimento * Bonus20dias;
                    } else if (dias > 17) {
                        bonus = vencimento * Bonus17dias;
                    } else if (dias < 17) {
                        bonus = vencimento;
                    }
                    recebe = vencimento + bonus;
                    subsidioalimentacao = dias * SAA;
                    break;
    }
    return recebe + subsidioalimentacao;
}
long lerssp(float totalrecebe, int cargo){
    if(cargo == 1 || cargo == 2 ){
        return totalrecebe * SSCEP;
    } else{
        return totalrecebe * SSAp;
    }      
}
long validacao(int funcionario, int x, int dias) {
        while (funcionario > 1000 || funcionario < 0) {
            printf("Esse valor nao e valido, por favor verifique o seu valor de funcionario.\n");
            printf("Digite o seu codigo de funcionario: ");
            scanf("%d", &funcionario);
        }
        while (dias > 31 || dias < 0) {
            printf("Esse valor nao e valido, por favor, verifique o valor digitado de dias trabalhados.\n");
            printf("Digite quantos dias trabalhou no mes %d: ", x);
            scanf("%d", &dias);
        }
        return dias;
}
