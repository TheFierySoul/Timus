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

const double PI = 3.1415926535;
const int G = 10;

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

int IsCell(int x, int y, int n)
{
	return ((x >= 1) && (x <= n) && (y >= 1) && (y <= n)) ? 1 : 0;
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
	int n, x, y;
	cin >> n >> x >> y;
	int left = x - 1;
	int right = n - x;
	int up = y - 1;
	int down = n - y;
	int ur = MIN(up, right);
	int ul = MIN(up, left);
	int dr = MIN(down, right);
	int dl = MIN(down, left);
	int king = MIN(up, 1) + MIN(right, 1) + MIN(left, 1) + MIN(down, 1) + MIN(ur, 1) + MIN(ul, 1) + MIN(dl, 1) + MIN(dr, 1);
	int bishop = ur + ul + dr + dl;
	int rook = down + up + right + left;
	int queen = bishop + rook;
	int knight = 0;
	knight += IsCell(x + 2, y + 1, n);
	knight += IsCell(x + 2, y - 1, n);
	knight += IsCell(x - 2, y - 1, n);
	knight += IsCell(x - 2, y + 1, n);
	knight += IsCell(x + 1, y + 2, n);
	knight += IsCell(x + 1, y - 2, n);
	knight += IsCell(x - 1, y + 2, n);
	knight += IsCell(x - 1, y - 2, n);
	cout << "King: " << king << endl;
	cout << "Knight: " << knight << endl;
	cout << "Bishop: " << bishop << endl;
	cout << "Rook: " << rook << endl;
	cout << "Queen: " << queen << endl;
	return 0;
}
