#include <bits/stdc++.h>

using namespace std;
const int maxn = 100010;
int n;
vector<int> v[maxn];

int dis[maxn]; // nodo a dist i

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

   // freopen( "dat.txt", "r", stdin );
    int diam = 0;
    cin >> n;
    for( int i = 1,x; i <= n; i++ ){
        cin >> x;
        v[ x ].push_back( i );
        diam = max( diam, x );
    }

    int a, b;
    vector< pair<int,int> > ans;
    int d_center, ccent;
    if( diam %2 == 1 ){
        ccent = 2;
        d_center = diam/2+1;
    }
    else{
        ccent = 1;
        d_center = diam/2;
    }

    int curr_d = d_center;


    if( v[ curr_d ].size() != ccent ){
        cout << "Epic fail\n";
        return 0;

    }
    a = v[curr_d].back(); v[curr_d].pop_back();
    if( ccent == 2 ){
        b = v[curr_d].back();
        v[curr_d].pop_back();
        ans.push_back( make_pair( a, b ) );
    }
    else
        b = a;

    int c,d;

    dis[ curr_d ] = a;

    while(curr_d < diam ){
        curr_d++;
        if( v[ curr_d ].size() < 2 ){
            cout << "Epic fail\n";
            return 0;
        }

        c = v[curr_d].back(); v[curr_d].pop_back();
        d = v[curr_d].back(); v[curr_d].pop_back();
        ans.push_back( make_pair( a, c ) );
        ans.push_back( make_pair( b, d ) );
        a = c;
        b = d;
        dis[ curr_d ] = a;
    }

    for( int i = 0; i <= diam; i++ ){
        for( auto e: v[ i ] ){
            if( i <= d_center || !dis[i-1] ){
                cout << "Epic fail\n";
                return 0;
            }
            ans.push_back( make_pair( dis[i-1], e ) );
        }
    }

    cout << "I got it\n";
    //assert( ans.size() == n-1 );

    for( auto e: ans ){
        cout <<  e.first << " " << e.second << '\n';

    }

    return 0;
}
