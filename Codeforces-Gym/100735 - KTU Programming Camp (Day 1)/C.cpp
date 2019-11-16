// KTU Programming Camp (Day 1)
// 100735C

#include <bits/stdc++.h>

using namespace std;

int n,m;
const int MAXN = 30;
int d[MAXN][MAXN][MAXN][MAXN];
string mapa[MAXN];

int movI[4] = { 0 , 0 , -1 , 1};
int movJ[4] = { -1 , 1 , 0 , 0};

typedef pair<int,int> par;
typedef pair< par, par > it;

bool can_move(par x){
    bool ok = ( x.first < n && x.second < m && x.first >= 0 && x.second >= 0 &&
                mapa[x.first][x.second] != 'X' );
    return ok;
}

par move_G(par A, par G){
    if( A.second != G.second  &&
       can_move( par( G.first , G.second + (A.second < G.second ? -1 : 1) ) ) ){
        G.second += (A.second < G.second ? -1 : 1);
    }
    else if( A.first != G.first &&
        can_move( par( G.first + (A.first < G.first ? -1 : 1) , G.second ) ) ){
        G.first += (A.first < G.first ? -1 : 1);
    }
    return G;
}

it cola[100000];

int bfs( par a, par g, par P ){
    int enq = 0, deq = 0;

    d[ a.first ][ a.second ][ g.first ][ g.second ] = 1;
    cola[enq++] = it( a , g );

    while(enq - deq){
        par A = cola[deq].first;
        par G = cola[deq++].second;

        for(int k = 0; k < 4; k++){
            int ai = A.first + movI[k];
            int aj = A.second + movJ[k];

            if( can_move( par(ai, aj) ) &&
                 ( ai != G.first || aj != G.second ) ){
                par nG = move_G( par(ai,aj) , G );
                if( nG.first == ai && nG.second == aj ||
                    d[ai][aj][nG.first][nG.second] ){
                    continue;
                }

                d[ai][aj][nG.first][nG.second] = d[ A.first ][ A.second ][G.first][G.second] + 1;
                cola[ enq++ ] = it( par(ai,aj) , nG );

                if( ai == P.first && aj == P.second ){
                    return d[ai][aj][nG.first][nG.second] - 1;
                }
            }
        }
    }

    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    cin >> n >> m;

    par A, G, P;

    for(int i = 0; i < n; i++){
        cin >> mapa[i];
        for(int j = 0; j < m; j++){
            if( mapa[i][j] == 'A' ) A = par( i , j );
            if( mapa[i][j] == 'G' ) G = par( i , j );
            if( mapa[i][j] == 'P' ) P = par( i , j );
        }
    }

    cout << bfs( A , G , P ) << '\n';
}
