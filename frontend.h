#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include <string>
using namespace std;

void setCursorPosition(int row, int col) {
    COORD coord;
    coord.X = col;
    coord.Y = row;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void drawOuterBox(int rows, int cols, int startRow, int startCol) {
    system("color 02");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            setCursorPosition(startRow + i, startCol + j);

            if (i == 0 && j == 0) {
                std::cout << '+';
            } else if (i == 0 && j == cols - 1) {
                std::cout << '+';
            } else if (i == rows - 1 && j == 0) {
                std::cout << '+';
            } else if (i == rows - 1 && j == cols - 1) {
                std::cout << '+';
            } else if (i == 0 || i == rows - 1) {
                std::cout << '-';
            } else if (j == 0 || j == cols - 1) {
                std::cout << '|';
            } else {
                std::cout << ' ';
            }
        }
    }

    system("color 07");
}


void getInput(int choice,string input[]) 
{
    system("cls");

    drawOuterBox(12,40,10,40);


    if (choice == 1)
    {
        system("color 02");

        setCursorPosition(14, 45);
        std::cout << "First Name: ";

        setCursorPosition(16, 45);
        cout << "Last Name: ";

        setCursorPosition(18, 45);
        cout << "Password: ";

        setCursorPosition(14, 56);
        std ::getline(std::cin, input[0]);

        setCursorPosition(16, 56);
        std ::getline(std::cin, input[1]);        

        setCursorPosition(18, 55);
        int ch;
        ch = getch();

        while (ch != 13)
        {
            input[2].push_back(ch);
            cout << "*";
            ch = getch();
        }
    }

    else if (choice == 2)
    {
        setCursorPosition(12, 45);
        std::cout << "First Name: ";

        system("color 02");

        setCursorPosition(14, 45);
        cout << "Last Name: ";

        setCursorPosition(16,45);
        cout << "Password : ";

        setCursorPosition(18,45);
        cout << "Confirm Password : ";

        setCursorPosition(12, 56);
        std ::getline(std::cin, input[0]);

        setCursorPosition(14, 56);
        std ::getline(std::cin, input[1]);

        setCursorPosition(16, 55);
        int ch;
        ch = getch();

        while (ch != 13)
        {
            input[2].push_back(ch);
            cout << "*";
            ch = getch();
        }
       beginning:
        string confirm;
        setCursorPosition(18, 65);
        ch = getch();
        while (ch != 13)
        {
            confirm.push_back(ch);
            cout << "*";
            ch = getch();
        }
        if(confirm!=input[2])
        {
            goto beginning;
        }
    }
}