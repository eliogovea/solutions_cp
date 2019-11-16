#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000000;

int n, a[2005];
bool criba[MAXN + 5];
vector<int> p;
void Criba() {
	for (int i = 2; i * i <= MAXN; i++)
		if (!criba[i])
			for (int j = i * i; j <= MAXN; j += i)
				criba[j] = 1;
	p.push_back(2);
	for (int i = 3; i <= MAXN; i += 2)
		if (!criba[i]) p.push_back(i);
}

map<int, int> M;
map<int, int>::iterator it;
vector<int> f[2005];
vector<int>::iterator vit;
int sol, act;

int main() {
	Criba();
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	int p1 = 0, p2 = 0;
	while (p1 <= n) {
			bool rep = false;
			for (it = M.begin(); it != M.end(); it++)
				if (it->second  > 1) {
					rep = true;
					break;
				}
			if (rep) {
				for (vit = f[p2].begin(); vit != f[p2].end(); vit++)
					M[*vit]--;
				p2++;
			}
			else {
				sol = max(sol, p1 - p2);
				if (p1 == n) break;

				for (int i = 0; p[i] * p[i] <= a[p1]; i++)
					if (a[p1] % p[i] == 0) {
						f[p1].push_back(p[i]);
						M[p[i]]++;
						while (a[p1] % p[i] == 0) a[p1] /= p[i];
					}
				if (a[p1] > 1) f[p1].push_back(a[p1]), M[a[p1]]++;
				p1++;
			}
	}
	printf("%d\n", sol);
}
