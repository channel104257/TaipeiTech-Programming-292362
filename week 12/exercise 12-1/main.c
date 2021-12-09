#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 6

int Check(int* Number, int* Guess);

int Number[SIZE] = {0};
int Guess[SIZE] = {0};


int main()
{
	int count = 0;
	const char* Price[SIZE + 1] = { "共辜", "共辜", "五獎", "四獎", "三獎", "二獎", "頭獎" };
	srand(time(NULL));
	int* NumberPtr = Number;
	int* GuessPtr = Guess;

	for (size_t i = 0; i < SIZE; i++)
	{
		Number[i] = 1 + (rand() % 42);
		printf("%d ", Number[i]);
		
		for (int j = 0; j < i; j++)
		{
			if (Number[i] == Number[j])
			{
				i--;
				break;
			}
		}
	}

	for (size_t i = 0; i < SIZE; i++)
	{
		printf("Please Enter Number %d : ", i+1);
		scanf_s("%d", &Guess[i]);
	}

	count = Check(NumberPtr, GuessPtr);

	for (size_t i = 0; i < SIZE; i++)
	{
		if (i == 0)
		{
			printf("%4s ", "中獎號碼");
		}
		printf("%2d ", Number[i]);
	}
	printf("\n");

	for (size_t i = 0; i < SIZE; i++)
	{
		if (i == 0)
		{
			printf("    %s ", "選號");
		}
		printf("%2d ", Guess[i]);
	}

	printf("\n");
	
	for (size_t i = 0; i < (SIZE + 1); i++)
	{
		if (count == i)
		{
			printf("%s", Price[i]);
			break;
		}
	}
	
	return 0;
}

int Check(int* Number, int* Guess)
{
	int count = 0;
	
	for (size_t i = 0; i < SIZE; i++)
	{
		for (size_t j = 0; j < SIZE; j++)
		{
			if (Guess[i] == Number[j])
			{
				count++;
				break;
			}
		}
	}

	return count;
}
