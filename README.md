# Arkanoid 2D - Trabalho M3

Um jogo Arkanoid 2D completo desenvolvido em C++ com a biblioteca Raylib, como trabalho prático da disciplina de Algoritmos e Programação II da UNIVALI.

## 📋 Objetivos do Projeto

Este projeto foi desenvolvido com o objetivo de aplicar de forma integrada os conceitos fundamentais da disciplina:

- **Alocação dinâmica de memória** e manipulação de ponteiros
- **Funções e sobrecargas** de funções
- **Structs** e tipos de dados estruturados
- **Passagem de parâmetros** por valor e referência
- **Modularização** com arquivos `.h` e `.cpp`
- **Manipulação de arquivos** para persistência de dados
- **Recursividade** em algoritmos
- **Escopo de variáveis** e boas práticas de programação
- **Templates de função** para código genérico

## 🎮 Descrição do Jogo

Arkanoid é um clássico jogo de arcade onde o jogador controla uma barra (paddle) que rebate uma bola para destruir blocos. O objetivo é destruir todos os blocos de cada fase sem deixar a bola cair.

### Características Principais

- **Menu Principal**: Iniciar Jogo, Selecionar Dificuldade, Visualizar Ranking
- **3 Níveis de Dificuldade**:
  - Fácil (velocidade padrão)
  - Médio (+0.25x velocidade)
  - Difícil (+0.5x velocidade)
- **Sistema de Pontuação**: Baseado em tempo, blocos quebrados, itens coletados e dificuldade
- **Ranking Persistente**: Salva e carrega dados de jogadores
- **Múltiplas Fases**: Pelo menos 3 fases progressivas
- **Blocos com Durabilidade**: Diferentes resistências (1 a 3 toques)
- **Itens Especiais Aleatórios**:
  - Vida extra (cumulativo)
  - Aumento do tamanho do paddle
  - Diminuição do tamanho do paddle
  - Pontos extras / Multiplicador de pontuação
- **Efeitos Visuais e Sonoros**: Trilha sonora, efeitos de colisão e partículas

## 📚 Bibliotecas Utilizadas

### Dependências Principais

- **Raylib** (`-lraylib`): Biblioteca gráfica para renderização 2D, entrada de usuário e áudio
- **OpenGL** (`-lGL`): Aceleração gráfica
- **Pthread** (`-lpthread`): Suporte a threads
- **Matemática** (`-lm`): Funções matemáticas
- **X11** (`-lX11`): Sistema de janelas (Linux)

### Compilação

O projeto utiliza **g++** com padrão C++11 e as seguintes flags:
- `-Wall`: Ativa todos os avisos do compilador
- `-std=c++11`: Utiliza o padrão C++11

## 🎮 Controles do Jogo

### Navegação no Menu

| Tecla | Ação |
|-------|------|
| **↑ / ↓** | Navegar entre opções |
| **ENTER** | Selecionar opção |
| **ESC** | Voltar ao menu anterior |

### Durante o Jogo

| Tecla | Ação |
|-------|------|
| **← / →** | Mover a barra para esquerda/direita |
| **ESPAÇO** | Iniciar o jogo (primeira bola) |
| **ESC** | Pausar o jogo |

### No Menu de Pausa

| Tecla | Ação |
|-------|------|
| **↑ / ↓** | Navegar entre opções |
| **ENTER** | Selecionar opção |
| **ESC** | Retomar o jogo |

## 📖 Regras do Jogo

### Objetivo
Destruir todos os blocos da fase sem deixar a bola cair para ganhar pontos e avançar para a próxima fase.

### Mecânicas Principais

1. **Movimento da Bola**: A bola se move continuamente pela tela, ricocheteando nas paredes, na barra e nos blocos.

2. **Controle da Barra**: O jogador controla uma barra horizontal na parte inferior da tela para rebater a bola.

3. **Destruição de Blocos**: Cada bloco requer um número específico de toques para ser destruído:
   - Blocos com 1 durabilidade: destruídos com 1 toque
   - Blocos com 2 durabilidade: requerem 2 toques
   - Blocos com 3 durabilidade: requerem 3 toques

4. **Vidas**: O jogador começa com 3 vidas. Perde uma vida quando a bola cai para fora da tela.

5. **Game Over**: O jogo termina quando o jogador perde todas as vidas.

6. **Vitória**: O jogador vence quando destrói todos os blocos da fase.

### Sistema de Pontuação

A pontuação é calculada com base em:
- **Blocos destruídos**: Pontos por bloco quebrado
- **Tempo**: Bônus por completar a fase rapidamente
- **Itens coletados**: Pontos extras por itens especiais
- **Multiplicador de dificuldade**: Fácil (1x), Médio (1.25x), Difícil (1.5x)

### Itens Especiais

Quando um bloco é destruído, pode gerar um item especial que cai verticalmente:

- **❤️ Vida Extra**: Adiciona uma vida ao jogador
- **📏 Barra Grande**: Aumenta o tamanho da barra (efeito cumulativo)
- **📏 Barra Pequena**: Diminui o tamanho da barra (efeito cumulativo)
- **⭐ Pontos Extras**: Adiciona pontos bônus à pontuação

### Ranking

O jogo mantém um ranking dos melhores jogadores com:
- Nome do jogador
- Pontuação alcançada
- Data e hora da partida
- Tempo de jogo

## 🚀 Como Compilar e Executar

### Pré-requisitos

- GCC/G++ com suporte a C++11
- Raylib instalada no sistema
- Make

### Compilação

```bash
make
```

### Execução

```bash
make run
```

Ou diretamente:

```bash
./arkanoid
```

### Limpeza

```bash
make clean
```

## 📁 Estrutura do Projeto

```
src/
├── header/          # Arquivos de cabeçalho (.h)
│   ├── barra.h
│   ├── blocos.h
│   ├── bola.h
│   ├── constantes.h
│   ├── cores.h
│   ├── estado.h
│   ├── fases.h
│   ├── graficos.h
│   ├── itens.h
│   ├── jogador.h
│   ├── jogo.h
│   ├── menu.h
│   ├── particulas.h
│   ├── ranking.h
│   ├── sons.h
│   └── utils.h
├── impl/            # Implementações (.cpp)
│   ├── barra.cpp
│   ├── blocos.cpp
│   ├── bola.cpp
│   ├── cores.cpp
│   ├── estado.cpp
│   ├── fases.cpp
│   ├── graficos.cpp
│   ├── itens.cpp
│   ├── jogador.cpp
│   ├── jogo.cpp
│   ├── menu.cpp
│   ├── particulas.cpp
│   ├── ranking.cpp
│   ├── sons.cpp
│   └── utils.cpp
└── main.cpp         # Arquivo principal

resources/          # Recursos do jogo
├── musicaFundo.mp3
├── somColisaoBarra.mp3
├── somColisaoBloco.mp3
├── faseCompleta.mp3
├── itemColetado.wav
└── perdeuVida.mp3
```

## 👥 Autores

Trabalho desenvolvido como atividade prática da disciplina **Algoritmos e Programação II** da Universidade do Vale do Itajaí (UNIVALI).

**Professor**: Welington Gadelha
**Alunos**:Mauro Grippa Junior
**Alunos**: Tiffany Ribeiro

## 📝 Notas

- O projeto demonstra o uso correto de conceitos fundamentais de programação em C++
- Código modularizado com separação clara entre interface (`.h`) e implementação (`.cpp`)
- Sistema de persistência de dados para ranking de jogadores
- Interface gráfica intuitiva com menu navegável
- Efeitos sonoros e visuais para melhor experiência do usuário
