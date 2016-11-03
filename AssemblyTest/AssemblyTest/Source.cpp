#include<iostream>
using namespace std;
#include<string>
int **station;
int min(int a, int b)
{
	if (a < b)
		return a;
	return b;
}
void iterative(int n)
{
	int f=0;
	for (int i = 0;i < 2;i++)
	{
		for (int j = 1;j < n-1;j++)
		{
			if (station[i][j - 1] <= station[i + 1][j - 1])
			{
				f += station[i][j - 1];
			}
			else
			{
				f += station[i + 1][j - 1];
			}
		}
	}
	cout << "Cost for the iterative path is " << f<<endl;
}
void recursive(int n)
{
	int f = 0;
	for (int j = 0;j < 2;j++)
	{
		for (int i = 0;i < n;i++)
		{
			if (n == 1)
				f = station[j][i];
			else
			{
				f += min(station[j][i], station[j + 1][i]);
			}
		}
	}
	cout << "Cost for the recursive path is " << f << endl;
}
void main()
{

	int n;
	cout << "Enter number of nodes: ";
	cin >> n;
	station = new int *[3];
	for (int i = 0;i < 3;i++)
	{
		station[i] = new int[n];
	}
	for (int i = 0;i < 3;i++)
	{
		for (int j = 0;j < n;j++)
		{
			station[i][j] = rand() % 30;
		}
	}
	iterative(n);
	recursive(n);
	system("pause");
}