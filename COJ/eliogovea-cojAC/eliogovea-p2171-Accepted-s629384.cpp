#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000000;

void maxi(int a, int &b) {if (a > b) b = a;}

int n, a[MAXN + 5], b, e, sol;

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> b >> e;
		a[b]++;
		a[e + 1]--;
	}
	for (int i = 1; i <= MAXN; i++)
		a[i] += a[i - 1];
	for (int i = 1; i <= MAXN; i++)
		maxi(a[i], sol);
	cout << sol << '\n';
}
