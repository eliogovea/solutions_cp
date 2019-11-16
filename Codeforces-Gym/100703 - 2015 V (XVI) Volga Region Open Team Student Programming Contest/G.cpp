// 2015 V (XVI) Volga Region Open Team Student Programming Contest
// 100703G

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1100;

int c[MAXN];
bool dp[MAXN][MAXN];
int back[MAXN][MAXN];

int solve( int n, int k ){
    dp[1][ c[1] ] = true;
    back[1][ c[1] ] = 0;

    if( c[1] > k ){
        return 0;
    }

    for( int i = 2; i <= n; i++ ){

        bool ok = false;

        for( int j = 0; j <= k; j++ ){
            if( dp[i-1][j] ){
                if( j + c[i] <= k ){
                    dp[i][ j + c[i] ] = true;
                    back[ i ][ j + c[i] ] = j;

                    ok = true;
                }
                if( j - c[i] >= 0 ){
                    dp[i][ j - c[i] ] = true;
                    back[ i ][ j - c[i] ] = j;

                    ok = true;
                }
            }
        }

        if( !ok ){
            return i-1;
        }
    }

    return n;
}

string outp( int i, int j ){
    int jj = back[i][j];

    string x = "-";

    if( jj < j ){
        x = "+";
    }
    if( i == 1 ){
        return x;
    }
    return outp( i-1 , jj ) + x;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int n, k;
    cin >> n >> k;

    for( int i = 1; i <= n; i++ ){
        cin >> c[i];
    }

    int mx = solve( n , k );

    cout << mx << '\n';
    if( mx ){
        int j = 0;
        for( ; j <= k; j++ ){
            if( dp[mx][j] ){
                break;
            }
        }
        cout << outp( mx , j ) << '\n';
    }
}
