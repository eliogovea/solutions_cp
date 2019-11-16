#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll c, m, x;

int main() {
    cin >> c >> m;
    while (c--) {
        cin >> x;
        x %= m;
        x = (x * x) % m;
        cout << x << '\n';
    }
}
