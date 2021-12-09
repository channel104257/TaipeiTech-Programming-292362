#include <iostream>

using namespace std;

int main()
{
	char a[100];

	cout << "請輸入一行字串 : ";
	cin.getline(a, 100);

	char* p = a;
	int count = 0;

	for (size_t i = 0; i < 100; i++)
	{
		if ((int)p[i] == 97)
		{
			count++;
		}
	}

	cout << "\"" << p << "\"" << endl;
		
	cout << "上列字串共有" << count << "個\'a\'字元" << endl;
	
	return 0;
}
