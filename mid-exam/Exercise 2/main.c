#include <stdio.h>

int main()
{
    float average, num1, num2, num3;
    char grade;

    printf("please enter you score :\n");
    scanf("%f", &num1);
    scanf("%f", &num2);
    scanf("%f", &num3);

    average = ((num1 + num2 + num3) / 3);

    if (average >= 60)
    {
        grade = 'A';
    }
    else
    {
        grade = 'B';
    }

    printf("score_1 score_2 score_3 Average Grade\n");
    printf("%7.0f %7.0f %7.0f %7.2f %5c", num1, num2, num3, average, grade);

    return 0;
}
