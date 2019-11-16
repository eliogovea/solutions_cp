#include <bits/stdc++.h>

using namespace std;

const int maxn = 200000+ 100;

int st_max[4*maxn];
int st_min[4*maxn];
int a[maxn];
int n, m;

void build( int nod, int l, int r ){
    if( l == r ){
        st_min[nod] = st_max[nod] = a[l];
        return;
    }

    int mid = (l+r)>>1;

    build( 2*nod, l, mid );
    build( 2*nod+1, mid+1, r );

    st_max[nod] = max( st_max[2*nod], st_max[2*nod+1] );
    st_min[nod] = min( st_min[2*nod], st_min[2*nod+1] );
}


void update( int nod, int l, int r, int p, int v ){
    if( l == r && l == p ){
        st_max[nod] = st_min[nod ] = a[l] = v;
        return;
    }

    int mid = ( l+r )>>1;

    if( p <= mid )
        update( 2*nod, l, mid, p, v );
    else
        update( 2*nod+1, mid+1, r, p, v );

    st_max[nod] = max( st_max[2*nod], st_max[2*nod+1] );
    st_min[nod] = min( st_min[2*nod], st_min[2*nod+1] );
}

pair<int,int> query( int nod, int l, int r, int ql, int qr ){

    if( l > qr || r < ql ) return { INT_MAX, INT_MIN};

    if( ql <= l && r <= qr ){
        return { st_min[nod], st_max[nod] };
    }

    int mid = ( l+r )>>1;

    pair<int,int> lo = query( 2*nod, l, mid, ql, qr ),
                  hi = query( 2*nod+1, mid+1,r, ql,qr ),
                  comb;

    comb.first = min( lo.first, hi.first );
    comb.second = max( lo.second, hi.second );
    return comb;
}

int ans = -1;
void get_ans( int nod, int l, int r, int ql, int qr, int k ){
    if( l > qr || r < ql )
        return;

    if( st_max[nod] < k )
            return ;

    if( l == r ){
        ans = min( ans, l );
        return ;
    }

    int mid = (l+r)>>1;


    if( ql <= l && r <= qr ){

        if( st_max[nod] < k )
            return ;

        if( st_max[2*nod] >= k )
            get_ans( 2*nod, l, mid, ql, qr, k );
        else
            get_ans( 2*nod+1, mid+1, r, ql, qr, k );

        return;
    }

    get_ans( 2*nod, l, mid, ql, qr, k );
    get_ans( 2*nod+1, mid+1, r, ql, qr, k );

}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

   // freopen( "dat.txt", "r", stdin );

    cin >> n >> m;

    for( int i = 1; i <= n; i++ )
        cin >> a[i];
    build( 1, 1, n );

    while( m-- ){
        int t, a, b;
        cin >> t >> a >> b;

        if( t == 1 ){
            ans = 1<<29;
            get_ans( 1, 1, n, a, n, b );
            cout << (ans==(1<<29)?-1:ans) << '\n';
        }
        else{
            update( 1, 1, n, a, b );
        }

    }

}
