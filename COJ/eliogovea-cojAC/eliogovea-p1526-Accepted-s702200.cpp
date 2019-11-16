#include <iostream>
#include <algorithm>
#include <set>
#include <cassert>

using namespace std;

typedef long long LL;

string ch;
LL n, k, x, a[25];
LL f[25];
set<int> S;
set<int>::iterator it;

int main() {
	cin >> n >> k;
	f[0] = 1;
	for (LL i = 1; i <= n; i++) f[i] = f[i - 1] * i;
	while (k--) {
		cin >> ch;
		if (ch[0] == 'P') {
			cin >> x;
			S.clear();
			for (int i = 1; i <= n; i++) S.insert(i);
			for (int i = 1; i < n; i++) {
				it = S.begin();
				while (x > f[n - i]) {
					x -= f[n - i];
					it++;
				}
				cout << *it << " ";
				S.erase(it);
			}
			cout << *S.begin() << "\n";
		} else {
			for (int i = 1; i <= n; i++)
				cin >> a[i];
			S.clear();
			LL ret = 1;
			for (int i = 1; i <= n; i++) S.insert(i);
			for (int i = 1; i <= n; i++) {
				it = S.find(a[i]);
				LL tmp = distance(S.begin(), it);
				ret += tmp * f[n - i];
				S.erase(it);
			}
			
			cout << ret << "\n";
		}
	}
}
