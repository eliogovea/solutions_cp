#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100005, LOGMAXN = 19;

int N, cnt, stp;
string str;

struct entry {
	int nr[2], p;
} L[MAXN];

int P[LOGMAXN][MAXN], suffix_array[MAXN];

pair<int, int> v[MAXN];

bool cmp(entry a, entry b) {
	if (a.nr[0] != b.nr[0]) return a.nr[0] < b.nr[0];
	return a.nr[1] < b.nr[1];
}

void build(string &str) {
	N = str.size();
	for (int i = 0; i < N; i++)
		P[0][i] = str[i] - 'a';
	for (stp = 1, cnt = 1; (cnt >> 1) < N; stp++, cnt <<= 1) {
		for (int i = 0; i < N; i++) {
			L[i].nr[0] = P[stp - 1][i];
			L[i].nr[1] = P[stp - 1][(i + cnt) % N];
			L[i].p = i;
		}
		sort(L, L + N, cmp);
		for (int i = 0; i < N; i++) {
			if (i > 0 && L[i].nr[0] == L[i - 1].nr[0] && L[i].nr[1] == L[i - 1].nr[1])
				P[stp][L[i].p] = P[stp][L[i - 1].p];
			else P[stp][L[i].p] = i;
		}
	}
	for (int i = 0; i < N; i++)
		v[i] = make_pair(P[stp - 1][i], i);
	sort(v, v + N);
}

int main() {
	ios::sync_with_stdio(false);
	cin >> str;
	build(str);
	int k = N - 1;
	while (k && v[k].first == v[k - 1].first) k--;
	cout << v[k].second << '\n';
}
