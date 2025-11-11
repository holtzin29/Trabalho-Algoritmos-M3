#include <iostream>

#ifndef BONECOS_H
#define BONECOS_H

struct Posicao {
    int x;
    int y;
};

struct Retangulo2D {
    Posicao posicao;
    int largura;
    int altura;
};

struct Tijolo {
    Retangulo2D retangulo;
    bool ativo;
    int vidaTotal;
};

struct Bola {
    Posicao posicao;
    int radio;
    int velocidadeX;
    int velocidadeY;
    bool estaPresa;
};

struct Barra {
    Retangulo2D retangulo;
    int tamanho;
};

#endif
