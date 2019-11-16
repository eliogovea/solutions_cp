#include <bits/stdc++.h>

using namespace std;

struct node;
typedef node* pnode;
struct node{
    int mn, mx, lazy;
    pnode ls, rs;

    node( int c ){
        mn = c;
        mx = c;
        lazy = 0;
        ls = rs = nullptr;
    }
};

pnode LS( pnode &nod ){
    if( nod->ls == nullptr ){
        nod->ls = new node(0);
    }
    return nod->ls;
}
pnode RS( pnode &nod ){
    if( nod->rs == nullptr ){
        nod->rs = new node(0);
    }
    return nod->rs;
}

void puttag( pnode &nod, int l, int r, int c ){
    nod->lazy = c;
    nod->mx = nod->mn = c;
}

void pushdown( pnode &nod, int l, int r ){
    if( l < r && nod->lazy ){
        pnode ls = LS(nod), rs = RS(nod);
        int mid = (l+r)/2;
        puttag( ls , l , mid , nod->lazy );
        puttag( rs , mid+1 , r , nod->lazy );
        nod->lazy = 0;
    }
}

void merge_st( pnode &nod ){
    pnode ls = LS(nod), rs = RS(nod);
    nod->mx = max( ls->mx , rs->mx );
    nod->mn = min( ls->mn , rs->mn );
}

void update_st( pnode &nod, int l, int r, int lq, int rq, int c ){
    if( r < lq || rq < l ) return;
    if( lq <= l && r <= rq ){
        puttag(nod, l, r, c);
        return;
    }

    pushdown( nod , l , r );

    pnode ls = LS(nod), rs = RS(nod);
    int mid = ( l + r ) / 2;

    update_st( ls , l , mid , lq , rq , c );
    update_st( rs , mid+1 , r , lq , rq , c );

    merge_st( nod );
}

const int MAXK = 50010;
int sol[MAXK];
void solve( pnode &nod, int l, int r ){
    if( nod->mn == nod->mx ){
        sol[ nod->mn ] += (r - l + 1);
        return;
    }

    pushdown( nod , l , r );
    pnode ls = LS(nod), rs = RS(nod);
    int mid = ( l + r ) / 2;

    solve( ls , l , mid );
    solve( rs , mid+1 , r );
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int n,k; cin >> n >> k;

    pnode st = new node(0);

    int m; cin >> m;

    for( int i = 1; i <= m; i++ ){
        int l, r, c; cin >> c >> l >> r;

        update_st( st , 1 , n , l , r , c );
    }

    solve( st , 1 , n );
    for( int i = 1; i <= k; i++ ){
        cout << sol[i] << " \n"[i==n];
    }
}

