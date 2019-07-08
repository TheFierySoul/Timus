// A.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <cmath>
#include <string>

#define MIN(a,b) (((a) < (b))?(a):(b))
#define MAX(a,b) (((a) > (b))?(a):(b))

using namespace std;

typedef long long int64;


struct ST
{
	vector<int> base;

	void Init(vector<int>& a)
	{
		base.assign(4 * a.size(), 0);
		Build(a, 1, 0, a.size() - 1);
	}

	void Build(vector<int>& a, int v, int tl, int tr) {
		if (tl == tr)
			base[v] = a[tl];
		else {
			int tm = (tl + tr) / 2;
			Build(a, v * 2, tl, tm);
			Build(a, v * 2 + 1, tm + 1, tr);
			base[v] = MAX(base[v * 2], base[v * 2 + 1]);
		}
	}
	
	int Max(int v, int tl, int tr, int l, int r)
	{
		if (l > r)
		{
			return 0;
		}
		if (tl == l && tr == r)
		{
			return base[v];
		}
		int tm = (tl + tr) / 2;
		return MAX(Max(2 * v, tl, tm, l, MIN(r, tm)), Max(2 * v + 1, tm + 1, tr, MAX(l, tm + 1), r));
	}

};

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
	int b, r, y;
	cin >> b >> r >> y;
	int k;
	cin >> k;
	int res = 1;
	for (int i = 0; i < k; i++)
	{
		string a;
		cin >> a;
		if (a == "Red")
		{
			res *= r;
			continue;
		}
		if (a == "Blue")
		{
			res *= b;
			continue;
		}
		if (a == "Yellow")
		{
			res *= y;
		}
	}
	cout << res << endl;
}
