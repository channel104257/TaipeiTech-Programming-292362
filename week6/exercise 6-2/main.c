#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int frequency[6] = {0};

int main()
{
	int times,Rnum;

	srand(time(NULL));
	printf("Please enter how many times do you want to roll : ");
	scanf_s("%d", &times);

	for (size_t i = 1; i <= times; i++)
	{
		Rnum = 1 + (rand() % 6);

		for (size_t j = 1; j <= 6; j++)
		{
			if (j == Rnum)
			{
				frequency[j]++;
			}
		}
	}

	printf("\nFace   Frequency\n");
	for (size_t i = 1; i <= 6; i++)
	{
		printf("%4d%12d\n", i, frequency[i]);
	}
	return 0;
}
