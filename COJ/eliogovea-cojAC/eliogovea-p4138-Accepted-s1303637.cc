#include <bits/stdc++.h>

using namespace std;

const int M = 1000 * 1000 * 1000 + 7;

inline int power(int x, int n) {
    int y = 1;
    while (n > 0) {
        if (n & 1) {
            y = (long long)y * x % M;
        }
        x = (long long)x * x % M;
        n >>= 1;
    }
    return y;
}

inline vector <int> fast(int n) {
    vector <int> a(n);
    a[0] = 1;
    for (int i = 1; i < n; i++) {
        a[i] = (long long)a[i - 1] * (2LL * i - 1) % M;
        a[i] = (long long)a[i] * power(2 * i, M - 2) % M;
    }
    return a;
}

inline vector <int> faster(int n) {
    vector <int> a(n);
    vector <int> fact(2 * n);
    vector <int> inv_fact(2 * n);
    fact[0] = 1;
    for (int i = 1; i < 2 * n; i++) {
        fact[i] = (long long)fact[i - 1] * i % M;
    }
    inv_fact[2 * n - 1] = power(fact[2 * n - 1], M - 2);
    for (int i = 2 * n - 2; i >= 0; i--) {
        inv_fact[i] = (long long)inv_fact[i + 1] * (i + 1) % M;
    }
    a[0] = 1;
    for (int i = 1; i < n; i++) {
        a[i] = (long long)a[i - 1] * (2LL * i - 1) % M;
        a[i] = (long long)a[i] * inv_fact[2 * i] % M;
        a[i] = (long long)a[i] * fact[2 * i - 1] % M;
    }
    return a;
}

bool test(int n) {
    assert(n <= 2000);
    auto a = faster(n);
    if (a[0] != 1) {
        return false;
    }
    for (int i = 1; i < n; i++) {
        int s = 0;
        for (int j = 0; j <= i; j++) {
            s += (long long)a[j] * a[i - j] % M;
            if (s >= M) {
                s -= M;
            }
        }
        if (s != 1) {
            cerr << i << " " << s << "\n";
            return false;
        }
    }
    return true;
}

bool gen_test_cases(const int N = 1000 * 1000) {
    ofstream input("000.in");
    input << N << "\n";
    for (int i = 0; i < N; i++) {
        input << i << "\n";
    }
    input.close();

    auto a = fast(N);
    ofstream output("000.out");
    for (int i = 0; i < N; i++) {
        output << a[i] << "\n";
    }
    output.close();
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // assert(test(2000));
    // gen_test_cases();
    
    auto a = faster(1000 * 1000);
    int t, n;
    // cin >> t;
    scanf("%d", &t);
    while (t--) {
        // cin >> n;
        scanf("%d", &n);
        // cout << a[n] << "\n";
        printf("%d\n", a[n]);

    }
}
