#ifndef CGRAPHICS_H
#define CGRAPHICS_H

#include <iostream>

using namespace std;

const int _width = 27;
const int _length = 16;
bool gamestart = false;


void space(int x)
{
    for (size_t i = 0; i < x; i++)
    {
        cout << " ";
    }
}

void X(int x)
{
    for (size_t i = 0; i < x; i++)
    {
        cout << "X";
    }
}

void DrawBoundary()
{
    for (size_t i = 0; i < _length; i++)
    {
        if (i == 0 || i == (_length - 1))
        {
            X(_width);
            cout << endl;
        }
        else
        {
            cout << "X";
            space(_width - 2);
            cout << "X";
            cout << endl;
        }
    }
}

void Beginning()
{
    for (size_t i = 2; i < 34; i++)
    {
        gotoxy(i, 1);
        cout << "@";
        Sleep(25);
    }
    for (size_t i = 2; i < 19; i++)
    {
        gotoxy(33, i);
        cout << "@";
        Sleep(25);
    }
    for (size_t i = 33; i > 0; i--)
    {
        gotoxy(i, 18);
        cout << "@";
        Sleep(25);
    }
    for (size_t i = 18; i > 0; i--)
    {
        gotoxy(1, i);
        cout << "@";
        Sleep(25);
    }

    gotoxy(9, 3);
    cout << "Snake Game 貪食蛇";

    gotoxy(3, 5);
    cout << "1、請切換至英文輸入法";
    gotoxy(3, 7);
    cout << "2、請使用 W A S D 控制方向";

    gotoxy(3, 15);
    cout << "作者 :";
    gotoxy(3, 16);
    cout << "110310138 電機一甲 劉千榮";

    while (gamestart == false)
    {
        gotoxy(8, 11);
        cout << "點擊任意鍵開始遊戲";

        if (_kbhit())
        {
            gamestart = !gamestart;
        }
    }

}

#endif