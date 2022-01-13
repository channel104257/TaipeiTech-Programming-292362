#include <iostream>
#include <fstream>

using namespace std;

struct student
{
	char name;
	float n1;
	float n2;
	float n3;
	float n4;
	float total;
	float average;
};

int main()
{
	FILE * file;
	student ostudent[20];

	student copystudent[20];

	file = fopen("Book1.txt", "r");

	printf("%s %s  %s %s %s %s  %s   %s\n", "名次", "姓名", "分數1", "分數2", "分數3", "分數4", "總分", "平均");

	if (!file)
	{
		cout << "檔案無法開啟\n";
	}
	else
	{
		for (size_t i = 0; i < 20; i++)
		{
			fscanf(file, "%c %f %f %f %f\n", &ostudent[i].name, &ostudent[i].n1, &ostudent[i].n2, &ostudent[i].n3, &ostudent[i].n4);

			ostudent[i].total = ostudent[i].n1 + ostudent[i].n2 + ostudent[i].n3 + ostudent[i].n4;
			ostudent[i].average = ostudent[i].total / 4;
		}

		for (size_t i = 0; i < 20; i++)
		{
			printf("  %d    %c    %.0f    %.0f    %.0f    %.0f    %.0f   %.2f\n", 1, ostudent[i].name, ostudent[i].n1, ostudent[i].n2, ostudent[i].n3, ostudent[i].n4, ostudent[i].total, ostudent[i].average);
		}
		fclose(file);
	}

	system("pause");
	return 0;
}
