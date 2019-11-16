#include <bits/stdc++.h>
using namespace std;

int a, b;

int main() {
    while (scanf("%d%d", &a, &b) == 2)
        printf("%s\n", __gcd(a, b) == 1 ? "YES" : "NO");
}
