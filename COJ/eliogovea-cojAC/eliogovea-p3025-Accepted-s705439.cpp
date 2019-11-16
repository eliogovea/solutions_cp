#include <iostream>

using namespace std;

const int N = 105;
long long n, b[N];

int main() {
	cin >> n;
	for (long long i = 1; i <= n; i++) {
		cin >> b[i];
		cout << i * b[i] - (i - 1) * b[i - 1];
		if (i != n) cout << " ";
		else cout << "\n";
	}
}
