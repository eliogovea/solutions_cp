// 2017-2018 ACM-ICPC Nordic Collegiate Programming Contest (NCPC 2017)
// 101572E

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXN = 600;

int movI[] = { 1 , -1 , 0 , 0 , 1 , -1 , 1 , -1 };
int movJ[] = { 0 , 0 , 1 , -1 , 1 , -1 , -1 , 1 };

int n, m;

bool mk[MAXN][MAXN];
int mn[MAXN][MAXN];
int mapa[MAXN][MAXN];

bool can_move( int i, int j ){
    return ( i >= 1 && j >= 1 && i <= n && j <= m && !mk[i][j] && mapa[i][j] < 0 );
}

ll sol = 0;

typedef pair<int,int> par;
typedef pair<int,par> tup;

void dijkstra( int i, int j, int lat ){
    priority_queue<tup> pq;
    mn[i][j] = mapa[i][j];
    pq.push( tup( -lat , par( i , j ) ) );

    while( !pq.empty() ){
        tup x = pq.top(); pq.pop();
        int i = x.second.first;
        int j = x.second.second;

        if( mk[i][j] ){
            continue;
        }

        //cerr << "i = " << i << "  j = " << j << "   mn[i][j] = " << mn[i][j] << '\n';

        sol += mn[i][j];

        mk[i][j] = true;

        for( int k = 0; k < 8; k++ ){
            int ii = i + movI[k];
            int jj = j + movJ[k];

            if( can_move( ii , jj ) ){
                mn[ii][jj] = min( mn[ii][jj] , max( mn[i][j] , mapa[ii][jj] ) );
                pq.push( tup( -mn[ii][jj] , par( ii , jj ) ) );
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    cin >> n >> m;

    for( int i = 1; i <= n; i++ ){
        for( int j = 1; j <= m; j++ ){
            cin >> mapa[i][j];
        }
    }

    int i, j; cin >> i >> j;
    dijkstra( i , j , mapa[i][j] );

    cout << -sol << '\n';
}
