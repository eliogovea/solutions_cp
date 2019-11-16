#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector <int> v = {4, 6};

	vector <vector <int>> last(10, vector <int> (10, -1));
	int n = 2;
	while (last[v[n - 2]][v[n - 1]] == -1) {
		last[v[n - 2]][v[n - 1]] = n - 2;
		int x = v[n - 2] * v[n - 1];
		if (x >= 10) {
			v.push_back(x / 10);
			n++;
		}
		v.push_back(x % 10);
		n++;
	}

	int l = n - 2 - last[v[n - 2]][v[n - 1]];

	
	for (int i = 0; i < 4; i++) {
		int p;
		cin >> p;

		if (p <= 2) {
			cout << v[p - 1];
		} else {
			cout << v[2 + ((p - 3) % l)];
		}
	}

}
