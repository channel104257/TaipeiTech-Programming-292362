#include <iostream>
#include <conio.h>
#define MOVE 9

using std::cin;
using std::cout;
using std::endl;

struct Node
{
    int moveNumber;
    char board[MOVE];
    Node *nextptr;
};

typedef struct Node node;
typedef Node *nodeptr;

char OX[2] = {'O', 'X'};

void displayList(node *head);
bool wincheck(node *current);

int main()
{
    nodeptr head = new node;
    head->moveNumber = 1;
    int moveNumber = head->moveNumber;
    int place;
    bool winCondition = false;
    bool moveError = false;

    while (moveNumber <= 1)
    {
        head->nextptr = NULL;
        for (size_t i = 0; i < MOVE; i++)
        {
            head->board[i] = ' ';
        }

        cout << "******************" << endl;
        cout << "Move number : " << head->moveNumber << endl;
        cout << "TURN : " << OX[head->moveNumber % 2] << " , please make your move : ";

        cin >> place;

        head->board[place - 1] = OX[(head->moveNumber) % 2];

        displayList(head);

        moveNumber++;
    }

    nodeptr current = head;

    for (size_t i = 1; i < MOVE; i++)
    {
        if (moveError == false)
        {
            nodeptr temp = current;
            current->nextptr = new node;

            current = current->nextptr;

            current->moveNumber = temp->moveNumber + 1;

            for (size_t i = 0; i < MOVE; i++)
            {
                current->board[i] = temp->board[i];
            }

            current->nextptr = NULL;
        }
        moveError = false;

        cout << "**********************" << endl;
        cout << "Move number : " << current->moveNumber << endl;
        cout << "TURN : " << OX[current->moveNumber % 2] << " , please make your move : ";
        cin >> place;

        if (current->board[place - 1] != ' ')
        {
            cout << "You can't move here." << endl;
            moveError = true;
            i--;
        }
        else
        {
            current->board[place - 1] = OX[(current->moveNumber) % 2];

            displayList(head);
            winCondition = wincheck(current);

            if (winCondition == true)
            {
                break;
            }
        }
    }

    cout << "Game Over" << endl;
    cout << "player " << OX[(current->moveNumber) % 2] << " win the game." << endl;
    getch();
}

void displayList(node *head)
{
    nodeptr current = head;

    while (current != NULL)
    {
        cout << "----------------------" << endl;
        cout << "Move Number : " << current->moveNumber << endl;
        for (int i = 0; i < (MOVE / 3); i++)
        {
            cout << " ___   ___   ___  " << endl;
            cout << "| " << current->board[i * (MOVE / 3)] << " | | " << current->board[i * (MOVE / 3) + 1] << " | | " << current->board[i * (MOVE / 3) + 2] << " | " << endl;
            cout << "|___| |___| |___| " << endl;
            cout << endl;
        }

        current = current->nextptr;
    }
}

bool wincheck(node *current)
{
    for (size_t i = 0; i < MOVE / 3; i++)
    {
        if ((current->board[i * 3] == current->board[i * 3 + 1]) && (current->board[i * 3 + 1] == current->board[i * 3 + 2]))
        {
            if (current->board[i * 3] != ' ')
            {
                return true;
                break;
            }
        }

        if ((current->board[i] == current->board[i + 3]) && (current->board[i + 3] == current->board[i + 6]))
        {
            if (current->board[i] != ' ')
            {
                return true;
                break;
            }
        }
    }

    if ((current->board[0] == current->board[4]) && (current->board[4] == current->board[8]))
    {
        if (current->board[0] != ' ')
        {
            return true;
        }
    }

    if ((current->board[2] == current->board[4]) && (current->board[4] == current->board[6]))
    {
        if (current->board[2] != ' ')
        {
            return true;
        }
    }

    return false;
}
