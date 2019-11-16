#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000;

bool criba[MAXN + 5];
int mark[MAXN + 5];
vector<int> p;
void Criba() {
	for (int i = 2; i * i <= MAXN; i++)
		if (!criba[i])
			for (int j = i * i; j <= MAXN; j += i)
				criba[j] = 1;

	p.push_back(2);
	for (int i = 3; i <= MAXN; i += 2)
		if (!criba[i]) p.push_back(i);

    for (int i = 1; p[i] + p[i - 1] + 1 <= MAXN; i++)
        if (!criba[ p[i] + p[i - 1] + 1 ])
            mark[p[i] + p[i - 1] + 1] = 1;
	for (int i = 2; i <= MAXN; i++)
		mark[i] += mark[i - 1];
}
int n, k;

int main() {
	Criba();
	scanf("%d%d", &n, &k);
	printf("%s\n", (mark[n] >= k) ? "YES" : "NO");
}
