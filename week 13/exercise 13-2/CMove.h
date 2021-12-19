#ifndef CMOVE_H
#define CMOVE_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "CConsole.h"

#define areaSIZE 500

using namespace std;

extern int TargetX, TargetY;
extern int SnakePositionX[areaSIZE];
extern int SnakePositionY[areaSIZE];

typedef struct Coor
{
    int CursorX;
    int CursorY;

} MoveCoor;

MoveCoor RandCoor()
{
    MoveCoor coor;

    const int _width = 27;
    const int _length = 16;

    coor.CursorX = 1 + rand() % (_width - 2);
    coor.CursorY = 1 + rand() % (_length - 2);

    gotoxy(coor.CursorX, coor.CursorY);

    return coor;
}

void TargetRand()
{
    MoveCoor Target;

    for (size_t i = 0; i < 1; i++)
    {
        for (size_t j = 0; j < areaSIZE; j++)
        {
            Target = RandCoor();

            TargetX = Target.CursorX;
            TargetY = Target.CursorY;

            if (SnakePositionX[j] == TargetX && SnakePositionY[j] == TargetY)
            {
                i--;
            }           
        }
    }

    cout << "$";
}

#endif