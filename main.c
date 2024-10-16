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

void jogadasPossiveis(int tabuleiro[N][N], int linha, int coluna) {
    printf("Jogadas possíveis para a peça na linha %d e coluna %d:\n", linha, coluna);

    // Verifica as posições ao redor da peça
    int direcoes[4][2] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    for (int i = 0; i < 4; i++) {
        int novaLinha = linha + direcoes[i][0];
        int novaColuna = coluna + direcoes[i][1];

        if (novaLinha >= 0 && novaLinha < N && novaColuna >= 0 && novaColuna < N && tabuleiro[novaLinha][novaColuna] == 0) {
            printf("Linha %d, Coluna %d\n", novaLinha, novaColuna);
        }
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
            jogadasPossiveis(tabuleiro, linha, coluna);
        }

        mostrarTabuleiro(tabuleiro);

        printf("Deseja continuar? (s/n): ");
        scanf(" %c", &continuar);
    } while (continuar == 's' || continuar == 'S');
}

int main() {
    int tabuleiro[N][N] = {0};

    colocarPeca(tabuleiro);
    jogadasPossiveis(tabuleiro, 0, 0);

    return 0;
}