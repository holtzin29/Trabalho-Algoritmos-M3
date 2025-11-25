#ifndef FASES_H
#define FASES_H

#include "blocos.h"
#include "constantes.h"

struct Fase {
    Bloco *blocos;
    int qtdBlocos;
    int blocosAtivos;
    int capacidadeMaxima;
    int *pontosBonus;
    float *multiplicadores;
};

void inicializarFase(Fase *fase, int numeroFase);

void desenharFase(Fase *fase);

bool verificarFaseCompleta(Fase *fase);

int contarBlocosAtivos(Fase *fase);

void liberarFase(Fase *fase);

int calcularBonusFase(Fase *fase, int indice);

#endif
