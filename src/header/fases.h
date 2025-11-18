#include <iostream>
#include "./blocos.h"
#include "./constantes.h"
#include "./itens.h"
#ifndef FASES_H
#define FASES_H

struct Fase {
    Bloco blocos[MAX_BLOCOS];
    int qtd;
};

void inicializarFase(Fase *f, int qtd);

bool terminarFase();

void desenharFase();

int inicializarItens(Fase *f, Item *itens[], int qtdMaxItens);



#endif
