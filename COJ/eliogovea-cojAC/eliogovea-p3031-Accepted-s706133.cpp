#include <iostream>

using namespace std;

long long a, b;

int main() {
    while (cin >> a >> b && (a | b))
        cout << (a / b) << " " << (a % b) << " / " << b << "\n";
}
