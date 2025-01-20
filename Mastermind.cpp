#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

class Mastermind {
private:
    vector<int> secretCode;
    int numDigits;
    int numAttempts;
    bool gameOver;

public:
    Mastermind(int digits = 4, int attempts = 10) : numDigits(digits), numAttempts(attempts), gameOver(false) {
        srand(time(nullptr));
        generateSecretCode();
    }

    void generateSecretCode() {
        secretCode.clear();
        for (int i = 0; i < numDigits; ++i) {
            secretCode.push_back(rand() % 10); // Random digit between 0 and 9
        }
    }

    void play() {
        cout << "Welcome to Mastermind!\n";
        cout << "Guess the " << numDigits << "-digit secret code. You have " << numAttempts << " attempts.\n";
        cout << "Rules: 0 means the digit is not in the number. "<<endl;
        cout << "Rules: 1 means the digit is in the number and at the right index. "<<endl;
        cout << "Rules: 2 means the digit is in the number but at wrong index. "<<endl;


        for (int attempt = 1; attempt <= numAttempts; ++attempt) {
            vector<int> guess = getGuess();
            vector<int> feedback = checkGuess(guess);

            cout << "Attempt " << attempt << ": ";
            for (int digit : guess) {
                cout << digit << " ";
            }
            cout << " -> ";

            for (int digit : feedback) {
                cout << digit << " ";
            }
            cout << endl;

            if (feedback == vector<int>(numDigits, 1)) { // All digits correct
                cout << "Congratulations! You've guessed the secret code.\n";
                gameOver = true;
                break;
            }
        }

        if (!gameOver) {
            cout << "Out of attempts! The secret code was: ";
            for (int digit : secretCode) {
                cout << digit << " ";
            }
            cout << endl;
        }
    }

    vector<int> getGuess() {
        cout << "Enter your guess (" << numDigits << " digits separated by spaces): ";
        vector<int> guess(numDigits);
        for (int i = 0; i < numDigits; ++i) {
            cin >> guess[i];
        }
        return guess;
    }

    vector<int> checkGuess(const vector<int>& guess) const {
        vector<int> feedback(numDigits);
        vector<int> secretCodeCopy = secretCode;

        for (int i = 0; i < numDigits; ++i) {
            if (guess[i] == secretCode[i]) {
                feedback[i] = 1; // Correct digit and position
                secretCodeCopy[i] = -1; // Mark as checked
            }
        }

        for (int i = 0; i < numDigits; ++i) {
            if (feedback[i] == 0) {
                auto it = find(secretCodeCopy.begin(), secretCodeCopy.end(), guess[i]);
                if (it != secretCodeCopy.end()) {
                    feedback[i] = 2; // Correct digit but wrong position
                    secretCodeCopy[it - secretCodeCopy.begin()] = -1; // Mark as checked
                }
            }
        }

        return feedback;
    }
};
