//快速陣列交換 https://www.796t.com/post/Nzh0N2U=.html

#include <iostream>
#include <algorithm>

using namespace std;

struct Student
{
    long id;
    char name[10];
    int subject[3];
};
typedef struct Student student;

void swap(student *s1, student *s2);
void printscore(student *sn);

int main()
{
    student st1 = {104310030, "學生1", {60, 70, 80}};
    student st2 = {104310047, "學生2", {90, 80, 70}};

    cout << "交換前" << endl;
    printscore(&st1);
    printscore(&st2);

    swap(&st1, &st2);

    return 0;
}

void swap(student *s1, student *s2)
{
    long tempid = s1->id;
    s1->id = s2->id;
    s2->id = tempid;

    std::swap(s1->name, s2->name);
    std::swap(s1->subject, s2->subject);

    cout << "交換後" << endl;
    printscore(s1);
    printscore(s2);
}

void printscore(student *sn)
{
    cout << sn->id << " " << sn->name << endl;
    for (size_t i = 0; i < 3; i++)
    {
        cout << "科目" << i + 1 <<"成績 : " << sn->subject[i] << endl;
    }
}
