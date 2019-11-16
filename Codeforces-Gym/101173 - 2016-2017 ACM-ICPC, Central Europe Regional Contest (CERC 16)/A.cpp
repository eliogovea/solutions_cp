// 2016-2017 ACM-ICPC, Central Europe Regional Contest (CERC 16)
// 101173A

#include <bits/stdc++.h>

using namespace std;

int r, c;
string s[200];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> s[i];
	}
	char x = s[0][0];
	int a, b;
	for (int i = 1; i < r; i++) {
		if (s[i][0] == x && s[i][1] == x) {
			a = i - 1;
			break;
		}
	}
	for (int i = 1; i < c; i++) {
		if (s[0][i] == x && s[1][i] == x) {
			b = i - 1;
			break;
		}
	}
	set <string> S;
	for (int i = 1; i < r; i += a + 1) {
		for (int j = 1; j < c; j += b + 1) {
			string s1, s2, s3, s4;
			for (int ii = 0; ii < a; ii++) {
				for (int jj = 0; jj < b; jj++) {
					s1 += s[i + ii][j + jj];
				}
				s1 += '$';
			}
			for (int jj = b - 1; jj >= 0; jj--) {
				for (int ii = 0; ii < a; ii++) {
					s2 += s[i + ii][j + jj];
				}
				s2 += '$';
			}
			for (int ii = a - 1; ii >= 0; ii--) {
				for (int jj = b - 1; jj >= 0; jj--) {
					s3 += s[i + ii][j + jj];
				}
				s3 += '$';
			}
			for (int jj = 0; jj < b; jj++) {
				for (int ii = a - 1; ii >= 0; ii--) {
					s4 += s[i + ii][j + jj];
				}
				s4 += '$';
			}
			S.insert(min(s1, min(s2, min(s3, s4))));
		}
	}
	cout << S.size() << "\n";
}
