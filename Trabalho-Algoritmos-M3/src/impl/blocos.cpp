#include "../header/blocos.h"
#include "../header/cores.h"
#include "../header/constantes.h"
#include "raylib.h"
#include <cmath>
#include <cstdlib>
#include <ctime>

void inicializarBloco(Bloco *bloco, float posicaoX, float posicaoY, int vida) {
    static bool seedInicializado = false;
    if (!seedInicializado) {
        srand(time(0));
        seedInicializado = true;
    }
    
    bloco->posicao.x = posicaoX;
    bloco->posicao.y = posicaoY;
    bloco->vida = vida;
    bloco->ativo = true;
    bloco->largura = BLOCO_LARGURA;
    bloco->altura = BLOCO_ALTURA;
    bloco->corAleatoria = rand() % 12;
}

void desenharBloco(Bloco *bloco) {
    if (!bloco->ativo) return;
    
    Color coresVida1[] = {
        (Color){255, 100, 100, 255}, (Color){100, 255, 100, 255},
        (Color){100, 100, 255, 255}, (Color){255, 255, 100, 255},
        (Color){255, 100, 255, 255}, (Color){100, 255, 255, 255},
        (Color){255, 150, 50, 255}, (Color){150, 255, 50, 255},
        (Color){50, 150, 255, 255}, (Color){255, 50, 150, 255},
        (Color){150, 50, 255, 255}, (Color){50, 255, 150, 255}
    };
    
    Color coresVida2[] = {
        (Color){200, 50, 50, 255}, (Color){50, 200, 50, 255},
        (Color){50, 50, 200, 255}, (Color){200, 200, 50, 255},
        (Color){200, 50, 200, 255}, (Color){50, 200, 200, 255},
        (Color){200, 100, 25, 255}, (Color){100, 200, 25, 255},
        (Color){25, 100, 200, 255}, (Color){200, 25, 100, 255},
        (Color){100, 25, 200, 255}, (Color){25, 200, 100, 255}
    };
    
    Color coresVida3[] = {
        (Color){150, 0, 0, 255}, (Color){0, 150, 0, 255},
        (Color){0, 0, 150, 255}, (Color){150, 150, 0, 255},
        (Color){150, 0, 150, 255}, (Color){0, 150, 150, 255},
        (Color){150, 75, 0, 255}, (Color){75, 150, 0, 255},
        (Color){0, 75, 150, 255}, (Color){150, 0, 75, 255},
        (Color){75, 0, 150, 255}, (Color){0, 150, 75, 255}
    };
    
    Color cor;
    if (bloco->vida >= 3) {
        cor = coresVida3[bloco->corAleatoria];
    } else if (bloco->vida == 2) {
        cor = coresVida2[bloco->corAleatoria];
    } else {
        cor = coresVida1[bloco->corAleatoria];
    }
    
    DrawRectangle((int)bloco->posicao.x, (int)bloco->posicao.y, 
                  (int)bloco->largura, (int)bloco->altura, cor);
    DrawRectangleLines((int)bloco->posicao.x, (int)bloco->posicao.y, 
                       (int)bloco->largura, (int)bloco->altura, BLACK);
}

bool verificarColisaoBloco(Bola *bola, Bloco *bloco) {
    if (!bloco->ativo) return false;

    // Encontrar ponto mais próximo da bola no bloco
    float pontoMaisProximoX = fmax(bloco->posicao.x, fmin(bola->posicao.x,
                                bloco->posicao.x + bloco->largura));
    float pontoMaisProximoY = fmax(bloco->posicao.y, fmin(bola->posicao.y,
                                bloco->posicao.y + bloco->altura));

    // Distância entre o centro da bola e o ponto mais próximo
    float distanciaX = bola->posicao.x - pontoMaisProximoX;
    float distanciaY = bola->posicao.y - pontoMaisProximoY;
    float distanciaQuadrada = distanciaX * distanciaX + distanciaY * distanciaY;

    // Verificar colisão: círculo vs retângulo
    if (distanciaQuadrada < (bola->raio * bola->raio)) {

        // Centro do bloco
        float centroBlocoX = bloco->posicao.x + bloco->largura / 2.0f;
        float centroBlocoY = bloco->posicao.y + bloco->altura / 2.0f;

        // Diferença da posição da bola para o centro do bloco
        float dx = bola->posicao.x - centroBlocoX;
        float dy = bola->posicao.y - centroBlocoY;

        float metadeLargura = bloco->largura / 2.0f;
        float metadeAltura = bloco->altura / 2.0f;

        float sobreposicaoX = metadeLargura + bola->raio - fabsf(dx);
        float sobreposicaoY = metadeAltura + bola->raio - fabsf(dy);

        // Velocidade atual da bola (módulo)
        float velocidadeAntes = sqrtf(bola->velocidadeX * bola->velocidadeX +
                                      bola->velocidadeY * bola->velocidadeY);

        // Determinar lado da colisão
        if (sobreposicaoX < sobreposicaoY) {
            // Colisão horizontal
            if (dx > 0) {
                bola->posicao.x = bloco->posicao.x + bloco->largura + bola->raio;
            } else {
                bola->posicao.x = bloco->posicao.x - bola->raio;
            }
            bola->velocidadeX = -bola->velocidadeX;

        } else {
            // Colisão vertical
            if (dy > 0) {
                bola->posicao.y = bloco->posicao.y + bloco->altura + bola->raio;
            } else {
                bola->posicao.y = bloco->posicao.y - bola->raio;
            }
            bola->velocidadeY = -bola->velocidadeY;

            // Impedir que a bola fique muito lenta no eixo Y
            if (fabsf(bola->velocidadeY) < 50.0f) {
                bola->velocidadeY = (bola->velocidadeY > 0) ? 50.0f : -50.0f;
            }
        }

        // Reajustar módulo da velocidade após o impacto
        float velocidadeDepois = sqrtf(bola->velocidadeX * bola->velocidadeX +
                                       bola->velocidadeY * bola->velocidadeY);

        if (velocidadeAntes > 0.001f && velocidadeDepois > 0.001f) {
            bola->velocidadeX *= velocidadeAntes / velocidadeDepois;
            bola->velocidadeY *= velocidadeAntes / velocidadeDepois;
        }

        return true;
    }

    return false;
}


void danificarBloco(Bloco *bloco) {
    if (bloco->ativo) {
        bloco->vida--;
        if (bloco->vida <= 0) {
            bloco->ativo = false;
        }
    }
}
