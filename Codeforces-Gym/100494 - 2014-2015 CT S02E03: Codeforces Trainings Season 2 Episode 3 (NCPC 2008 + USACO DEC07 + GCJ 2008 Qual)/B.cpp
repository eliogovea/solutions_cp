// 2014-2015 CT S02E03: Codeforces Trainings Season 2 Episode 3 (NCPC 2008 + USACO DEC07 + GCJ 2008 Qual)
// 100494B

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n, b;
    cin >> n >> b;
    long long t = (1LL << (b + 1LL)) - 1LL;
    cout << (t >= n ? "yes" : "no") << "\n";
}
