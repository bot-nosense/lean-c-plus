#include <iostream>
#include "SnakeLib.h"
#define MAX_ARRAY_LENGTH 10

using namespace std;

const int pickup_point[2] = { 20, 12};
int snake_length = 4;

void Draw(char cCharacter, int nPosX, int nPosY)
{
    gotoXY(nPosX, nPosY);
    cout << cCharacter;
}

void SnakeDraw(int nPosX[], int nPosY[])
{
    for (int i = 0; i < snake_length; i++)
    {
        // if (i == 0) Draw('O', nPosX[i], nPosY[i]);
        // else 
        Draw('O', nPosX[i], nPosY[i]);
    }
}

int main()
{
    int move = 0;
    int X[MAX_ARRAY_LENGTH], Y[MAX_ARRAY_LENGTH];
    X[0] = pickup_point[0]; Y[0] = pickup_point[1];
    
    // snake_length ++;
    for (int i = 0; i < snake_length; i++)
    {
        X[i] = X[0]+1;
        // Y[i] = Y[0]+1;

        Draw('O',X[i], Y[i]);
        Sleep(1000);
    }
    
    // while(snake_length<MAX_ARRAY_LENGTH)
    // {
        
    // }

    _getch();
    return 0;
}