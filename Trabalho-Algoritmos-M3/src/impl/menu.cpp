#include "../header/menu.h"
#include "../header/constantes.h"
#include "raylib.h"
#include <cstring>

void inicializarMenu(Menu *menu) {
    menu->opcaoSelecionada = 0;
    menu->totalOpcoes = 3;
    strcpy(menu->nomeJogador, "");
    menu->tamanhoNome = 0;
}

void desenharMenuPrincipal(Menu *menu) {
    ClearBackground(RAYWHITE);
    
    DrawText("ARKANOID", SCREEN_WIDTH / 2 - 150, 100, 60, DARKBLUE);
    
    const char *opcoes[] = {"Iniciar Jogo", "Dificuldades", "Ranking"};
    
    for (int i = 0; i < 3; i++) {
        Color cor = (i == menu->opcaoSelecionada) ? RED : BLACK;
        DrawText(opcoes[i], SCREEN_WIDTH / 2 - 100, 250 + i * 50, 30, cor);
    }
    
    DrawText("Use SETAS para navegar", SCREEN_WIDTH / 2 - 120, 450, 20, GRAY);
    DrawText("ENTER para selecionar", SCREEN_WIDTH / 2 - 110, 475, 20, GRAY);
    DrawText("ESC para sair", SCREEN_WIDTH / 2 - 70, 500, 20, GRAY);
}

void desenharMenuDificuldade(Menu *menu) {
    ClearBackground(RAYWHITE);
    
    DrawText("SELECIONE A DIFICULDADE", SCREEN_WIDTH / 2 - 200, 100, 40, DARKBLUE);
    
    const char *opcoes[] = {"Facil", "Medio (+0.25x velocidade)", "Dificil (+0.5x velocidade)"};
    
    for (int i = 0; i < 3; i++) {
        Color cor = (i == menu->opcaoSelecionada) ? RED : BLACK;
        DrawText(opcoes[i], SCREEN_WIDTH / 2 - 150, 250 + i * 50, 25, cor);
    }
    
    DrawText("Use SETAS para navegar", SCREEN_WIDTH / 2 - 120, 450, 20, GRAY);
    DrawText("ENTER para selecionar", SCREEN_WIDTH / 2 - 110, 475, 20, GRAY);
    DrawText("ESC para voltar", SCREEN_WIDTH / 2 - 70, 500, 20, GRAY);
}

void desenharMenuGameOver(Menu *menu, int pontuacao, int tempo) {
    ClearBackground(RAYWHITE);
    
    DrawText("GAME OVER", SCREEN_WIDTH / 2 - 150, 100, 60, RED);
    
    DrawText(TextFormat("Pontuacao: %d", pontuacao), SCREEN_WIDTH / 2 - 100, 200, 30, BLACK);
    DrawText(TextFormat("Tempo: %d segundos", tempo), SCREEN_WIDTH / 2 - 120, 240, 30, BLACK);
    
    const char *opcoes[] = {"Jogar Novamente", "Menu Principal"};
    
    for (int i = 0; i < 2; i++) {
        Color cor = (i == menu->opcaoSelecionada) ? RED : BLACK;
        DrawText(opcoes[i], SCREEN_WIDTH / 2 - 120, 320 + i * 50, 25, cor);
    }
    
    DrawText("Use SETAS para navegar", SCREEN_WIDTH / 2 - 120, 450, 20, GRAY);
    DrawText("ENTER para selecionar", SCREEN_WIDTH / 2 - 110, 475, 20, GRAY);
}

void desenharMenuVitoria(Menu *menu, int pontuacao, int tempo) {
    ClearBackground(RAYWHITE);
    
    DrawText("VITORIA!", SCREEN_WIDTH / 2 - 120, 100, 60, GREEN);
    DrawText("Parabens! Voce completou todas as fases!", SCREEN_WIDTH / 2 - 250, 180, 20, DARKGREEN);
    
    DrawText(TextFormat("Pontuacao Final: %d", pontuacao), SCREEN_WIDTH / 2 - 120, 230, 30, BLACK);
    DrawText(TextFormat("Tempo Total: %d segundos", tempo), SCREEN_WIDTH / 2 - 140, 270, 30, BLACK);
    
    const char *opcoes[] = {"Jogar Novamente", "Menu Principal"};
    
    for (int i = 0; i < 2; i++) {
        Color cor = (i == menu->opcaoSelecionada) ? RED : BLACK;
        DrawText(opcoes[i], SCREEN_WIDTH / 2 - 120, 340 + i * 50, 25, cor);
    }
    
    DrawText("Use SETAS para navegar", SCREEN_WIDTH / 2 - 120, 450, 20, GRAY);
    DrawText("ENTER para selecionar", SCREEN_WIDTH / 2 - 110, 475, 20, GRAY);
}

void desenharMenuPausa(Menu *menu) {
    DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGTH, Fade(BLACK, 0.5f));
    
    DrawText("PAUSADO", SCREEN_WIDTH / 2 - 100, 150, 50, WHITE);
    
    const char *opcoes[] = {"Continuar", "Menu Principal"};
    
    for (int i = 0; i < 2; i++) {
        Color cor = (i == menu->opcaoSelecionada) ? YELLOW : WHITE;
        DrawText(opcoes[i], SCREEN_WIDTH / 2 - 80, 280 + i * 50, 25, cor);
    }
    
    DrawText("Use SETAS para navegar", SCREEN_WIDTH / 2 - 120, 400, 20, LIGHTGRAY);
    DrawText("ENTER para selecionar", SCREEN_WIDTH / 2 - 110, 425, 20, LIGHTGRAY);
}

int atualizarMenu(Menu *menu) {
    if (IsKeyPressed(KEY_UP)) {
        menu->opcaoSelecionada--;
        if (menu->opcaoSelecionada < 0) {
            menu->opcaoSelecionada = menu->totalOpcoes - 1;
        }
    }
    
    if (IsKeyPressed(KEY_DOWN)) {
        menu->opcaoSelecionada++;
        if (menu->opcaoSelecionada >= menu->totalOpcoes) {
            menu->opcaoSelecionada = 0;
        }
    }
    
    if (IsKeyPressed(KEY_ENTER)) {
        return menu->opcaoSelecionada;
    }
    
    return -1;
}

void desenharMenuRegistro(Menu *menu) {
    ClearBackground(RAYWHITE);
    
    int tituloLargura = MeasureText("DIGITE SEU NOME", 40);
    DrawText("DIGITE SEU NOME", SCREEN_WIDTH / 2 - tituloLargura / 2, 100, 40, DARKBLUE);
    
    DrawRectangle(SCREEN_WIDTH / 2 - 200, 200, 400, 60, LIGHTGRAY);
    DrawRectangleLines(SCREEN_WIDTH / 2 - 200, 200, 400, 60, BLACK);
    
    if (menu->tamanhoNome > 0) {
        int textoLargura = MeasureText(menu->nomeJogador, 30);
        DrawText(menu->nomeJogador, SCREEN_WIDTH / 2 - textoLargura / 2, 215, 30, BLACK);
    } else {
        int placeholderLargura = MeasureText("Digite aqui...", 30);
        DrawText("Digite aqui...", SCREEN_WIDTH / 2 - placeholderLargura / 2, 215, 30, GRAY);
    }
    
    int inst1 = MeasureText("Digite seu nome (max 20 caracteres)", 20);
    int inst2 = MeasureText("ENTER para confirmar", 20);
    int inst3 = MeasureText("BACKSPACE para apagar", 20);
    int inst4 = MeasureText("ESC para voltar", 20);
    
    DrawText("Digite seu nome (max 20 caracteres)", SCREEN_WIDTH / 2 - inst1 / 2, 280, 20, DARKGRAY);
    DrawText("ENTER para confirmar", SCREEN_WIDTH / 2 - inst2 / 2, 320, 20, DARKGRAY);
    DrawText("BACKSPACE para apagar", SCREEN_WIDTH / 2 - inst3 / 2, 345, 20, DARKGRAY);
    DrawText("ESC para voltar", SCREEN_WIDTH / 2 - inst4 / 2, 370, 20, DARKGRAY);
}

bool atualizarMenuRegistro(Menu *menu) {
    int tecla = GetCharPressed();
    
    while (tecla > 0) {
        if ((tecla >= 32) && (tecla <= 125) && (menu->tamanhoNome < 20)) {
            menu->nomeJogador[menu->tamanhoNome] = (char)tecla;
            menu->nomeJogador[menu->tamanhoNome + 1] = '\0';
            menu->tamanhoNome++;
        }
        
        tecla = GetCharPressed();
    }
    
    if (IsKeyPressed(KEY_BACKSPACE)) {
        if (menu->tamanhoNome > 0) {
            menu->tamanhoNome--;
            menu->nomeJogador[menu->tamanhoNome] = '\0';
        }
    }
    
    if (IsKeyPressed(KEY_ENTER) && menu->tamanhoNome > 0) {
        return true;
    }
    
    return false;
}
