#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

typedef struct {
    int x, y;
} Position;

typedef struct {
    Position pos;
    char type; // 'b' for black, 'w' for white, 'B' for black king, 'W' for white king
} Piece;

void readBoard(const char *filename, Piece board[SIZE][SIZE]) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            fscanf(file, " %c", &board[i][j].type);
            board[i][j].pos.x = i;
            board[i][j].pos.y = j;
        }
    }

    fclose(file);
}

void printBoard(Piece board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j].type);
        }
        printf("\n");
    }
}

void findMoves(Piece board[SIZE][SIZE], char side, FILE *output) {
    // Implement logic to find possible moves for the given side
    // For simplicity, this example just prints the positions of the pieces
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j].type == side || board[i][j].type == (side - 32)) {
                fprintf(output, "Piece at (%d, %d)\n", i, j);
                printf("Piece at (%d, %d)\n", i, j);
            }
        }
    }
}

int main() {
    Piece board[SIZE][SIZE];
    const char *inputFile = "input.txt";
    const char *outputFile = "output.txt";

    readBoard(inputFile, board);
    printBoard(board);

    FILE *output = fopen(outputFile, "w");
    if (!output) {
        perror("Failed to open output file");
        exit(EXIT_FAILURE);
    }

    char side = 'b'; // Change to 'w' for white
    findMoves(board, side, output);

    fclose(output);
    return 0;
}