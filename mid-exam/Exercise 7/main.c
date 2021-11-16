#include <stdio.h>

int main()
{
    int Enum;

    printf("列印出n*n的西洋棋盤 : n=");
    scanf("%d", &Enum);

    for (size_t i = 0; i < Enum; i++)
    {
        if ((i % 2) == 0)
        {
            for (size_t j = 0; j < Enum; j++)
            {
                if ((j % 2) == 0)
                {
                    printf("██");
                }
                else
                {
                    printf("  ");
                }
                if (j == (Enum - 1))
                {
                    printf("\n");
                }
            }
        }
        else
        {
            for (size_t j = 0; j < Enum; j++)
            {
                if ((j % 2) == 1)
                {
                    printf("██");
                }
                else
                {
                    printf("  ");
                }
                if (j == (Enum - 1))
                {
                    printf("\n");
                }
            }
        }
    }

    return 0;
}
