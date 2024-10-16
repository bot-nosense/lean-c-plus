//#include "Draw.h"
//#include "SnakeLib.h"
//#include <iostream>
//
//int g_nSnakeLength = 4,
//    g_nPosDefault[2] = { 50, 12 },
//    g_nBorderGame[4] = { 5, 3, 105, 23 }    // Begin(5,3), console screen (100x20)
//    ;
//
//class Draw
//{
//public:
//	
//	void Deploy(char cCharacter, int nPosX, int nPosY)
//	{
//		gotoXY(nPosX, nPosY);
//		std::cout << cCharacter;
//	}
//
//    void BorderDraw()
//    {
//        int a = g_nBorderGame[0],
//            b = g_nBorderGame[0],
//            e = g_nBorderGame[1],
//            f = g_nBorderGame[1];
//
//        while (a <= g_nBorderGame[2])
//        {
//            Deploy('+', a, g_nBorderGame[1]);
//            a += 1;
//            Deploy('+', b, g_nBorderGame[3]);
//            b += 1;
//        }
//        while (e <= g_nBorderGame[3])
//        {
//            Deploy('+', g_nBorderGame[0], e);
//            e += 1;
//            Deploy('+', g_nBorderGame[2], f);
//            f += 1;
//        }
//    }
//
//
//};
