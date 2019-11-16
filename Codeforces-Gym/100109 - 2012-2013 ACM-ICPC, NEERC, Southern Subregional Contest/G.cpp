// 2012-2013 ACM-ICPC, NEERC, Southern Subregional Contest
// 100109G

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);
    freopen( "input.txt", "r", stdin );
    freopen( "output.txt", "w", stdout);

    map<string,int> sol;

    int n; cin >> n;

    for( int i = 0; i < n; i++ ){
        int k; cin >> k;

        vector<string> s( k , "" );
        for( int i = 0; i < k; i++ ){
            cin >> s[i];
        }

        sort( s.begin() , s.end() );

        for( int i = 1; i < (1<<k); i++ ){
            string x = "";
            for( int j = 0; j < k; j++ ){
                if( i & (1 << j) ){
                    x += s[j];
                    x += ";";
                }
            }

            sol[x]++;
        }
    }

    int m; cin >> m;

    while( m-- ){
        int l; cin >> l;
        string x = "";
        vector<string> s( l , "" );
        for( int i = 0; i < l; i++ ){
            cin >> s[i];
        }

        sort( s.begin() , s.end() );

        for( int i = 0; i < l; i++ ){
            x += s[i];
            x += ";";
        }

        cout << sol[x] << '\n';
    }
}
