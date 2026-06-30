#include <stdio.h>

char board[3][3] = { {' ', ' ', ' '},
                     {' ', ' ', ' '},
                     {' ', ' ', ' '} };

void printBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < 2) printf("---|---|---\n");
    }
}

int checkWinner(char p) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0]==p && board[i][1]==p && board[i][2]==p) return 1;
        if (board[0][i]==p && board[1][i]==p && board[2][i]==p) return 1;
    }
    if (board[0][0]==p && board[1][1]==p && board[2][2]==p) return 1;
    if (board[0][2]==p && board[1][1]==p && board[2][0]==p) return 1;
    return 0;
}

int main() {
    int row, col, moves = 0;
    char player = 'X';

    while (1) {
        printBoard();
        printf("Jogador %c, escolha linha e coluna (1-3): ", player);
        scanf("%d %d", &row, &col);

        row--; 
        col--;

        if (row<0||row>2||col<0||col>2||board[row][col]!=' ') {
            printf("Movimento inválido!\n");
            continue;
        }

        board[row][col] = player;
        moves++;

        if (checkWinner(player)) {
            printBoard();
            printf("Jogador %c venceu!\n", player);
            break;
        }
        if (moves == 9) {
            printBoard();
            printf("Empate!\n");
            break;
        }

        player = (player=='X') ? 'O' : 'X';
    }
    return 0;
}