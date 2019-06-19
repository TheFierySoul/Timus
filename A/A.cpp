// A.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <string>

#define MIN(a,b) (((a) < (b))?(a):(b))

using namespace std;

int main()
{
	map<string, pair<int, int>> a;
	int n = 6;
	for (int i = 0; i < n; i++)
	{
		string name;
		cin >> name;
		string device;
		cin >> device;
		int price;
		cin >> price;
		if (a.find(device) == a.end())
		{
			a[device] = { 1, price };
		}
		else
		{
			a[device].first++;
			a[device].second = MIN(a[device].second, price);
		}
	}
	string best = "";
	int mx = 0;
	int mnPrice = 1e9;
	for (auto item : a)
	{
		if (item.second.first > mx)
		{
			best = item.first;
			mx = item.second.first;
			mnPrice = item.second.second;
		}
		else if (item.second.first == mx && item.second.second < mnPrice)
		{
			best = item.first;
			mx = item.second.first;
			mnPrice = item.second.second;
		}
	}
	cout << best << endl;
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
