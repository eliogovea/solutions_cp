#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 1000001;

int ac[MAXN + 5], n;
bool criba[MAXN + 5];
vector<int> p;

inline void Criba() {
	for (int i = 5; i * i <= MAXN; i += 4)
		if (!criba[i])
			for (int j = i * i; j <= MAXN; j += i)
				criba[j] = 1;
	for (int i = 5; i <= MAXN; i += 4)
		if (!criba[i]) p.push_back(i);
	int ps = p.size();
	long long aux;
	for (int i = 0; i < ps; i++)
		for (int j = 0; j <= i; j++) {
			aux = p[i] * p[j];
			if (aux > MAXN) break;
			ac[aux] = 1;
		}
	for (int i = 1; i <= MAXN; i++)
		ac[i] += ac[i - 1];
}

int main() {
	Criba();
	while (cin >> n && n)
		cout << n << ' ' << ac[n] << '\n';
}
