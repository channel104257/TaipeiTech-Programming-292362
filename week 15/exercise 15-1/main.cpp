#include <iostream>
#include <algorithm>

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
		puts("Please enter 8 Student score : \n");

		int test[8];
		int max, min;
		size_t i;

		for (i = 0; i < 8; i++)
		{
			printf("Student%d:", i + 1);
			scanf_s("%d", &test[i]);
			fprintf(cfptr, "%s%d %d\n", "Student", i+1, test[i]);
		}

		puts("Access complete!");
		fprintf(cfptr, "\n");

		int ctest[8];

		for (size_t i = 0; i < 8; i++)
		{
			ctest[i] = test[i];
		}

		std::sort(ctest, ctest+8);

		fprintf(cfptr, "Highest score: %d\n", ctest[7]);
		fprintf(cfptr, "Lowest score: %d", ctest[0]);
		
		fclose(cfptr);
	}
	
	return 0;
}
