#include <bits/stdc++.h>

using namespace std;

const int MAXN = 90*90;

string s[MAXN];

int movI[] = { 0 , 1 , 0 , -1 };
int movJ[] = { 1 , 0 , -1 , 0 };

int N;

bool can_move( int i, int j ){
    return ( i >= 1 && i <= N && j >= 1 && j <= N );
}

int dic[2][MAXN][MAXN];
int sz[2];

int getv( int i, int j ){
    if( !dic[ (i+j) % 2 ][i][j] ){
        dic[ (i+j) % 2 ][i][j] = ++sz[ (i+j) % 2 ];
    }

    return dic[ (i+j) % 2 ][i][j];
}

int n, m;
vector<int> g[MAXN];
bool mk[MAXN];
int from[MAXN];

bool kuhn( int u ){
    if( mk[u] ){
        return false;
    }

    mk[u] = true;

    for( int i = 0; i < g[u].size(); i++ ){
        int v = g[u][i];

        if( !from[v] || kuhn( from[v] ) ){
            from[v] = u;
            return true;
        }
    }

    return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

    //freopen("dat.txt","r",stdin);

    cin >> N;
    int NN = N;
    N--;

    int tot_p = 0;

    for( int i = 0; i < 2*NN-1; i++ ){
        cin >> s[i];
        for( int j = 0; j < 2*NN-1; j++ ){
            if( s[i][j] == '.' ){
                tot_p++;
            }
        }
    }

    tot_p -= N*N;

    n = 0;
    m = 0;

    for( int i = 1; i <= N; i++ ){
        for( int j = 1; j <= N; j++ ){
            int u = getv( i , j );

            for( int k = 0; k < 4; k++ ){
                int ii = i + movI[k];
                int jj = j + movJ[k];

                if( can_move( ii , jj ) ){
                    int uu = u;
                    int v = getv( ii , jj );

                    if( (i+j) % 2 != 0 ){
                        swap( uu , v );
                    }

                    if( s[ 2*i-1 + movI[k] ][ 2*j-1 + movJ[k] ] == '.' ){
                        g[uu].push_back(v);
                    }
                }
            }
        }
    }

    n = sz[0];
    m = sz[1];

    int mxf = 0;
    for( int u = 1; u <= n; u++ ){
        if( kuhn( u ) ){
            mxf++;
        }
        fill( mk , mk + n + 1 , false );
    }

    int sol = (n+m) - mxf;

    sol = tot_p - sol;
    cout << sol+1 << '\n';
}
