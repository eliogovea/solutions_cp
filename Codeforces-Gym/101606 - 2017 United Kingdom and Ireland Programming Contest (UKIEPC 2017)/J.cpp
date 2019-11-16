// 2017 United Kingdom and Ireland Programming Contest (UKIEPC 2017)
// 101606J

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll x[20];

int len( int x ){
    int cnt = 0;
    do{
        cnt++;
        x /= 10;
    }while( x > 0 );
    return cnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    x[0] = 20000;
    x[1] = 10000;
    x[2] = 10000 / 2;
    x[4] = 10000 / 4;
    x[8] = 10000 / 8;
    x[16] = 10000 / 16;

    int n; cin >> n;
    ll sol = 0ll;

    for( int i = 1; i <= n; i++ ){
        int s; cin >> s;
        sol += x[s];
    }

    cout << sol / 10000ll << '.';
    int l = len( sol % 10000ll );
    for( int i = 0; i < 4 - l; i++ ){
        cout << '0';
    }
    cout << sol % 10000ll << '\n';
}
