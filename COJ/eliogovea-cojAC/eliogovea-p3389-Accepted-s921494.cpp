#include <bits/stdc++.h>
#define MAXN 110000
using namespace std;
typedef unsigned long long ll;
struct suff{
    string s;
    bool w;

};
bool cmp( const suff&a, const suff &b ){
    if (a.s != b.s)
        return a.s < b.s;
    return a.w < b.w;
}

int n;
string a,b;
char mk[300];
vector< suff > v;

string make_suff( string a, int x ){
    fill( mk+64, mk+200, '0' );
    string res = a;
    int c = 'a';
    for( int i = x; i < x+n; i++ ){
            if( mk[ a[i] ] == '0'  ){
                mk[ a[i] ] = c++;
            }
            res[i-x] = mk[ a[i] ];
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen( "dat.txt", "r", stdin );
    cin >> n;
    cin >> a >> b;
    a += a;
    b += b;
    for( int i = 0; i < n; i++ ){
        v.push_back( (suff){make_suff( a,i ), 0} );
        v.push_back( (suff){make_suff( b,i ), 1} );
    }
    int sol = 0;
//    cout <<"ok"<< endl;

    sort( v.begin(), v.end() , cmp);
    //for( int i = 0; i < v.size(); i++ )
    //    cout << v[i].s << endl;

    for( int i = 0; i < v.size()-1; i++ ){
        if( v[i].w != v[i+1].w ){
            int c = 0;
            for( ; c < n && v[i].s[c] == v[i+1].s[c]; c++ );
            sol =max( sol, c );
        }
    }
    cout << sol << endl;



}
