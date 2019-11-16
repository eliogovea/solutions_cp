#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
const ll inf = (ll)1e18;
ll f[1000000],n, m;
vector<ll> sol;

int main() {
    f[1] = 1ll;
    f[2] = 1ll;
    int last = 0;
    for (int i = 3; ; i++) {
        f[i] = f[i - 1] + f[i - 2];
        if (f[i] > inf) break;
        last = max(last, i);
    }

    ll n;
    while (cin >> n) {
        int ind = last;
        ll m = n;
        sol.clear();
        while (m) {
            while (f[ind] > m) ind--;
            sol.push_back(f[ind]);
            m -= f[ind];
        }
        cout << n << " = ";
        for (int i = sol.size() - 1; i >= 0; i--) {
            cout << sol[i];
            if (i != 0) cout << " + ";
            else cout << endl;
        }
    }

}
