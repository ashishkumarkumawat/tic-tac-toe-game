#include <stdio.h>

char board[3][3];  // 3x3 Tic-Tac-Toe board

// Function to initialize the board with empty spaces
void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to display the board
void displayBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

// Function to check if a player has won
char checkWinner() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return board[i][0];  // Row match
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return board[0][i];  // Column match
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return board[0][0];  // Left diagonal
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return board[0][2];  // Right diagonal

    return ' ';  // No winner yet
}

// Function to check if the board is full (Draw)
int isBoardFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') return 0;  // Empty space found
        }
    }
    return 1;  // Board is full
}

// Function to play the game
void playGame() {
    int row, col;
    char currentPlayer = 'X';

    while (1) {
        displayBoard();

        // Input move
        printf("Player %c, enter row and column (1-3): ", currentPlayer);
        scanf("%d %d", &row, &col);
        
        // Convert to 0-based index
        row--; col--;

        // Check for valid input
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            printf("Invalid move! Try again.\n");
            continue;
        }

        // Make the move
        board[row][col] = currentPlayer;

        // Check for winner
        char winner = checkWinner();
        if (winner != ' ') {
            displayBoard();
            printf("🎉 Player %c wins! 🎉\n", winner);
            return;
        }

        // Check for a draw
        if (isBoardFull()) {
            displayBoard();
            printf("It's a draw! 🤝\n");
            return;
        }

        // Switch player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}

// Main function
int main() {
    printf("Welcome to Tic-Tac-Toe!\n");
    initializeBoard();
    playGame();
    return 0;
}

