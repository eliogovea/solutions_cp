#include <iostream>
#include <algorithm>

using namespace std;

int n;
string s[205];

struct triple {
  int a, b, c;
  int diff;
  triple() {
    a = 1000, b = 1000, c = 1000;
    diff = 100;
  }
  triple(int aa, int bb, int cc) {
    a = aa; b = bb; c = cc;
    diff = 0;
    for (int i = 0; i < 20; i++) {
      if (s[a][i] != s[b][i]) diff++;
      if (s[a][i] != s[c][i]) diff++;
      if (s[b][i] != s[c][i]) diff++;
    }
  }
  bool operator < (const triple &T) const {
    if (diff != T.diff) return diff < T.diff;
    if (a != T.a) return a < T.a;
    if (b != T.b) return b < T.b;
    return c < T.c;
  }
} tmp, sol;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> s[i];
	sort(s, s + n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++)
			for (int k = 0; k < j; k++)
        if (s[i] != s[j] && s[i] != s[k] && s[j] != s[k]) {
          tmp = triple(k, j, i);
          if (tmp < sol) sol = tmp;
        }
	cout << sol.diff << "\n"
       << s[sol.a] << "\n"
       << s[sol.b] << "\n"
       << s[sol.c] << "\n";
}
