#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1000;
int n;
char c;
bool criba[MAXN + 10];
vector<int> p;

int main()
{
	for (int i = 2; i * i <= MAXN; i++)
		if (!criba[i])
			for (int j = i * i; j <= MAXN; j += i)
				criba[j] = 1;
	for (int i = 2; i <= MAXN; i++)
		if (!criba[i]) p.push_back(i);
	while (cin >> n >> c >> n)
	{
		int sol = 1;
		for (int i = 0; p[i] * p[i] <= n; i++)
			if (n % p[i] == 0)
			{
				int cant = 0;
				while (n % p[i] == 0)
				{
					cant++;
					n /= p[i];
				}
				sol *= (2 * cant + 1);
			}
		if (n > 1) sol *= 3;
		cout << (sol + 1) / 2 << endl;
	}
}
