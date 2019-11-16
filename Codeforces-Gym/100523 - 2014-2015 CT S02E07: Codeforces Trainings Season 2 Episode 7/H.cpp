// 2014-2015 CT S02E07: Codeforces Trainings Season 2 Episode 7
// 100523H

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	int n;
	string s;
	cin >> n >> s;
	vector <int> H(n, 0);
	vector <int> M(n, 0);
	H[0] = 1;
	M[0] = 1;
	for (int i = 0; i < n - 1; i++) {
		if (s[i] == 'H') {
			H[i + 1]++;
		} else {
			M[i + 1]++;
		}
	}
	for (int i = 1; i < n; i++) {
		H[i] += H[i - 1];
		M[i] += M[i - 1];
	}
	int posH = 0;
	while (H[posH] > 1) {
		if (posH + 1 == H.size()) {
			H.push_back(0);
		}
		H[posH + 1] += H[posH] / 2;
		H[posH] %= 2;
		posH++;
	}
	int posM = 0;
	while (M[posM] > 1) {
		if (posM + 1 == M.size()) {
			M.push_back(0);
		}
		M[posM + 1] += M[posM] / 2;
		M[posM] %= 2;
		posM++;
	}
	if (H.size() > M.size()) {
		cout << "H\n";
	} else if (M.size() > H.size()) {
		cout << "M\n";
	} else {
		bool eq = true;
		for (int i = H.size() - 1; i >= 0; i--) {
			if (H[i] != M[i]) {
                eq = false;
				if (H[i] > M[i]) {
					cout << "H\n";
				} else {
					cout << "M\n";
				}
                break;
			}
		}
		if (eq) {
            cout << "HM\n";
		}
	}
}
