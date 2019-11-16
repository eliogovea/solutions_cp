// 2012-2013 ACM-ICPC, NEERC, Southern Subregional Contest
// 100109B

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1000000009;

int add( int a, int b ){
    a += b;
    if( a >= mod ){
        a -= mod;
    }

    return a;
}

int mult( int a, int b ){
    return ( (ll)a * (ll)b ) % mod;
}

const int MAXN = 505;

int dp[2][MAXN][MAXN];

typedef pair<int,int> par;

par s[2*MAXN];

int cnt0[2*MAXN];
int cnt1[2*MAXN];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);
    freopen( "input.txt", "r", stdin );
    freopen( "output.txt", "w", stdout);

    int N, K10; cin >> N >> K10;

    if( (N - K10) % 2 != 0 ){
        cout << "0\n";
        return 0;
    }

    int K01 = (N - K10) / 2;
    K10 += K01;

    for( int i = 0; i < N; i++ ){
        cin >> s[i+1].first;
        s[i+1].second = 0;
    }

    for( int i = 0; i < N; i++ ){
        cin >> s[i+N+1].first;
        s[i+N+1].second = 1;
    }

    sort( s+1 , s+1+N+N );

    /*for( int i = 1; i <= N+N; i++ ){
        cerr << s[i].first << ' ';
    }cerr << '\n';

    for( int i = 1; i <= N+N; i++ ){
        cerr << s[i].second << ' ';
    }cerr << '\n';*/

    for( int i = 1; i <= N+N; i++ ){
        cnt0[i] = cnt0[i-1];
        cnt1[i] = cnt1[i-1];

        if( s[i].second == 0 ){
            cnt0[i]++;
        }
        else{
            cnt1[i]++;
        }
    }

    dp[0][0][0] = 1;

    for( int n = 0; n < N+N; n++ ){
        for( int k01 = 0; k01 <= K01; k01++ ){
            for( int k10 = 0; k10 <= K10; k10++ ){
                dp[1][k01][k10] = add( dp[1][k01][k10] ,
                                         dp[0][k01][k10] );

                int c0 = cnt0[n+1] - (k01 + k10);
                int c1 = cnt1[n+1] - (k01 + k10);

                if( c1 > 0 && s[n+1].second == 0 ){
                    dp[1][k01][k10+1] = add( dp[1][k01][k10+1] ,
                                              mult( c1 , dp[0][k01][k10] ) );
                }

                if( c0 > 0 && s[n+1].second == 1 ){
                    dp[1][k01+1][k10] = add( dp[1][k01+1][k10] ,
                                              mult( c0 , dp[0][k01][k10] ) );
                }
            }
        }

        for( int k01 = 0; k01 <= K01; k01++ ){
            for( int k10 = 0; k10 <= K10; k10++ ){
                dp[0][k01][k10] = dp[1][k01][k10];
                dp[1][k01][k10] = 0;
            }
        }
    }

    cout << dp[0][K01][K10] << '\n';
}
