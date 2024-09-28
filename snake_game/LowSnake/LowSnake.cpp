

#include <iostream>
#include "SnakeLib.h"

int snake_length = 4;

void draw(char ch, int x, int y)
{
    gotoXY(x, y);
    std::cout << ch;
}

void snake_draw(int x[], int y[])
{
    if (snake_length == 4)
    {
        draw('O', x[0], y[0]);
        draw('0', x[1], y[1]);
        draw('o', x[2], y[2]);
        draw('.', x[3], y[3]);
    }
    else 
    {
        draw('O', x[0], y[0]);
        draw('0', x[1], y[1]);
        draw('.', x[snake_length], y[snake_length]);
        for (int i = 2; i < snake_length; i++)
            draw('o', x[i], y[i]);
    }
}

void snake_sketch(int x[], int y[])
{
    int i = 0, a = 50, b = 12;
    for (int i = 0; i < snake_length; i++)
    {
        x[i] = a;
        y[i] = b;
        a--;
        std::cout << a;
    }
}

void add_first(int arr[], int arr_length, int new_value)
{
    std::cout << arr_length;
    for (int i = arr_length; i > 0; i--)
    {
        std::cout << i + ", " + arr[i];
        arr[i] = arr[i - 1];
    }
    arr[0] = new_value;
    arr_length++;
}

void remove(int arr[], int index)
{
    for (int i = index; i < snake_length; i++)
    {
        arr[i] = arr[i + 1];
    }
    snake_length--;
}

void snake_move(int x[], int y[], int a, int b, int length)
{
    //add_array(x, length, a );
}

void border_draw()
{
    int a = 10, b = 1, c = 100, d = 26, i = a, j = a, k = b, l = b;
    
    while (i < c)
    {
        draw('+', i, b);
        i += 1;
        draw('+', j, d);
        j += 1;
    }
    while (k <= d)
    {
        draw('+', a, k);
        k += 1;
        draw('+', c, l);
        l += 1;
    }
}

int main()
{
    int check = 0;  // 0: cham bien tren -> di xuong
                    // 1: cham bien duoi -> di len
                    // 2: cham bien trai -> sang phai
                    // 3: cham bien phai -> sang trai
    int color = 1;
    int x = 10, y = 0;
    int x_old = x, y_old = y;
    int toadoX[100], toadoY[100];


    //border_draw();
    /*snake_sketch(toadoX, toadoY, snake_length);
    snake_draw(toadoX, toadoY, snake_length);*/
    
    //snake_move(toadoX, toadoY, x, y, snake_length);

    /*for (int i = snake_length; i > 0; i--)
    {
        std::cout << i + ", " + toadoX[i];
        toadoX[i] = toadoX[i - 1];
    }
    toadoX[0] = 0;*/
    //snake_length++;

    for (int i = 4; i > 0; i--)
    {
        std::cout << i ;
        toadoX[i] = toadoX[i - 1];
        std::cout << toadoX[i];
        std::cout << '\n';
    }

    /*while (true)
    {
        gotoXY(x_old, y_old);
        std::cout << "    ";
        gotoXY(x, y);
        std::cout << "hehe";
        x_old = x;
        y_old = y;

        SetColor(color);
        color++;
        color = (color > 15) ? 1 : color;

        if (_kbhit())
        {
            char ch = _getch();
            if (ch == -32)
            {
                ch = _getch();
                ch = (ch == 72) ? check = 1 : (ch == 80) ? check = 0 : (ch == 75) ? check = 3 : (ch == 77) ? check = 2 : ch;
            }
            ch = (ch == 's') ? check = 1 : (ch == 'x') ? check = 0 : (ch == 'z') ? check = 3 : (ch == 'c') ? check = 2 : ch;
        }

        y = (check == 0) ? (y + 1) : (check == 1) ? (y - 1) : y;
        x = (check == 2) ? (x + 1) : (check == 3) ? (x - 1) : x;
        check = (y == 20) ? 1 : (y == 0) ? 0 : (x == 0) ? 2 : (x == 100) ? 3 : check;

        Sleep(100);
    }*/

    
    _getch();
    return 0;
}