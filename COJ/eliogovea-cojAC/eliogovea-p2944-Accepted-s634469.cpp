#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN = 505;

int n, m[MAXN], a, b, sol;

int main() {
	ios::sync_with_stdio(false);
	//freopen("e.in", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> m[i];
	while (cin >> a >> b) {
		if (m[a] < m[b]) sol += m[a];
		else sol += m[b];
	}
	cout << sol << '\n';
}
