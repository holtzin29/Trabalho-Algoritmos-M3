#include "../header/fases.h"
#include "../header/constantes.h"
#include "../header/utils.h"
#include "raylib.h"
#include <cstdlib>

void inicializarFase(Fase *fase, int numeroFase) {
    fase->qtdBlocos = 0;
    fase->blocosAtivos = 0;
    
    int linhas = 3 + numeroFase;
    int colunas = 10;
    fase->capacidadeMaxima = linhas * colunas;
    
    fase->blocos = (Bloco*)malloc(fase->capacidadeMaxima * sizeof(Bloco));
    fase->pontosBonus = alocarArrayInt(fase->capacidadeMaxima);
    fase->multiplicadores = alocarArrayFloat(fase->capacidadeMaxima);
    float espacamentoX = 10.0f;
    float espacamentoY = 10.0f;
    float inicioX = (SCREEN_WIDTH - (colunas * BLOCO_LARGURA + (colunas - 1) * espacamentoX)) / 2.0f;
    float inicioY = 50.0f;

    for (int i = 0; i < linhas && fase->qtdBlocos < fase->capacidadeMaxima; i++) {
        for (int j = 0; j < colunas && fase->qtdBlocos < fase->capacidadeMaxima; j++) {
            float x = inicioX + j * (BLOCO_LARGURA + espacamentoX);
            float y = inicioY + i * (BLOCO_ALTURA + espacamentoY);
            
            int vida = 1;
            int aleatorio = GetRandomValue(0, 100);
            
            if (numeroFase >= 2) {
                if (aleatorio < 20) {
                    vida = 3;
                } else if (aleatorio < 50) {
                    vida = 2;
                } else {
                    vida = 1;
                }
            } else {
                if (aleatorio < 30) {
                    vida = 2;
                } else {
                    vida = 1;
                }
            }

            inicializarBloco(&fase->blocos[fase->qtdBlocos], x, y, vida);
            fase->qtdBlocos++;
            fase->blocosAtivos++;
        }
    }
}

void desenharFase(Fase *fase) {
    for (int i = 0; i < fase->qtdBlocos; i++) {
        desenharBloco(&fase->blocos[i]);
    }
}

bool verificarFaseCompleta(Fase *fase) {
    return contarBlocosAtivos(fase) == 0;
}

int contarBlocosAtivos(Fase *fase) {
    if (fase->qtdBlocos == 0) {
        fase->blocosAtivos = 0;
        return 0;
    }
    int count = contarBlocosRecursivo(fase->blocos, 0, fase->qtdBlocos - 1);
    fase->blocosAtivos = count;
    return count;
}

void liberarFase(Fase *fase) {
    if (fase->blocos != NULL) {
        free(fase->blocos);
        fase->blocos = NULL;
    }
    if (fase->pontosBonus != NULL) {
        liberarArray(fase->pontosBonus);
        fase->pontosBonus = NULL;
    }
    if (fase->multiplicadores != NULL) {
        liberarArray(fase->multiplicadores);
        fase->multiplicadores = NULL;
    }
}

int calcularBonusFase(Fase *fase, int indice) {
    if (indice < 0 || indice >= fase->qtdBlocos) {
        return 0;
    }
    return fase->pontosBonus[indice];
}
