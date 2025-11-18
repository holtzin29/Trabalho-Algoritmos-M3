#include <iostream>
#include "barra.h"
#ifndef BLOCO_H
#define BLOCO_H

struct Bloco {
    Posicao posicao;
    float velocidadeX;
    float velocidadeY;
    int vida;
    bool ativo;
    float largura;
    float altura;
 //     Cor corDoBloco; // TODO: Adicionar um arquivo de cores que fetch do raylib
};

void inicializarBloco(Bloco *bloco, float posicaoX, int posicaoY, int vida); // Possivelmente necessita de outro parametro 

void desenharBloco(Bloco *bloco);

#endif
