// 2017 United Kingdom and Ireland Programming Contest (UKIEPC 2017)
// 101606E

#include <bits/stdc++.h>

using namespace std;
struct pii{
    int first;
    int second;
    int idx;
    bool operator < ( const pii &b ) const{
        return first < b.first;
    }

};
const int maxn = 5100;
const int oo = 1<<30;
int n, m;
pair<int,int> s[maxn];
int p[maxn], r[maxn];
vector<pii> v;
vector<int> stree;

int op( int a, int b ){
    if( a == -1 )
        return b;
    if( b == -1 )
        return a;
    if( v[a].second < v[ b ].second )
        return a;
    else
        return b;

}

void build( int nod, int l, int r ){
    if( l == r ){
        stree[nod] = l;
        return ;
    }

    int mid = (l+r)>>1;

    build( 2*nod, l, mid );
    build( 2*nod+1, mid+1, r );

    stree[nod] = op( stree[2*nod], stree[2*nod+1] );

    return ;
}

int query( int nod, int l, int r, const int& ql, const int& qr ){
    if( qr < l || ql > r )
        return -1;

    if( ql <= l && r <= qr ){
        return stree[nod];
    }

    int mid = ( l+r )>>1;

    int lo = query( 2*nod, l, mid, ql, qr ),
        hi = query( 2*nod+1, mid+1, r, ql, qr );

    return op( lo, hi );

}

void update( int nod, int l, int r, int &pos, int val ){
    if( l == r && l == pos ){
        v[pos].second = val;
        return ;
    }
    int mid = ( l+r ) >> 1;

    if( pos <= mid ){
        update( 2*nod, l,mid, pos, val );
    }
    else{
        update( 2*nod+1, mid+1, r, pos, val );
    }
    stree[nod] = op( stree[2*nod], stree[2*nod+1] );

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen( "dat.txt", "r", stdin );

    cin >> n >> m;

    for( int i = 0; i < n; i++ ){
        cin >> s[i].first;
        s[i].second = i;
    }
    for( int i = 0; i < m; i++ ){
        cin >> p[i];
    }
    for( int i = 0; i < m; i++ ){
        cin >> r[i];
    }

    sort( s, s+n );
    reverse( s ,s+n );

    v.push_back( (pii){0,0,0} );

    for( int i = 0; i < m; i++ ){
        v.push_back( (pii){p[i], r[i], i+1 } );
    }
    sort( v.begin(), v.end() );

    stree.resize( 4*maxn );
    build( 1, 1, m );

    bool ans_ok = true;
    vector<int> ans(n);
    for( int i = 0; i < n && ans_ok; i++ ){
        int lo = lower_bound( v.begin(), v.end(), (pii){ s[i].first,0,0 } ) - v.begin();

        int q = query( 1, 1, m, lo, m );
        if( q == -1 || v[q].second == oo )
            ans_ok = false;
        else{
            update( 1, 1, m, q, oo );
            ans[ s[i].second ] = v[q].idx ;
        }

    }
    if( ans_ok ){
        for( int i = 0; i < ans.size(); i++ ){
            cout << ans[i] << " \n"[i+1==ans.size()];
        }
    }
    else
        cout << "impossible\n";

}
