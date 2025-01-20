#include <iostream>
#include <vector>

using namespace std;

const int ROWS = 6;
const int COLS = 7;
const char EMPTY = ' ';
const char player3 = 'X';
const char player4 = 'O';

class Board {
private:
    vector<vector<char>> grid;
public:
    Board() : grid(ROWS, vector<char>(COLS, EMPTY)) {}

    void print() const {
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                cout << "| " << grid[i][j] << " ";
            }
            cout << "|" << endl;
        }
        for (int j = 0; j < COLS; ++j) {
            cout << "----";
        }
        cout << "-" << endl;
        for (int j = 0; j < COLS; ++j) {
            cout << "  " << j + 1 << " ";
        }
        cout << endl;
    }

    bool dropPiece(int column, char symbol) {
        if (column < 0 || column >= COLS || grid[0][column] != EMPTY) {
            return false; // Invalid move
        }
        for (int i = ROWS - 1; i >= 0; --i) {
            if (grid[i][column] == EMPTY) {
                grid[i][column] = symbol;
                return true; // Valid move
            }
        }
        return false; // Column is full
    }

    bool checkWin(char symbol) const {
        // Check horizontally
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j <= COLS - 4; ++j) {
                if (grid[i][j] == symbol && grid[i][j + 1] == symbol && grid[i][j + 2] == symbol && grid[i][j + 3] == symbol) {
                    return true;
                }
            }
        }
        // Check vertically
        for (int j = 0; j < COLS; ++j) {
            for (int i = 0; i <= ROWS - 4; ++i) {
                if (grid[i][j] == symbol && grid[i + 1][j] == symbol && grid[i + 2][j] == symbol && grid[i + 3][j] == symbol) {
                    return true;
                }
            }
        }
        // Check diagonally (positive slope)
        for (int i = 0; i <= ROWS - 4; ++i) {
            for (int j = 0; j <= COLS - 4; ++j) {
                if (grid[i][j] == symbol && grid[i + 1][j + 1] == symbol && grid[i + 2][j + 2] == symbol && grid[i + 3][j + 3] == symbol) {
                    return true;
                }
            }
        }
        // Check diagonally (negative slope)
        for (int i = 0; i <= ROWS - 4; ++i) {
            for (int j = COLS - 1; j >= 3; --j) {
                if (grid[i][j] == symbol && grid[i + 1][j - 1] == symbol && grid[i + 2][j - 2] == symbol && grid[i + 3][j - 3] == symbol) {
                    return true;
                }
            }
        }
        return false;
    }

    bool isFull() const {
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                if (grid[i][j] == EMPTY) {
                    return false;
                }
            }
        }
        return true;
    }
};

class Playr {
private:
    char symbol;

public:
    Playr(char sym) : symbol(sym) {}

    char getSymbol() const {
        return symbol;
    }
};

class ConnectFour {
private:
    Board board;
    Playr player3;
    Playr player4;
    bool player3Turn;

public:
    ConnectFour() : player3(player3), player4(player4), player3Turn(true) {}

    void play() {
        while (true) {
            system("cls");
            board.print();

            Playr currentPlayer = (player3Turn) ? player3 : player4;
            char symbol = currentPlayer.getSymbol();

            int column;
            cout << "Player " << symbol << ", enter column (1-7): ";
            cin >> column;
            column--;
            if (board.dropPiece(column, symbol)) {
                if (board.checkWin(symbol)) {
                    board.print();
                    cout << "Player " << symbol << " wins!" << endl;
                    break;
                } else if (board.isFull()) {
                    board.print();
                    cout << "It's a draw!" << endl;
                    break;
                }
                player3Turn = !player3Turn;
            } 
            else {
                cout << "Invalid move, try again." << endl;
            }
        }
    }
};