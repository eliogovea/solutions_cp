// 2016-2017 CT S03E03: Codeforces Trainings Season 3 Episode 3 - 2007-2008 ACM-ICPC, Central European Regional Contest 2007 (CERC 07)
// 101095Z

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll d, K, n;

ll solve_par( ll k ){
    if( k <= 0 ){
        k = d*2ll;
    }

    k = k/2ll;
    k = (k+n)%d;
    if( k == 0 ){
        k = d;
    }

    k = k*2;

    return k;
}


ll solve_impar( ll k ){
    if( k > d*2ll ){
        k = 1ll;
    }

    k = (k+1ll)/2ll;
    k = (k-n+d)%d;
    if( k == 0ll ){
        k = d;
    }

    k = k*2 - 1;

    return k;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    cin >> d >> K >> n; d /= 2ll; n %= d;

    if( K & 1 ){
        cout << solve_par( K+1ll ) << ' ' << solve_par( K-1ll ) << '\n';
    }
    else{
        cout << solve_impar( K+1ll ) << ' ' << solve_impar( K-1ll ) << '\n';
    }
}

