#include <iostream>
#include "SnakeLib.h"
#define MAX_ARRAY_LENGTH 100

using namespace std;

int g_nSnakeLength = 2,
    g_nPosDefault[2] = { 50, 12 },
    g_nBorderGame[4] = { 5, 3, 105, 23 }    // Begin(5,3), console screen (100x20)
    ;

void Draw(string sText, int nPosX, int nPosY)
{
    gotoXY(nPosX, nPosY);
    cout << sText;
}

string PrintValue(int value)
{
    if (value >=0 && value <= 9) return to_string(value);
    else return to_string(value % 10);
}

int Control(char c_Input, char c_Left, char c_Top, char c_Down, char c_Right)
{
    int move = 4; // None
    if (c_Input == -32)
    {
        c_Input = _getch();
        c_Input = (c_Input == 72) ? move = 1 : (c_Input == 80) ? move = 0 : (c_Input == 75) ? move = 3 : (c_Input == 77) ? move = 2 : c_Input;
    }
    else
        (c_Input == c_Top) ? move = 1 : (c_Input == c_Down) ? move = 0 : (c_Input == c_Left) ? move = 3 : (c_Input == c_Right) ? move = 2 : c_Input;
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
    int a = g_nBorderGame[0],
        b = g_nBorderGame[0],
        e = g_nBorderGame[1],
        f = g_nBorderGame[1];

    while (a <= g_nBorderGame[2])
    {
        Draw("+", a, g_nBorderGame[1]);
        a += 1;
        Draw("+", b, g_nBorderGame[3]);
        b += 1;
    }
    while (e <= g_nBorderGame[3])
    {
        Draw("+", g_nBorderGame[0], e);
        e += 1;
        Draw("+", g_nBorderGame[2], f);
        f += 1;
    }
}

void InsertValue(int arr[], int value)
{
    for (int i = g_nSnakeLength; i > 0; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[0] = value;

    // - chuyển các value lên vị trí +1
    // - thêm value mới vào vị trí a[0]
}

int main()
{
    int move = 4, color = 1;
    int X[MAX_ARRAY_LENGTH], Y[MAX_ARRAY_LENGTH];
    X[0] = 50; Y[0] = 12;
    int x = X[0], y = Y[0];

    BorderDraw();

    while (true)
    {
        // sự kiện ẩn đi rắn ở ô hiện tại  
        // sự kiện hiện rắn ở ô tiếp theo  
        // gán phím di chuyển  
        // kiểm tra hướng di chuyển và xác định vị trí tiếp theo  
        // check va chạm tường với vị trí mới  

        Draw(" ", x, y);
        if (move == 3 || move == 2) Draw(PrintValue(x), X[0], Y[0]);
        else Draw(PrintValue(y), X[0], Y[0]);

        x = X[0]; y = Y[0];

        SetColor(color);
        color++;
        color = (color > 15) ? 1 : color;

        if (_kbhit())
        {
            char ch = _getch();
            move = Control(ch, 'z', 's', 'x', 'c');
        }

        Y[0] = (move == 0) ? (Y[0] + 1) : (move == 1) ? (Y[0] - 1) : Y[0];
        X[0] = (move == 2) ? (X[0] + 1) : (move == 3) ? (X[0] - 1) : X[0];
        move = CheckLimited(X[0], Y[0], move);

        Sleep(100);
    }

    _getch();
    return 0;
}