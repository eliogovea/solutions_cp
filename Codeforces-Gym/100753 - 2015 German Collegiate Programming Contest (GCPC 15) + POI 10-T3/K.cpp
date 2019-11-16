// 2015 German Collegiate Programming Contest (GCPC 15) + POI 10-T3
// 100753K

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int val[] = {0, 1, 2, -1, -1, 5, 9, -1, 8, 6};

inline bool check(LL x) {
    while (x) {
        if (val[x % 10] == -1) return false;
        x /= 10;
    }
    return true;
}

inline bool primo(LL n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2LL == 0) return false;
    for (int i = 3; 1LL * i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    LL n;
    cin >> n;
    if (!check(n) || !primo(n)) {
        cout << "no\n";
        return 0;
    }
    vector<int> v;
    while (n) {
        v.push_back(n % 10);
        n /= 10;
    }
    for (int i = 0; i < v.size(); i++) {
        n = 10LL * n + val[v[i]];
    }
    cout << (primo(n) ? "yes" : "no") << "\n";
}
