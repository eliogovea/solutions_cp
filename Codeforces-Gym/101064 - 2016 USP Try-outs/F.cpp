// 2016 USP Try-outs
// 101064F

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int solve( int n, int i, int pp = 1 ){
    if( ( i % 2 ) == pp ){
        return (i+1)/2;
    }

    if( n % 2 == 0 ){
        return (n/2) + solve( n / 2 , (i+1)/2 , pp );
    }
    else{
        if( pp ){
            return (n+1)/2 + solve( n/2, (i+1)/2, pp^1 );
        }
        else{
            return n/2 + solve( (n+1)/2 , (i+1)/2, pp^1 );
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int tc; cin >> tc;

    while( tc-- ){
        int n, i; cin >> n >> i;

        cout << solve( n , i ) << '\n';
    }
}
