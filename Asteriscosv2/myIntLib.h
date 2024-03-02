void asteriscos(int valor, int i) {       
    while (valor < 1 || valor > 20){
        printf("Por favor digite um valor dentro do intervalo.");
        printf("\nDigite um valor: ");
        scanf("%d", &valor);
    }
    for (i = 1; i <= valor; i++) {
        printf("*");
    }
}

