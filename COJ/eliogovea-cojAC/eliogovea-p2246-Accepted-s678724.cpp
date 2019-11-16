//============================================================================
// Name        : 2246.cpp
// Author      : eliogovea
// Version     :
// Copyright   : 
// Description :
//============================================================================

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

LL n, t1, t2;

int main() {
	cin >> n >> t1 >> t2;
	LL lo = 0LL, hi = 1LL << 60LL, mid, fmid, cnt, time;
	while (lo + 1LL < hi) {
		mid = (lo + hi + 1LL) >> 1LL;
		fmid = (mid / t1) + (mid / t2);
		if (fmid >= n) {
			hi = mid;
			cnt = fmid;
			if (hi % t1) cnt++;
			if (hi % t2) cnt++;
			time = hi;
			if (hi % t1) time = max(time, hi + t1 - (hi % t1));
			if (hi % t2) time = max(time, hi + t2 - (hi % t2));
		}
		else lo = mid;
	}
	cout << cnt << " " << time << "\n";
}
