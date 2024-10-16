#include <stdio.h>

#define N 8

void mostrarTabuleiro(int tabuleiro[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", tabuleiro[i][j]);
        printf("\n");
    }
}

void verificaPosicao(int tabuleiro[N][N], int linha, int coluna) {
    if (tabuleiro[linha][coluna] == 1) {
        printf("Posição ocupada, escolha outra\n");
    }
    else {
        tabuleiro[linha][coluna] = 1;
        printf("Peça colocada na linha %d e coluna %d\n", linha, coluna);
    }
}

void colocarPeca(int tabuleiro[N][N]) {
    int linha, coluna;
    char continuar;

    do {
        mostrarTabuleiro(tabuleiro);

        printf("Digite a linha e a coluna para colocar a peça\n");
        scanf("%d %d", &linha, &coluna);

        if (linha >= N || coluna >= N || linha < 0 || coluna < 0) {
            printf("Posição inválida, fora do tabuleiro. Tente novamente.\n");
        } else {
            verificaPosicao(tabuleiro, linha, coluna);
        }

        mostrarTabuleiro(tabuleiro);

        printf("Deseja continuar? (s/n): ");
        scanf(" %c", &continuar);
    } while (continuar == 's' || continuar == 'S');
}

int main() {

    int tabuleiro[N][N] = {0};

    colocarPeca(tabuleiro);

    return 0;
}