// 2016-2017 National Taiwan University World Final Team Selection Contest
// 101234G

#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> par;

const int MAXN = 200100;

int x[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    //freopen("dat.txt", "r", stdin);

    int n, k; cin >> n >> k;
    for( int i = 0; i < n; i++ ){
        cin >> x[i];
    }

    sort( x , x + n );

    multiset<par> s;
    s.insert( par( x[0] , 0 ) );

    while( k-- > 1 ){
        par cur = ( *s.begin() );
        s.erase( s.begin() );

        int sum = cur.first;
        int p = cur.second;

        if( p+1 < n ){
            s.insert( par( sum + x[p+1] , p+1 ) );
            s.insert( par( sum + x[p+1] - x[p] , p+1 ) );
        }

        while( s.size() > k ){
            s.erase( s.find( (*s.rbegin()) ) );
        }
    }

    cout << (*s.begin()).first << '\n';
}
