#ifndef BLOCO_H
#define BLOCO_H

#include "barra.h"
#include "bola.h"

struct Bloco {
    Posicao posicao;
    int vida;
    bool ativo;
    float largura;
    float altura;
    int corAleatoria;
};

void inicializarBloco(Bloco *bloco, float posicaoX, float posicaoY, int vida);

void desenharBloco(Bloco *bloco);

bool verificarColisaoBloco(Bola *bola, Bloco *bloco);

void danificarBloco(Bloco *bloco);

#endif
