//============================================================================
// Name        : 2396.cpp
// Author      : eliogovea
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int dist[22][(1 << 21) + 2];
bool mark[25];
queue<int> Q;

void calc(int c) {
	if (mark[c]) return;
	mark[c] = true;
	for (int i = 0; i < (1 << c); i++) dist[c][i] = -1;
	dist[c][0] = 0;
	Q.push(0);
	int u, aux;
	while (!Q.empty()) {
		u = Q.front(); Q.pop();
		for (int i = 0; i < c; i++) {
			aux = u;
			if (i > 0) aux ^= (1 << (i - 1));
			aux ^= (1 << i);
			if (i < c - 1) aux ^= (1 << (i + 1));
			if (dist[c][aux] == -1) {
				dist[c][aux] = dist[c][u] + 1;
				Q.push(aux);
			}
		}
	}
}

int tc, n;
string s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> tc;
	while (tc--) {
		cin >> n >> s;
		calc(n);
		int tmp = 0;
		for (int i = 0; i < n; i++)
			if (s[i] == '0') tmp |= (1 << i);
		cout << dist[n][tmp] << "\n";
	}
}
