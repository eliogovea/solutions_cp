#include <bits/stdc++.h>

using namespace std;

const int N = 5000;

long long n;
int a, b, c, d;
int va[N + 5], vb[N + 5], vc[N + 5], vd[N + 5];
int vcd[N * N + 5], szcd;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	while (cin >> n >> a >> b >> c >> d) {
		if (n == 0 && a == 0 && b == 0 && c == 0 && d == 0) {
			break;
		}
		for (int i = 0; i < a; i++) {
			cin >> va[i];
		}
		for (int i = 0; i < b; i++) {
			cin >> vb[i];
		}
		for (int i = 0; i < c; i++) {
			cin >> vc[i];
		}
		for (int i = 0; i < d; i++) {
			cin >> vd[i];
		}
		szcd = 0;
		for (int i = 0; i < c; i++) {
			for (int j = 0; j < d; j++) {
				vcd[szcd++] = vc[i] + vd[j];
			}
		}
		sort(vcd, vcd + szcd);
		long long ans = 0;
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				ans += (long long)(upper_bound(vcd, vcd + szcd, n - va[i] - vb[j]) - vcd);
			}
		}
		cout << ans << "\n";
	}
	
}