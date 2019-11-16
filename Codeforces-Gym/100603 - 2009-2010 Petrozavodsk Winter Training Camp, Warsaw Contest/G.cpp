// 2009-2010 Petrozavodsk Winter Training Camp, Warsaw Contest
// 100603G

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 2000;
const int MAXK = 60;

int dp[MAXN][MAXK];

int BIT[MAXN];

int n;

int upd_bit( int p, int upd ){
    while( p <= n ){
        BIT[p] += upd;
        p += ( p & -p );
    }
}

int get_bit( int p ){
    int ret = 0;

    while( p > 0 ){
        ret += BIT[p];
        p -= ( p & -p );
    }

    return ret;
}

typedef pair<int,int> par;
vector<par> out[MAXN];

par back[MAXN][MAXK];

bool mk[MAXN];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int K; cin >> n >> K;

    int sol = 0;
    par ls = par( 0 , 0 );

    for( int i = 1; i <= n; i++ ){
        int tot = 0;
        for( int j = i+1; j <= n; j++ ){
            int c; cin >> c;
            tot += c;

            out[j].push_back( par( i , c ) );
        }

        upd_bit( i , tot );

        for( int j = 0; j < out[i].size(); j++ ){
            upd_bit( out[i][j].first , -out[i][j].second );
        }

        for( int k = 1; k <= K; k++ ){
            dp[i][k] = dp[i-1][k];
            back[i][k] = back[i-1][k];

            for( int j = 1; j <= i; j++ ){
                int tmp = dp[j-1][k-1] + get_bit(i) - get_bit( j-1 );

                if( dp[i][k] < tmp ){
                    dp[i][k] = tmp;
                    back[i][k] = par( j-1 , k-1 );
                }
            }

            if( sol < dp[i][k] ){
                sol = dp[i][k];
                ls = par( i , k );
            }
        }
    }

    if( sol == 0 ){
        for( int i = 1; i <= K; i++ ){
            cout << i << " \n"[i+1==K];
        }
        return 0;
    }

    vector<int> solution;

    while( ls.first > 0 ){
        mk[ls.first] = true;
        solution.push_back( ls.first );
        ls = back[ls.first][ls.second];
    }

    for( int i = 1; i <= n && solution.size() < K; i++ ){
        if( !mk[i] ){
            solution.push_back( i );
        }
    }

    sort( solution.begin() , solution.end() );

    for( int i = 0; i < solution.size(); i++ ){
        cout << solution[i] << " \n"[i+1==solution.size()];
    }
}
