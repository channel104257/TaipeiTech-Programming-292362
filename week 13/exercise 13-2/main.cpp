#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include "CConsole.h"
#include "CGraphics.h"
#include "CMove.h"

#define areaSIZE 500

using namespace std;

int TargetX, TargetY;
int SnakePositionX[areaSIZE];
int SnakePositionY[areaSIZE];

int main()
{
    bool snakegame = true;
    bool gameend = false;
    int BodyCount = 0;
    float Ctime = 0;

    srand(time(NULL));
    CursorInvisible();

    SetConsoleTitle("Snake Game");
    SetConsoleSize(_width + 7, _length + 4);

    Beginning();

    Clr();

    DrawBoundary();

    TargetRand();

    gotoxy(1, 18);
    cout << "作者 : 110310138 電機一甲 劉千榮";

    MoveCoor SnakeHead;

    SnakeHead = RandCoor();

    SnakePositionX[0] = SnakeHead.CursorX;
    SnakePositionY[0] = SnakeHead.CursorY;

    cout << "O";

    Sleep(500);

    enum directionflag
    {
        w,
        a,
        s,
        d
    } DirectionFlag;

    DirectionFlag = w;

    while (snakegame == true)
    {
        //是否吃到金幣
        if (SnakePositionX[0] == TargetX && SnakePositionY[0] == TargetY)
        {
            BodyCount++;

            //增加蛇尾長度
            switch (DirectionFlag)
            {
            case w:
                SnakePositionX[BodyCount] = SnakePositionX[BodyCount - 1];
                SnakePositionY[BodyCount] = SnakePositionY[BodyCount - 1] + 1;
                break;

            case a:
                SnakePositionX[BodyCount] = SnakePositionX[BodyCount - 1] + 1;
                SnakePositionY[BodyCount] = SnakePositionY[BodyCount - 1];
                break;

            case s:
                SnakePositionX[BodyCount] = SnakePositionX[BodyCount - 1];
                SnakePositionY[BodyCount] = SnakePositionY[BodyCount - 1] - 1;
                break;

            case d:
                SnakePositionX[BodyCount] = SnakePositionX[BodyCount - 1] - 1;
                SnakePositionY[BodyCount] = SnakePositionY[BodyCount - 1];
                break;
            }

            TargetRand();
        }

        gotoxy(28, 2);
        cout << "level:";
        gotoxy(28, 3);
        cout << BodyCount + 1;

        Ctime = Ctime + 0.5;

        gotoxy(28, 5);
        cout << "Time:";
        gotoxy(28, 6);
        cout << (int)Ctime;

        //蛇消失
        for (size_t i = 0; i <= BodyCount; i++)
        {
            gotoxy(SnakePositionX[i], SnakePositionY[i]);
            cout << " ";
        }

        //蛇身座標移動
        for (int i = BodyCount; i >= 0; i--)
        {
            SnakePositionX[i + 1] = SnakePositionX[i];
            SnakePositionY[i + 1] = SnakePositionY[i];
        }

        //蛇頭座標移動(鍵盤讀取和禁止回頭)
        if (_kbhit())
        {
            char c[2];

            c[0] = getch();

            switch (c[0])
            {
            case 'w':
                if (c[1] == 's')
                {
                    c[0] = 's';
                    break;
                }

                DirectionFlag = w;
                break;

            case 'a':
                if (c[1] == 'd')
                {
                    c[0] = 'd';
                    break;
                }

                DirectionFlag = a;
                break;

            case 's':
                if (c[1] == 'w')
                {
                    c[0] = 'w';
                    break;
                }

                DirectionFlag = s;
                break;

            case 'd':
                if (c[1] == 'a')
                {
                    c[0] = 'a';
                    break;
                }

                DirectionFlag = d;
                break;
            }

            c[1] = c[0];
        }

        switch (DirectionFlag)
        {
        case w:
            SnakePositionY[0] = SnakePositionY[0] - 1;
            DirectionFlag = w;
            break;

        case a:
            SnakePositionX[0] = SnakePositionX[0] - 1;
            DirectionFlag = a;
            break;

        case s:
            SnakePositionY[0] = SnakePositionY[0] + 1;
            DirectionFlag = s;
            break;

        case d:
            SnakePositionX[0] = SnakePositionX[0] + 1;
            DirectionFlag = d;
            break;
        }

        //全蛇顯示
        for (size_t i = 0; i <= BodyCount; i++)
        {
            gotoxy(SnakePositionX[i], SnakePositionY[i]);
            cout << "O";
        }

        //遊戲失敗偵測
        if (SnakePositionX[0] == 0 || SnakePositionX[0] == 26)
        {
            snakegame = !snakegame;
        }
        if (SnakePositionY[0] == 0 || SnakePositionY[0] == 15)
        {
            snakegame = !snakegame;
        }

        for (size_t i = 1; i < areaSIZE; i++)
        {
            if (SnakePositionX[0] == SnakePositionX[i] && SnakePositionY[0] == SnakePositionY[i])
            {
                snakegame = !snakegame;
            }
        }

        cin.sync();

        Sleep(500);
    }

    Clr();

    gotoxy(0, 2);
    cout << "-------------遊戲結束-------------";
    gotoxy(10, 4);
    cout << "長度 : " << BodyCount + 1;
    gotoxy(10, 5);
    cout << "時間 : " << Ctime << " s";

    gotoxy(10, 8);
    cout << "請按任意鍵結束";

    while (gameend == false)
    {
        if (_kbhit())
        {
            gameend = !gameend;
        }
    }

    return 0;
}
