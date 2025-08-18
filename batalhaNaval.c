#include <stdio.h>

int main() {
    int tabuleiro[10][10];
    int i, j;

    // Inicializa o tabuleiro com água
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            tabuleiro[i][j] = 0;
        }
    }

    // --- Navios ---
    tabuleiro[0][0] = 3; tabuleiro[0][1] = 3; tabuleiro[0][2] = 3;
    tabuleiro[1][1] = 3; tabuleiro[8][1] = 3; tabuleiro[9][1] = 3;
    tabuleiro[2][2] = 3; tabuleiro[3][3] = 3; tabuleiro[4][4] = 3;
    tabuleiro[5][8] = 3; tabuleiro[6][8] = 3; tabuleiro[7][8] = 3;

    // --- Habilidades ---
    // Cone 3x5
    int cone[3][5] = {
        {0,0,1,0,0},
        {0,1,1,1,0},
        {1,1,1,1,1}
    };
    int origemConeLinha = 0, origemConeCol = 7;
    for(i=0;i<3;i++){
        for(j=0;j<5;j++){
            int linha = origemConeLinha + i;
            int col = origemConeCol - 2 + j;
            if(linha>=0 && linha<10 && col>=0 && col<10 && cone[i][j]==1){
                tabuleiro[linha][col] = 4; // Cone
            }
        }
    }

    // Cruz 3x5
    int cruz[3][5] = {
        {0,0,1,0,0},
        {1,1,1,1,1},
        {0,0,1,0,0}
    };
    int origemCruzLinha = 7, origemCruzCol = 4;
    for(i=0;i<3;i++){
        for(j=0;j<5;j++){
            int linha = origemCruzLinha - 1 + i;
            int col = origemCruzCol - 2 + j;
            if(linha>=0 && linha<10 && col>=0 && col<10 && cruz[i][j]==1){
                tabuleiro[linha][col] = 5; // Cruz
            }
        }
    }

    // Octaedro 3x3
    int octaedro[3][3] = {
        {0,0,1},
        {0,1,0},
        {0,0,1}
    };
    int origemOctLinha = 5, origemOctCol = 1;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            int linha = origemOctLinha - 1 + i;
            int col = origemOctCol - 1 + j;
            if(linha>=0 && linha<10 && col>=0 && col<10 && octaedro[i][j]==1){
                tabuleiro[linha][col] = 6; // Octaedro
            }
        }
    }

    // --- Legenda ---
    printf("Legenda:\n");
    printf("~ : Agua\n");
    printf("N : Navio\n");
    printf("* : Habilidade Cone\n");
    printf("+ : Habilidade Cruz\n");
    printf(". : Habilidade Octaedro\n\n");

    // --- Exibe o tabuleiro ---
    printf("  ");
    for(j=0;j<10;j++) printf("%c ", 'A'+j);
    printf("\n");

    for(i=0;i<10;i++){
        printf("%d ", i);
        for(j=0;j<10;j++){
            if(tabuleiro[i][j]==0) printf("~ ");       // água
            else if(tabuleiro[i][j]==3) printf("N ");  // navio
            else if(tabuleiro[i][j]==4) printf("* ");  // Cone
            else if(tabuleiro[i][j]==5) printf("+ ");  // Cruz
            else if(tabuleiro[i][j]==6) printf(". ");  // Octaedro
        }
        printf("\n");
    }

    return 0;
}
