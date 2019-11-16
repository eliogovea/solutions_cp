// 2016-2017 ACM-ICPC Southwestern European Regional Programming Contest (SWERC 2016)
// 101174H

#include <bits/stdc++.h>

using namespace std;

const int N = 32;

bool sieve[N + 5];
vector <int> primes;
int pos[N + 5];

int e[N][N];

typedef long long LL;

inline LL power(LL x, int n) {
    LL res = 1;
    while (n) {
        if (n & 1) {
            res *= x;
        }
        x *= x;
        n >>= 1;
    }
    return res;
}

int cnt[N];

set <LL> answer;

void solve(int curSum, int curDim, int last, int needSum, int tDim) {
    // cerr << curSum << " " << curDim << " " << last << " " << needSum << " " << tDim << "\n";
    if (curDim > tDim) {
        return;
    }
    if (curSum == needSum && curDim == tDim) {
        LL val = 1;
        for (int i = 0; i < primes.size(); i++) {
            //cerr << i << " " << primes[i] << " " << cnt[i] << "\n";
            val *= power(primes[i], cnt[i]);
        }
        //cerr << "\n";
        answer.insert(val);
        return;
    }
    for (int i = last; curSum + i <= needSum; i++) {
        for (int j = 0; j < primes.size(); j++) {
            cnt[j] -= e[i][j];
        }
        solve(curSum + i, curDim + 1, i, needSum, tDim);
        for (int j = 0; j < primes.size(); j++) {
            cnt[j] += e[i][j];
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    sieve[0] = true;
    sieve[1] = true;

    for (int i = 2; i <= N; i++) {
        if (!sieve[i]) {
            for (int j = i + i; j <= N; j += i) {
                sieve[j] = true;
            }
        }
    }
    for (int i = 2; i <= N; i++) {
        if (!sieve[i]) {
            pos[i] = primes.size();
            primes.push_back(i);
        }
    }

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j < primes.size(); j++) {
            e[i][j] = e[i - 1][j];
            int x = i;
            while (x % primes[j] == 0) {
                e[i][j]++;
                x /= primes[j];
            }
        }
    }

    int h, d;
    cin >> d >> h;
    for (int i = 0; i < primes.size(); i++) {
        cnt[i] = e[h - 1][i];
    }
    solve(0, 0, 0, h - 1, d);
    for (set <LL> :: iterator it = answer.begin(); it != answer.end(); it++) {
        cout << *it << "\n";
    }
    return 0;
}
