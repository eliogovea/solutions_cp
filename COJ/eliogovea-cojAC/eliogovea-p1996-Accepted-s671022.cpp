//============================================================================
// Name        : 1996.cpp
// Author      : eliogovea
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

const int MAXN = 1000000;

bool criba[MAXN + 5];
vector<int> p;
int pos[MAXN + 5];

int main() {
	for (int i = 2; i * i <= MAXN; i++)
		if (!criba[i])
			for (int j = i * i; j <= MAXN; j += i)
				criba[j] = true;
	pos[2] = p.size(); p.push_back(2);
	for (int i = 3; i <= MAXN; i += 2)
		if (!criba[i]) {
			pos[i] = p.size();
			p.push_back(i);
		}
	int sz = p.size();
	vector<int> v(sz);
	int tc, n, m;
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> tc;
	for (int cas = 1; cas <= tc; cas++) {
		for (int i = 0; i < sz; i++) v[i] = 0;
		cin >> n >> m;
		for (int i = 0, x; i < n; i++) {
			cin >> x;
			for (int i = 0; p[i] * p[i] <= x; i++)
				while (x % p[i] == 0) {
					v[i]++;
					x /= p[i];
				}
			if (x > 1) v[pos[x]]++;
		}
		for (int i = 0, x; i < m; i++) {
			cin >> x;
			for (int i = 0; p[i] * p[i] <= x; i++)
				while (x % p[i] == 0) {
					v[i]--;
					x /= p[i];
				}
			if (x > 1) v[pos[x]]--;
		}
		int num = 1, den = 1;
		for (int i = 0; i < sz; i++)
			if (v[i] > 0) num *= pow(p[i], v[i]);
			else if (v[i] < 0) den *= pow(p[i], -v[i]);
		cout << "Case #" << cas << ": "<< num << " / " << den << "\n";
	}
}
