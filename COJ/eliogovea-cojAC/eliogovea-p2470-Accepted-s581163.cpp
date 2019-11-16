#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 31000;

int n, k, suma[MAXN + 10], last;
string str;
vector<int> v[25];

int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		int s = str.size();
		int p = v[s].end() - lower_bound(v[s].begin(), v[s].end(), i - k);
		v[s].push_back(i);
		int carry = 0;
		for (int j = 0; j <= last || p; j++)
		{
			carry += suma[j] + (p % 10);
			suma[j] = carry % 10;
			carry /= 10;
			p /= 10;
			last = max(last, j);
		}
		if (carry) suma[++last] = carry;
	}
	for (int i = last; i >= 0; i--) cout << suma[i];
	cout << endl;
}
