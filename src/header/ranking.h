#include <iostream>
#include "./jogador.h"
#include "./constantes.h"
#ifndef RANKING_H
#define RANKING_H

struct Ranking {
    Jogador jogadores[MAX_JOGADORES];
    int qtdJogadores;
};

void inicializarRanking(Ranking *ranking, char *arquivo);

void atualizarRanking(Ranking *ranking, Jogador jogador);

void salvarRanking(Ranking *ranking);

void carregarRanking(Ranking *ranking);

void desenharRanking(Ranking *ranking);

#endif
