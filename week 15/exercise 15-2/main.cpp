#include <iostream>
#include <cstdio> 
#include <cstdlib> 

int DisplayBits(int value);

struct Temperature
{
	int Celsius;
	int Fahrenheit;
};

typedef struct Temperature Temp;

int main()
{
	
	FILE *cfptr;
	fopen_s(&cfptr, "test.txt", "w+");
	
	
	if (cfptr == NULL)
	{
		puts("File could not be opened");
	}
	else
	{
		puts("請輸入10個攝氏溫度。");
		fprintf(cfptr, "編號  攝氏  華氏 1的數量\n");

		Temp temp;

		for (size_t i = 0; i < 10; i++)
		{
			scanf_s("%d", &temp.Celsius);

			temp.Fahrenheit = temp.Celsius * 9 / 5 + 32;

			int count = DisplayBits(temp.Fahrenheit);

			fprintf(cfptr, "%4d  %4d  %4d  %5d\n", i+1, temp.Celsius, temp.Fahrenheit, count);
		}

		fclose(cfptr);
	}
	return 0;
}

int DisplayBits(int value)
{
	Temp temp;
	char str[100];
	int count = 0;
	_itoa(value, str, 2);

	for (int i = 0; i < 100; i++)
	{
		if (str[i] == '1')
		{
			count++;
		}
	}

	return count;
}
