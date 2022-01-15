#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void calender(FILE *readptr, int days, int firstdays);

int main()
{
    FILE *fileptr;
    fileptr = fopen("test.txt", "w+");

    if (fileptr == NULL)
    {
        printf("You can't put data here.");
    }
    else
    {
        int days;
        int firstdays;
        
        for (size_t i = 0; i < 1; i++)
        {
            printf("請輸入天數 : ");
            cin >> days;

            if (days < 28 || days > 31)
            {
                cout << "天數輸入錯誤" << endl;
                i--;
            }          
        }
        
        for (size_t i = 0; i < 1; i++)
        {
            printf("請輸入該月第一天的星期 : ");
            cin >> firstdays;

            if (firstdays < 1 || firstdays > 7)
            {
                cout << "天數輸入錯誤" << endl;
                i--;
            }
            
        }

        calender(fileptr, days, firstdays);
    }

    fclose(fileptr);
    return 0;
}

void calender(FILE *readptr, int days, int firstdays)
{
    fprintf(readptr, " %3s %3s %3s %3s %3s %3s %3s\n", "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat");

    for (size_t i = 0; i <= firstdays - 1; i++)
    {
        if (firstdays == 7)
        {
            break;
        }

        fprintf(readptr, " %3s", " ");
    }

    for (size_t i = 1; i <= days; i++)
    {
        fprintf(readptr, " %3d", i);

        for (size_t j = 0; j < 5; j++)
        {
            if (i == (7 - firstdays) + 7 * j)
            {
                fprintf(readptr, "\n");
            }
        }
    }
}
