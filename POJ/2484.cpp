#include <iostream>

using namespace std;

const int N = 1000;

int grundy[N + 5];
int used[N + 5];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	while (cin >> n && n) {
		cout << ((n <= 2) ? "Alice" : "Bob") << "\n";
	}

}
