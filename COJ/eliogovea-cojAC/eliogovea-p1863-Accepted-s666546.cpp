//============================================================================
// Name        : 1863.cpp
// Author      : eliogovea
// Version     :
// Copyright   : 
// Description :
//============================================================================

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

LL N, B, ans;
pair<LL, LL> C[100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> B;
	for (int i = 0; i < N; i++)
		cin >> C[i].first >> C[i].second;
	sort(C, C + N);
	for (int i = 0; i < N; i++)
		if (B / C[i].first >= C[i].second) {
			B -= C[i].first * C[i].second;
			ans += C[i].second;
		} else {
			ans += B / C[i].first;
			break;
		}
	cout << ans << "\n";
}
