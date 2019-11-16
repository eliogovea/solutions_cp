// 2014-2015 CT S02E03: Codeforces Trainings Season 2 Episode 3 (NCPC 2008 + USACO DEC07 + GCJ 2008 Qual)
// 100494G

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;

string m[MAXN];
bool mk[MAXN][MAXN];
bool d[MAXN][MAXN];

int movI[] = { 0 , 1 , 0 , -1 };
int movJ[] = { 1 , 0 , -1 , 0 };

int r, c;

bool can_mov( int i, int j ){
    return ( i >= 0 && j >= 0 && i < r && j < c && m[i][j] != '#' && m[i][j] != 'T' );
}

typedef pair<int,int> par;

par cola[MAXN * MAXN];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("in.txt","r",stdin);

    cin >> c >> r;

    int xi, xj;

    for( int i = 0; i < r; i++ ){
        cin >> m[i];
        for( int j = 0; j < c; j++ ){
            if( m[i][j] == 'P' ){
                xi = i;
                xj = j;
            }
            else if( m[i][j] == 'T' ){
                for( int k = 0; k < 4; k++ ){
                    int ii = i + movI[k];
                    int jj = j + movJ[k];

                    if( can_mov( ii , jj ) ){
                        d[ii][jj] = true;
                    }
                }
            }
        }
    }

    int sol = 0;

    int enq = 0, deq = 0;

    cola[enq++] = par( xi , xj );

    mk[ xi ][ xj ] = true;

    while( enq - deq ){
        int i = cola[deq].first;
        int j = cola[deq++].second;

        if( m[i][j] == 'G' ){
            sol++;
        }

        if( d[i][j] ){
            continue;
        }

        for( int k = 0; k < 4; k++ ){
            int ii = i + movI[k];
            int jj = j + movJ[k];

            if( can_mov( ii , jj ) && !mk[ii][jj] ){
                cola[enq++] = par( ii , jj );
                mk[ii][jj] = true;
            }
        }
    }

    cout << sol << '\n';
}
