#include <iostream>

using namespace std;

int n, k, s, t, r;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	while (k--) {
		cin >> s >> t >> r;
		int tot = n, time = 0;
		while (tot) {
			if (tot > s * t) {
				time += t + r;
				tot -= s * t;
			} else {
			  int x = tot / s;
				time += x;
				tot -= x * s;
        if (tot > 0) time++;
				tot = 0;
			}
		}
		cout << time << "\n";
	}
}
