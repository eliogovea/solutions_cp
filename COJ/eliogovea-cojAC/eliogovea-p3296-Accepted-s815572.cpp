#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll inf = 1e15;

ll v[] = {8LL, 49LL, 288LL, 1681LL, 9800LL, 57121LL, 332928LL, 1940449LL, 11309768LL, 65918161LL, 384199200LL, 2239277041LL, 13051463048LL, 76069501249LL, 443365544448LL, 2584123765441LL, 15061377048200LL, 87784138523761LL, 511643454094368LL, inf + 5LL};

ll n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (cin >> n && n) {
		int cnt = 0;
		while (v[cnt] <= n) {
			cnt++;
		}
		cout << cnt << "\n";
	}
}
