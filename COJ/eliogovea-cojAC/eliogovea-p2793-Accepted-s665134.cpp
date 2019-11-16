#include <iostream>
#include <vector>

using namespace std;

int k, m, x;
vector<int> a[15];

int main() {
	cin >> k;
	for (int i = 0; i <= k; i++) a[0].push_back(i);
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> x;
		for (int j = 0; j < (int)a[i - 1].size(); j++) {
			if (j && (j % x == 0)) continue;
			a[i].push_back(a[i - 1][j]);
		}
	}
	for (int i = 1; i < (int)a[m].size(); i++)
		cout << a[m][i] << "\n";
}
