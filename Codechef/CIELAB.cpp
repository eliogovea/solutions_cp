#include <bits/stdc++.h>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a, b;
	cin >> a >> b;
	a -= b;
	if (a % 10 != 9) {
		a++;
	} else {
		a--;
	}
	cout << a << "\n";
}

