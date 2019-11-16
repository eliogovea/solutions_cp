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

const int MAXN = 200100;

pnode roots[MAXN];

int head[MAXN];
int tail[MAXN];

int a[MAXN];

void build_st( pnode &root, int l, int r ){
    root = new node( 0 );

    if( l == r ){
        root->v = a[l];
        return;
    }

    int mid = ( l + r ) / 2;

    build_st( root->ls , l , mid );
    build_st( root->rs , mid+1 , r );
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

    return clone;
}

int get_v( pnode t , int l, int r, int pos ){
    if( l == r ){
        return t->v;
    }

    int mid = ( l + r ) / 2;

    if( pos <= mid ){
        return get_v( t->ls , l , mid , pos );
    }
    else{
        return get_v( t->rs , mid+1 , r , pos );
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int n; cin >> n;
    build_st(roots[0], 0, n);
    head[0] = 0;
    tail[0] = 0;
    for( int i = 1; i <= n; i++ ){
        int op;
        cin >> op;
        if (op == 1) {
            int v, x;
            cin >> v >> x;
            head[i] = head[v];
            tail[i] = tail[v] + 1;
            roots[i] = new_version(roots[v], 0, n, tail[v], x);
        } else {
            int v;
            cin >> v;
            roots[i] = roots[v];
            head[i] = head[v] + 1;
            tail[i] = tail[v];
            int x = get_v(roots[v], 0, n, head[v]);
            cout << x << "\n";
        }
    }
}
