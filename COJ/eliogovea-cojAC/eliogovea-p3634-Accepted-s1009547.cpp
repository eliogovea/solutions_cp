#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	long long n;
	long long t;
	char d;
	string a, b, c;

	while (cin >> n >> t >> d) {
        getline(cin, a);
        getline(cin, a);
        getline(cin, b);
        getline(cin, c);

        string s;
        for (int i = 1; i < b.size(); i += 2) {
            s += b[i];
        }

        long long start;
        if (d == 'L') {
            start = t % n;
        } else {
            start = n - (t % n);
        }
        cout << a << "\n";
        cout << "|";
        for (int i = 0; i < n; i++) {
            cout << s[(start + i) % n] << "|";
        }
        cout << "\n";
        cout << c << "\n";
	}
}
