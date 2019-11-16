#include <bits/stdc++.h>

using namespace std;

int joseph(int n, int m) {
	int res = 0;
	for (int i = 1; i <= n; i++) {
		res = (res + m) % i;
	}
	return res + 1;
}

int ans[105];

int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);

	//freopen("dat.txt", "r", stdin);
	for (int i = 13; i <= 100; i++) {
		int cur = 1;
		while (true) {
            int x = joseph(i, cur) - 1;
            x = (x - ((cur - 1) % i) + i) % i;
            if (x == 12) {
                break;
                //cout << "ans " << i << " " << cur << " " << x << "\n";
            }
            //cout << i << " " << cur << " " << x << "\n";
			cur++;
		}
		ans[i] = cur;
	}
	int n;
	while (cin >> n && n) {
		cout << ans[n] << "\n";
	}
}
