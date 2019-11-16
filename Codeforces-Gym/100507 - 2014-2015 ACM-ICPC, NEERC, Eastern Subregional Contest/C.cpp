// 2014-2015 ACM-ICPC, NEERC, Eastern Subregional Contest
// 100507C

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100100;
typedef long long ll;
ll stree[4*MAXN],
    lazy[4*MAXN];

ll gan[MAXN];
struct date{
    ll mes, dia, h, mi, idx;
    date(){};
    date( int a, int b, int c, int d, int e ){
        mes = a; dia = b; h = c; mi = d; idx = e;
    }
    bool operator<( const date & b ) const{
        if( mes != b.mes )
            return mes < b.mes;
        if( dia != b.dia )
            return dia < b.dia;
        if( h != b.h )
            return h < b.h;
        return mi < b.mi;
    }
};
vector<date> fecha, org;

ll comb( ll a, ll b ){
    return min( a,b );
}

void propagate( int nod, int l, int r ){
    if( l == r ){
        lazy[nod] = 0LL;
        return;
    }
    stree[2*nod] += lazy[nod];
    lazy[2*nod] += lazy[nod];
    stree[2*nod+1] += lazy[nod];
    lazy[2*nod+1] += lazy[nod];
    lazy[nod] = 0LL;

}

int ul, ur;
ll uval;
void update( int nod, int l, int r ){
    propagate(nod, l, r);
    if( r < ul || l > ur )
        return;

    if( ul <= l && r <= ur ){
        stree[nod] += uval;
        lazy[nod] += uval;
        return;
    }
    int mid = (l+r)>>1;

    update( 2*nod, l, mid );
    update( 2*nod+1, mid+1, r );
    stree[nod] = comb( stree[2*nod], stree[2*nod+1] );
}

int ql, qr;
ll query( int nod, int l, int r ){
    propagate( nod, l, r );
    if( r < ql || l > qr )
        return 0;
    if( ql <= l && r <= qr )
        return stree[nod];

    int mid = (l+r)>>1;
    return comb( query( 2*nod, l, mid ), query( 2*nod+1, mid+1, r ) );
}

int main(){
    //ios::sync_with_stdio(0);
   // cin.tie(0);
  //  freopen( "dat.txt", "r", stdin ) ;
    ll n;
    scanf( "%I64d", &n );
    for( int i = 0,x,d,m,h,mm; i < n; i++ ){
        scanf( "%d %d.%d %d:%d", &x, &d, &m, &h, &mm );
       // cout << x << " " << d << endl;
        gan[i] = x;
        org.push_back( date( m,d,h,mm, i ) );
        fecha.push_back( date( m,d,h,mm, i ) );
    }
    sort( fecha.begin(), fecha.end() );
    for( int i = 0; i < n; i++ ){
        int p = lower_bound( fecha.begin(), fecha.end(), org[i] ) - fecha.begin() +1;
        ul = p, ur = n;
        uval = gan[i];
        update( 1, 1, n );
        ql = 1; qr = n;
        ll ans = query( 1, 1, n );
        //cout << min( ans, 0LL ) << '\n';
        printf( "%I64d\n", min( ans, 0LL ) );
    }
}
