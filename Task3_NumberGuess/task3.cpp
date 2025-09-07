#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

int highScore = numeric_limits<int>::max();

int chooseDifficulty() {
    int choice;
    cout << "\nSelect Difficulty Level:\n";
    cout << "1. Easy (1-50)\n";
    cout << "2. Medium (1-100)\n";
    cout << "3. Hard (1-500)\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1: return 50;
        case 2: return 100;
        case 3: return 500;
        default: cout << "Invalid choice. Defaulting to Medium.\n"; return 100;
    }
}

void playGame() {
    int maxRange = chooseDifficulty();
    srand(time(0));
    int secretNumber = rand() % maxRange + 1;
    int guess, attempts = 0;
    bool hintShown = false;

    cout << "\nWelcome to the Number Guessing Game!\n";
    cout << "Guess the number between 1 and " << maxRange << ".\n";

    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess < secretNumber)
            cout << "Too low!\n";
        else if (guess > secretNumber)
            cout << "Too high!\n";
        else
            cout << "Correct! You guessed it in " << attempts << " attempts.\n";

        if (attempts >= 3 && !hintShown && guess != secretNumber) {
            int lowerHint = max(secretNumber - 10, 1);
            int upperHint = min(secretNumber + 10, maxRange);
            cout << "Hint: The number is between " << lowerHint << " and " << upperHint << ".\n";
            hintShown = true;
        }

    } while (guess != secretNumber);

    if (attempts < highScore) {
        highScore = attempts;
        cout << "New High Score: " << highScore << " attempts.\n";
    } else {
        cout << "Your best score so far: " << highScore << " attempts.\n";
    }
}

int main() {
    char playAgain;

    do {
        playGame();
        cout << "Play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!\n";
    return 0;
}
