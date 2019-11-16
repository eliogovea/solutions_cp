#include <iostream>

using namespace std;

int t;
long long a, b, c;

int main() {
ios::sync_with_stdio(false);
cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        bool ok = false;
        if (a + b == c) {
            ok = true;
        }
        if (a - b == c) {
            ok = true;
        }
        if (a * b == c) {
            ok  =true;
        }
        if (b != 0 && a / b == c) {
            ok  = true;
        }
        if (b != 0 && a % b == c) {
            ok = true;
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
