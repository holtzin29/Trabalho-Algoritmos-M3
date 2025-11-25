#include "../header/graficos.h"
#include "../header/constantes.h"
#include <cmath>

void desenharFundo(int fase, float tempo) {
    if (fase == 1) {
        desenharFundoFloresta(tempo);
    } else if (fase == 2) {
        desenharFundoOceano(tempo);
    } else {
        desenharFundoVulcao(tempo);
    }
}

void desenharFundoFloresta(float tempo) {
    for (int y = 0; y < SCREEN_HEIGTH; y += 2) {
        float t = (float)y / SCREEN_HEIGTH;
        int r = (int)(135 - t * 50);
        int g = (int)(206 - t * 80);
        int b = (int)(235 - t * 100);
        DrawRectangle(0, y, SCREEN_WIDTH, 2, (Color){r, g, b, 255});
    }
    
    for (int i = 0; i < 15; i++) {
        int seed = i * 7919;
        int x = (seed * 73) % SCREEN_WIDTH;
        int y = 100 + (seed % 250);
        float offset = sinf(tempo * 2.0f + i) * 8.0f;
        DrawCircle(x + (int)offset, y, 12 + (seed % 8), Fade(WHITE, 0.8f));
    }
    
    DrawRectangle(0, SCREEN_HEIGTH - 60, SCREEN_WIDTH, 60, (Color){76, 175, 80, 255});
    
    for (int i = 0; i < 40; i++) {
        int seed = i * 2654;
        int x = (seed * 131) % SCREEN_WIDTH;
        int y = SCREEN_HEIGTH - 60 + (seed % 20);
        float balanco = sinf(tempo * 4.0f + i * 0.3f) * 4.0f;
        DrawRectangle(x + (int)balanco, y, 2, 10, (Color){46, 125, 50, 255});
    }
    
    for (int i = 0; i < 10; i++) {
        int seed = i * 5381;
        int x = (seed * 97) % SCREEN_WIDTH;
        int altura = 100 + (seed % 60);
        
        DrawRectangle(x - 6, SCREEN_HEIGTH - altura - 60, 12, altura, (Color){101, 67, 33, 255});
        DrawCircle(x, SCREEN_HEIGTH - altura - 80, 30, (Color){34, 139, 34, 255});
        DrawCircle(x - 15, SCREEN_HEIGTH - altura - 70, 20, (Color){46, 125, 50, 255});
        DrawCircle(x + 15, SCREEN_HEIGTH - altura - 70, 20, (Color){27, 94, 32, 255});
    }
    
    for (int lado = 0; lado < 2; lado++) {
        int baseX = lado == 0 ? 5 : SCREEN_WIDTH - 25;
        
        for (int i = 0; i < 6; i++) {
            int y = i * 100 + 50;
            float balanco = sinf(tempo * 3.0f + i * 0.5f) * 10.0f;
            
            DrawRectangle(baseX + 8, y, 4, 100, (Color){101, 67, 33, 200});
            
            for (int j = 0; j < 4; j++) {
                int folhaY = y + j * 25;
                int folhaX = baseX + 10 + (int)(balanco * (1.0f - j * 0.2f));
                DrawEllipse(folhaX, folhaY, 10, 6, (Color){34, 139, 34, 220});
            }
        }
    }
}

void desenharFundoOceano(float tempo) {
    for (int y = 0; y < SCREEN_HEIGTH; y += 2) {
        float t = (float)y / SCREEN_HEIGTH;
        float onda = sinf(tempo * 0.8f + t * 8.0f) * 3.0f;
        int r = (int)(30 + t * 20 + onda);
        int g = (int)(100 + t * 50 + onda);
        int b = (int)(180 + t * 50);
        DrawRectangle(0, y, SCREEN_WIDTH, 2, (Color){r, g, b, 255});
    }
    
    for (int i = 0; i < 25; i++) {
        int seed = i * 3571;
        int x = (seed * 89) % SCREEN_WIDTH;
        int y = 50 + (seed % 200);
        int tamanho = 10 + (seed % 15);
        int alpha = 80 + (seed % 100);
        float movimento = sinf(tempo * 1.5f + i * 0.3f) * 30.0f;
        DrawCircle(x, y + (int)movimento, tamanho, (Color){150, 200, 255, alpha});
    }
    
    DrawRectangle(0, SCREEN_HEIGTH - 40, SCREEN_WIDTH, 40, (Color){194, 178, 128, 255});
    
    for (int i = 0; i < 25; i++) {
        int seed = i * 1987;
        int x = (seed * 149) % SCREEN_WIDTH;
        int y = SCREEN_HEIGTH - 40 + (seed % 10);
        int tamanho = 2 + (seed % 3);
        DrawCircle(x, y, tamanho, (Color){160, 140, 100, 255});
    }
    
    for (int lado = 0; lado < 2; lado++) {
        int baseX = lado == 0 ? 8 : SCREEN_WIDTH - 20;
        
        for (int i = 0; i < 8; i++) {
            int y = i * 75 + 30;
            float balanco = sinf(tempo * 3.5f + i * 0.6f) * 15.0f;
            
            DrawRectangle(baseX + 6, y, 3, 75, (Color){34, 139, 34, 180});
            
            for (int j = 0; j < 3; j++) {
                int algaY = y + j * 25;
                int algaX = baseX + 7 + (int)(balanco * (1.0f - j * 0.3f));
                DrawEllipse(algaX, algaY, 8, 5, (Color){46, 125, 50, 180});
            }
        }
    }
}

void desenharFundoVulcao(float tempo) {
    for (int y = 0; y < SCREEN_HEIGTH; y += 2) {
        float t = (float)y / SCREEN_HEIGTH;
        float pulso = sinf(tempo * 1.5f) * 8.0f;
        int r = (int)(80 + t * 60 + pulso);
        int g = (int)(20 + t * 20);
        int b = (int)(20 + t * 20);
        DrawRectangle(0, y, SCREEN_WIDTH, 2, (Color){r, g, b, 255});
    }
    
    for (int i = 0; i < 30; i++) {
        int seed = i * 6143;
        int x = (seed * 113) % SCREEN_WIDTH;
        int baseY = 30 + (seed % 150);
        int tamanho = 6 + (seed % 10);
        int alpha = 120 + (seed % 135);
        float movimento = fmodf(tempo * 40.0f + i * 10.0f, (float)SCREEN_HEIGTH);
        int finalY = baseY - (int)movimento;
        if (finalY < 0) finalY += SCREEN_HEIGTH;
        DrawCircle(x, finalY, tamanho, (Color){255, 120, 0, alpha});
    }
    
    DrawRectangle(0, SCREEN_HEIGTH - 50, SCREEN_WIDTH, 50, (Color){80, 40, 40, 255});
    
    for (int i = 0; i < 15; i++) {
        int seed = i * 4567;
        int x = (seed * 127) % SCREEN_WIDTH;
        int y = SCREEN_HEIGTH - 50 + (seed % 20);
        int largura = 12 + (seed % 15);
        int altura = 8 + (seed % 12);
        DrawEllipse(x, y, largura, altura, (Color){100, 50, 50, 255});
    }
    
    for (int lado = 0; lado < 2; lado++) {
        int baseX = lado == 0 ? 5 : SCREEN_WIDTH - 30;
        
        for (int i = 0; i < 10; i++) {
            int y = i * 60 + 20;
            int seed = i * 9973;
            int largura = 15 + (seed % 10);
            int altura = 25 + (seed % 15);
            
            DrawEllipse(baseX + 15, y + altura/2, largura/2, altura/2, (Color){80, 40, 40, 255});
            DrawEllipse(baseX + 15, y + altura/2, largura/3, altura/3, (Color){100, 50, 50, 255});
            
            if (i % 2 == 0) {
                float brilho = (sinf(tempo * 2.5f + i) + 1.0f) / 2.0f;
                DrawCircle(baseX + 15, y + altura/2, 4, (Color){255, 100, 0, (int)(brilho * 180)});
            }
        }
    }
}
