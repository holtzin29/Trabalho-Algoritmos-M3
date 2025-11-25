#include "../header/sons.h"
#include <cmath>
#include <cstdio>

void inicializarSons(Sons *sons) {
    InitAudioDevice();
    
    Wave waveColisaoBarra = {0};
    waveColisaoBarra.frameCount = 2205;
    waveColisaoBarra.sampleRate = 44100;
    waveColisaoBarra.sampleSize = 16;
    waveColisaoBarra.channels = 1;
    waveColisaoBarra.data = (short*)RL_MALLOC(waveColisaoBarra.frameCount * waveColisaoBarra.channels * sizeof(short));
    
    for (unsigned int i = 0; i < waveColisaoBarra.frameCount; i++) {
        float t = (float)i / 44100.0f;
        float freq = 600.0f + t * 200.0f;
        float envelope = 1.0f - (t * 20.0f);
        if (envelope < 0) envelope = 0;
        ((short*)waveColisaoBarra.data)[i] = (short)(25000.0f * envelope * sinf(2.0f * PI * freq * t));
    }
    sons->colisaoBarra = LoadSoundFromWave(waveColisaoBarra);
    UnloadWave(waveColisaoBarra);
    SetSoundVolume(sons->colisaoBarra, 0.4f);
    
    Wave waveColisaoBloco = {0};
    waveColisaoBloco.frameCount = 1470;
    waveColisaoBloco.sampleRate = 44100;
    waveColisaoBloco.sampleSize = 16;
    waveColisaoBloco.channels = 1;
    waveColisaoBloco.data = (short*)RL_MALLOC(waveColisaoBloco.frameCount * waveColisaoBloco.channels * sizeof(short));
    
    for (unsigned int i = 0; i < waveColisaoBloco.frameCount; i++) {
        float t = (float)i / 44100.0f;
        float freq = 800.0f - t * 400.0f;
        float envelope = 1.0f - (t * 30.0f);
        if (envelope < 0) envelope = 0;
        ((short*)waveColisaoBloco.data)[i] = (short)(28000.0f * envelope * sinf(2.0f * PI * freq * t));
    }
    sons->colisaoBloco = LoadSoundFromWave(waveColisaoBloco);
    UnloadWave(waveColisaoBloco);
    SetSoundVolume(sons->colisaoBloco, 0.4f);
    
    Wave waveItemColetado = {0};
    waveItemColetado.frameCount = 3675;
    waveItemColetado.sampleRate = 44100;
    waveItemColetado.sampleSize = 16;
    waveItemColetado.channels = 1;
    waveItemColetado.data = (short*)RL_MALLOC(waveItemColetado.frameCount * waveItemColetado.channels * sizeof(short));
    
    for (unsigned int i = 0; i < waveItemColetado.frameCount; i++) {
        float t = (float)i / 44100.0f;
        float freq1 = 523.0f + t * 400.0f;
        float freq2 = 659.0f + t * 500.0f;
        float envelope = 1.0f - (t * 12.0f);
        if (envelope < 0) envelope = 0;
        ((short*)waveItemColetado.data)[i] = (short)(20000.0f * envelope * 
            (sinf(2.0f * PI * freq1 * t) + sinf(2.0f * PI * freq2 * t)) / 2.0f);
    }
    sons->itemColetado = LoadSoundFromWave(waveItemColetado);
    UnloadWave(waveItemColetado);
    SetSoundVolume(sons->itemColetado, 0.5f);
    
    Wave wavePerdeuVida = {0};
    wavePerdeuVida.frameCount = 8820;
    wavePerdeuVida.sampleRate = 44100;
    wavePerdeuVida.sampleSize = 16;
    wavePerdeuVida.channels = 1;
    wavePerdeuVida.data = (short*)RL_MALLOC(wavePerdeuVida.frameCount * wavePerdeuVida.channels * sizeof(short));
    
    for (int i = 0; i < wavePerdeuVida.frameCount; i++) {
        ((short*)wavePerdeuVida.data)[i] = (short)(32000.0f * sinf(2.0f * PI * 220.0f * i / 44100.0f));
    }
    sons->perdeuVida = LoadSoundFromWave(wavePerdeuVida);
    UnloadWave(wavePerdeuVida);
    SetSoundVolume(sons->perdeuVida, 0.5f);
    
    Wave waveFaseCompleta = {0};
    waveFaseCompleta.frameCount = 8820;
    waveFaseCompleta.sampleRate = 44100;
    waveFaseCompleta.sampleSize = 16;
    waveFaseCompleta.channels = 1;
    waveFaseCompleta.data = (short*)RL_MALLOC(waveFaseCompleta.frameCount * waveFaseCompleta.channels * sizeof(short));
    
    for (int i = 0; i < waveFaseCompleta.frameCount; i++) {
        float freq = 880.0f + (i / 100.0f);
        ((short*)waveFaseCompleta.data)[i] = (short)(32000.0f * sinf(2.0f * PI * freq * i / 44100.0f));
    }
    sons->faseCompleta = LoadSoundFromWave(waveFaseCompleta);
    UnloadWave(waveFaseCompleta);
    SetSoundVolume(sons->faseCompleta, 0.5f);
}

void descarregarSons(Sons *sons) {
    UnloadSound(sons->colisaoBarra);
    UnloadSound(sons->colisaoBloco);
    UnloadSound(sons->itemColetado);
    UnloadSound(sons->perdeuVida);
    UnloadSound(sons->faseCompleta);
    UnloadMusicStream(sons->musicaFundo);
    remove("/tmp/arkanoid_music.wav");
    CloseAudioDevice();
}

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
    Wave waveMusicaFundo = {0};
    waveMusicaFundo.frameCount = 44100 * 4;
    waveMusicaFundo.sampleRate = 44100;
    waveMusicaFundo.sampleSize = 16;
    waveMusicaFundo.channels = 2;
    waveMusicaFundo.data = (short*)RL_MALLOC(waveMusicaFundo.frameCount * waveMusicaFundo.channels * sizeof(short));
    
    float notas[] = {261.63f, 293.66f, 329.63f, 349.23f, 392.00f, 440.00f, 493.88f, 523.25f};
    int melodia[] = {0, 2, 4, 2, 0, 2, 4, 2, 4, 5, 7, 4, 5, 7, 7, 0};
    int notasPorBeat = 44100 / 4;
    
    for (unsigned int i = 0; i < waveMusicaFundo.frameCount; i++) {
        int beatIndex = (i / notasPorBeat) % 16;
        float freq = notas[melodia[beatIndex]];
        float t = (float)i / 44100.0f;
        
        float onda1 = sinf(2.0f * PI * freq * t);
        float onda2 = sinf(2.0f * PI * (freq * 2.0f) * t) * 0.2f;
        float baixo = sinf(2.0f * PI * (freq * 0.5f) * t) * 0.3f;
        
        int posicaoNaBeat = i % notasPorBeat;
        float envelope = 1.0f;
        if (posicaoNaBeat < 1000) {
            envelope = (float)posicaoNaBeat / 1000.0f;
        } else if (posicaoNaBeat > notasPorBeat - 1000) {
            envelope = (float)(notasPorBeat - posicaoNaBeat) / 1000.0f;
        }
        
        short sample = (short)(12000.0f * envelope * (onda1 + onda2 + baixo));
        
        ((short*)waveMusicaFundo.data)[i * 2] = sample;
        ((short*)waveMusicaFundo.data)[i * 2 + 1] = sample;
    }
    
    ExportWave(waveMusicaFundo, "/tmp/arkanoid_music.wav");
    sons->musicaFundo = LoadMusicStream("/tmp/arkanoid_music.wav");
    UnloadWave(waveMusicaFundo);
    
    sons->musicaFundo.looping = true;
    SetMusicVolume(sons->musicaFundo, 0.25f);
    PlayMusicStream(sons->musicaFundo);
}

void pararMusicaFundo(Sons *sons) {
    if (IsMusicStreamPlaying(sons->musicaFundo)) {
        StopMusicStream(sons->musicaFundo);
    }
}

void atualizarMusicaFundo(Sons *sons) {
    if (IsMusicStreamPlaying(sons->musicaFundo)) {
        UpdateMusicStream(sons->musicaFundo);
    }
}
