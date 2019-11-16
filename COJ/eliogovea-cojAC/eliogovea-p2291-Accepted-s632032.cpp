#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e7;

const int xmov[] = {0, 1, 0, -1};
const int ymov[] = {1, 0, -1, 0};

int x[MAXN], y[MAXN];
bool criba[MAXN + 5];

void Criba() {
	criba[0] = criba[1] = 1;
	for (int i = 2; i * i <= MAXN; i++)
		if (!criba[i])
			for (int j = i * i; j <= MAXN; j += i)
				criba[j] = 1;
}

int tc, n;

int main() {
	ios::sync_with_stdio(false);
	//freopen("e.in", "r", stdin);
	Criba();
	int d = 0;
	for (int i = 1; i <= MAXN; i++) {
		x[i] = x[i - 1] + xmov[d];
		y[i] = y[i - 1] + ymov[d];
		if (!criba[i]) d = (d + 1) % 4;
	}
	cin >> tc;
	while (tc--) {
		cin >> n;
		cout << x[n] << ' ' << y[n] << '\n';
	}
}
