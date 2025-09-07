#include<bits/stdc++.h>
using namespace std;

char grid[3][3];
int scoreX = 0, scoreO = 0;

void resetBoard() {
    char cell = '1';
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            grid[i][j] = cell++;
}

void showBoard() {
    cout << "\nCurrent Board:\n";
    for (int i = 0; i < 3; ++i) {
        cout << " ";
        for (int j = 0; j < 3; ++j) {
            cout << grid[i][j];
            if (j < 2) cout << " | ";
        }
        if (i < 2) cout << "\n-----------\n";
    }
    cout << "\n";
}

bool isWin(char symbol) {
    for (int i = 0; i < 3; ++i)
        if ((grid[i][0] == symbol && grid[i][1] == symbol && grid[i][2] == symbol) ||
            (grid[0][i] == symbol && grid[1][i] == symbol && grid[2][i] == symbol))
            return true;
    if ((grid[0][0] == symbol && grid[1][1] == symbol && grid[2][2] == symbol) ||
        (grid[0][2] == symbol && grid[1][1] == symbol && grid[2][0] == symbol))
        return true;
    return false;
}

bool isDraw() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (grid[i][j] != 'X' && grid[i][j] != 'O')
                return false;
    return true;
}

void playRound(char player1, char player2) {
    resetBoard();
    char current = player1;
    int move;

    while (true) {
        showBoard();
        cout << "Player " << current << ", enter your move (1-9): ";
        cin >> move;

        int row = (move - 1) / 3;
        int col = (move - 1) % 3;

        if (move < 1 || move > 9 || grid[row][col] == 'X' || grid[row][col] == 'O') {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        grid[row][col] = current;

        if (isWin(current)) {
            showBoard();
            cout << "Player " << current << " wins this round!\n";
            if (current == 'X') scoreX++;
            else scoreO++;
            break;
        }

        if (isDraw()) {
            showBoard();
            cout << "It's a draw!\n";
            break;
        }

        current = (current == player1) ? player2 : player1;
    }
}

int main() {
    char player1, player2;
    char playAgain;

    cout << "Welcome to Tic-Tac-Toe! "<< endl;
    cout << "Player 1, choose your symbol (X or O): ";
    cin >> player1;
    player2 = (player1 == 'X') ? 'O' : 'X';

    do {
        playRound(player1, player2);
        cout << "Scores : X: " << scoreX << " | O: " << scoreO <<endl;
        cout << "Play another round? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Final Scores → X: " << scoreX << " | O: " << scoreO << endl;
    cout << "Thanks for playing!\n";
    return 0;
}
