#include <iostream>
#include <locale>
#include <bitset>
using namespace std;
void task1()
{
	
		int a;
		cin >> a;
		for (int i = 0; i <= a; i++)
		{
			for (int f = 0; f <= i; f++)
			{
				cout << f;
			}
		}
		cout << endl;

}
long double faktorial(int t)
{
	long double res = 1;
	for (int i = 1; i <= t; i++)
	{
		res = res * i;
	}
	return res;
void task3()
{
	int m, n, k;
   cin >> n >> k;
	double C = 1;
	for (int i = 1; i <= k; ++i)
		C = C * (n - k + i) / i;
	cout << C << endl;
}
int main()
{
	int choise = 0;
	int a;
	while (a!=4)

	{
		cout << " Что вы хотите выполнить ? / n"
			<< "1.задание /n"
			<< "2.задание /n"
			<< "3.задание /n"
			<< "4.выход/n";
		cin >> choice;
		switch (choice)
		{
			case 1:
			{
				task1();
				break;
			}

			
			case 3:
			{
				task3();
				break;
			}
			default:
			{
				return 0;
			}
		}
	}
}

