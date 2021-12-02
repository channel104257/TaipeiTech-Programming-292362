#include <stdio.h>

void Mul(int Mul[10][10], int X[10][10], int Y[10][10]);

int A[10][10];
int B[10][10];
int ans[10][10];

int main()
{
	int level;
	
	printf("Please enter the matrix level n=");
	scanf_s("%d", &level);
	printf("enter the A matrix element\n");
	
	for (int i = 0; i < level; i++)
	{
		for (int j = 0; j < level; j++)
		{
			scanf_s("%d", &A[i][j]);
		}
		
	}

	printf("enter the B matrix element\n");

	for (int i = 0; i < level; i++)
	{
		for (int j = 0; j < level; j++)
		{
			scanf_s("%d", &B[i][j]);
		}

	}

	Mul(ans, A, B);

	printf("multiply of the matrix\n");

	for (int i = 0; i < level; i++)
	{
		for (int j = 0; j < level; j++)
		{
			printf("%d", ans[i][j]);
			printf(" ");
		}
		printf("\n");
	}
	
	return 0;
}

void Mul(int Mul[10][10],int X[10][10],int Y[10][10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < 10; k++)
			{
				if (X[i][k] != 0 || Y[k][j] != 0)
				{
					Mul[i][j] = Mul[i][j] + (X[i][k] * Y[k][j]);
				}
			}
		}
	}
}
