#include <cstdio>
#include <queue>

using namespace std;

const int N = 200005;

int n;
char a[N], b[N];
int Q[N], qh, qt;

int first[N];

int bit[N];

void update(int p) {
    while (p <= n) {
        bit[p]++;
        p += p & -p;
    }
}

int query(int p) {
    int res = 0;
    while (p > 0) {res += bit[p]; p -= p & -p;}
    return res;
}

int ans[N];

int main() {
	scanf("%d%s%s", &n, a, b);
	int posa = 0;
	int posb = 0;
	int cola = 0;
	while (posb < n) {
		while (qh != qt && a[Q[qh]] == b[posb]) {
			ans[Q[qh]] = query(n) - query(Q[qh]);
			update(Q[qh] + 1);
			qh++;
			posb++;
			cola++;
			continue;
		}
		if (posa < n && a[posa] == b[posb]) {
			posa++; posb++;
			update(posa);
		} else if (posa < n && a[posa] != b[posb]){
			Q[qt++] = posa++;
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d\n", ans[i]);
	}
}
