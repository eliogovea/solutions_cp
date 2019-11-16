#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	long long n;
	cin >> n;
	if (n % 3LL == 0LL) {
		cout << "Victor wins\n";
	} else {
		cout << "Kedir wins\n";
	}
}