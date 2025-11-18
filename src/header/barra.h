#include <iostream>

#ifndef BARRA_H
#define BARRA_H

struct Posicao {
       float x;
       float y;
};
struct Barra {
    Posicao posicao; 
    float largura;
    float altura;
    float velocidadeX;
};

void inicializarBarra(Barra *barra);

void atualizarBarra(Barra *barra, int dt);

void desenharBarra(Barra *barra);

void aumentarTamanho(Barra *barra, int tamanhoAdd); // De acordo 
#endif
