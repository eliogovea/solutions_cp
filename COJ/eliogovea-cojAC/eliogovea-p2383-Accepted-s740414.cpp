#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;

const LL inf = 1e9;
const int N = 1e5;

int criba[N + 5];
vector<int> p;

void Criba() {
	criba[1] = true;
	for (int i = 2; i * i <= N; i++)
		if (!criba[i])
			for (int j = i * i; j <= N; j += i)
				criba[j] = true;
	p.push_back(2);
	for (int i = 3; i <= N; i += 2)
		if (!criba[i]) p.push_back(i);
}

bool primo(int n) {
	if (n <= N) return !criba[n];
	for (int i = 0; p[i] * p[i] <= n; i++)
		if (n % p[i] == 0)
			return false;
	return true;
}

vector<int> v;

void f1(int cur) {
	if (cur > inf) return;
	if (primo(cur)) {
		if (cur) v.push_back(cur);
		for (int i = 1; i <= 9; i++)
			f1(10 * cur + i);
	}
}

void f2(LL cur, LL pw10) {
	if (cur > inf) return;
	if (primo(cur)) {
		if (cur) v.push_back(cur);
		for (int i = 1; i <= 9; i++)
			f2(pw10 * i + cur, 10ll * pw10);
	}
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
	Criba();
	f1(0);
	f2(0, 1);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	int tc, a, b;
	cin >> tc;
	while (tc--) {
		cin >> a >> b;
		int ans = upper_bound(v.begin(), v.end(), b) - lower_bound(v.begin(), v.end(), a);
		cout << ans << "\n";
	}
}
