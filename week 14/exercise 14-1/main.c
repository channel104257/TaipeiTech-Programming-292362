#include <stdio.h>
int add(int x, int y);

int main()
{
	int n1, n2;
  
	printf("Please enter two numbers:\nnumber1 : ");
	scanf_s("%d", &n1);
	printf("number2 : ");
	scanf_s("%d", &n2);
  
	printf("The added number is : %3d", add(n1, n2));
}

int add(int x, int y) {
  
	while (y != 0) {
		unsigned sum = x ^ y;
		unsigned carry = (x & y) << 1;
		x = sum;
		y = carry;
	}
  
	return x;
}
