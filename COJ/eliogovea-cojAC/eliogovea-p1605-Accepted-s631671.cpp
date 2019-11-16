#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> GC[15];

int main() {
	ios::sync_with_stdio(false);
	//freopen("e.in", "r", stdin);
	GC[1].push_back(0);
	GC[1].push_back(1);
	for (int i = 2; i <= 13; i++) {
		for (int j = 0; j < GC[i - 1].size(); j++)
			GC[i].push_back(GC[i - 1][j]);
		for (int j = GC[i - 1].size() - 1; j >= 0; j--)
			GC[i].push_back((1 << (i - 1)) | GC[i - 1][j]);
	}
	while (cin >> n && n) {
		string r = "";
		for (int i = GC[n].size() - 1; i >= 0; i--)
			for (int j = 0; j < n; j++) {
				if (GC[n][i] & (1 << j)) r += '1';
				else r += '0';
			}
		reverse(r.begin(), r.end());
		cout << r << '\n';
	}
}
