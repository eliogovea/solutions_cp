#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 100100;


ll f[MAXN];
void calc_fact( ll n ){
    f[0] = 1;
    for( ll i = 1; i <= n; i++ ) f[i] = f[i-1] * i;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    //freopen("dat.txt", "r", stdin);

    string s; cin >> s;

    calc_fact( s.size() );

    int n = s.size();

    vector<ll> cnt( 30 , 0 );

    for( int i = 0; i < n; i++ ){
        cnt[ s[i] - 'a' ]++;
    }

    ll sol = f[n];
    ll k = 1;

    for( int i = 0; i < 30; i++ ){
        k *= f[ cnt[i] ];
    }

    cout << sol / k << '\n';
}
