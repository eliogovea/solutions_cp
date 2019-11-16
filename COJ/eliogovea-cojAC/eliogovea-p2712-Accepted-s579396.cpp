#include <iostream>
#include <map>
using namespace std;

int n, q;
string a, b;
map<string, int> m;

int main()
{
	for (cin >> n; n--;)
	{
		cin >> a >> b;
		m[b]++;
	}
	for (cin >> q; q--;)
	{
		cin >> a >> b;
		cout << m[b] << endl;
	}
}
