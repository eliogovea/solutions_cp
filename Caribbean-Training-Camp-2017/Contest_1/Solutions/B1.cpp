#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAXN = 100100;
const LL oo = 1e14;


LL st[4*MAXN];
LL lazy[4*MAXN];

void build_st( int nod, int l, int r ){
    lazy[nod] = st[nod] = -oo;
    if( l == r ){
        return;
    }

    int ls = nod*2, rs = ls + 1;
    int mid = ( l + r ) / 2;

    build_st( ls , l , mid );
    build_st( rs , mid+1 , r );
}

void propagate_st( int nod, int l, int r ){
    if( lazy[nod] != -oo ){
        st[nod] = max( st[nod] , lazy[nod] );
        if( l != r ){
            int ls = nod*2, rs = ls + 1;
            lazy[ls] = max( lazy[ls] , lazy[nod] );
            lazy[rs] = max( lazy[rs] , lazy[nod] );
        }
        lazy[nod] = -oo;
    }
}

void upd_st( int nod, int l, int r, int lq, int rq, LL upd ){
    propagate_st( nod , l , r );
    if( l > rq || r < lq ){
        return;
    }

    if( lq <= l && r <= rq ){
        lazy[nod] = upd;
        propagate_st( nod , l , r );
        return;
    }

    int ls = nod*2, rs = ls + 1;
    int mid = ( l + r ) / 2;

    upd_st( ls , l , mid , lq , rq , upd );
    upd_st( rs , mid+1 , r , lq , rq , upd );

    st[nod] = max( st[ls] , st[rs] );
}

void build_st_min( int nod, int l, int r ){
    propagate_st( nod , l , r );

    if( l == r ){
        return;
    }

    int ls = nod*2, rs = ls + 1;
    int mid = ( l + r ) / 2;

    build_st_min( ls , l , mid );
    build_st_min( rs , mid+1 , r );

    st[nod] = min( st[ls] , st[rs] );
}

LL query_st( int nod, int l, int r, int lq, int rq ){
    if( l > rq || r < lq ){
        return oo;
    }

    if( lq <= l && r <= rq ){
        return st[nod];
    }

    int ls = nod*2, rs = ls + 1;
    int mid = ( l + r ) / 2;

    return min( query_st( ls , l , mid , lq , rq ) ,
                query_st( rs , mid+1 , r , lq , rq ) );
}

struct query{
    int l, r;
    LL q;
};

query qs[MAXN];

int n;
void print_st( int nod, int l, int r ){
    if( l == r ){
        LL val = st[nod];
        if (val < -(1LL << 31LL)) {
            val = -(1LL << 31LL);
        }
        if (val > (1LL << 31LL) - 1LL) {
            val = (1LL << 31LL) - 1LL;
        }
        cout << val << " \n"[l==n];
        return;
    }

    int ls = nod*2, rs = ls + 1;
    int mid = ( l + r ) / 2;

    print_st( ls , l , mid );
    print_st( rs , mid+1 , r );
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    //freopen("dat.txt", "r", stdin);

    int m; cin >> n >> m;

    build_st( 1 , 1 , n );

    for( int i = 1; i <= m; i++ ){
        cin >> qs[i].l >> qs[i].r >> qs[i].q;
        upd_st( 1 , 1 , n , qs[i].l , qs[i].r , qs[i].q );
    }

    build_st_min( 1 , 1 , n );

    for( int i = 1; i <= m; i++ ){
        if( query_st( 1 , 1 , n , qs[i].l , qs[i].r ) != qs[i].q ){
            cout << "inconsistent\n";
            return 0;
        }
    }

    cout << "consistent\n";
    print_st( 1 , 1 , n );
}
