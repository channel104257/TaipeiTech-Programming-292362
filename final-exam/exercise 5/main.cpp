#include <iostream>

using namespace std;

struct Check
{
    char number;
    Check *nextptr;
};
typedef struct Check check;
typedef Check *checkptr;

void displayBits(unsigned int x);
void printList(checkptr head);
checkptr isEmpty(checkptr head);

int main()
{
    unsigned int x;
    cout << "Please Enter a number (0 ~ 127) : ";
    cin >> x;

    // displayBits(x);

    unsigned int displayMask = 1 << 7;

    checkptr head = new check;
    head->number = x & displayMask ? '1' : '0';
    head->nextptr = NULL;
    x <<= 1;

    checkptr current = head;

    for (size_t i = 0; i < 7; i++)
    {
        current->nextptr = new check;
        current = current->nextptr;

        current->number = (x & displayMask ? '1' : '0');
        x <<= 1;
        current->nextptr = NULL;
    }

    printList(head);

    checkptr last = isEmpty(head);
    last->nextptr = new check;
    last = last->nextptr;

    last->number = current->number;
    last->nextptr = NULL;

    printList(head);

    return 0;
}

void displayBits(unsigned int x)
{
    unsigned int displayMask = 1 << 7;

    for (size_t i = 0; i < 8; i++)
    {
        char c = x & displayMask ? '1' : '0';
        putchar(c);
        x <<= 1;
        printf(" --> ");
    }

    printf("NULL");
    cout << endl;
}

void printList(checkptr head)
{
    checkptr current = head;

    while (current != NULL)
    {
        cout << current->number << " --> ";
        current = current->nextptr;
    }

    cout << "NULL" << endl;
}

checkptr isEmpty(checkptr head)
{
    checkptr current = head;

    while (current->nextptr != NULL)
    {
        current = current->nextptr;
    }

    return current;
}
