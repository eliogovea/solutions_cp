#include <bits/stdc++.h>

using namespace std;

const int N = 1000000;

string s;
bool criba[N + 5];

const string v[] = {"Neither", "Prime", "Divisible by 6", "Both"};

int main() {
	for (int i = 2; i * i <= N; i++) {
		if (!criba[i]) {
			for (int j = i * i; j <= N; j += i) {
				criba[j] = true;
			}
		}
	}
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	sort(s.begin(), s.end());
	int ans = 0;
	do {
		int x = 0, y = 0;
		for (int i = 0; s[i]; i++) {
			x = 10 * x + s[i] - '0';
		}
		if (!criba[x]) {
			ans |= 1;
		}
		if (x % 6 == 0) {
			ans |= 2;
		}
	} while(next_permutation(s.begin(), s.end()));
	cout << v[ans] << "\n";
}