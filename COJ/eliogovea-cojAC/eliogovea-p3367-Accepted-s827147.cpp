#include <bits/stdc++.h>

using namespace std;

const int N = 1000;

bool criba[N * N + 5];

long long ans[N + 5];

int t, n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 2; i <= N; i++) {
		if (!criba[i]) {
			for (int j = i * i; j <= N * N; j += i) {
				criba[j] = true;
			}
		}
	}
	int fila = 1;
	int cnt = 0;
	for (int i = 1; i <= N * N; i++) {
        if (fila > N) {
            break;
        }
        cnt++;
		if (!criba[i]) {
            //cout << i << " " << fila << "\n";
			ans[fila] += (long long)i;
		}
        if (cnt == fila) {
            fila++;
            cnt = 0;
        }
	}
	ans[1] = 0;
	cin >> t;
	while (t--) {
        cin >> n;
        cout << ans[n] << "\n";
	}
}
