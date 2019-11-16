// 2014-2015 CT S02E10: Codeforces Trainings Season 2 Episode 10 - 2014 Amirkabir University of Technology Annual Programming Contest (AUT APC 14)
// 100534A

#include <bits/stdc++.h>

using namespace std;

long long n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    long long sum = 0;
    long long cur = 3;
    int ans = 0;
    while (sum + cur <= n) {
        ans++;
        sum += cur++;
    }
    cout << ans << "\n";
}
