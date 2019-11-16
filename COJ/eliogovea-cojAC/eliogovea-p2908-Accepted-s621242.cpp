#include <iostream>
//#include <fstream>
using namespace std;

const int MAXN = 505;

int n, arr[MAXN * MAXN], pi, pj, abi[MAXN * MAXN], tot;
string str;

void update(int pos, int val) {
	for (; pos <= n * n; pos += pos & -pos)
		abi[pos] += val;
}

int query(int pos) {
	int r = 0;
	for (; pos; pos -= pos & -pos) r += abi[pos];
	return r;
}

int to_int(string &s) {
	if (s == "#") return n * n;
	int x = 0;
	for (int i = 0; s[i]; i++)
		x = 10 * x + s[i] - '0';
	return x;
}

int main() {
    //freopen("e.in", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n * n; i++) {
		cin >> str;
		arr[i] = to_int(str);
		if (arr[i] == n * n) pi = i;
	}
	while (pi + n <= n * n) swap(arr[pi], arr[pi + n]), pi += n;
	while (pi + 1 <= n * n) swap(arr[pi], arr[pi + 1]), pi++;
	for (int i = 1; i <= n * n; i++) {
		tot += arr[i] - 1 - query(arr[i]);
		update(arr[i], 1);
	}
	cout << ((tot & 1) ? "unsolvable" : "solvable") << endl;
}
