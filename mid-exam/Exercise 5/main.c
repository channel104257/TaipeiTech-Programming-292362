#include <stdio.h>

int main()
{
    int Enum1, Enum2, _Enum1, _Enum2, flag, GCD, LCM;
    flag = 0;

    while (flag == 0)
    {
        printf("輸入兩數 : ");
        scanf("%d %d", &Enum1, &Enum2);

        if (Enum1 > 0 && Enum2 > 0)
        {
            flag++;
            _Enum1 = Enum1;
            _Enum2 = Enum2;
        }
        else
        {
            printf("請勿輸入0或小於0的數字\n");
        }
    }

    if (Enum2 < Enum1)
    {
        int t = Enum2;
        Enum2 = Enum1;
        Enum1 = t;
    }

    while (Enum1 != 0)
    {
        Enum2 = Enum2 % Enum1;
        if (Enum2 == 0)
        {
            break;
        }
        Enum1 = Enum1 % Enum2;
    }

    if (Enum1 == 0)
    {
        GCD = Enum2;
    }
    else
    {
        GCD = Enum1;
    }

    LCM = (_Enum1 * _Enum2) / GCD;

    printf("GCD : %d", GCD);
    printf("\nLCM : %d", LCM);

    return 0;
}
