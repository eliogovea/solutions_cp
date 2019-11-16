#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 1005;

struct pt {
	LL x, y;
	pt() {}
	pt(LL _x, LL _y) : x(_x), y(_y) {}
};

bool operator < (const pt &a, const pt &b) {
	if (a.y != b.y) return a.y < b.y;
	return a.x < b.x;
}

inline LL dist2(pt a, pt b) {
	LL dx = a.x - b.x;
	LL dy = a.y - b.y;
	return dx * dx + dy * dy;
}

int sign(LL n) {
	if (n < 0) return -1;
	if (n > 0) return 1;
	return 0;
}

inline LL cross(pt O, pt P1, pt P2) {
	return (P1.x - O.x) * (P2.y - O.y) - (P1.y - O.y) * (P2.x - O.x);
}

pt O;

bool comp(pt a, pt b) {
	int c = sign(cross(O, a, b));
	if (c != 0) return c > 0;
	return dist2(a, O) < dist2(b, O);
}

int n;
pt P[N];
pt CH[2 * N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> P[i].x >> P[i].y;
	}
	sort(P, P + n);
	O = P[0];
	sort(P + 1, P + n, comp);
	int size = 0;
	for (int i = 0; i < n; i++) {
		while (size > 2 && sign(cross(CH[size - 2], CH[size - 1], P[i])) < 0) size--;
		CH[size++] = P[i];
	}
	for (int i = 0; i < size; i++) {
		CH[size + i] = CH[i];
	}
	LL ans = 0;
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			int lo = i + 1;
			int hi = j;
			int best1 = lo;
			while (lo <= hi) {
				int mid = (lo + hi) >> 1;
				if (abs(cross(CH[i], CH[j], CH[mid])) > abs(cross(CH[i], CH[j], CH[mid - 1]))) {
					best1 = mid;
					lo = mid + 1;
				} else {
					hi = mid - 1;
				}
			}
			ans = max(ans, abs(cross(CH[i], CH[j], CH[best1])));
			lo = j + 1;
			hi = i + size;
			int best2 = lo;
			while (lo <= hi) {
				int mid = (lo + hi) >> 1;
				if (abs(cross(CH[i], CH[j], CH[mid])) >  abs(cross(CH[i], CH[j], CH[mid - 1]))) {
					best2 = mid;
					lo = mid + 1;
				} else {
					hi = mid - 1;
				}
			}
			ans = max(ans, abs(cross(CH[i], CH[j], CH[best2])));
		}
	}
	cout.precision(1);
	cout << fixed << 0.5 * (double)ans << "\n";
}
