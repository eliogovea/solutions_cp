// 2014 ACM-ICPC Vietnam National First Round
// 100499D

#include <iostream>

using namespace std;

const int N = 1000000;

int criba[N + 5];

int main() {
    for (int i = 2; i * i <= N; i++) {
        if (!criba[i]) {
            for (int j = i * i; j <= N; j += i) {
                criba[j] = 1;
            }
        }
    }
    criba[1] = 1;
    for (int i = 2; i <= N; i++) {
        criba[i] = criba[i - 1] + !criba[i];
    }
    int tc, n;
    cin >> tc;
    for (int i = 1; i <= tc; i++) {
        cin >> n;
        cout << "Case #" << i << ": " << criba[n] << "\n";
    }
}
