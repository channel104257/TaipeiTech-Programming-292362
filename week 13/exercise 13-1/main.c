#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

struct Test
{
	int score = 0;
	char Name[4];

};

int main()
{
	struct Test testdata[SIZE];

	for (size_t i = 0; i < SIZE; i++)
	{
		printf("Please enter your name : ");
		scanf_s("%s", &testdata[i].Name, (unsigned)_countof(testdata[i].Name));
		printf("Please enter your score %s : ", testdata[i].Name);
		scanf_s("%d", &testdata[i].score);
	}

	printf("\n");
	printf(" Name Score\n");

	for (size_t i = 0; i < SIZE; i++)
	{
		printf(" %4s %5d\n", testdata[i].Name, testdata[i].score);
	}

	return 0;
}
