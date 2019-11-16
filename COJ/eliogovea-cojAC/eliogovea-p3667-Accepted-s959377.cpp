#include <bits/stdc++.h>

using namespace std;

const int MOD1 = 1000000007;
const int MOD2 = 1000000047;

const int BASE1 = 59;
const int BASE2 = 67;

inline void add(int &a, int b, const int MOD) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

inline int mul(int a, int b, const int MOD) {
	return (long long)a * b % MOD;
}

const int N = 2000005;

int POW1[N], POW2[N];
int HASH1[N], HASH2[N];

inline int getHASH(int *HASH, int *POW, int s, int e, const int MOD) {
	int res = HASH[e];
	add(res, MOD - mul(HASH[s], POW[e - s], MOD), MOD);
	return res;
}

inline int val(char ch) {
	if (ch >= 'a' && ch <= 'z') {
		return ch - 'a' + 1;
	}
	return 1 + 'z' - 'a' + ch - 'A' + 1;
}

int pattHASH1[2500];
int pattHASH2[2500];

int n;
string s;
char ans[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	POW1[0] = POW2[0] = 1;

	for (int i = 1; i < N; i++) {
        POW1[i] = mul(POW1[i - 1], BASE1, MOD1);
        POW2[i] = mul(POW2[i - 1], BASE2, MOD2);
	}

	cin >> n;
	int size = 0;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (i == 0) {
			size = s.size();
			for (int j = 1; j <= s.size(); j++) {
				ans[j - 1] = s[j - 1];
				HASH1[j] = mul(HASH1[j - 1], BASE1, MOD1); add(HASH1[j], val(s[j - 1]), MOD1);
				HASH2[j] = mul(HASH2[j - 1], BASE2, MOD2); add(HASH2[j], val(s[j - 1]), MOD2);
			}
			continue;
		}
		int len = 0;
		for (int j = 1; j <= s.size(); j++) {
			pattHASH1[j] = mul(pattHASH1[j - 1], BASE1, MOD1); add(pattHASH1[j], val(s[j - 1]), MOD1);
			pattHASH2[j] = mul(pattHASH2[j - 1], BASE2, MOD2); add(pattHASH2[j], val(s[j - 1]), MOD2);
			if (pattHASH1[j] == getHASH(HASH1, POW1, size - j, size, MOD1)
					&& pattHASH2[j] == getHASH(HASH2, POW2, size - j, size, MOD2)) {
						len = j;
					}
		}
		for (int j = len; j < s.size(); j++) {
			int pos = size + (j - len) + 1;
			ans[pos - 1] = s[j];
			//cout << pos << " " << s[j] << "\n";
			HASH1[pos] = mul(HASH1[pos - 1], BASE1, MOD1); add(HASH1[pos], val(s[j]), MOD1);
			HASH2[pos] = mul(HASH2[pos - 1], BASE2, MOD2); add(HASH2[pos], val(s[j]), MOD2);
		}
		size = size + (s.size() - len);
		//ans[size] = 0;
		//cout << i << " " << s << "\n";
		//cout << len << "\n";
		//cout << size << "\n";
		//cout << ans << "\n";
	}
	ans[size] = 0;
	cout << ans << "\n";
}
