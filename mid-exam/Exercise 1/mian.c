#include <stdio.h>

int main()
{
    int ENum, ONum;
    ONum = 0;

    printf("please enter number : ");
    scanf("%d", &ENum);

    while (ENum != 0)
    {
        ONum = (ONum * 10) + (ENum % 10);
        ENum = (ENum - ENum % 10) / 10;
    }
    
    printf("The opposite number is %d", ONum);

    return 0;
}
