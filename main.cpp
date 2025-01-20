// Main Function to run all the games.
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "tic.cpp"
#include "pac.cpp"
#include "hang.cpp"
#include "connect.cpp"
#include "Mastermind.cpp"

using namespace std;

bool Login(string &username, string &password)
{
    cout << "\n\nLogin: \n";
    cout << "Username : ";
    cin >> username;
    cout << "Password : ";
    for (int i = 0; i < 15; ++i)
    {
        char ch = _getch();
        if (ch == '\r')
            break;
        password += ch;
    }

    if (username == "admin" && password == "1234")
        return true;
    else
        return false;
}

int main()
{

    while (1)
    {
        system("cls"); // Clearing the screen Befor starting any game

        string userName = "";
        string passWord = "";

        bool isLoggedIn = Login(userName, passWord);
        if (!isLoggedIn)
        {
            cout << "\nWrong Username or Password! Try Again.";
            Sleep(2000);
        }
        else
            break;
    }

    // Choosing Game from Menu
    int choice;
    char c;
    do
    {
        system("cls");
        cout << "\nGAME MENU:\n";
        cout << "1. Play Tic-tac-toe.\n";
        cout << "2. PLay Pacman .\n";
        cout << "3. Play Hangman .\n";
        cout << "4. Play Connect Four. \n";
        cout << "5. Play Mastermind. \n";
        cout << "6. Exit.\n";
        cout << "Enter your choice : ";
        cin >> choice;

        if (choice == 1)
        {
            TicTacToe game;
            game.start();
        }
        else if (choice == 2)
        {
            Pacman game2;
            game2.start();
        }
        else if (choice == 3)
        {
            HangMan game3;
            game3.start();
        }

        else if (choice == 4)
        {
            ConnectFour game4;
            game4.play();
        }

        else if (choice == 5)
        {
            system("cls");
            Mastermind game5;
            game5.play();
        }

        else if (choice == 6)
        {
            break;
        }
        else
        {
            cout << "Invalid Choice! Please Enter a Valid Number." << endl;
        }

        cout << "\nDo you want to continue? Y/N : ";
        cin >> c;
    } while (c == 'y' || c == 'Y');

    cout << "Hope you  had fun playing our games!\n";

    Sleep(1000);

    return 0;
}