// 2014-2015 ACM-ICPC, NEERC, Southern Subregional Contest
// 100513G

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	int k, n;
	cin >> n >> k;
	vector <long long> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	long long mn = v[0];
	for (int i = 1; i < n; i++) {
		mn = min(mn, v[i]);
	}
	vector <long long> s(n);
	int b = 0;
	int e = 0;
	long long curSum = 0;
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		curSum += v[i];
		s[e++] = i;
		//cerr << "check sum start: " << i << " " << curSum << "\n";
		if (i >= k - 1) {
			while (curSum >= 0 && b < e) {
				if (v[s[e - 1]] - mn > curSum) {
					v[s[e - 1]] -= (curSum + 1LL);
					ans += (curSum + 1LL);
					//cerr << "change: " << s[e - 1] << " " << (curSum + 1) << "\n";
					curSum = -1;
					if (v[s[e - 1]] == mn) {
						e--;
					}
				} else {
					curSum -= v[s[e - 1]] - mn;
					ans += v[s[e - 1]] - mn;
					cerr << "change: " << s[e - 1] << " " << v[s[e - 1]] - mn << "\n";
					v[s[e - 1]] = mn;
					e--;
				}
			}
			//cerr << "check sum end: " << i << " " << curSum << "\n";
			if (s[b] == i - k + 1) {
				b++;
			}
			curSum -= v[i - k + 1];
			//cerr << "check sum end: " << i << " " << curSum << "\n";
		}

	}
	cout << ans << "\n";
	for (int i = 0; i < n; i++) {
		cout << v[i];
		if (i + 1 < n) {
			cout << " ";
		}
	}
	cout << "\n";
}
