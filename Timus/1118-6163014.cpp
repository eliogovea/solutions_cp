// Problem: pace=1&num=1118
// Verdict: Accepted

#include <bits/stdc++.h>

using namespace std;

const int N = 1000000;

long long cnt[N + 5], a, b;

int main() {
	//freopen("data.txt", "r", stdin);
	for (int i = 1; i <= N; i++) {
		for (int j = i + i; j <= N; j += i) {
			cnt[j] += i;
		}
	}
	cin >> a >> b;
	int x = a;
	for (int i = a + 1; i <= b; i++) {
		if (cnt[i] * x < cnt[x] * i) {
			x = i;
		}
	}
	cout << x << "\n";
}