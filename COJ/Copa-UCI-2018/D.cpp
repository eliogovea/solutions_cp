#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long x, y, c1, c2; cin >> c1 >> c2 >> x >> y;


    ll ini = 1, fin = (1ll<<60);

    ll sol = 0;

    while( ini <= fin ){
        ll n = (ini + fin) / 2ll;

        if( n - n/x >= c1 && n - n/y >= c2 && n - n/(x*y) >= c1 + c2 ){
            sol = n;
            fin = n-1ll;
        }
        else{
            ini = n+1ll;
        }
    }

    cout << sol << '\n';
}

