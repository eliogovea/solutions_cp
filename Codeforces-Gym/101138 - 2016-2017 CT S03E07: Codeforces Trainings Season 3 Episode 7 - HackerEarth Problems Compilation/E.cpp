// 2016-2017 CT S03E07: Codeforces Trainings Season 3 Episode 7 - HackerEarth Problems Compilation
// 101138E

#include <bits/stdc++.h>

using namespace std;
int w[500], h[500];
bool mk[5000];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   // freopen( "dat.txt", "r", stdin );
    int tc;
    cin >> tc;
    while( tc-- ){
        int n;
        cin >> n;

        for( int i = 0; i < n; i++ )
            cin >> w[i];
        for( int i = 0; i < n; i++ )
            cin >> h[i];
        int idm = 0;
        for( int i = 0; i < n; i++ )
            if( h[idm] < h[i] )
                idm = i;

        int top = w[0]*h[idm];
        swap( h[0], h[idm] );
        sort( w+1, w+n, greater<int>() );
        sort( h+1, h+n );
        fill( mk, mk+n+1, 0 );

        bool ok = true;
        for( int i = 1; i < n && ok; i++ ){
            int j = 1, ss = -1;
            while( true  ){
                if( !mk[j] && w[i]*h[j] < top )
                    ss = j;
                if( w[i]*h[j] >= top )
                    break;
                j++;
            }
            if( ss == -1 ){
                ok = false;
                break;
            }
            mk[ss] = true;
        }
        if( ok )
            cout << "YES\n";
        else
            cout << "NO\n";
    }

}
