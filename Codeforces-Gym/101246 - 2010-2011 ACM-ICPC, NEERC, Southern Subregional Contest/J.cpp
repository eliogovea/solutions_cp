// 2010-2011 ACM-ICPC, NEERC, Southern Subregional Contest
// 101246J

#include <bits/stdc++.h>

using namespace std;



int n;
double x[450];

double ans;
double xAns[450];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

    //freopen("dat.txt", "r", stdin);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}



	for (int i = 0; i < n; i++) {
		double lo = 0;
		double hi = 400.0 * 2.0 * 10000.0;
		double d, a, b, fa, fb;
		for (int it = 0; it < 400; it++) {
			d = (hi - lo) / 3.0;
			a = lo + d;
			b = hi - d;
			fa = 0.0;
			fb = 0.0;
			for (int j = 0; j < n; j++) {
				fa += abs(x[i] + ((double)(j - i)) * a - x[j]);
				fb += abs(x[i] + ((double)(j - i)) * b - x[j]);
			}
			if (fa > fb) {
				lo = a;
			} else {
				hi = b;
			}
		}
		double val = (lo + hi) / 2.0;
		double f = 0.0;
		for (int j = 0; j < n; j++) {
			f += abs(x[i] + (double)(j - i) * val - x[j]);
		}
		if (i == 0 || f < ans) {
			ans = f;
			for (int j = 0; j < n; j++) {
				xAns[j] = x[i] + ((double)(j - i)) * val;
			}
		}
	}
	cout.precision(10);
	cout << fixed << ans << "\n";
	for (int i = 0; i < n; i++) {
		cout << fixed << xAns[i];
		if (i + 1 < n) {
            cout << " ";
		}
	}
	cout << "\n";
}
