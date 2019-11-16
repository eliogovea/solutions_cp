#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

const int N = 105;

int tc, n;
double x, p[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout.precision(5);
	cin >> tc;
	while (tc--) {
		cin >> n >> x;
		p[1] = 1.0;
		for (int i = 1; i < n; i++)
			p[i + 1] = p[i] * (1.0 - x) + (1.0 - p[i]) * x;
		cout << fixed << x * p[n] + (1.0 - x) * (1.0 - p[n]) << "\n";
	}
}
