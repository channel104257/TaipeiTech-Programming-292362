#include <stdio.h>

int factorial(int x);

int main()
{
    int n, k, C, P;
    C = 0;
    P = 0;

    while (1)
    {
        printf("\n請輸入n,k:");
        scanf("%d %d", &n, &k);

        if (n > k)
        {
            break;
        }
        else
        {
            printf("n必須大於等於k，請重新輸入。\n");
        }
    }

    P = factorial(n) / factorial(n - k);
    C = factorial(n) / (factorial(n - k) * factorial(k));

    printf("P(%d,%d)=%d\n", n, k, P);
    printf("C(%d,%d)=%d\n", n, k, C);

    return 0;
}

int factorial(int x)
{
    int Fnum = 1;

    for (size_t i = 0; i < x; i++)
    {
        Fnum = Fnum * (i + 1);
    }

    return Fnum;
}
