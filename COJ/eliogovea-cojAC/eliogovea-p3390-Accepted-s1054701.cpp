#include <bits/stdc++.h>

using namespace std;

const int N = 100 * 1000 + 5;

int n;
int s[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	int mn;
	for (int i = 0; i < n; i++) {
		int cnt = s[i] / (n + 1);
		if (i == 0 || cnt < mn) {
			mn = cnt;
		}
	}
	for (int i = 0; i < n; i++) {
		s[i] -= mn * (n + 1);
	}
	sort(s, s + n);
	bool second = false;
	for (int i = 0; i < n; i++) {
		if (s[i] <= i) { // el primer jugador no puede jugar
			second = true;
		}
	}
	cout << (second ? "S" : "N") << "\n";
}
