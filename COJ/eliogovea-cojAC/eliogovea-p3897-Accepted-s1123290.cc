#include <bits/stdc++.h>

using namespace std;

const int N = 200 * 1000 + 10;

int n;
int x[N], y[N];
int cnt[5][5][5];
int ap[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	for (int i = 1; i < n; i++) {
		x[i] -= x[0];
		y[i] -= y[0];
	}
	x[0] = 0;
	y[0] = 0;
	for (int i = 0; i < n; i++) {
		x[i] = ((x[i] % 2) + 2) % 2;
		y[i] = ((y[i] % 2) + 2) % 2;
	}
	int pa = 0;
	for (int i = 1; i + 1 < n; i++) {
		pa += ((x[i] * y[i + 1] - y[i] * x[i + 1]) + 2) % 2;
		pa %= 2;
	}

	if (pa != 0) { // el area total tiene que ser par
		cout << "0\n";
		return 0;
	}

	long long answer = 0;

	ap[0] = 0;

	int ca = 0;
	for (int i = 1; i < n; i++) {
		ca += (x[i - 1] * y[i] - y[i - 1] * x[i] + 2) % 2;
		ca %= 2;
		ap[i] = ca;
		for (int aap = 0; aap < 2; aap++) {
			for (int mx = 0; mx < 2; mx++) {
				for (int my = 0; my < 2; my++) {
					if (((ca + (((mx * y[i] - my * x[i]) + 2) % 2) + aap) % 2) == 0) {
						answer += cnt[aap][mx][my];
					}
				}
			}
		}
		// cerr << i << " " << answer << "\n";
		cnt[ap[i - 1]][x[i - 1]][y[i - 1]]++;
	}
	answer--; // estoy contando el primer punton con el ultimo

	cout << answer << "\n";
}
