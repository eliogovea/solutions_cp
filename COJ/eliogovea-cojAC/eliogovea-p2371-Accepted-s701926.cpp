#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;

const LL lim = 1e9;

int tc;
LL a, b, ans;
vector<LL> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	v.push_back(1);
	for (LL i = 2; i * i <= lim; i++)
		for (LL p = i * i; p <= lim; p *= i)
			v.push_back(p);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	cin >> tc;
	for (int c = 1; c <= tc; c++){
		cin >> a >> b;
		if (a > b) {
			LL tmp = a;
			a = b;
			b = tmp;
		}
		ans = upper_bound(v.begin(), v.end(), b) -
				lower_bound(v.begin(), v.end(), a);
		cout << "Case " << c << ": " << ans << "\n";
	}
}
