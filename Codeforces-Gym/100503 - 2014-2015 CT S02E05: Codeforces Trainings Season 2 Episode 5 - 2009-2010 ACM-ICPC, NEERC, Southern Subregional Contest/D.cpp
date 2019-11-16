// 2014-2015 CT S02E05: Codeforces Trainings Season 2 Episode 5 - 2009-2010 ACM-ICPC, NEERC, Southern Subregional Contest
// 100503D

#include <bits/stdc++.h>

using namespace std;

const int INF = 20000000;

typedef long long LL;

LL a, b, c;

inline LL f(LL x) {
	return (a * x + x % b) % c;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	//freopen("dat.txt", "r", stdin);

	cin >> a >> b >> c;

	LL x = 0, fx = 1;
	LL y = 0, fy = 1;
	do {
		fx = f(fx); x++;
		fy = f(f(fy)); y += 2;
	} while (fx != fy && x <= INF);

	if (x > INF) {
        cout << "-1\n";
        return 0;
	}

	x = 0;
	fx = 1;
	while (fx != fy && x <= INF) {
		fx = f(fx); x++;
		fy = f(fy);
	}
	do {
        fx = f(fx); x++;
	} while (fx != fy && x <= INF);

	if (x >= INF) {
		cout << "-1\n";
	} else {
		cout << x << "\n";
	}
}
