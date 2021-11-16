#include <stdio.h>

int count = 0;
int sqar(int x, int y);
int TurnToDecimal(int x);
void DecimalTransform(int x, int y);

int Cnum[100] = {};
char number[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

int main()
{
    int Bcarry, Acarry, Ans, Dnum;
    char Enum[100];
    Dnum = 0;
    Ans = 0;

    printf("請輸入轉換前進制 : ");
    scanf("%d", &Bcarry);
    printf("請輸入數字 : ");
    scanf("%s", &Enum);
    printf("請輸入轉換後進制 : ");
    scanf("%d", &Acarry);

    for (size_t i = 0; i < 17; i++)
    {
        for (size_t j = 0; j < 17; j++)
        {
            if (Enum[i] == number[j])
            {
                Cnum[i] = j;
                count++;
                break;
            }
        }
    }

    Dnum = TurnToDecimal(Bcarry);

    if (Acarry == 10)
    {
        Ans = Dnum;
        printf("%d", Ans);
    }
    else
    {
        DecimalTransform(Acarry, Dnum);
    }

    return 0;
}

int sqar(int x /*底數*/, int y /*指數*/)
{
    int _x = x;

    if (y == 0)
    {
        return 1;
    }
    else if (y == 1)
    {
        return x;
    }
    else
    {
        for (size_t i = 2; i <= y; i++)
        {
            x = x * _x;
        }
        return x;
    }
}

int TurnToDecimal(int x)
{
    int _Dnum = 0;
    int _flag = 0;

    for (int i = count; i > 0; i--)
    {
        _Dnum = _Dnum + (Cnum[_flag] * sqar(x, (i - 1)));
        _flag++;
    }

    return _Dnum;
}

void DecimalTransform(int x /*Acarry*/, int y /*Decimal*/)
{
    int _flag = 0;
    char ACnum[100];

    for (size_t i = 0; i < 100; i++)
    {
        if (y <= 0 && _flag > 0)
        {
            break;
        }

        for (size_t j = 0; j < 17; j++)
        {
            int _Rnum = y % x;

            if (_Rnum == j)
            {
                y = y / x;
                ACnum[i] = number[j];
                _flag++;
                break;
            }
        }
    }

    for (int i = _flag; i > 0; i--)
    {
        printf("%c", ACnum[i - 1]);
    }
}
