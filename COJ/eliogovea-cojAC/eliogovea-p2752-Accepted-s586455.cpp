#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1010;

int n;
short mark[MAXN];

int main()
{
	cin >> n;
	vector<string> names(n);
	vector<int> id(n);
	for (int i = 0; i < n; i++)
	{
		cin >> names[i] >> id[i];
		if (id[i] < 0) id[i] *= -1;
		mark[id[i]] ^= 1;
	}
	cout << "FOREVER ALONE ones:" << endl;
	for (int i = 0; i < n; i++)
		if (mark[id[i]]) cout << names[i] << endl;
}
