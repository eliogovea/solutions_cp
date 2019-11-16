#include <bits/stdc++.h>

using namespace std;

const int M = 1000 * 1000 * 1000 + 7;
const int INV_2 = (M + 1) / 2;

inline int to_value(string s) {
    int v = 0;
    for (auto c : s) {
        v = (10LL * v + c - '0') % M;
    }
    return v;
}

inline string to_binary(int v) {
    if (v == 0) {
        return "0";
    }
    string s;
    while (v > 0) {
        s += '0' + (v & 1);
        v >>= 1;
    }
    reverse(s.begin(), s.end());

    return s;
}

inline int sum(string x) {
    string rx = x;
    reverse(rx.begin(), rx.end());

    if (rx < x) {
        swap(x, rx);
    }

    int a = to_value(x);
    int b = to_value(rx);

    int c = (a + b) % M;
    int d = (b - a + 1 + M) % M;
    
    int ans = (long long)c * d % M;
    ans = (long long)ans * INV_2 % M;

    return ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        int x = sum(s);
        string y = to_binary(x);

        cout << y << "\n";

    }
}
