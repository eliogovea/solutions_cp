#include <iostream>
using namespace std;

long long n;

int main() {
    while (cin >> n && n) cout << 6ll * n * n << " " << 3ll * n * (n + 1ll) + 1ll << " " << 3ll * n * (3ll * n + 1ll) << endl;
}
