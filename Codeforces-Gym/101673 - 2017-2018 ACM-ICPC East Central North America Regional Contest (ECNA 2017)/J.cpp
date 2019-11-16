// 2017-2018 ACM-ICPC East Central North America Regional Contest (ECNA 2017)
// 101673J

#include <bits/stdc++.h>

using namespace std;

int jim_u[20], jim_r[20], jim_t;

int u[20], r[20], t[20];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

   //  freopen("dat.txt", "r", stdin);
    for( int i  = 0; i < 10; i++ )
        cin >> jim_u[i] >> jim_r[i];

    for( int i = 0; i < 10; i++ ){
        cin >> u[i] >> r[i] >> t[i];
    }

    for( int k = 0; k < 30; k++ ){
        int i = k % 10;

        if( t[i] > jim_t ){
            jim_t += jim_u[i];
            t[i] = max( t[i], jim_t );
            jim_t += jim_r[i];

        }
        else{
            int x = ( jim_t - t[i] )/( u[i]+r[i] );
            if( t[i] + (u[i]+r[i])*x > jim_t ) x--;

            int tprox = t[i] + (u[i]+r[i])*x;

            jim_t = max( jim_t, tprox+u[i] ) + jim_u[i];
            t[i] = max( tprox+u[i]+r[i], jim_t );
            jim_t += jim_r[i];

        }

    }
    cout << jim_t - jim_r[9] << '\n';

}
