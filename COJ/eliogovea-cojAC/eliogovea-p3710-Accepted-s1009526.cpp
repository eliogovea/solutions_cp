#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

const int N = 1005;

int t, a, b;
double line[N];
double v[N];

int s[N];

bool cmp(int x, int y) {
	return v[x] > v[y];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> a >> b;
		for (int i = 0; i < a; i++) {
			v[i] = 0.0;
		}
		double T = 0.0;
		for (int i = 0; i < b; i++) {
			for (int j = 0; j < a; j++) {
				cin >> line[j];
				line[j] /= 100.0;
			}
			double tv;
			cin >> tv;
			for (int j = 0; j < a; j++) {
				v[j] += tv * line[j];
			}
			T += tv;
		}
		for (int i = 0; i < a; i++) {
			s[i] = i;
		}
		sort(s, s + a, cmp);

		int w1 = s[0];
		if (v[w1] * 1000.0 > 501.0 * T + EPS) {
			cout << w1 + 1 << " " << (int)(v[w1] + EPS) << "\n";
		} else {
			int w2 = s[1];
			cout << w1 + 1 << " " << (int)(v[w1] + EPS) << "\n";
			cout << w2 + 1 << " " << (int)(v[w2] + EPS) << "\n";
		}
		if (t) {
            cout << "\n";
		}
	}
}
