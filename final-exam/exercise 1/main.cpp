#include <iostream>
#include <math.h>
#include <fstream>
#include <algorithm>

using namespace std;

struct Student
{
    char name;
    int score1;
    int score2;
    int score3;
    int score4;
    float total;
    float average;
    int No;
};
typedef struct Student student;

int main()
{
    ifstream infile;
    ofstream outfile;
    infile.open("Book1.txt", ios_base::in);
    outfile.open("grade.txt", ios_base::in | ios_base::out | ios_base::trunc);

    student grade[20];
    float s1 = 0;
    float s2 = 0;
    float s3 = 0;
    float s4 = 0;

    float x1 = 0;
    float x2 = 0;
    float x3 = 0;
    float x4 = 0;

    float a1, a2, a3, a4;
    float sd1, sd2, sd3, sd4;

    printf("%4s %4s %5s %5s %5s %5s  %4s    %4s\n","名次", "姓名", "分數1", "分數2", "分數3", "分數4", "總分", "平均");
    outfile << "名次" << " " << "姓名" << " " << "分數1"  << " " << "分數2" << " " << "分數3" << " " << "分數4" << "   " << "總分" << "    " << "平均" << endl;

    for (size_t i = 0; i < 20; i++)
    {
        infile >> grade[i].name;
        infile >> grade[i].score1;
        infile >> grade[i].score2;
        infile >> grade[i].score3;
        infile >> grade[i].score4;

        grade[i].total = grade[i].score1 + grade[i].score2 + grade[i].score3 + grade[i].score4;
        grade[i].average = grade[i].total / 4;

        s1 = s1 + grade[i].score1;
        s2 = s2 + grade[i].score2;
        s3 = s3 + grade[i].score3;
        s4 = s4 + grade[i].score4;

        x1 = x1 + pow(grade[i].score1, 2);
        x2 = x2 + pow(grade[i].score2, 2);
        x3 = x3 + pow(grade[i].score3, 2);
        x4 = x4 + pow(grade[i].score4, 2);
    }

    int ctotal[20];
    for (size_t i = 0; i < 20; i++)
    {
        ctotal[i] = grade[i].total;
    }

    sort(ctotal, ctotal + 20, std::greater<int>());

    for (size_t i = 0; i < 20; i++)
    {
        for (size_t j = 0; j < 20; j++)
        {
            if (ctotal[i] == grade[j].total)
            {
                printf("%4d %4c %5d %5d %5d %5d  %4.0f    %4.2f\n", i + 1, grade[j].name, grade[j].score1, grade[j].score2, grade[j].score3, grade[j].score4, grade[j].total, grade[j].average);
                if (i < 9)
                {
                    outfile << "  " << i + 1 << "     " << grade[j].name;
                    outfile << "    " << grade[j].score1  << "    " << grade[j].score2 << "    " << grade[j].score3 << "    " << grade[j].score4;
                    outfile << "    " << grade[j].total <<  "    " << grade[j].average << endl;
                    grade[j].total = 0;
                    break;
                }
                else
                {
                    outfile << " " << i + 1 << "     " << grade[j].name;
                    outfile << "    " << grade[j].score1  << "    " << grade[j].score2 << "    " << grade[j].score3 << "    " << grade[j].score4;
                    outfile << "    " << grade[j].total <<  "    " << grade[j].average << endl;
                    grade[j].total = 0;
                    break;
                }
                
            }
        }
    }

    a1 = s1 / 20;
    a2 = s2 / 20;
    a3 = s3 / 20;
    a4 = s4 / 20;

    sd1 = sqrt((x1 / 20) - pow(a1, 2));
    sd2 = sqrt((x2 / 20) - pow(a2, 2));
    sd3 = sqrt((x3 / 20) - pow(a3, 2));
    sd4 = sqrt((x4 / 20) - pow(a4, 2));

    cout << endl;
    outfile << endl;
    printf("平均    %4.2f  %4.2f  %4.2f  %4.2f\n", a1, a2, a3, a4);
    outfile << "平均    " << a1 << "  " << a2 << "  " << a3 << "  " << a4 << "  " << endl;
    printf("均方差  %5.2f  %5.2f  %5.2f  %5.2f\n", sd1, sd2, sd3, sd4);
    outfile << "均方差   " << sd1 << "   " << sd2 << "   " << sd3 << "   " << sd4 << "   " << endl;
    cout << endl;

    infile.close();
    outfile.close();

    return 0;
}

