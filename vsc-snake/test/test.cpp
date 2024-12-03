#include <iostream>
#include <conio.h>
#include <windows.h>
#include "SnakeLib.h"
#define MAX_ARRAY_LENGTH 100

using namespace std;

// Global variables
int g_nSnakeLength = 2;
int g_nBorderGame[4] = {5, 3, 105, 23}; // Begin(5,3), console screen (100x20)

// void gotoXYZ(int x, int y)
// {
//     COORD coord;
//     coord.X = x;
//     coord.Y = y;
//     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
// }

void Draw(string sText, int nPosX, int nPosY)
{
    gotoXY(nPosX, nPosY);
    cout << sText;
}

int Control(char c_Input, char c_Left, char c_Top, char c_Down, char c_Right)
{
    int move = 4; // None
    if (c_Input == -32)
    {
        c_Input = _getch();
        c_Input = (c_Input == 72) ? move = 1 : (c_Input == 80) ? move = 0 : 
                  (c_Input == 75) ? move = 3 : (c_Input == 77) ? move = 2 : c_Input;
    }
    else
        (c_Input == c_Top) ? move = 1 : (c_Input == c_Down) ? move = 0 : 
        (c_Input == c_Left) ? move = 3 : (c_Input == c_Right) ? move = 2 : c_Input;
    return move;
}

int CheckLimited(int n_PosX, int n_PosY, int check)
{
    return  (n_PosY == (g_nBorderGame[3] - 1)) ? 1 :
            (n_PosY == (g_nBorderGame[0] - 1)) ? 0 :
            (n_PosX == (g_nBorderGame[0] + 1)) ? 2 :
            (n_PosX == (g_nBorderGame[2] - 1)) ? 3 :
            check;
}

void BorderDraw()
{
    for (int x = g_nBorderGame[0]; x <= g_nBorderGame[2]; ++x)
    {
        Draw("+", x, g_nBorderGame[1]);
        Draw("+", x, g_nBorderGame[3]);
    }
    for (int y = g_nBorderGame[1]; y <= g_nBorderGame[3]; ++y)
    {
        Draw("+", g_nBorderGame[0], y);
        Draw("+", g_nBorderGame[2], y);
    }
}

// Update snake position
void UpdateSnakePosition(int X[], int Y[], int g_nSnakeLength, int newHeadX, int newHeadY)
{
    for (int i = g_nSnakeLength - 1; i > 0; --i)
    {
        X[i] = X[i - 1];
        Y[i] = Y[i - 1];
    }
    X[0] = newHeadX;
    Y[0] = newHeadY;
}

// Clear the tail of the snake
void ClearTail(int X[], int Y[], int g_nSnakeLength)
{
    Draw(" ", X[g_nSnakeLength - 1], Y[g_nSnakeLength - 1]);
}

string PrintValue(int value)
{
    if (value >=0 && value <= 9) return to_string(value);
    else return to_string(value % 10);
}

// Draw the snake
void DrawSnake(int X[], int Y[], int g_nSnakeLength, int move)
{
    for (int i = 0; i < g_nSnakeLength; ++i)
    {
        if (move == 3 || move == 2) Draw(PrintValue(X[i]), X[0], Y[0]);
        else Draw(PrintValue(Y[i]), X[0], Y[0]);
    }
}

void ShowConsoleCursor(bool showFlag)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = showFlag; // false để ẩn, true để hiện
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

int main()
{
    int move = 4, color = 1; // Current direction: 4 (none)
    int X[MAX_ARRAY_LENGTH], Y[MAX_ARRAY_LENGTH];
    X[0] = 50; Y[0] = 12;

    ShowConsoleCursor(false);
    BorderDraw();

    while (true)
    {
        ClearTail(X, Y, g_nSnakeLength); // Clear the old tail

        if (_kbhit())
        {
            char ch = _getch();
            move = Control(ch, 'z', 's', 'x', 'c');
        }

        SetColor(color);
        color++;
        color = (color > 15) ? 1 : color;

        int newHeadX = (move == 2) ? (X[0] + 1) : (move == 3) ? (X[0] - 1) : X[0];
        int newHeadY = (move == 0) ? (Y[0] + 1) : (move == 1) ? (Y[0] - 1) : Y[0];

        UpdateSnakePosition(X, Y, g_nSnakeLength, newHeadX, newHeadY); // Update the snake's position
        DrawSnake(X, Y, g_nSnakeLength, move); // Draw the snake

        move = CheckLimited(X[0], Y[0], move); // Check for collisions

        Sleep(100); // Control speed
    }

    _getch();
    return 0;
}