#include <iostream>
#include <vector>

using namespace std;

const int inf = 1e9;

const string s = "moo";

int n, l[100005];

char solve(int p) {
	if (p < 3) return s[p];
	int ind = 0;
	while (l[ind] < p + 1) ind++;
	int lk = l[ind - 1];
	if (p == lk) return 'm';
	if (p > lk && p < lk + ind + 3) return 'o';
	if (p >= lk + ind + 3) p -= lk + ind + 3;
	return solve(p);
}

int main() {
	l[0] = 3;
	int cnt = 0;
	while (l[cnt++] <= inf) {
		l[cnt] = 2 * l[cnt - 1] + 1 + cnt + 2;
	}
	cin >> n;
	cout << solve(n - 1) << "\n";
}
