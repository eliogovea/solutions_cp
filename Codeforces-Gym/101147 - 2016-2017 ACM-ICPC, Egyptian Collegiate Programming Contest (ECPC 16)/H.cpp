// 2016-2017 ACM-ICPC, Egyptian Collegiate Programming Contest (ECPC 16)
// 101147H

#include <bits/stdc++.h>

using namespace std;

struct data{
    int f, x, y;
    data(){}
    data( int ff, int xx, int yy ){
        f = ff;
        x = xx;
        y = yy;
    }
};

int dp[12][12][12];
int h[12][12][12];
bool mk[12][12][12];

bool ok( int f, int x, int y ){
    return ( f > 0 && f <= 10  && x > 0 && x <= 10 && y > 0 && y <= 10 );
}

int bfs(){
    dp[10][1][1] = h[10][1][1];
    mk[10][1][1] = true;

    queue<data> q;
    q.push( data( 10 , 1 , 1 ) );

    while( !q.empty() ){
        data u = q.front(); q.pop();

        data v = u;
        v.x++;
        if( ok( v.f , v.x , v.y ) ){
            dp[ v.f ][ v.x ][ v.y ] = max( dp[ v.f ][ v.x ][ v.y ] , dp[ u.f ][ u.x ][ u.y ] + h[ v.f ][ v.x ][ v.y ] );
            if( !mk[ v.f ][ v.x ][ v.y ] ){
                q.push( v );
                mk[ v.f ][ v.x ][ v.y ] = true;
            }
        }

        v = u;
        v.y++;
        if( ok( v.f , v.x , v.y ) ){
            dp[ v.f ][ v.x ][ v.y ] = max( dp[ v.f ][ v.x ][ v.y ] , dp[ u.f ][ u.x ][ u.y ] + h[ v.f ][ v.x ][ v.y ] );
            if( !mk[ v.f ][ v.x ][ v.y ] ){
                q.push( v );
                mk[ v.f ][ v.x ][ v.y ] = true;
            }
        }

        v = u;
        v.f--;
        if( ok( v.f , v.x , v.y ) ){
            dp[ v.f ][ v.x ][ v.y ] = max( dp[ v.f ][ v.x ][ v.y ] , dp[ u.f ][ u.x ][ u.y ] + h[ v.f ][ v.x ][ v.y ] );
            if( !mk[ v.f ][ v.x ][ v.y ] ){
                q.push( v );
                mk[ v.f ][ v.x ][ v.y ] = true;
            }
        }
    }

    return dp[1][10][10];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("commandos.in","r",stdin);

    int tc; cin >> tc;

    while( tc-- ){
        for( int i = 0; i < 12; i++ ){
            for( int j = 0; j < 12; j++ ){
                for( int k = 0; k < 12; k++ ){
                    h[i][j][k] = dp[i][j][k] = 0;
                    mk[i][j][k] = false;
                }
            }
        }

        int n; cin >> n;
        for( int i = 0; i < n; i++ ){
            int f, x, y, hh; cin >> f >> x >> y >> hh;
            h[f][x][y] += hh;
        }

        cout << bfs() << '\n';
    }
}
