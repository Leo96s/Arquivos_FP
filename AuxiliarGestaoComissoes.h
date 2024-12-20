/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AuxiliarGestaoComissoes.h
 * Author: Leonardo
 *
 * Created on 18 de fevereiro de 2023, 19:22
 */

#ifndef AUXILIARGESTAOCOMISSOES_H
#define AUXILIARGESTAOCOMISSOES_H

void imprimirComissao(Comissao *comissao, Vendedores *vendedores, Mercados *mercados);
void imprimirMercadoComissao(Comissao *comissao, Mercados *mercados);

void memoriaComissoes(Comissoes *comissoes);
void adicionarmemoria_vend(Comissoes *comissoes, Vendedores *vendedores);

int procurarComissao(Comissoes *comissoes, int codigo);
void procurar_vendcomissao(Comissoes *comissoes, int codigo, int *pos_vend, int *pos_comissao);

void expandir_mem_vend(Comissoes *comissoes, Vendedores *vendedores, int n_comissao);

void adicionarVendedores(Comissoes *comissoes, Vendedores *vendedores, int n_comissao, int mostrarcodigo);


#endif /* AUXILIARGESTAOCOMISSOES_H */

