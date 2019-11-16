// 2015 V (XVI) Volga Region Open Team Student Programming Contest
// 100703L

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100100;

int p[MAXN] , k[MAXN] , r[MAXN];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int n; cin >> n;

    int pp = 0, kk = 0;

    for( int i = 0; i < n; i++ ){
        cin >> p[i];
    }

    for( int i = 0; i < n; i++ ){
        cin >> k[i];
    }

    for( int i = 0; i < n; i++ ){
        cin >> r[i];
    }


    for( int i = 0; i < n; i++ ){
        if( abs( r[i] - p[i] ) < abs( r[i] - k[i] ) ){
            pp++;
        }
        else if( abs( r[i] - p[i] ) > abs( r[i] - k[i] ) ){
            kk++;
        }
    }

    cout  << pp << ' ' << kk << '\n';
}
