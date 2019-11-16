#include <bits/stdc++.h>

using namespace std;

struct node;
typedef node* pnode;

struct node{
    int v;
    pnode ls, rs;

    node( int v ){
        this->v = v;
        ls = rs = NULL;
    }
};

const int MAXN = 100100;

pnode roots[MAXN];

void build_st( pnode &root, int l, int r ){
    root = new node( 0 );

    if( l == r ){
        root->v = 0;
        return;
    }

    int mid = ( l + r ) / 2;

    build_st( root->ls , l , mid );
    build_st( root->rs , mid+1 , r );
}

int sum( pnode t ){
    if( t == NULL ){
        return 0;
    }

    return t->v;
}

pnode new_version( pnode t, int l, int r, int pos, int v ){
    pnode clone = new node( t->v );

    if( l == r ){
        clone->v = v;
        return clone;
    }

    int mid = ( l + r ) / 2;

    if( mid < pos ){
        clone->ls = t->ls;
        clone->rs = new_version( t->rs , mid+1 , r , pos , v );
    }
    else{
        clone->rs = t->rs;
        clone->ls = new_version( t->ls , l , mid , pos , v );
    }

    clone->v = sum( clone->ls ) + sum( clone->rs );
    return clone;
}

int get_v( pnode t , int l, int r, int lq, int rq ){
    if( t == NULL ){
        return 0;
    }

    if( l > rq || r < lq ){
        return 0;
    }

    if( lq <= l && r <= rq ){
        return t->v;
    }

    int mid = ( l + r ) / 2;

    return get_v( t->ls , l , mid , lq , rq ) +
           get_v( t->rs , mid+1 , r , lq , rq );
}

int last[MAXN];

void print_st( pnode t , int l, int r ){
    if( t == NULL ){
        return;
    }

    if( l == r ){
        cerr << t->v << ' ';
        return;
    }

    int mid = ( l + r ) / 2;

    print_st( t->ls , l , mid );
    print_st( t->rs , mid+1 , r );
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int n, m; cin >> n >> m;

    build_st( roots[0] , 1 , n );

    for( int i = 1; i <= n; i++ ){
        int x; cin >> x;
        roots[i] = new_version( roots[i-1] , 1 , n , i , 1 );
        if( last[x] ){
            roots[i] = new_version( roots[i] , 1 , n , last[x] , 0 );
        }

        last[x] = i;
    }

    int q; cin >> q;
    int p = 0;
    for( int i = 1; i <= q; i++ ){
        int x, y; cin >> x >> y;
        int l = ( (x + p) % n ) + 1;
        int k = ( (y + p) % m ) + 1;

        int r = 0;
        int ini = l, fin = n;
        while( ini <= fin ){
            int mid = ( ini + fin ) / 2;

            if( get_v( roots[mid] , 1 , n , l , mid ) >= k ){
                r = mid;
                fin = mid-1;
            }
            else{
                ini = mid+1;
            }
        }

        p = r;

        cout << r << '\n';
    }
}
