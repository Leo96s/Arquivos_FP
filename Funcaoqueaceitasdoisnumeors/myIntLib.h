int potencia(int x, int y){
    int resultado;
    if(y == 0){
        return 1;
    }else if (y > 0){
        return x * potencia(x, y - 1);
    } else if (y < 0){
        return 1 / potencia(x, -y);
    }
}

