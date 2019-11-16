// 2016-2017 CT S03E03: Codeforces Trainings Season 3 Episode 3 - 2007-2008 ACM-ICPC, Central European Regional Contest 2007 (CERC 07)
// 101095K

#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> par;

struct st{
    int i, j, mask;
    st( int ii, int jj, int maskk ){
        i = ii;
        j = jj;
        mask = maskk;
    }

    bool operator < ( const st &o ) const {
        return i + j + mask < o.i + o.j + o.mask;
    }
};

typedef pair<int,st> kk;

const int MAXN = 110;
const int oo = ( 1 << 29 );

int n, m;

int movI[] = { 0 , 1 , 0 , -1 };
int movJ[] = { 1 , 0 , -1 , 0 };

string s[MAXN];
int door[MAXN][MAXN];
int key[MAXN][MAXN];

bool can_move( int i, int j ){
    return ( i >= 0 && j >= 0 && i < n && j < m && s[i][j] != '#' );
}

int getv( char c ){
    if( c == 'B' || c == 'b' ){
        return 0;
    }

    if( c == 'Y' || c == 'y' ){
        return 1;
    }

    if( c == 'R' || c == 'r' ){
        return 2;
    }

    if( c == 'G' || c == 'g' ){
        return 3;
    }

    return -1;
}

bool is_door( int i, int j ){
    return ( s[i][j] == 'B' || s[i][j] == 'Y' || s[i][j] == 'R' || s[i][j] == 'G' );
}

bool is_key( int i, int j ){
    return ( s[i][j] == 'b' || s[i][j] == 'y' || s[i][j] == 'r' || s[i][j] == 'g' );
}

bool mk[MAXN][MAXN][16];
int dp[MAXN][MAXN][16];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    while( cin >> n >> m, ( n && m ) ){
        par ini;

        for( int i = 0; i < n; i++ ){
            for( int j = 0; j < m; j++ ){
                door[i][j] = key[i][j] = 0;

                for( int mask = 0; mask < 16; mask++ ){
                    mk[i][j][mask] = false;
                    dp[i][j][mask] = oo;
                }
            }
        }

        for( int i = 0; i < n; i++ ){
            cin >> s[i];

            for( int j = 0; j < m; j++ ){
                int v = getv( s[i][j] );
                if( is_door( i , j ) ){
                    door[i][j] = ( 1 << v );
                }

                if( is_key( i , j ) ){
                    key[i][j] = ( 1 << v );
                }

                if( s[i][j] == '*' ){
                    ini = par( i , j );
                }
            }
        }

        dp[ ini.first ][ ini.second ][0] = 0;
        priority_queue<kk> pq;
        pq.push( kk( 0 , st( ini.first , ini.second , 0 ) ) );

        bool ok = false;

        while( !pq.empty() ){
            st x = pq.top().second; pq.pop();

            if( mk[ x.i ][ x.j ][ x.mask ] ){
                continue;
            }

            mk[ x.i ][ x.j ][ x.mask ] = true;
            if( s[x.i][x.j] == 'X' ){
                cout << "Escape possible in " << dp[x.i][x.j][x.mask] << " steps.\n";
                ok = true;
                break;
            }

            for( int k = 0; k < 4; k++ ){
                int ni = x.i + movI[k];
                int nj = x.j + movJ[k];

                if( can_move( ni , nj ) && ( !door[ni][nj] || (door[ni][nj] & x.mask) ) ){
                    int nmask = ( x.mask | key[ni][nj] );

                    if( dp[ni][nj][nmask] > dp[x.i][x.j][x.mask] + 1 ){
                        dp[ni][nj][nmask] = dp[x.i][x.j][x.mask] + 1;
                        pq.push( kk( -dp[ni][nj][nmask] , st( ni , nj , nmask ) ) );
                    }
                }
            }
        }

        if( !ok ){
            cout << "The poor student is trapped!\n";
        }
    }
}
