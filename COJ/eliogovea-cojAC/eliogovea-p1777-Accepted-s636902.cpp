#include <iostream>

using namespace std;

int n;
bool a[10005];

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = n, x; i; i--) {
		cin >> x;
		a[x] = 1;
	}
	for (int i = n; i >= 1; i--)
    if (a[i]) n--;
  cout << n << '\n';
}
