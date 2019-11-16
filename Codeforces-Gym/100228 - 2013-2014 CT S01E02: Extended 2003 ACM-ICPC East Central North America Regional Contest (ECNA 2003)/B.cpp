// 2013-2014 CT S01E02: Extended 2003 ACM-ICPC East Central North America Regional Contest (ECNA 2003)
// 100228B

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 30;
const int MAXL = 110;
const int MAXM = 610;

int next[MAXM][MAXN];
int dp[MAXL][MAXM];
string s[MAXM];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int n, l, m;

    while( cin >> n >> l >> m , n ){
        map<string,int> dic;

        for( int i = 1; i <= m; i++ ){
            cin >> s[i];
            dic[ s[i] ] = i;
        }

        for( int i = 1; i <= m; i++ ){
            string tmp = s[i].substr( 1 , s[i].size()-1 );
            for( int j = 0; j < n; j++ ){
                next[i][j] = 0;
                if( dic[ tmp+(char)('A'+j) ] ){
                    next[i][j] = dic[ tmp+(char)('A'+j) ];
                }
            }
        }

        for( int i = 0; i <= l; i++ ){
            for( int j = 1; j <= m; j++ ){
                dp[i][j] = 0;
            }
        }

        for( int i = 1; i <= m; i++ ){
            dp[ s[1].size() ][i] = 1;
        }

        for( int i = s[1].size(); i < l; i++ ){
            for( int j = 1; j <= m; j++ ){
                for( int k = 0; k < n; k++ ){
                    if( next[j][k] ){
                        dp[i+1][ next[j][k] ] += dp[i][j];
                    }
                }
            }
        }

        int sol = 0;
        for( int i = 1; i <= m; i++ ){
            sol += dp[l][i];
        }

        cout << sol << '\n';
    }
}
