// 2011-2012 Northwestern European Regional Contest (NWERC 2011)
// 100729E

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100100;

int p[300];
int c[300];

typedef pair<int,int> par;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int tc; cin >> tc;
    while( tc-- ){
        for( int i = 0; i < 300; i++ ){
            p[i] = -1;
            c[i] = 0;
        }

        vector<par> sol;

        int n; cin >> n;

        string s; cin >> s;

        for( int i = 0; i < n; i++ ){
            c[ s[i] ]++;
            p[ s[i] ] = i;
        }

        for( int i = 0; i < 300; i++ ){
            if( c[i] ){
                sol.push_back( par( p[i] , c[i] ) );
            }
        }

        sort( sol.begin(), sol.end() );

        int outp = 0;
        int cont = 0;
        for( int i = 0; i < sol.size(); i++ ){
            if( cont != (sol[i].first - sol[i].second + 1) ){
                outp += ( (sol[i].first - sol[i].second + 1) - cont ) * sol[i].second * 5;
            }

            cont += sol[i].second;
        }

        cout << outp << '\n';
    }
}
