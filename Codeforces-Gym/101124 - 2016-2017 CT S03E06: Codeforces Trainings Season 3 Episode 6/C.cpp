// 2016-2017 CT S03E06: Codeforces Trainings Season 3 Episode 6
// 101124C

#include <bits/stdc++.h>

using namespace std;

const string names[] = {"king", "queen", "bishop", "knight", "rook", "pawn"};
const int need[] = {1, 1, 2, 2, 2, 8};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	int k1, k2;
	cin >> k1 >> k2;
	map <string, int> white1, black1, white2, black2;
	for (int i = 0; i < k1; i++) {
		string a, b;
		cin >> a >> b;
		if (a == "white") {
			white1[b]++;
		} else {
			black1[b]++;
		}
	}
	for (int i = 0; i < k2; i++) {
		string a, b;
		cin >> a >> b;
		if (a == "white") {
			white2[b]++;
		} else {
			black2[b]++;
		}
	}
	bool ok = true;
	for (int i = 0; i < 6; i++) {
		if (white1[names[i]] + white2[names[i]] < need[i]) {
			ok = false;
			break;
		}
		if (black1[names[i]] + black2[names[i]] < need[i]) {
			ok = false;
			break;
		}
	}
	if (!ok) {
		cout << "impossible\n";
	} else {
		for (int i = 0; i < 6; i++) {
			if (white1[names[i]] < need[i]) {
				int c = need[i] - white1[names[i]];
				for (int j = 0; j < c; j++) {
					cout << "white " << names[i] << "\n";
				}
			}
			if (black1[names[i]] < need[i]) {
				int c = need[i] - black1[names[i]];
				for (int j = 0; j < c; j++) {
					cout << "black " << names[i] << "\n";
				}
			}
		}
	}
}
