// 2015 USP Try-outs
// 101047E

#include <bits/stdc++.h>

using namespace std;
const int movx[] = { 1,0,-1,0 },
          movy[] = { 0,1, 0, -1 };
int n,m;

int d[1100][1100];
char mat[1100][1100];
queue< pair<int,int> > q;
void bfs( int sx, int sy ){

    d[sx][sy] = 0;
    q.push( make_pair( sx,sy ) );

    while( !q.empty() ){
        int x = q.front().first,
            y = q.front().second;
        q.pop();

        for( int k = 0; k < 4; k++ ){
            int dx = x + movx[k],
                dy = y + movy[k];
            if( dx <0 || dy <0) continue;
            if( mat[dx][dy] != '#' && d[dx][dy] > d[x][y]+1 ){
                d[dx][dy] = d[x][y]+1;
                q.push( make_pair(dx,dy) );
            }

        }
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	int tc;
	cin >> tc;
    while( tc-- ){
        int stx=0,sty=0;
        cin >> n >> m;
        for( int i = 0; i < n; i++ ){
            cin >> mat[i];
            fill( d[i], d[i]+m+1, 1<<29 );
            for( int j = 0; j < m; j++ )
                if( mat[i][j] == 'E' ){
                    stx = i;
                    sty = j;
                }
        }
        //cout << "asdasddasa" << endl;
        bfs( stx, sty );
        //cout << "asda" << endl;
        int dmen = 1<<29, dfire = 1<<29;
        for( int i = 0; i < n; i++)
            for( int j = 0; j < m; j++ )
                if( mat[i][j] == 'S' ){
                    dmen = min( dmen, d[i][j] );
                }
                else if( mat[i][j] == 'F' ){
                    dfire = min( dfire, d[i][j] );
                }
        /*for( int i = 0; i < n; i++)
            for( int j = 0; j < m; j++ )
                cout << d[i][j] << " \n"[j+1==m];*/
        if( dmen == 1<<29 )
            cout << "N";
        else if( dmen >= dfire )
            cout << "N";
        else
            cout << "Y";
        cout << '\n';
    }
}
