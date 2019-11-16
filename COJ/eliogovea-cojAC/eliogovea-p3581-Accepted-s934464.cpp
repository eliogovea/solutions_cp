#include <bits/stdc++.h>

using namespace std;

const int MAXL = 10005;

vector <int> mask_from[15][15];
vector <int> carry_from[15][15];
vector <int> mask_to[15][15];
vector <int> carry_to[15][15];

void prepare() {
	for (int mask = 0; mask < 8; mask++) {
		for (int carry = 0; carry < 3; carry++) {
			for (int a = 0; a < 10; a++) {
				if (a != 3) {
					for (int b = 0; b < 10; b++) {
						if (b != 3) {
							for (int c = 0; c < 10; c++) {
								if (c != 3) {
									int ndigit = (a + b + c + carry) % 10;
									for (int ldigit = 0; ldigit < 10; ldigit++) {
										int next_mask = 0;
										if ((a > ldigit) || ((a == ldigit) && (mask & 1))) {
											next_mask |= 1;
										}
										if ((b > ldigit) || ((b == ldigit) && (mask & 2))) {
											next_mask |= 2;
										}
										if ((c > ldigit) || ((c == ldigit) && (mask & 4))) {
											next_mask |= 4;
										}
										int next_carry = (a + b + c + carry) / 10;
										mask_from[ndigit][ldigit].push_back(mask);
										carry_from[ndigit][ldigit].push_back(carry);
										mask_to[ndigit][ldigit].push_back(next_mask);
										carry_to[ndigit][ldigit].push_back(next_carry);
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

const int MOD = 12345647;

inline void add(int &a, int b) {
	if ((a += b) >= MOD) {
		a -= MOD;
	}
}

string sn, sl;

int dp[3][10][MAXL];

int solve() {
	int szn = sn.size();
	int szl = sl.size();
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 8; j++) {
			for (int k = 0; k <= szn; k++) {
				dp[i][j][k] = 0;
			}
		}
	}
	reverse(sn.begin(), sn.end());
	reverse(sl.begin(), sl.end());
	for (int i = szl; i < szn; i++) {
		sl += '0';
	}
	for (int i = 0; i < szn; i++) {
		sn[i] -= '0';
		sl[i] -= '0';
	}
	dp[0][7][0] = 1;
	for (int i = 0; i < szn; i++) {
		int sz = mask_from[sn[i]][sl[i]].size();
		for (int j = 0; j < sz; j++) {
			add(dp[carry_to[sn[i]][sl[i]][j]][mask_to[sn[i]][sl[i]][j]][i + 1], dp[carry_from[sn[i]][sl[i]][j]][mask_from[sn[i]][sl[i]][j]][i]);
		}
	}
	return dp[0][7][szn];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	prepare();
	while (cin >> sn >> sl) {
		if (sn == "0" && sl == "0") {
			break;
		}
		cout << solve() << "\n";
	}
}
