#ifndef GRAFICOS_H
#define GRAFICOS_H

#include "raylib.h"

void desenharFundo(int fase, float tempo);

void desenharFundoFloresta(float tempo);

void desenharFundoOceano(float tempo);

void desenharFundoVulcao(float tempo);

// Initialize graphics assets (loads background/menu images if present)
void inicializarGraficos();

// Unload graphics assets
void descarregarGraficos();

// Draw menu background (uses loaded image when available, otherwise clears to white)
void desenharBackgroundMenu();

#endif
