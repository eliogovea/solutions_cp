#include <iostream>

using namespace std;

const int MAXN = 1000005;

int val(char c) {
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    return 5;
  return 3;
}

string s;
int n, len, pi[MAXN], ac[MAXN];

int prefix(string &s) {
	int len = s.size();
	int mx = 0;
	ac[0] = 0;
	for (int i = 1; i < len; i++) {
    ac[i] = ac[i - 1] + val(s[i]);
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j])
			j = pi[j - 1];
		if (s[i] == s[j]) j++;
		pi[i] = j;
		if (ac[j] > mx) mx = ac[j];
	}
	return mx;
}

int main() {
  ios::sync_with_stdio(false);
	cin >> n;
	while (n--) {
    cin >> s;
    cout << prefix(s) << '\n';
	}
}
