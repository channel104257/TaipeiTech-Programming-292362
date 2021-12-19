#ifndef CCONSOLE_H
#define CCONSOLE_H

#include <windows.h>

// ============================================
// �禡�G Clr, �M���ù�
// �����G �ѨM�ϥ� system("cls") �|���{�{���D
//        �ƹ�W�o�u�O��C���I����W�ťզӤw
// ����G CodeGurn
// ===========================================
void Clr()
{
    COORD coordScreen = {0, 0};
    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD dwConSize;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    GetConsoleScreenBufferInfo(hConsole, &csbi);
    dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    FillConsoleOutputCharacter(hConsole, TEXT(' '),
                               dwConSize,
                               coordScreen,
                               &cCharsWritten);
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    FillConsoleOutputAttribute(hConsole,
                               csbi.wAttributes,
                               dwConSize,
                               coordScreen,
                               &cCharsWritten);
    SetConsoleCursorPosition(hConsole, coordScreen);
}

// ============================================
// �禡�G SetConsoleSize
// �����G �]�w Console �����j�p
//        // x ���n��.
// ===========================================
BOOL SetConsoleSize(int W, int H)
{
    BOOL ret;
    SMALL_RECT SR;
    SR.Top = 0;
    SR.Left = 0;
    SR.Bottom = H - 1;
    SR.Right = W - 1;
    ret = SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &SR);
    if (!ret)
        return ret;

    COORD Sz;
    Sz.X = W;
    Sz.Y = H;

    return SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), Sz);
}

// =============================================
// �禡�G gotoxy
// �����G ���ʴ�Цܫ��w��m
// ============================================
void gotoxy(int x, int y)
{
    COORD point;
    point.X = x, point.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}

// =============================================
// �禡�G CursorInvisible
// �����G ���÷ƹ�����
// ============================================
void CursorInvisible()
{
    CONSOLE_CURSOR_INFO corson_info = {1, 0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &corson_info);
}

// =============================================
// �禡�G getxy
// �����G ���o�ثe��Ц�m
// ============================================
void getxy(int &x, int &y)
{
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        x = csbi.dwCursorPosition.X;
        y = csbi.dwCursorPosition.Y;
}

// ============================================
// �禡�G SetColor, �]�w��r�C��P�I���C��
// �����G �o�̪��C��n�� macro,�ƹ�W���ܦh�զX
//        �u�O�o�̵� 0~15 ���s��²�ƲզX
// ����G CodeGurn
// ===========================================

void SetColor(int color=-1) // ���������w�]
{
        switch (color)
        {
        case 0:    // White on Black
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                        FOREGROUND_INTENSITY | FOREGROUND_RED |
                        FOREGROUND_GREEN | FOREGROUND_BLUE);
                break;
        case 1:    // Red on Black
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                        FOREGROUND_INTENSITY | FOREGROUND_RED);
                break;
        case 2:    // Green on Black
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                        FOREGROUND_INTENSITY | FOREGROUND_GREEN);
                break;
        case 3:    // Yellow on Black
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                        FOREGROUND_INTENSITY | FOREGROUND_RED |
                        FOREGROUND_GREEN);
                break;
        case 4:    // Blue on Black
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                        FOREGROUND_INTENSITY | FOREGROUND_BLUE);
                break;
        case 5:    // Magenta on Black
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                        FOREGROUND_INTENSITY | FOREGROUND_RED |
                        FOREGROUND_BLUE);
                break;
        case 6:    // Cyan on Black
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                        FOREGROUND_INTENSITY | FOREGROUND_GREEN |
                        FOREGROUND_BLUE);
                break;
        case 7:    // Black on Gray
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                        BACKGROUND_INTENSITY | BACKGROUND_INTENSITY);
                break;
        case 8:    // Black on White
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                        BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |
                        BACKGROUND_RED | BACKGROUND_GREEN |
                        BACKGROUND_BLUE);
                break;
        case 9:    // Red on White
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                        BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |
                        BACKGROUND_RED | BACKGROUND_GREEN |
                        BACKGROUND_BLUE |
                        FOREGROUND_RED);
                break;
        case 10:    // Green on White
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                        BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |
                        BACKGROUND_RED | BACKGROUND_GREEN |
                        BACKGROUND_BLUE | FOREGROUND_GREEN);
                break;
        case 11:    // Yellow on White
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                        BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |
                        BACKGROUND_RED | BACKGROUND_GREEN |
                        BACKGROUND_BLUE | FOREGROUND_RED |
                        FOREGROUND_GREEN);
                break;
        case 12:    // Blue on White
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                        BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |
                        BACKGROUND_RED | BACKGROUND_GREEN |
                        BACKGROUND_BLUE | FOREGROUND_BLUE);
                break;
        case 13:    // Magenta on White
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                        BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |
                        BACKGROUND_RED | BACKGROUND_GREEN |
                        BACKGROUND_BLUE | FOREGROUND_RED |
                        FOREGROUND_BLUE);
                break;
        case 14:    // Cyan on White
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                        BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |
                        BACKGROUND_RED | BACKGROUND_GREEN |
                        BACKGROUND_BLUE | FOREGROUND_GREEN |
                        FOREGROUND_BLUE);
                break;
        case 15:    // White on White
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                        BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |
                        BACKGROUND_RED | BACKGROUND_GREEN |
                        BACKGROUND_BLUE | FOREGROUND_RED |
                        FOREGROUND_GREEN | FOREGROUND_BLUE);
                break;
        default :    // White on Black
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                        FOREGROUND_INTENSITY | FOREGROUND_RED |
                        FOREGROUND_GREEN | FOREGROUND_BLUE);
                break;
        }
}

#endif