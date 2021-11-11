#include <stdio.h>

void space(int x);
void star(int x);

int EnterNum;

int main()
{
	printf("please enter a odd number : ");
	scanf_s("%d", &EnterNum);
	printf("\n");

	for (size_t i = 0; i <= EnterNum / 2; i++)
	{
		space((EnterNum - 2 * i) / 2);
		star(1 + 2 * i);
		space((EnterNum - 2 * i) / 2);
		printf("\n");
	}
	for (int i = (EnterNum-2) / 2; i >= 0; i--)
	{
		space((EnterNum - 2 * i) / 2);
		star(1 + 2 * i);
		space((EnterNum - 2 * i) / 2);
		printf("\n");
	}

	return 0;
}

void space(int x)
{
	for (size_t i = 0; i <= x; i++)
	{
		printf(" ");
	}
}

void star(int x)
{
	for (size_t i = 1; i <= x; i++)
	{
		printf("*");
	}
}
