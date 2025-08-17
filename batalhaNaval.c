#include <stdio.h>

int main() {
    // Declaração das variáveis
    int tabuleiro[10][10];  // Matriz 10x10 do tabuleiro
    int i, j;               // Índices para loops
    int navio1[3][2];       // Navio horizontal
    int navio2[3][2];       // Navio vertical

    // 1️⃣ Inicializa o tabuleiro com zeros (água)
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;  // 0 representa água
        }
    }

    // 2️⃣ Define as coordenadas do navio horizontal (navio1)
    navio1[0][0] = 2; navio1[0][1] = 4; // Parte 1
    navio1[1][0] = 2; navio1[1][1] = 5; // Parte 2
    navio1[2][0] = 2; navio1[2][1] = 6; // Parte 3

    // 3️⃣ Define as coordenadas do navio vertical (navio2)
    navio2[0][0] = 5; navio2[0][1] = 1; // Parte 1
    navio2[1][0] = 6; navio2[1][1] = 1; // Parte 2
    navio2[2][0] = 7; navio2[2][1] = 1; // Parte 3

    // 4️⃣ Coloca o navio horizontal no tabuleiro
    for (i = 0; i < 3; i++) {
        int linha = navio1[i][0];
        int coluna = navio1[i][1];
        tabuleiro[linha][coluna] = 1; // 1 representa navio
    }

    // 5️⃣ Coloca o navio vertical no tabuleiro
    for (i = 0; i < 3; i++) {
        int linha = navio2[i][0];
        int coluna = navio2[i][1];
        tabuleiro[linha][coluna] = 1; // 1 representa navio
    }

    // 6️⃣ Exibe o tabuleiro usando símbolos
    printf("Tabuleiro de Batalha Naval:\n\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if (tabuleiro[i][j] == 0)
                printf("~ "); // Água
            else
                printf("N "); // Navio
        }
        printf("\n"); // Quebra de linha após cada linha do tabuleiro
    }

    return 0;
}
