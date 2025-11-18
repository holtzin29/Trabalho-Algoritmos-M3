#include <iostream>

#ifndef JOGADOR_H
#define JOGADOR_H

struct Jogador {
    char nome[50];
    char data[20]; // [17/11/2025]
    int pontuacao;
    int tempoJogado;
    int vidas;
};

void adicionarJogador(Jogador *j, char nome);

void atualizarPontuacao(Jogador *j, int numPts);

#endif
