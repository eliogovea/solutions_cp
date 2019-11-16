// 2017-2018 ACM-ICPC East Central North America Regional Contest (ECNA 2017)
// 101673H

#include <bits/stdc++.h>

using namespace std;
int n, m;
const int movx[] = {1,0, -1,  0, 1,-1,-1, 1 },
          movy[] = {0,1,  0, -1, 1, 1,-1,-1 };

char mat[500][500];
bool mk[500][500];

void dfs( int x, int y ){
  //  cerr << x << "; " << y << endl;
    mk[x][y] = true;

    for( int k = 0; k < 8; k++ ){
        int dx = x + movx[k],
            dy = y + movy[k];
        if( mk[dx][dy] || mat[dx][dy] != '#' ) continue;
        dfs( dx, dy );

    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

   // freopen("dat.txt","r",stdin);

    cin >> n >> m;

    for( int i = 1; i <= n; i++ )
        cin >> (mat[i]+1);

    int ans = 0;
    for( int i = 1; i <= n; i++ )
        for( int j  =1; j <= m; j++ )
            if( mat[i][j] == '#' && !mk[i][j] ){
                dfs( i, j );
                ans++;

            }
    cout << ans << '\n';
}
