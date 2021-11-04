#include <stdio.h>
#include <stdlib.h>
#define SIZE 6

int mat[SIZE] = {};
int matCopy[SIZE] = {};
int rank[SIZE] = {0};

void greater(int v[]);

int main()
{
    int enter;

    for (size_t i = 1; i <= 5; i++)
    {
        printf("number %u:", i);
        scanf("%d", &enter);
        mat[i] = enter;
        matCopy[i] = mat[i];
    }

    greater(matCopy);
    
    for (int i = 1;i <= 5;i++)
    {
        for (int j = 1;j <= 5;j++)
        {
            if (mat[i] == matCopy[j])  
            {
                rank[i] = j;
                break;
            }
        }
    }

    printf("\nnumber: %d\t%d\t%d\t%d\t%d",mat[1], mat[2], mat[3], mat[4], mat[5]);
    printf("\n%6s: %d\t%d\t%d\t%d\t%d", "rank", rank[1], rank[2], rank[3], rank[4], rank[5]);


    return 0;
}

void greater(int v[])
{
    int y;
    //氣泡排序法
    for (int s = 1;s <= 5;s++)
    {
        for (int j = s + 1;j <= 5;j++)
        {
            if (v[j] > v[s])  
            {
            y = v[j];
            v[j] = v[s];
            v[s] = y;
            }
        }
    }
}
