#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100005, LOGMAXN = 20;

int N, stp, cnt, k;
string str;

struct entry {
	int nr[2], p;
} L[MAXN];

bool cmp(entry a, entry b) {
	return (a.nr[0] == b.nr[0]) ? (a.nr[1] < b.nr[1]) : (a.nr[0] < b.nr[0]);
}

int P[LOGMAXN][MAXN];

void build() {
	N = str.size();
	for (int i = 0; i < N; i++)
		P[0][i] = str[i] - 'A';
	for (stp = 1, cnt = 1; (cnt >> 1) < N; stp++, cnt <<= 1) {
		for (int i = 0; i < N; i++) {
			L[i].nr[0] = P[stp - 1][i];
			L[i].nr[1] = P[stp - 1][(i + cnt) % N];
			L[i].p = i;
		}
		sort(L, L + N, cmp);
		for (int i = 0; i < N; i++) {
			P[stp][L[i].p] = (i > 0 && L[i].nr[0] == L[i - 1].nr[0]
			 && L[i].nr[1] == L[i - 1].nr[1]) ? P[stp][L[i - 1].p] : i;
		}
	}
}

pair<int, int> v[MAXN];

int main() {
	cin >> str >> k;
	k--;
	build();
	for (int i = 0; i < N; i++)
		v[i] = make_pair(P[stp - 1][i], i);
	sort(v, v + N);
	while (k && v[k].first == v[k - 1].first) k--;
	cout << v[k].second << ' ';
	for (int i = v[k].second, j = 0; j < N; j++)
		cout << str[(i + j) % N];
	cout << '\n';
}
