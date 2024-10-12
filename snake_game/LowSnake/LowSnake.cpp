﻿

#include <iostream>
#include "SnakeLib.h"

int g_nSnakeLength = 4,
    g_nPosDefault[2] = { 50, 12 },
    g_nBorderGame[4] = { 5, 3, 105, 23 }    // A(5,3), console screen (100x20)
    ;

int CheckLimited(int n_PosX, int n_PosY, int check)
{
    return  (n_PosY == (g_nBorderGame[3] - 1)) ? 1 :
            (n_PosY == (g_nBorderGame[0] - 1)) ? 0 :
            (n_PosX == (g_nBorderGame[0] + 1)) ? 2 :
            (n_PosX == (g_nBorderGame[2] - 3)) ? 3 :
            check;
}

void Draw(char cCharacter, int nPosX, int nPosY)
{
    gotoXY(nPosX, nPosY);
    std::cout << cCharacter;
}

void SnakeDraw(int nPosX[], int nPosY[])
{
    if (g_nSnakeLength == 4)
    {
        Draw('O', nPosX[0], nPosY[0]);
        Draw('0', nPosX[1], nPosY[1]);
        Draw('o', nPosX[2], nPosY[2]);
        Draw('.', nPosX[3], nPosY[3]);
    }
    else 
    {
        Draw('O', nPosX[0], nPosY[0]);
        Draw('0', nPosX[1], nPosY[1]);
        Draw('.', nPosX[g_nSnakeLength], nPosY[g_nSnakeLength]);
        for (int i = 2; i < g_nSnakeLength; i++)
            Draw('o', nPosX[i], nPosY[i]);
    }
}

void SnakeSketch(int nPosX[], int nPosY[])
{
    for (int i = 0; i < g_nSnakeLength; i++)
    {
        nPosX[i] = g_nPosDefault[0];
        nPosY[i] = g_nPosDefault[1];
        g_nPosDefault[0]--;
        std::cout << g_nPosDefault[0];
    }
}

void InsertBegin(int nArr[], int nLength, int nValue)
{
    for (int i = nLength; i > 0; i--)
        nArr[i] = nArr[i - 1];
    nArr[0] = nValue;
    nLength++;
}

void RemoveLast(int nArr[], int nIndex)
{
    for (int i = nIndex; i < g_nSnakeLength; i++)
        nArr[i] = nArr[i + 1];
    g_nSnakeLength--;
}

void BorderDraw()
{
    int a = g_nBorderGame[0],
        b = g_nBorderGame[0],
        e = g_nBorderGame[1],
        f = g_nBorderGame[1];

    while (a <= g_nBorderGame[2])
    {
        Draw('+', a, g_nBorderGame[1]);
        a += 1;
        Draw('+', b, g_nBorderGame[3]);
        b += 1;
    }
    while (e <= g_nBorderGame[3])
    {
        Draw('+', g_nBorderGame[0], e);
        e += 1;
        Draw('+', g_nBorderGame[2], f);
        f += 1;
    }
}

void snake_move(int x[], int y[], int a, int b, int length)
{
    //add_array(x, length, a );
}

int main()
{
    int move = 0;  // 0: cham bien tren -> di xuong
                    // 1: cham bien duoi -> di len
                    // 2: cham bien trai -> sang phai
                    // 3: cham bien phai -> sang trai
    int color = 1;
    int x = g_nPosDefault[0], y = g_nPosDefault[1];
    int toadoX[100], toadoY[100];

    BorderDraw();

    /*SnakeSketch(toadoX, toadoY, g_nSnakeLength);
    SnakeDraw(toadoX, toadoY, g_nSnakeLength);*/
    
    //snake_move(toadoX, toadoY, x, y, g_SnakeLength);

    /*for (int i = g_nSnakeLength; i > 0; i--)
    {
        std::cout << i + ", " + toadoX[i];
        toadoX[i] = toadoX[i - 1];
    }
    toadoX[0] = 0;*/
    //g_SnakeLength++;

    /*for (int i = 4; i > 0; i--)
    {
        std::cout << i ;
        toadoX[i] = toadoX[i - 1];
        std::cout << toadoX[i];
        std::cout << '\n';
    }*/

    while (true)
    {
        gotoXY(x, y);
        std::cout << "   ";
        gotoXY(g_nPosDefault[0], g_nPosDefault[1]);
        std::cout << "[!]";

        x = g_nPosDefault[0];
        y = g_nPosDefault[1];

        SetColor(color);
        color++;
        color = (color > 15) ? 1 : color;

        if (_kbhit())
        {
            char ch = _getch();
            if (ch == -32)
            {
                ch = _getch();
                ch = (ch == 72) ? move = 1 : (ch == 80) ? move = 0 : (ch == 75) ? move = 3 : (ch == 77) ? move = 2 : ch;
            }
            ch = (ch == 's') ? move = 1 : (ch == 'x') ? move = 0 : (ch == 'z') ? move = 3 : (ch == 'c') ? move = 2 : ch;
        }

        g_nPosDefault[1] = (move == 0) ? (g_nPosDefault[1] + 1) : (move == 1) ? (g_nPosDefault[1] - 1) : g_nPosDefault[1];
        g_nPosDefault[0] = (move == 2) ? (g_nPosDefault[0] + 1) : (move == 3) ? (g_nPosDefault[0] - 1) : g_nPosDefault[0];
        move = CheckLimited(g_nPosDefault[0], g_nPosDefault[1], move);

        Sleep(100);
    }

    _getch();
    return 0;
}