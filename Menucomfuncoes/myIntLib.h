long somar(int n1, int n2){
    return n1 + n2;
}
long subtrair(int n1, int n2){
    return n1 - n2;
}
long multiplicar(int n1, int n2){
    return n1 * n2;
}
float dividir(int n1, int n2){
    return  (float) n1 / n2;
}
int potencia(int n1, int n2){
    int resultado;
    if(n2 == 0){
        return 1;
    }else if (n2 > 0){
        return n1 * potencia(n1, n2 - 1);
    } else if (n2 < 0){
        return 1 / potencia(n1, -n2);
    }
}