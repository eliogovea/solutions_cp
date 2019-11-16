// 2016-2017 ACM-ICPC, Central Europe Regional Contest (CERC 16)
// 101173C

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(13);
	//freopen("dat.txt", "r", stdin);
	int n;
	string s;
	cin >> n >> s;
	bool allT = true;
	for (int i = 0; i < n; i++) {
		if (s[i] != 'T') {
			allT = false;
			break;
		}
	}
	if (allT) {
        double ans = 2 * n + 1;
		cout << fixed << ans << "\n";
		return 0;
	}
	if (s[0] == 'S' && s[n - 1] == 'S') {
	    double ans = 2 * n + 2;
		cout << fixed << ans << "\n";
		return 0;
	}
	const double r = 1.0 / 2.0;
    const double h = sqrt(3.0) / 2.0;
	if (s[0] == 'C' && s[n - 1] == 'C') {
        double ans = 2.0 * ((double)(n - 1)) + 2.0 * M_PI * r;
		cout << fixed << ans << "\n";
		return 0;
	}
	if ((s[0] == 'C' && s[n - 1] == 'S') || (s[0] == 'S' && s[n - 1] == 'C')) {
        double ans = 2.0 * ((double)n - 1.0) + 2.0 + M_PI * r;
		cout << fixed << ans << "\n";
		return 0;
	}

	double ans = 0.0;
	int pos1 = -1;
	if (s[0] == 'T') {
		int pos = 0;
		while (s[pos] == 'T') {
			pos++;
		}
		pos1 = pos;
		if (s[pos] == 'C') {
			double dx = pos;
			double dy = h - r;
			double d = sqrt(dx * dx + dy * dy);
			double a1 = atan(dy / dx);
			double a2 = acos(r / d);
			double a = M_PI / 2.0 - a1 - a2;
			double d2 = sqrt(d * d - r * r);
			ans += d2 + a * r;
		} else {
			double dy = 1.0 - h;
			double dx = pos - 0.5;
			double d = sqrt(dx * dx + dy * dy);
			ans += d + 0.5;
		}
		if (s[n - 1] != 'T') {
			ans += (double)(n - 1 - pos);
			if (s[n - 1] == 'C') {
				ans += M_PI * r;
			} else {
				ans += 2.0;
			}
			ans += (double)n - 1.0 + 1.5;
			cout << fixed << ans << "\n";
			return 0;
		}
	}
	int pos2 = -1;
	if (s[n - 1] == 'T') {
		int pos = n - 1;
		while (s[pos] == 'T') {
			pos--;
		}
		pos2 = pos;
		if (s[pos] == 'C') {
			double dx = n - 1 - pos;
			double dy = h - r;
			double d = sqrt(dx * dx + dy * dy);
			double a1 = atan(dy / dx);
			double a2 = acos(r / d);
			double a = M_PI / 2.0 - a1 - a2;
			double d2 = sqrt(d * d - r * r);
			ans += d2 + a * r;
		} else {
			double dy = 1.0 - h;
			double dx = (double)n - 1.0 - (double)pos - 0.5;
			double d = sqrt(dx * dx + dy * dy);
			ans += d + 0.5;
		}
		if (s[0] != 'T') {
			ans += (double)pos;
			if (s[0] == 'C') {
				ans += M_PI * r;
			} else {
				ans += 2.0;
			}
			ans += (double)n - 1.0 + 1.5;
			cout << fixed << ans << "\n";
			return 0;
		}
	}
	ans += (double)(pos2 - pos1);
	ans += (double)(n + 2.0);
	cout << fixed << ans << "\n";
}
