#include <stdio.h>

void Reference(int* x, int* y);
void Value(int x, int y);


int main()
{
	int num1, num2;
	
	printf("Please Enter Two Number :\n");
	printf("num1 = ");
	scanf_s("%d", &num1);
	printf("num2 = ");
	scanf_s("%d", &num2);

	const int _num1 = num1;
	const int _num2 = num2;

	Value(num1, num2);
	Reference(&num1, &num2);

	printf("\n");
	printf("After Swap : num1' = %d num2' = %d\n", num1, num2);
	printf("Call By Value : num1 = %d num2 = %d\n", _num1, _num2);

	printf("After Swap : num1' = %d num2' = %d\n", num1, num2);
	printf("Call By Reference : num1 = %d num2 = %d\n", num1, num2);
	
	return 0;
}

void Value(int x, int y)
{
	int t = x;
	x = y;
	y = t;
}

void Reference(int* x, int* y)
{
	int t = *x;
	*x = *y;
	*y = t;
}
