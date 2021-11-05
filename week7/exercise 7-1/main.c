#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y);

int main()
{
    int n1,n2;
  
    printf("Enter number 1: );
    scanf_s("%d", &n1);
    printf("\nEnter number 2: );
    scanf_s("%d", &n2);
    
    printf("\nBefore swap n1:%d, n2:%d, n1, n2);
    swap(&n1, &n2);
    printf("\nAfter swap n1:%d, n2:%d, n1, n2);
}
           
void swap(int *x, int *y)
{
    int t;
  
    t = *x;
    *x = *y;
    *y = t;
}
