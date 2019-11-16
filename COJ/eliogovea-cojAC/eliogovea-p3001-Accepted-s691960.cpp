//============================================================================
// Name        : 3018.cpp
// Author      : eliogovea
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

using namespace std;

typedef long long LL;

LL n, m, u, d, ans = -1;

inline LL f(LL a) {
	return u * a - d * (n - a);
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> u >> d;
		LL a = (n * d) / (u + d);
		while (f(a) <= 0) a++;
		LL tmp = f(a);
		if (ans == -1LL || tmp < ans) ans = tmp;
	}
	cout << ans << "\n";
}
