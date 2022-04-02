#include <stdio.h>

void displayBits(unsigned int value);

int main()
{
    unsigned int x;

    printf("%s", "Enter a nonnegative int : ");
    scanf("%u", &x);

    displayBits(x);
}

void displayBits(unsigned int value)
{
    unsigned int displayMask = 1 << 31;

    printf("%10u = ", value);
    for (unsigned int i = 1; i <= 32; ++i)
    {
        putchar(value & displayMask ? '0' : '1');
        value <<= 1;

        if (i % 8 == 0)
        {
            putchar(' ');
        }
    }

    putchar('\n');
}