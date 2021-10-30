#include <stdio.h>
#define RESPONSES_SIZE 15
#define FREQUENCY_SIZE 10

int responses[RESPONSES_SIZE];
int frequency[FREQUENCY_SIZE] = {0};

int main()
{
    int score;

    for (size_t i = 1; i <= RESPONSES_SIZE; ++i)
    {
        printf("Please Enter The Responses %d (1 ~ 10) : ", i);
        scanf("%d", &score);

        if (score < 1 || score > 10)
        {
            i = i - 1;
        }

        if (score >= 1 || score <= 10)
        {
            responses[i] = score;

            for (size_t j = 1; j <= FREQUENCY_SIZE; j++)
            {
                if (j == score)
                {
                    frequency[j]++;
                }
            }
        }
    }

    printf("\nRating   Frequency\n");
    for (size_t i = 1; i <= FREQUENCY_SIZE; i++)
    {
        printf("%6d%12d\n",i, frequency[i]);
    }

    return 0;
}
