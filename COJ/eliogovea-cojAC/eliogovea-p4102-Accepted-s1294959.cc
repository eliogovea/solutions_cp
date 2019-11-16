#include <bits/stdc++.h>

using namespace std;

const int A = 'z' - 'a' + 1;

const int M = 1000 * 1000 * 1000 + 7;

inline void add(int & a, int b) {
	a += b;
	if (a >= M) {
		a -= M;
	}
}

inline int mul(int a, int b) {
	return (long long)a * b % M;
}

int n;
string s;
map <char, int> last;
vector <int> pos;

const int N = 100 * 1000 + 10;
int p[N];
int sp[N];

int t[50][50];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> s;

	p[0] = 1;
	for (int i = 1; i <= n; i++) {
		p[i] = mul(p[i - 1], A);
	}

	for (int i = 0; i <= n; i++) {
		sp[i] = p[i];
		if (i > 0) {
			add(sp[i], sp[i - 1]);
		}
	}

	map <char, int> last;
	for (int i = 0; i < n; i++) {
		last[s[i]] = i;
	}

	vector <int> pos;
	for (auto i : last) {
		pos.push_back(i.second);
	}

	for (int i = 0; i <= pos.size(); i++) {
		t[i][0] = t[i][i] = 1;
		for (int j = 1; j < i; j++) {
			t[i][j] = t[i - 1][j - 1];
			add(t[i][j], t[i - 1][j]);
		}
	}

	sort(pos.begin(), pos.end());

	int answer = 0;

	for (int i = 0; i < (int)pos.size(); i++) {
		int v = 1;

		for (int c = 0; c <= i; c += 2) {
			int v = t[i][c];

			if (c + 1 < n) {
				int x = i + 1 + (A - (int)pos.size());
				if (c + 2 < n) {
					x = mul(x, sp[n - c - 2]);
				}
				add(x, 1);
				v = mul(v, x);	
			}
			add(answer, v);
		}
	}

	cout << answer << "\n";
}
