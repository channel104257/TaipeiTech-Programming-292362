#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;

struct Data
{
    int Character = 0;
    int Newline = 1;
    int Space = 0;
};

typedef struct Data data;

void textFile(FILE *readptr, data *number);

int main()
{
    FILE *fileptr;
    data number;
    fileptr = fopen("Book1.txt", "r");

    if (fileptr == NULL)
    {
        cout << "無法讀取檔案" << endl;
        return EXIT_FAILURE;
    }
    else
    {
        textFile(fileptr, &number);
    }

    fclose(fileptr);
    return 0;
}

void textFile(FILE *readptr, data *number)
{
    char c;
    while ((c = fgetc(readptr)) != EOF)
    {
        switch (c)
        {
        case ' ':
            number->Space++;
            break;
        
        case '\n':
            number->Newline++;
            break;

        default:
            number->Character++;
            break;
        }
    }

    printf("%9s    %7s    %5s\n", "Character", "Newline", "Space");
    printf("%9d    %7d    %5d\n", number->Character++, number->Newline++, number->Space++);
}
