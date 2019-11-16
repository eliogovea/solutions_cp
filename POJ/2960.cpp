#include <iostream>
#include <algorithm>

using namespace std;

const int N = 10 * 1000;

int grundy[N + 5];
int used[N + 5];

int k, s[105];
int m, n, c;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (cin >> k && k) {
		for (int i = 0; i < k; i++) {
			cin >> s[i];
		}
		sort(s, s + k);
		grundy[0] = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < k; j++) {
				if (s[j] > i) {
					break;
				}
				used[grundy[i - s[j]]] = i;
			}
			grundy[i] = 0;
			while (used[grundy[i]] == i) {
				grundy[i]++;
			}
		}
		cin >> m;
		while (m--) {
			cin >> n;
			int xorSum = 0;
			while (n--) {
				cin >> c;
				xorSum ^= grundy[c];
			}
			cout << "LW"[xorSum != 0];
		}
		cout << "\n";
	}
}
