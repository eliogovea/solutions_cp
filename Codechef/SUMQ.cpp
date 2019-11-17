#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

inline void add(int &a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

inline int mul(int a, int b) {
	return (long long)a * b % MOD;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int sa, sb, sc;
		cin >> sa >> sb >> sc;

		vector <int> va(sa);
		for (int i = 0; i < sa; i++) {
			cin >> va[i];
		}
		vector <int> vb(sb);
		for (int i = 0; i < sb; i++) {
			cin >> vb[i];
		}
		vector <int> vc(sc);
		for (int i = 0; i < sc; i++) {
			cin >> vc[i];
		}
		sort(va.begin(), va.end());
		sort(vb.begin(), vb.end());
		sort(vc.begin(), vc.end());

		int pa = 0;
		int pc = 0;

		int suma = 0;
		int sumc = 0;

		int answer = 0;

		for (int i = 0; i < vb.size(); i++) {
			while (pa < sa && va[pa] <= vb[i]) {
				add(suma, va[pa]);
				pa++;
			}
			while (pc < sc && vc[pc] <= vb[i]) {
				add(sumc, vc[pc]);
				pc++;
			}
			add(answer, mul(mul(vb[i], vb[i]), mul(pa, pc)));
			add(answer, mul(vb[i], mul(pc, suma)));
			add(answer, mul(vb[i], mul(pa, sumc)));
			add(answer, mul(suma, sumc));
		}

		cout << answer << "\n";
	}
}

/*
1
3 1 3
1 2 3
5
4 5 6

399
*/

