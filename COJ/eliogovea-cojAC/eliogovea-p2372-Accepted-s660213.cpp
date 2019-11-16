#include <cstdio>
#include <vector>

using namespace std;

typedef long long LL;

const int MAXN = 200005;
const LL base = 26, mod = 200003;

int N;
char s[MAXN];
int used[mod], id;
vector<int> M[mod];

LL POW[MAXN], HASH[MAXN];

inline LL getHash(int lo, int hi) {
	LL r = HASH[hi];
	if (lo > 0) r -= HASH[lo - 1];
	if (r < 0) r += mod;
	r = (r * POW[N - 1 - hi]) % mod;
	return r;
}

bool check(int l) {
	for (int i = l - 1; i < N; i++) {
		LL tmp = getHash(i - l + 1, i);
		if (used[tmp] == id) {
			bool esta = false;
			for (int j = 0; j < M[tmp].size(); j++) {
				bool ok = true;
				int x = M[tmp][j];
				for (int k = 0; k < l; k++)
					if (s[i - l + 1 + k] != s[x + k]) {
						ok = false;
						break;
					}
				if (ok) {
					esta = true;
					break;
				}
			}
			if (esta) return true;
		}
		M[tmp].clear();
		used[tmp] = id;
		M[tmp].push_back(i - l + 1);
	}
	return false;
}

int main() {

	//freopen("e.in", "r", stdin);

  scanf("%d%s", &N, &s);

	POW[0] = 1;
	for (int i = 1; i < N; i++)
		POW[i] = (POW[i - 1] * base) % mod;
	for (int i = 0; i < N; i++) {
		HASH[i] = (POW[i] * (s[i] - 'a')) % mod;
		if (i > 0) HASH[i] = (HASH[i] + HASH[i - 1]) % mod;
	}

	int lo = 0, hi = N, mid;
	while (lo + 1 < hi) {
		id++;
		int mid = (lo + hi + 1) >> 1;
		if (check(mid)) lo = mid;
		else hi = mid;
	}
	printf("%d\n", lo);
}
