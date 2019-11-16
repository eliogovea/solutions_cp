#include <iostream>
#include <fstream>

using namespace std;

int n, m, f, c, st, p[1005];
char t[1005];

int main() {
    //freopen("e.in", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> f >> c >> st;
	for (int i = 1; i <= st; i++) cin >> t[i] >> p[i];
	for (int i = st; i; i--) {
		if (t[i] == 'E') c -= p[i];
		else if (t[i] == 'W') c += p[i];
		else if (t[i] == 'N') f += p[i];
		else f -= p[i];
	}
	cout << f << " " << c << "\n";
}
