#include <bits/stdc++.h>

using namespace std;

int t;
double n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(false);
	cin >> t;
	while (t--) {
        cin >> n;
        int ans = 1 + (int)log(n);
        cout << ans << "\n";
	}

}
