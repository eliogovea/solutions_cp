#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
bool cmp( const pii &a, const pii &b ){
    if( a.first != b.first )
        return a.first > b.first;
    return a.second < b.second;
}
vector<pii> v;
int f[100];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    for( auto e: s ){
        f[e-'0']++;
    }
    for( int i = 0; i < 10; i++ ){
        if( f[i] )
            v.push_back( make_pair( f[i], i ) );
    }
    sort( v.begin(), v.end(), cmp );

    for( int i = 0; i < v.size(); i++ ){
        cout << v[i].second << " \n"[i+1==v.size()];

    }
}

