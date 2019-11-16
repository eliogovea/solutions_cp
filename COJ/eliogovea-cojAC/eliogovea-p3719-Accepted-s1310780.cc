#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector <int> v(n);
    for (auto & x : v) {
        cin >> x;
    }

    vector <long long> s(1 << n);
    for (int i = 0; i < n; i++) {
        s[1 << i] = v[i];
    }

    for (int m = 1; m < (1 << n); m++) {
        s[m] = s[m ^ (m & -m)] + s[m & -m];
    }

    unordered_map <long long, int> f;
    for (int m = 1; m < (1 << n); m++) {
        f[s[m]]++;
    }

    int q;
    cin >> q;

    while (q--) {
        int x;
        cin >> x;

        cout << f[x] << "\n";
    }
}
