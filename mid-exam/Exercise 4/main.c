#include <stdio.h>

char number[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
int cardsitu[10] = {0};

int main()
{
    int Enum1, Enum2, loop;
    loop = 0;

    while (loop != 1)
    {
        for (size_t i = 0; i < 10; i++)
        {
            if (cardsitu[i] == 0)
            {
                printf("■ ");
            }
            else
            {
                printf("%d ", i + 1);
            }
        }
        printf("\n(1)開啟 (2)關上 (3)結束 : ");
        scanf("%d", &Enum1);

        switch (Enum1)
        {
        case 1:
            printf("\n請選擇要打開的數字 : ");
            scanf("%d", &Enum2);

            if (cardsitu[Enum2 - 1] == 0)
            {
                cardsitu[Enum2 - 1]++;
            }
            else
            {
                printf("\n已經被打開了\n");
            }
            break;

        case 2:
            printf("\n請選擇要關上的數字 : ");
            scanf("%d", &Enum2);

            if (cardsitu[Enum2 - 1] == 1)
            {
                cardsitu[Enum2 - 1]--;
            }
            else
            {
                printf("\n已經被關上了\n");
            }
            break;

        case 3:
            printf("\n感謝遊玩");
            loop++;
            break;
        }
    }

    return 0;
}
