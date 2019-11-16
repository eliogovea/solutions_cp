#include <iostream>
using namespace std;

int c;
long long n, l, r;

int main()
{
	cin >> c;
	while (c--)
	{
		cin >> n >> l >> r;
		if ((n / l) * r >= n) cout << "Yes\n";
		else cout << "No\n";
	}
}
