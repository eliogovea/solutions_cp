#include <iostream>

using namespace std;

int n, k, l[300005];
long long cnt[22][300005], ans;
string s;

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		l[i] = s.size();
		for (int j = 2; j <= 20; j++) {
			cnt[j][i] = cnt[j][i - 1];
		}
		cnt[l[i]][i]++;
		ans += cnt[l[i]][i - 1] - cnt[l[i]][max(i - k - 1, 0)];
	}
	cout << ans << "\n";
}
