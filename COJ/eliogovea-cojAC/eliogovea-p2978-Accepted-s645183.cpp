#include <iostream>
//#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int tar;
string str, sol, aux;
vector<int> v;

inline int pw(int a, int b) {
	int r = 1;
	while (b--) r *= a;
	return r;
}

int main() {
	//freopen("e.in", "r", stdin);
	ios::sync_with_stdio(false);
	aux.resize(5);
	while (cin >> tar >> str) {
    if (tar == 0 && str == "END") break;
		int s = str.size();
		v.resize(s);
		sol.clear();
		bool ok = false;
		for (int i = 0; i < s; i++)
			v[i] = (i < 5) ? i + 1 : 0;
    sort(v.begin(), v.end());
		do {
			int sum = 0;
			for (int i = 0, tmp; i < s; i++)
				if (v[i]) {
					tmp = pw(str[i] - 'A' + 1, v[i]);
					if (!(v[i] & 1)) tmp = -tmp;
					sum += tmp;
				}
			if (sum == tar) {
				ok = true;
				for (int i = 0; i < s; i++)
					if (v[i]) aux[v[i] - 1] = str[i];
        if (aux > sol) sol = aux;
			}
		} while (next_permutation(v.begin(), v.end()));

		if (ok) cout << sol << '\n';
		else cout << "no solution\n";
	}
}
