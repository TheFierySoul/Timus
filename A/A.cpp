// A.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <cmath>
#include <string>

#define MIN(a,b) (((a) < (b))?(a):(b))

using namespace std;

typedef long long int64;

void P(int64& x, int64& y)
{
	int i, j;
	if (x > 0 && y > 0)
	{
		for (i = 1; i <= x + y; i++)
		{
			y = x * x + y;
			x = x * x + y;
			y = sqrt(x + (y / labs(y)) * (-labs(y)));
			for (j = 1; j <= 2 * y; j++)
				x = x - y;
		}
	}
}

int main()
{
	/*
	int64 a, b;
	cin >> a >> b;
	if (a > 0 && b > 0 && a > b)
	{
		swap(a, b);
	}
	cout << a << ' ' << b << endl;
	return 0;
	*/
	int n, s;
	cin >> n >> s;
	vector<int> d(n);
	for (int i = 0; i < n; i++)
	{
		cin >> d[i];
	}
	vector<int> a(n);
	for (int i = 1; i < n; i++)
	{
		a[i] = d[i - 1] / d[i];
		s /= a[i];
	}
	a[0] = s;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] - 1 << ' ';
	}
	cout << endl;
}
