#include <bits/stdc++.h>

using namespace std;

const int N = 300005;

int n, m;
long long xv[N], yv[N], lv[N];
long long xh[N], yh[N], lh[N];

int bit[N];

inline void clearBit(int sz) {
	for (int i = 0; i <= sz; i++) {
		bit[i] = 0;
	}
}

inline void updateBit(int p, int v, int sz) {
	while (p <= sz) {
		bit[p] += v;
		p += p & -p;
	}
}

inline int queryBit(int p, int sz) {
	int res = 0;
	while (p > 0) {
		res += bit[p];
		p -= p & -p;
	}
	return res;
}

struct event {
	long long x;
	long long y1;
	long long y2;
	int id;
};

bool operator < (const event &a, const event &b) {
	if (a.x != b.x) {
		return a.x < b.x;
	}
	return a.id < b.id;
}

event E[N];
int szE;
long long Y[N];
int szY;

inline long long sweepLine(long long l) {
	szE = 0;
	szY = 0;
	for (int i = 0; i < n; i++) {
		if (lv[i] >= 2LL * l) {
			E[szE].x = xv[i];
			E[szE].y1 = yv[i] + l;
			E[szE].y2 = yv[i] + lv[i] - l;
			E[szE].id = 0;
			szE++;
			Y[szY++] = yv[i] + l;
			Y[szY++] = yv[i] + (lv[i] - l);
		}
	}
	for (int i = 0; i < m; i++) {
		if (lh[i] >= 2LL * l) {
			E[szE].x = xh[i] + l;
			E[szE].y1 = yh[i];
			E[szE].y2 = yh[i];
			E[szE].id = -1;
			szE++;
			E[szE].x = xh[i] + (lh[i] - l);
			E[szE].y1 = yh[i];
			E[szE].y2 = yh[i];
			E[szE].id = 1;
			szE++;
			Y[szY++] = yh[i];
		}
	}
	sort(Y, Y + szY);
	int cy = unique(Y, Y + szY) - Y;
    sort(E, E + szE);
	clearBit(cy);
	long long cnt = 0;
	for (int i = 0; i < szE; i++) {
		if (E[i].id == -1) {
			int pos = lower_bound(Y, Y + cy, E[i].y1) - Y + 1;
			updateBit(pos, 1, cy);
		} else if (E[i].id == 1) {
			int pos = lower_bound(Y, Y + cy, E[i].y1) - Y + 1;
			updateBit(pos, -1, cy);
		} else {
			int pos1 = lower_bound(Y, Y + cy, E[i].y1) - Y + 1;
			int pos2 = lower_bound(Y, Y + cy, E[i].y2) - Y + 1;
			cnt += (long long)queryBit(pos2, cy) - (long long)queryBit(pos1 - 1, cy);
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	while (cin >> n >> m) {
		for (int i = 0; i < n; i++) {
			cin >> xv[i] >> yv[i] >> lv[i];
		}
		for (int i = 0; i < m; i++) {
			cin >> xh[i] >> yh[i] >> lh[i];
		}
		long long lo = 0;
		long long hi = 1000000000 / 2;
		long long ansLen = 0;
		long long ansCnt = 0;
		while (lo <= hi) {
			long long mid = (lo + hi) / 2LL;
			long long val = sweepLine(mid);
			if (val > 0) {
				ansLen = mid;
				ansCnt = val;
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}
		if (ansLen == 0) {
			ansCnt = 0;
		}
		cout << 2LL * ansLen << " " << ansCnt << "\n";
	}
}
