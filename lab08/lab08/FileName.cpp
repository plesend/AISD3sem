#include <string>
#include <Windows.h>
#include <iostream>
using namespace std;

int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N, M;
	cout << "¬ведите вместительность рюкзака: ";
	cin >> N;
	if (N <= 0)
	{
		return 0;
	}
	cout << "¬ведите количество предметов: ";
	cin >> M;
	if (M <= 0)
	{
		return 0;
	}
	string* itemnames = new string[M];
	int* prices = new int[M];
	int* weight = new int[M];

	for (int i = 0; i < M; i++)
	{
		cout << "введите название\tпредмета " << i + 1 << ": ";
		cin >> itemnames[i];

		cout << "введите стоимость\tпредмета " << i + 1 << ": ";
		cin >> prices[i];
		cout << "¬ведите вес\t\tпредмета " << i + 1 << ": ";
		cin >> weight[i];
	}

	int** backpack = new int* [M + 1];
	for (int i = 0; i < M + 1; i++)
	{
		backpack[i] = new int[N + 1];
	}

	for (int i = 0; i < M + 1; i++)
	{
		for (int j = 0; j < N + 1; j++)
		{
			backpack[i][j] = 0;
		}
	}

	for (int i = 1; i < M + 1; i++)
	{
		for (int j = 1; j < N + 1; j++)
		{
			if (j < weight[i - 1])
			{

				backpack[i][j] = backpack[i - 1][j];

			}
			else
			{
				backpack[i][j] = max(backpack[i - 1][j], backpack[i - 1][j - weight[i - 1]] + prices[i - 1]);
			}
		}
	}
	cout << "максимальна€ стоимость в рюкзаке " << backpack[M][N] << endl
		<< "предметы в рюкзаке: " << endl;;
	int i = M, j = N;
	while (i > 0 and j > 0)
	{
		if (backpack[i][j] != backpack[i - 1][j])
		{
			cout << itemnames[i - 1] << "\n";
			j -= weight[i - 1];
		}
		i--;
	}
	cout << endl;
}