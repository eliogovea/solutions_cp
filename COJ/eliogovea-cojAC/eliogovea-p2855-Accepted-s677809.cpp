//============================================================================
// Name        : 2855.cpp
// Author      : eliogovea
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

using namespace std;

typedef long long LL;

LL f[15], d[15];
string s;

LL calc() {
	LL size = 0LL;
	for (int i = 0; i < 10; i++) size += d[i];
	LL per = f[size];
	for (int i = 0; i < 10; i++) per /= f[d[i]];
	LL sum = 0;
	for (LL i = 0; i < 10; i++)
		sum += i * per * d[i] / size;
	LL ret = 0LL;
	for (int i = 0; i < size; i++)
		ret = 10LL * ret + sum;
	return ret;
}

int main() {
	f[0] = 1;
	for (LL i = 1; i <= 11; i++) f[i] = i * f[i - 1];
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while (cin >> s && s[0] != '0') {
		for (int i = 0; i < 10; i++) d[i] = 0;
		for (int i = 0; s[i]; i++) d[s[i] - '0']++;
		LL ans = calc();
		if (d[0]) {
			d[0]--;
			ans -= calc();
		}
		cout << ans << "\n";
	}
}
