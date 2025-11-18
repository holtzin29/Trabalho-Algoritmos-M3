#include "./barra.h"
#include "./blocos.h"
#include "./barra.h"
#include "./jogador.h"


#ifndef JOGO_H
#define JOGO_H

struct Jogo {
    Barra barra;
    Bola Bola;
    Bloco blocos[MAX_BLOCOS];
    Jogador jogador;
    
};

#endif
