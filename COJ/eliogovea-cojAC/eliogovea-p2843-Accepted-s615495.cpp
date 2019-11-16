#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, mx, cant;
vector<int> v;
vector<int>::iterator it;

int main() {
	while (cin >> n) {
		for (it = v.begin(); it != v.end(); it++)
			mx = max(mx, __gcd(*it, n));
		v.push_back(n);
		cant++;
	}
	if (cant == 1) cout << n << endl;
	else cout << mx << endl;
}
