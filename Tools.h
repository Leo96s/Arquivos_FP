/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Auxilio.h
 * Author: Leonardo
 *
 * Created on 15 de fevereiro de 2023, 18:03
 */

#ifndef AUXILIO_H
#define AUXILIO_H
#include "GestaodeComissoes.h"

void inserirDataRegisto(int *dia, int *mes, int *ano);
void inserirDataFim(int *dia, int *mes, int *ano);

int compararDatas(Comissoes *comissoes, Data *data1, Data *data2, int n_comissao, int codvend);


#endif /* AUXILIO_H */

