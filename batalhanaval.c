#include <stdio.h>
#include <stdlib.h>

#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 5

/*
Valores utilizados:
0 -> Água
3 -> Navio
5 -> Área afetada por habilidade
*/

// Função para inicializar o tabuleiro com água
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for(int i = 0; i < TAM_TABULEIRO; i++) {
        for(int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para posicionar alguns navios fixos
void posicionarNavios(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    tabuleiro[2][3] = 3;
    tabuleiro[2][4] = 3;
    tabuleiro[2][5] = 3;

    tabuleiro[6][7] = 3;
    tabuleiro[7][7] = 3;
    tabuleiro[8][7] = 3;
}

// Criar habilidade Cone (apontando para baixo)
void criarCone(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {

    for(int i = 0; i < TAM_HABILIDADE; i++) {
        for(int j = 0; j < TAM_HABILIDADE; j++) {

            int centro = TAM_HABILIDADE / 2;

            // Condição para formar o cone
            if(j >= centro - i && j <= centro + i) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Criar habilidade Cruz
void criarCruz(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {

    int centro = TAM_HABILIDADE / 2;

    for(int i = 0; i < TAM_HABILIDADE; i++) {
        for(int j = 0; j < TAM_HABILIDADE; j++) {

            if(i == centro || j == centro) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Criar habilidade Octaedro (Losango)
void criarOctaedro(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {

    int centro = TAM_HABILIDADE / 2;

    for(int i = 0; i < TAM_HABILIDADE; i++) {
        for(int j = 0; j < TAM_HABILIDADE; j++) {

            // Distância Manhattan para formar losango
            if((abs(i - centro) + abs(j - centro)) <= centro) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Sobrepor habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO],
                       int habilidade[TAM_HABILIDADE][TAM_HABILIDADE],
                       int origemLinha,
                       int origemColuna) {

    int offset = TAM_HABILIDADE / 2;

    for(int i = 0; i < TAM_HABILIDADE; i++) {
        for(int j = 0; j < TAM_HABILIDADE; j++) {

            int linhaTab = origemLinha - offset + i;
            int colunaTab = origemColuna - offset + j;

            // Verifica se está dentro do tabuleiro
            if(linhaTab >= 0 && linhaTab < TAM_TABULEIRO &&
               colunaTab >= 0 && colunaTab < TAM_TABULEIRO) {

                if(habilidade[i][j] == 1) {
                    tabuleiro[linhaTab][colunaTab] = 5;
                }
            }
        }
    }
}

// Exibir tabuleiro
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {

    for(int i = 0; i < TAM_TABULEIRO; i++) {
        for(int j = 0; j < TAM_TABULEIRO; j++) {

            if(tabuleiro[i][j] == 0)
                printf("~ ");  // Água
            else if(tabuleiro[i][j] == 3)
                printf("N ");  // Navio
            else if(tabuleiro[i][j] == 5)
                printf("* ");  // Habilidade
        }
        printf("\n");
    }
}

int main() {

    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];

    inicializarTabuleiro(tabuleiro);
    posicionarNavios(tabuleiro);

    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);

    // Definindo origens fixas
    aplicarHabilidade(tabuleiro, cone, 2, 2);
    aplicarHabilidade(tabuleiro, cruz, 5, 5);
    aplicarHabilidade(tabuleiro, octaedro, 7, 2);

    exibirTabuleiro(tabuleiro);

    return 0;
}
