#include <iostream>
#include "./barra.h"
#ifndef BOLA_H
#define BOLA_H

struct Bola {
    Posicao posicao;
    float raio;
    float velocidadeX;
    float velocidadeY;
    bool presa;
};

void inicializarBola(Bola *bola); 

void atualizarBola(Bola *bola, int dt);

void desenharBola(Bola *bola);

void lancarBola(Bola *bola, int velocidadeDeLancamento, float anguloLancamento);

void ColisaoBloco(Bola *bola, Bloco *bloco );


#endif
