#ifndef CCONSOLE_H
#define CCONSOLE_H

#include <windows.h>

// ============================================
// 函式： Clr, 清除螢幕
// 說明： 解決使用 system("cls") 會有閃爍問題
//        事實上這只是把每個點都填上空白而已
// 轉載： CodeGurn
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
// 函式： SetConsoleSize
// 說明： 設定 Console 視窗大小
//        // x 不好用.
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
// 函式： gotoxy
// 說明： 移動游標至指定位置
// ============================================
void gotoxy(int x, int y)
{
    COORD point;
    point.X = x, point.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}

// =============================================
// 函式： CursorInvisible
// 說明： 隱藏滑鼠光標
// ============================================
void CursorInvisible()
{
    CONSOLE_CURSOR_INFO corson_info = {1, 0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &corson_info);
}

// =============================================
// 函式： getxy
// 說明： 取得目前游標位置
// ============================================
void getxy(int &x, int &y)
{
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        x = csbi.dwCursorPosition.X;
        y = csbi.dwCursorPosition.Y;
}

// ============================================
// 函式： SetColor, 設定文字顏色與背景顏色
// 說明： 這裡的顏色要看 macro,事實上有很多組合
//        只是這裡給 0~15 的編號簡化組合
// 轉載： CodeGurn
// ===========================================

void SetColor(int color=-1) // 直接先給預設
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