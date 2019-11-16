#include <iostream>
#include <algorithm>
#include <queue>
#include <fstream>

using namespace std;

const int MAXN = 100005;

typedef pair<int, int> pii;

int n, a[MAXN], L[MAXN], R[MAXN], sol;
priority_queue<pii> Q;

int main() {
	ios::sync_with_stdio(false);
	//freopen("e.in", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	n++;
	for (int i = 1; i < n; i++) R[i] = n - 1;
	for (int i = 1; i < n; i++) {
		while (!Q.empty() && Q.top().first > a[i]) {
			R[Q.top().second] = i - 1;
			Q.pop();
		}
		Q.push(make_pair(a[i], i));
	}
	while (!Q.empty()) Q.pop();
	for (int i = 1; i < n; i++) L[i] = 1;
	for (int i = n - 1; i; i--) {
		while (!Q.empty() && Q.top().first > a[i]) {
			L[Q.top().second] = i + 1;
			Q.pop();
		}
		Q.push(make_pair(a[i], i));
	}
	for (int i = 1; i < n; i++) {
    //cout << a[i] << ' ' << L[i] << ' ' << R[i] << '\n';
    sol = max(sol, a[i] * (R[i] - L[i] + 1));
	}
	cout << sol << '\n';
}
