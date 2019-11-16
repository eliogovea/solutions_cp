// 3071 - Theatre Square

#include <iostream>

using namespace std;

long long n, m, a, ans;

int main() {
	cin >> n >> m >> a;
	ans = (n / a) * (m / a);
	if (n % a != 0LL) ans += (m / a);
	if (m % a != 0LL) ans += (n / a);
	if ((n % a != 0LL) && (m % a != 0LL)) ans++;
	cout << ans << "\n";
}
