#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

enum class Player
{
    EMPTY,
    PLAYER_X,
    PLAYER_O
};

class TicTacToe
{
private:
    vector<vector<Player>> board;
    Player currentPlayer;
    string playerXName;
    string playerOName;

public:
    TicTacToe() : currentPlayer(Player::PLAYER_X) {}

    void setPlayerNames()
    {
        cout << "Enter name for Player X: ";
        cin >> playerXName;
        cout << "Enter name for Player O or Enter Computer: ";
        cin >> playerOName;
    }

    void initializeBoard(int size)
    {
        board = vector<vector<Player>>(size, vector<Player>(size, Player::EMPTY));
    }

    void printBoard() const
    {
        for (const auto &row : board)
        {
            for (const auto &cell : row)
            {
                switch (cell)
                {
                case Player::PLAYER_X:
                    cout << " X ";
                    break;
                case Player::PLAYER_O:
                    cout << " O ";
                    break;
                case Player::EMPTY:
                    cout << "   ";
                    break;
                }
                cout << "|";
            }
            cout << "\n";
            cout << " ";
            for (int i = 0; i < board.size() * 4 - 1; ++i)
            {
                cout << "-";
            }
            cout << "\n";
        }
    }

    bool isMoveValid(int row, int col) const
    {
        return (row >= 0 && row < board.size() && col >= 0 && col < board.size() && board[row][col] == Player::EMPTY);
    }

    bool isBoardFull() const
    {
        for (const auto &row : board)
        {
            for (const auto &cell : row)
            {
                if (cell == Player::EMPTY)
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool checkForWinner() const
    {
        // Check rows and columns
        for (int i = 0; i < board.size(); ++i)
        {
            bool rowWin = true;
            bool colWin = true;

            for (int j = 1; j < board.size(); ++j)
            {
                if (board[i][j] != board[i][0])
                {
                    rowWin = false;
                }
                if (board[j][i] != board[0][i])
                {
                    colWin = false;
                }
            }

            if (rowWin && board[i][0] != Player::EMPTY)
            {
                return true; // Row
            }
            if (colWin && board[0][i] != Player::EMPTY)
            {
                return true; // Column
            }
        }

        // Check diagonals
        bool diag1Win = true;
        bool diag2Win = true;

        for (int i = 0; i < board.size(); ++i)
        {
            if (board[i][i] != board[0][0])
            {
                diag1Win = false;
            }
            if (board[i][board.size() - 1 - i] != board[0][board.size() - 1])
            {
                diag2Win = false;
            }
        }

        return (diag1Win && (board[0][0] != Player::EMPTY)) || (diag2Win && board[0][board.size() - 1] != Player::EMPTY);
    }

    void makeMove(int row, int col)
    {
        if (isMoveValid(row, col))
        {
            board[row][col] = currentPlayer;
        }
        else
        {
            cout << "Invalid move.\n Enter row and column again.";
            cin>>row >>col;
            makeMove(row-1,col-1);
        }
    }

    void makeComputerMove()
    {
        // Simple AI: Randomly choose an empty cell for the computer's move
        int row, col;
        do
        {
            row = rand() % board.size();
            col = rand() % board.size();
        } while (!isMoveValid(row, col));

        cout << "Computer (" << getPlayerSymbol(currentPlayer) << ") chose row " << row + 1 << " and column " << col + 1 << ".\n";
        board[row][col] = currentPlayer;
        //currentPlayer = (currentPlayer == Player::PLAYER_X) ? Player::PLAYER_O : Player::PLAYER_X;
        
    }

    string getPlayerSymbol(Player player) const
    {
        return (player == Player::PLAYER_X) ? "X" : "O";
    }

    string getCurrentPlayerName() const
    {
        return (currentPlayer == Player::PLAYER_X) ? playerXName : playerOName;
    }

    void changeCurrentPlayerName()
    {
        currentPlayer = (currentPlayer == Player::PLAYER_X) ? Player::PLAYER_O : Player::PLAYER_X;
    }

    int start()
    {

        TicTacToe game;
        int boardSize;
        system("cls");
        cout << "Welcome to Tic-Tac-Toe!\n";

        cout << "Enter the size of the board (minimum 3): ";
        cin >> boardSize;

        if (boardSize < 3)
        {
            cout << "Invalid board size. Setting it to the minimum size of 3.\n";
            boardSize = 3;
        }

        game.initializeBoard(boardSize);
        game.setPlayerNames();

        do
        {
            game.printBoard();

            if (game.getCurrentPlayerName() == "Computer")
            {
                game.makeComputerMove();
            }
            else
            {
                int row, col;
                cout << game.getCurrentPlayerName() << ", enter your move (row and column): ";
                cin >> row >> col;

                game.makeMove(row - 1, col - 1);
            }

            if (game.checkForWinner())
            {
                system("cls");
                game.printBoard();
                cout << game.getCurrentPlayerName() << " wins!\n";
                break;
            }
            else if (game.isBoardFull())
            {
                system("cls");
                game.printBoard();
                cout << "It's a draw!\n";
                break;
            }

            game.changeCurrentPlayerName();
            system("cls");

        } while (true);

        cout << "Thanks for playing!\n";
    }
};