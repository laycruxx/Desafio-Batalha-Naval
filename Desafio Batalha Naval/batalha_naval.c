#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 5

int main() {
    int linha, coluna;
    int navioLinha, navioColuna;
    int tentativa = 0;
    char tabuleiro[TAM][TAM];

   
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = '~';
        }
    }

   
    srand(time(NULL));
    navioLinha = rand() % TAM;
    navioColuna = rand() % TAM;

    printf("Bem-vindo à Batalha Naval (5x5)!\n");
    printf("Tente afundar o navio escondido!\n");

    while (1) {
        tentativa++;
        printf("\nTentativa %d: Digite linha e coluna (0 a 4):\n", tentativa);
        printf("Linha: ");
        scanf("%d", &linha);
        printf("Coluna: ");
        scanf("%d", &coluna);

        if (linha < 0 || linha >= TAM || coluna < 0 || coluna >= TAM) {
            printf("Coordenadas inválidas! Tente novamente.\n");
            continue;
        }

        if (linha == navioLinha && coluna == navioColuna) {
            tabuleiro[linha][coluna] = 'X';
            printf("💥 BOOM! Você acertou o navio na posição [%d, %d]!\n", linha, coluna);
            break;
        } else {
            if (tabuleiro[linha][coluna] == '~') {
                tabuleiro[linha][coluna] = '*';
                printf("Água! Nada foi atingido.\n");
            } else {
                printf("Você já tentou essa posição!\n");
            }
        }

       
        printf("Tabuleiro:\n");
        for (int i = 0; i < TAM; i++) {
            for (int j = 0; j < TAM; j++) {
                printf("%c ", tabuleiro[i][j]);
            }
            printf("\n");
        }
    }

    printf("\nFim de jogo! Tentativas: %d\n", tentativa);

    return 0;
}
