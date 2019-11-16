#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

long long k, l;

int main() {
	//freopen("dat.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> l >> k;
	long long lo = 1, hi = l * l / k;
	long long ans = lo;
	long long mid, sum;
	long long last;
	while (lo <= hi) {
		mid = (lo + hi) >> 1;
		bool ok = true;
		sum = 0;
		last = 0;
		for (int i = 0; i < k; i++) {
            if (l - last < k - i) {
                ok = false;
                break;
            }
            if (last < k && (2 * last + 1 >= mid) && l - last >= k - i) {
                break;
            }
			sum += mid;
			last = sqrt(sum);
			if (last * last < sum) last++;
			if (last > l) {
				ok = false;
				break;
			}
			sum = last * last;
		}
		if (ok) {
			ans = mid;
			lo = mid + 1LL;
		} else {
			hi = mid - 1LL;
		}
	}
	cout << ans << "\n";
}
