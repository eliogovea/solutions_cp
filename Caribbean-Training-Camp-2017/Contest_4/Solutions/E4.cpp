#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> par;

const int MAXR = 110;
const int MAXN = 10100;

int R, C;
string mapa[MAXR];

int nod[MAXR][MAXR];
char solMX[MAXR][MAXR];
char solMN[MAXR][MAXR];

par coord1[MAXN];
par coord2[MAXN];

bool can_move( int i, int j ){
    return ( i >= 0 && j >= 0 && i < R && j < C );
}

int movI[] = { 0 , 1 , 0 , -1 };
int movJ[] = { 1 , 0 , -1 , 0 };
char dir[] = { 'R' , 'D' , 'L' , 'U' };

vector<int> g[MAXN];
int from[MAXN];
int go[MAXN];
bool mk[MAXN];

bool dfs( int u ){
    if( mk[u] ){
        return false;
    }

    mk[u] = true;

    for( int i = 0; i < g[u].size(); i++ ){
        int v = g[u][i];
        if( !from[v] || dfs( from[v] ) ){
            from[v] = u;
            go[u] = v;
            return true;
        }
    }

    return false;
}

char get_dir( int i, int j, int ii, int jj ){
    for( int k = 0; k < 4; k++ ){
        if( i + movI[k] == ii && j + movJ[k] == jj ){
            return dir[k];
        }
    }

    return '.';
}

par father[MAXR][MAXR];

void dfs2( int i, int j ){
    for( int k = 0; k < 4; k++ ){
        int ii = i + movI[k];
        int jj = j + movJ[k];
        if( can_move( ii, jj ) && mapa[ii][jj] == '?' && father[ii][jj].first == -1 ){
            father[ii][jj] = par( i , j );
            dfs2( ii , jj );

            if( father[i][j].first == i && father[i][j].second == j ){
                solMN[i][j] = get_dir( i , j , ii , jj );
            }
        }
    }

    if( !(father[i][j].first == i && father[i][j].second == j)  ){
        solMN[i][j] = get_dir( i , j , father[i][j].first , father[i][j].second );
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    cin >> R >> C;

    int n = 0, m = 0;

    for( int i = 0; i < R; i++ ){
        cin >> mapa[i];

        for( int j = 0; j < C; j++ ){
            solMX[i][j] = solMN[i][j] = mapa[i][j];

            if( mapa[i][j] == '?' ){
                if( (i+j) % 2 == 0 ){
                    nod[i][j] = ++n;
                    coord1[n] = par( i , j );
                }
                else{
                    nod[i][j] = ++m;
                    coord2[m] = par( i , j );
                }
            }
        }
    }

    for( int i = 0; i < R; i++ ){
        for( int j = 0; j < C; j++ ){
            father[i][j] = par( -1 , -1 );
        }
    }

    for( int i = 0; i < R; i++ ){
        for( int j = 0; j < C; j++ ){
            if( mapa[i][j] == '?' && father[i][j].first == -1 ){
                father[i][j] = par( i , j );
                dfs2( i , j );
            }
        }
    }

    for( int i = 0; i < R; i++ ){
        for( int j = (i % 2); j < C; j+=2 ){
            if( nod[i][j] ){
                for( int k = 0; k < 4; k++ ){
                    int ii = i + movI[k];
                    int jj = j + movJ[k];

                    if( can_move( ii , jj ) && nod[ii][jj] ){
                        g[ nod[i][j] ].push_back( nod[ii][jj] );
                    }
                }
            }
        }
    }

    for( int i = 1; i <= n; i++ ){
        fill( mk , mk + n + 1 , false );
        dfs(i);
    }

    for( int i = 0; i < R; i++ ){
        for( int j = 0; j < C; j++ ){
            if( mapa[i][j] == '?' ){
                if( (i+j) % 2 == 0 ){
                    if( go[ nod[i][j] ] ){
                        int v = go[ nod[i][j] ];
                        solMX[i][j] = get_dir( i , j , coord2[v].first , coord2[v].second );
                    }
                }
                else{
                    if( from[ nod[i][j] ] ){
                        int v = from[ nod[i][j] ];
                        solMX[i][j] = get_dir( i , j , coord1[v].first , coord1[v].second );
                    }
                }
            }
        }
    }

    for( int i = 0; i < R; i++ ){
        for( int j = 0; j < C; j++ ){
            if( solMX[i][j] == '?' ){
                for( int k = 0; k < 4; k++ ){
                    int ii = i + movI[k];
                    int jj = j + movJ[k];

                    if( can_move( ii , jj ) && mapa[ii][jj] == '?' ){
                        solMX[i][j] = get_dir( i , j , ii , jj );
                    }
                }
            }
        }
    }

    for( int i = 0; i < R; i++ ){
        for( int j = 0; j < C; j++ ){
            cout << solMN[i][j];
        }
        cout << '\n';
    }

    cout << '\n';


    for( int i = 0; i < R; i++ ){
        for( int j = 0; j < C; j++ ){
            cout << solMX[i][j];
        }
        cout << '\n';
    }
}
