#include <iostream>
#include "./barra.h"
#ifndef ITENS_H
#define ITENS_H

struct Item {
     Posicao posicaoItem;
     int tipo; 
     float velocidadeY; // Um item so se move verticalmente
     float largura;
     float altura;
     bool ativo;
};  

void inicializarItem(Item *item, Posicao posicaoItem, int tipo);

void atualizarItem(Item *item, int dt);

#endif
