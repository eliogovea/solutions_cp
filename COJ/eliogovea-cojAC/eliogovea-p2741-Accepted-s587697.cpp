#include <iostream>
#include <algorithm>
using namespace std;

long long  n, a[100010], sol;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		sol += abs(a[i] - i);
	cout << sol << endl;
}
