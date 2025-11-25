# Arkanoid - Trabalho M3

## Descricao
Jogo Arkanoid 2D desenvolvido em C++ utilizando a biblioteca Raylib. O jogador controla uma barra que rebate uma bola para destruir blocos em diferentes fases.

## Objetivos do Projeto
Aplicar de forma integrada os conceitos de:
- Alocacao dinamica de memoria
- Ponteiros
- Funcoes e passagem de parametros
- Structs
- Modulos com arquivos .h e .cpp
- Manipulacao de arquivos
- Escopo de variaveis

## Bibliotecas Utilizadas
- **Raylib**: Biblioteca grafica para desenvolvimento de jogos 2D
  - Versao recomendada: 4.0 ou superior
  - Site oficial: https://www.raylib.com/

## Requisitos do Sistema
- Sistema operacional: Linux
- Compilador: g++ com suporte a C++11
- Bibliotecas necessarias:
  - raylib
  - OpenGL
  - pthread
  - X11

## Instalacao da Raylib (Ubuntu/Debian)
```bash
sudo apt update
sudo apt install libasound2-dev mesa-common-dev libx11-dev libxrandr-dev libxi-dev xorg-dev libgl1-mesa-dev libglu1-mesa-dev
git clone https://github.com/raysan5/raylib.git
cd raylib/src
make PLATFORM=PLATFORM_DESKTOP
sudo make install
```

## Compilacao
Para compilar o projeto, execute:
```bash
make
```

Para limpar os arquivos compilados:
```bash
make clean
```

## Execucao
Para executar o jogo:
```bash
make run
```

Ou diretamente:
```bash
./arkanoid
```

## Controles do Jogo
- **Setas Esquerda/Direita** ou **A/D**: Mover a barra
- **Espaco**: Lancar a bola
- **Setas Cima/Baixo**: Navegar nos menus
- **Enter**: Selecionar opcao no menu
- **ESC**: Pausar o jogo / Voltar ao menu anterior

## Regras do Jogo

### Objetivo
Destruir todos os blocos de cada fase usando a bola rebatida pela barra.

### Vidas
- O jogador comeca com 3 vidas
- Perde uma vida quando a bola cai abaixo da barra
- O jogo termina quando todas as vidas sao perdidas

### Blocos
- **Blocos Amarelos** (1 vida): 10 pontos
- **Blocos Laranjas** (2 vidas): 20 pontos
- **Blocos Vermelhos** (3 vidas): 30 pontos
- Blocos sao gerados aleatoriamente a cada fase

### Itens Especiais
Ao destruir blocos, ha 30% de chance de aparecer um item:
- **+V (Verde)**: Vida extra
- **+B (Azul Claro)**: Aumenta o tamanho da barra
- **-B (Roxo)**: Diminui o tamanho da barra
- **+P (Dourado)**: 50 pontos extras
- **x2 (Rosa)**: Multiplicador de pontos x2 por 10 segundos
- **-P (Cinza)**: Inversor de pontos (pontos negativos) por 5 segundos

### Niveis de Dificuldade
- **Facil**: Velocidade normal
- **Medio**: +25% de velocidade
- **Dificil**: +50% de velocidade

### Fases
- O jogo possui 3 fases progressivas
- Cada fase aumenta a quantidade de blocos
- A dificuldade dos blocos aumenta nas fases avancadas

### Pontuacao
A pontuacao e calculada baseada em:
- Blocos destruidos
- Itens coletados
- Tempo de jogo
- Dificuldade selecionada
- Multiplicadores ativos

### Ranking
- O ranking salva os 10 melhores jogadores
- Informacoes salvas: nome, data, pontuacao, tempo
- Os dados sao salvos mesmo em caso de derrota
- O ranking e ordenado por pontuacao

## Estrutura do Projeto
```
Trabalho-Algoritmos-M3/
├── src/
│   ├── header/
│   │   ├── barra.h
│   │   ├── bola.h
│   │   ├── blocos.h
│   │   ├── constantes.h
│   │   ├── cores.h
│   │   ├── estado.h
│   │   ├── fases.h
│   │   ├── itens.h
│   │   ├── jogador.h
│   │   ├── jogo.h
│   │   ├── menu.h
│   │   ├── ranking.h
│   │   └── sons.h
│   ├── impl/
│   │   ├── barra.cpp
│   │   ├── bola.cpp
│   │   ├── blocos.cpp
│   │   ├── cores.cpp
│   │   ├── estado.cpp
│   │   ├── fases.cpp
│   │   ├── itens.cpp
│   ��   ├── jogador.cpp
│   │   ├── jogo.cpp
│   │   ├── menu.cpp
│   │   ├── ranking.cpp
│   │   └── sons.cpp
│   └── main.cpp
├── Makefile
├── README.md
└── ranking.txt (gerado automaticamente)
```

## Funcionalidades Implementadas
- Menu principal com opcoes de iniciar, dificuldade e ranking
- 3 niveis de dificuldade
- Sistema de pontuacao baseado em multiplos fatores
- Ranking ordenado salvo em arquivo
- Salvamento de dados mesmo em derrota
- Opcao de reiniciar ou voltar ao menu
- Blocos com posicoes e cores aleatorias
- Blocos com diferentes durabilidades (1-3 vidas)
- 3 fases progressivas
- Informacoes em tela (tempo, pontuacao, vidas, fase)
- 6 tipos de itens especiais com efeitos cumulativos
- Otimizacao e estabilidade visual
- Design caprichado com cores coerentes
- Sistema de colisao preciso
- Fisica da bola com angulo variavel

## Conceitos da Disciplina Aplicados
- **Ponteiros**: Utilizados em todas as funcoes para manipular structs
- **Alocacao dinamica**: Arrays de blocos e itens
- **Structs**: Estruturas para Barra, Bola, Bloco, Item, Jogador, etc.
- **Passagem por referencia**: Todas as funcoes recebem ponteiros
- **Modulos**: Separacao em arquivos .h e .cpp
- **Manipulacao de arquivos**: Sistema de ranking com leitura/escrita
- **Escopo de variaveis**: Variaveis locais e globais bem definidas
- **Funcoes**: Modularizacao do codigo em funcoes especificas

## Autores
Trabalho desenvolvido para a disciplina de Algoritmos e Programacao II - UNIVALI

## Licenca
Projeto academico - UNIVALI 2024
