//#include "Snake.h"
//#include "SnakeLib.h"
//#include <iostream>
//#include "Draw.h"
//
//int g_nSnakeLength = 4,
//    g_nPosDefault[2] = { 50, 12 },
//    g_nBorderGame[4] = { 5, 3, 105, 23 }    // Begin(5,3), console screen (100x20)
//    ;
//
//class Snake {
//public:
//
//    Draw draw;
//
//    int Control(char c_Input, char c_Left, char c_Top, char c_Down, char c_Right)
//    {
//        int move = -1; // None
//        if (c_Input == -32)
//        {
//            c_Input = _getch();
//            c_Input = (c_Input == 72) ? move = 1 : (c_Input == 80) ? move = 0 : (c_Input == 75) ? move = 3 : (c_Input == 77) ? move = 2 : c_Input;
//        }
//        else
//            (c_Input == c_Top) ? move = 1 : (c_Input == c_Down) ? move = 0 : (c_Input == c_Left) ? move = 3 : (c_Input == c_Right) ? move = 2 : c_Input;
//        return move;
//    }
//
//    void Sketch(int nPosX[], int nPosY[])
//    {
//        for (int i = 0; i < g_nSnakeLength; i++)
//        {
//            nPosX[i] = g_nPosDefault[0];
//            nPosY[i] = g_nPosDefault[1];
//            g_nPosDefault[0]--;
//            std::cout << g_nPosDefault[0];
//        }
//    }
//
//    void Move(int nPosX[], int nPosY[], int a, int b)
//    {
//        //add_array(x, length, a );
//    }
//
//    void Draw(int nPosX[], int nPosY[])
//    {
//        if (g_nSnakeLength == 4)
//        {
//            draw.Deploy('O', nPosX[0], nPosY[0]);
//            draw.Deploy('0', nPosX[1], nPosY[1]);
//            draw.Deploy('o', nPosX[2], nPosY[2]);
//            draw.Deploy('.', nPosX[3], nPosY[3]);
//        }
//        else
//        {
//            draw.Deploy('O', nPosX[0], nPosY[0]);
//            draw.Deploy('0', nPosX[1], nPosY[1]);
//            draw.Deploy('.', nPosX[g_nSnakeLength], nPosY[g_nSnakeLength]);
//            for (int i = 2; i < g_nSnakeLength; i++)
//                draw.Deploy('o', nPosX[i], nPosY[i]);
//        }
//    }
//};