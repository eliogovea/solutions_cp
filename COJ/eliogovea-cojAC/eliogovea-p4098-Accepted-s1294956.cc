#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    if (m == 1) {
        cout << "1\n";
        return 0;
    }

    vector <int> c(m);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        c[x - 1]++;
    }

    int zero = 0;
    for (int i = 0; i < m; i++) {
        if (c[i] == 0) {
            zero++;
        }
    }

    if (zero == 0) {
        cout << "0\n";
        return 0;
    }

    int x = m - zero;
		
    int y = 0;

    for (int i = 0; i < m; i++) {
        if (c[i] > 1) {
            y++;
        }
    }

    if (x == 1) {
        cout << "1\n";
        return 0;
    }

    if (x >= 3) {
	if (m == 4 && y == 0) {
		cout << m - 1 << "\n";
		return 0;
	}
        cout << m << "\n";
        return 0;
    }

    // x == 2
    

    assert(y <= 2);

    cout << m - 2 + y << "\n";
}

