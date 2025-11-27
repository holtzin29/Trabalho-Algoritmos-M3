#include "../header/sons.h"

void inicializarSons(Sons *sons) {
    InitAudioDevice();

    // Sons simples carregados de arquivos
    sons->colisaoBarra   = LoadSound("resources/somColisaoBarra.mp3");
    sons->colisaoBloco   = LoadSound("resources/somColisaoBloco.mp3");
    sons->itemColetado   = LoadSound("resources/itemColetado.mp3");
    sons->perdeuVida     = LoadSound("resources/perdeuVida.mp3");
    sons->faseCompleta   = LoadSound("resources/faseCompleta.mp3");

    // Ajuste de volume
    SetSoundVolume(sons->colisaoBarra, 0.6f);
    SetSoundVolume(sons->colisaoBloco, 0.6f);
    SetSoundVolume(sons->itemColetado, 0.8f);
    SetSoundVolume(sons->perdeuVida, 0.7f);
    SetSoundVolume(sons->faseCompleta, 0.7f);

    // Música
    sons->musicaFundo = LoadMusicStream("resources/musicaFundo.mp3");
    SetMusicVolume(sons->musicaFundo, 0.3f);
    sons->musicaFundo.looping = true;
}

void descarregarSons(Sons *sons) {
    UnloadSound(sons->colisaoBarra);
    UnloadSound(sons->colisaoBloco);
    UnloadSound(sons->itemColetado);
    UnloadSound(sons->perdeuVida);
    UnloadSound(sons->faseCompleta);

    UnloadMusicStream(sons->musicaFundo);

    CloseAudioDevice();
}

// ---- Play functions ---- //

void tocarSomColisaoBarra(Sons *sons) {
    PlaySound(sons->colisaoBarra);
}

void tocarSomColisaoBloco(Sons *sons) {
    PlaySound(sons->colisaoBloco);
}

void tocarSomItemColetado(Sons *sons) {
    PlaySound(sons->itemColetado);
}

void tocarSomPerdeuVida(Sons *sons) {
    PlaySound(sons->perdeuVida);
}

void tocarSomFaseCompleta(Sons *sons) {
    PlaySound(sons->faseCompleta);
}

void tocarMusicaFundo(Sons *sons) {
    PlayMusicStream(sons->musicaFundo);
}

void pararMusicaFundo(Sons *sons) {
    StopMusicStream(sons->musicaFundo);
}

void atualizarMusicaFundo(Sons *sons) {
    UpdateMusicStream(sons->musicaFundo);
}
