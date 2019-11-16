#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

const int MAXN = 200010;

int c, n, id;
string s1, s2;
map<string, int> m;
int p[MAXN], rank[MAXN];

void make(int x)
{
	p[x] = x;
	rank[x] = 1;
}

int find(int x)
{
	if (p[x] != x) p[x] = find(p[x]);
	return p[x];
}

int join(int x, int y)
{
	int px = find(x);
	int py = find(y);

	if (px == py) return rank[py];

	p[px] = py;
	rank[py] += rank[px];
	return rank[py];
}

int main()
{
	for (cin >> c; c--;)
	{
		cin >> n;

		for (int i = 1; i <= n; i++)
		{
			cin >> s1 >> s2;

			if (m.find(s1) == m.end())
			{
				m[s1] = id++;
				make(id - 1);
			}
			if (m.find(s2) == m.end())
			{
				m[s2] = id++;
				make(id - 1);
			}

			cout << join(m[s1], m[s2]) << endl;
		}

		if (c)
		{
			//for (int i = 0; i < id; i++)
				//p[i] = rank[i] = 0;
			m.clear();
			id = 0;
		}
	}
}
