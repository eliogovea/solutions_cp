#include <bits/stdc++.h>

using namespace std;

const int M = 1000 * 1000 * 1000 + 7;

inline void add(int & a, int b) {
    a += b;
    if (a >= M) {
        a -= M;
    }
}

inline int mul(int a, int b) {
    return (long long)a * b % M;
}

inline int power(int x, int n) {
    int y = 1;
    while (n) {
        if (n & 1) {
            y = mul(y, x);
        }
        x = mul(x, x);
        n >>= 1;
    }
    return y;
}

const int N = 100 * 1000 + 10;

int n;
int p[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

   //  freopen("dat.txt", "r", stdin);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        p[i] = mul(x, power(y, M - 2));;
    }

    int e = 0;
    for (int i = 0; i < n; i++) {
        add(e, 1);
        e = mul(e, power(p[i], M - 2));
    }

    cout << e << "\n";
}
