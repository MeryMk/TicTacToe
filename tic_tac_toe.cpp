#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> board(3, vector<char>(3, ' '));  // 3x3 Tic-Tac-Toe grid

// Function to display the current state of the board
void displayBoard() {
    cout << "\nTic-Tac-Toe Board:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "--------\n";
    }
}

void takeTurn(int player) {
    int row, col;
    char symbol = (player == 1) ? 'X' : 'O';

    cout << "Player " << player << " (" << symbol << "), enter row (0-2) and column (0-2): ";
    cin >> row >> col;

    // Ensure valid input
    while (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
        cout << "Invalid move. Try again: ";
        cin >> row >> col;
    }

    board[row][col] = symbol;
}

bool checkWinner() {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return true;
        }
    }

    // Check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ') {
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return true;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return true;
    }

    return false;
}

bool isDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false; // There's still an empty spot
            }
        }
    }
    return true; // No empty spots, it's a draw
}

int main() {
    int currentPlayer = 1;  // Player 1 starts
    bool winner = false;

    while (!winner && !isDraw()) {
        displayBoard();
        takeTurn(currentPlayer);

        // Check for winner after each turn
        winner = checkWinner();
        if (winner) {
            displayBoard();
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }

        // Check for draw if no winner
        if (isDraw()) {
            displayBoard();
            cout << "It's a draw!\n";
            break;
        }

        // Switch player turn
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }

    return 0;
}
