// 2014-2015 CT S02E04: Codeforces Trainings Season 2 Episode 4 (US College Rockethon 2014 + COCI 2008-5 + GCJ Finals 2008 C)
// 100497E

#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

typedef long long LL;

int n, k;
LL vals[N];
LL L[N], R[N];
LL f[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> vals[i];
	}
	for (int i = 0; i < n; i++) {
		L[i] = -1;
		R[i] = n;
	}
	stack <int> S;
	for (int i = 0; i < n; i++) {
		while (S.size() && vals[S.top()] > vals[i]) {
			R[S.top()] = i;
			S.pop();
		}
		S.push(i);
	}
	S = stack <int>();
	for (int i = n - 1; i >= 0; i--) {
		while (S.size() && vals[S.top()] >  vals[i]) {
			L[S.top()] = i;
			S.pop();
		}
		S.push(i);
	}

	LL sum = 0;
	for (int i = 0; i < n; i++) {
		f[i] = (long long)(R[i] - i) * (i - L[i]) * (R[i] - L[i]) / 2LL;
		sum += f[i] * vals[i];
	}
	sort(f, f + n, greater <LL>());
	for (int i = 0; i < k; i++) {
		sum += f[i];
	}
	cout << sum << "\n";

}
