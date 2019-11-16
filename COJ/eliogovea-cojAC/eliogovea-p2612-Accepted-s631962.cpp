/*
	COJ - 2612 - Go up to Ultras
	eliogovea
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005, d = 150000;

int n, H[MAXN], R[MAXN], L[MAXN], MN[28][MAXN];
vector<int> ultra;
set<pair<int, int> > S;

void build() {
	for (int i = 1; i <= n; i++)
		MN[0][i] = H[i];
	for (int i = 1; 1 << i <= n; i++)
		for (int j = 1; j + (1 << i) - 1 <= n; j++)
			MN[i][j] = min(MN[i - 1][j], MN[i - 1][j + (1 << (i  - 1))]);
}

int query(int i, int j) {
	int n = j - i + 1;
	int lg = 31 - __builtin_clz(n);
	return min(MN[lg][i], MN[lg][j + 1 - (1 << lg)]);
}

int main() {
	ios::sync_with_stdio(false);
	//freopen("e.in", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> H[i];
	}
	build();
	S.clear();
	for (int i = 1; i <= n; i++) {
		while (S.size() && S.begin()->first < H[i]) {
			R[S.begin()->second] = i;
			S.erase(S.begin());
		}
		S.insert(make_pair(H[i], i));
	}
	S.clear();
	for (int i = n; i; i--) {
		while (S.size() && S.begin()->first < H[i]) {
			L[S.begin()->second] = i;
			S.erase(S.begin());
		}
		S.insert(make_pair(H[i], i));
	}

	for (int i = 2; i < n; i++)
		if (H[i - 1] < H[i] && H[i + 1] < H[i]) {
			int mn1, mn2;
			if (R[i]) mn1 = query(i, R[i]);
			if (L[i]) mn2 = query(L[i], i);

			if (L[i] && R[i])
				if (H[i] - max(mn1, mn2) >= d)
					ultra.push_back(i);
			if (L[i] && !R[i])
				if (H[i] - mn2 >= d)
					ultra.push_back(i);
			if (!L[i] && R[i])
				if (H[i] - mn1 >= d)
					ultra.push_back(i);
			if (!L[i] && !R[i])
                if (H[i] >= d)
                    ultra.push_back(i);
		}
	for (int i = 0; i < ultra.size(); i++) {
		cout << ultra[i];
		if (i < ultra.size() - 1) cout << ' ';
		else cout << '\n';
	}
}
