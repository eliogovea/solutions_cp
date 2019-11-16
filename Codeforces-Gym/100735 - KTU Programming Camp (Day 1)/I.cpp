// KTU Programming Camp (Day 1)
// 100735I

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> big;

const big ZERO = vector<int>(1, 0);

vector<int> a, b, c;

big operator + (const big &a, const big &b) {
    big res;
    int len = max(a.size(), b.size());
    int carry = 0;
    for (int i = 0; i < len; i++) {
        if (i < a.size()) carry += a[i];
        if (i < b.size()) carry += b[i];
        res.push_back(carry % 10);
        carry /= 10;
    }
    if (carry) {
        res.push_back(carry);
    }
    while (res.back() == 0) {
        res.pop_back();
    }
    return res;
}

string s;

void print(big b) {
    for (int i = b.size() - 1; i >= 0; i--) {
        cout << b[i];
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    for (int i = s.size() - 1; i >= 0; i--) {
        a.push_back(s[i] - '0');
    }
    cin >> s;
    for (int i = s.size() - 1; i >= 0; i--) {
        b.push_back(s[i] - '0');
    }
    cin >> s;
    for (int i = s.size() - 1; i >= 0; i--) {
        c.push_back(s[i] - '0');
    }
    if (a + a == b || a + a == c || b + b == a || b + b == c || c + c == a || c + c == b || a + b == c || a + c == b || b + c == a) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
