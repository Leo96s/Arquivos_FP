/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Listagens.h
 * Author: Leonardo
 *
 * Created on 11 de fevereiro de 2023, 17:54
 */

#ifndef LISTAGENS_H
#define LISTAGENS_H
#include "GestaodeComissoes.h"
#include "GestaodeMercados.h"

void listarRankingMercados(Comissoes *comissoes, Mercados *mercados);
void listarMercadosAtivos(Mercados *mercados);
void listarVendedoresAtivosMercado(Comissoes *comissoes, Vendedores *vendedores, Mercados *mercados);
void listarMelhorVendedorComissao(Comissoes *comissoes, Mercados *mercados, Vendedores *vendedores);
#endif /* LISTAGENS_H */

