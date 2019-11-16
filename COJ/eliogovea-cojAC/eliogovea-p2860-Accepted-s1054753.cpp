#include <bits/stdc++.h>

using namespace std;

inline int getGrundy(int n) {
	if (n == 0) {
		return 0;
	}
	int x = 1;
	int res = 1;
	while (2 * x <= n) {
		res++;
		x *= 2;
	}
	return res;
}

int solveSlow(int n) {
	if (n & 1) {
		return 1;
	}
	int xorSum = 1 ^ getGrundy(n);
	int result = -1;
	for (int i = 2; i <= n; i++) {
		for (int j = (i + 1) / 2; j <= i; j++) {
			if ((xorSum ^ getGrundy(i) ^ getGrundy(i - j)) == 0) {
				if (result == -1 || j < result) {
                    result = j;
				}
			}
		}
	}
	return result;
}

int solveFast(int n) {
	if (n & 1) {
		return 1;
	}
	int gn = getGrundy(n);
	int xorSum = 1 ^ gn;
	int result = -1;
	for (int gx = 2; gx <= gn; gx++) {
		int gy = xorSum ^ gx;
		if (gy < gx) {
			long long x = (1LL << (long long)gx) >> 1LL; // menor numero con grundy = gx
			long long minY = (1LL << (long long)gy) >> 1LL;
			long long maxY = min(x >> 1LL, max(0LL, (minY << 1LL) - 1LL)); //  mayor numero que puede ser y
			if (minY <= maxY) {
                long long diff = x - maxY;
				if (result == -1LL || diff < result) {
					result = diff;
				}
			}
		}
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	while (cin >> n) {
        cout << solveFast(n) << "\n";
	}
}
