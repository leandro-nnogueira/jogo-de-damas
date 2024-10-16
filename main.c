#include <stdio.h>

#define N 8

void mostrarTabuleiro(int tabuleiro[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", tabuleiro[i][j]);
        printf("\n");
    }
}

void colocarPeca(int tabuleiro[N][N]) {
    int linha, coluna;

    while (1) {

    printf("Digite a linha e a coluna onde deseja colocar a peça: ");
    scanf("%d %d", &linha, &coluna);

    tabuleiro[linha][coluna] = 1;
    printf("Peça colocada na linha %d e coluna %d\n", linha, coluna);

    printf("Deseja colocar outra peça? (1 - Sim, 0 - Não): ");
    int opcao;
    scanf("%d", &opcao);
    if (opcao == 0) {

        break;
    }
    else {
        mostrarTabuleiro(tabuleiro);
    }
}
}

int main() {

    int tabuleiro[N][N] = {0};

    colocarPeca(tabuleiro);

    return 0;
}