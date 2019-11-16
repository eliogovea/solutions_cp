#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX_CNTNODES = 11000000;
int size[MAX_CNTNODES], value[MAX_CNTNODES],
    ls[MAX_CNTNODES], rs[MAX_CNTNODES];
void update( int t ){
    if( !t ) return;
    size[t] = size[ ls[t] ] + 1 + size[ rs[t] ];
}
int CNT_NODE = 0;
int newnode( int v ){
    int t = ++CNT_NODE;
    value[t] = v;
    size[t] = 1;
    return t;
}
int copynode( int t ){
    if( !t ) return 0;
    int ct = newnode( value[t] );
    ls[ct] = ls[t];
    rs[ct] = rs[t];
    size[ct] = size[t];
    return ct;
}
const int elio = 2000000000;
inline int randint( int r = elio ){
    static unsigned int seed = 239017u;
    seed = seed * 1664525u + 1013904223u;
    return seed % r;
}
bool hey( int A, int B ) {
    return (ll)(randint()) * (ll)(size[A] + size[B]) <
           (ll)size[A] * (ll)elio;
}
void split( int t, int key, int &L, int &R,
            bool copie = true ){
    if( !t ){ L = R = 0; return; }
    if( size[ls[t]] + 1 <= key ){
        L = copie ? copynode(t) : t;
        split( rs[L] , key - (size[ls[t]] + 1) , rs[L] , R , copie );
        update(L);
    }
    else{
        R = copie ? copynode(t) : t;
        split( ls[R] , key , L , ls[R] , copie );
        update(R);
    }
}
int merge( int L, int R, bool copie = true ){
    int t = NULL;
    if( !L || !R ){
        if( copie )
            t = !L ? copynode(R) : copynode(L);
        else
            t = !L ? R : L;
        return t;
    }
    if( hey( L , R ) ){
        t = copie ? copynode(L) : L;
        rs[t] = merge( rs[t] , R , copie );
    }
    else{
        t = copie ? copynode(R) : R;
        ls[t] = merge( L , ls[t] , copie );
    }
    update(t);
    return t;
}
void build_treap( int &t, int l, int r, int *vs ){
    if( l == r ){
        t = newnode(vs[l]);
        return;
    }
    int mid = ( l + r ) >> 1;
    t = newnode(vs[mid]);
    if( mid > l )
        build_treap( ls[t] , l , mid-1 , vs );
    if( mid < r )
        build_treap( rs[t] , mid+1 , r , vs );
    update(t);
}
int n;
int *vs;
int pos = 0;
void copy_treap( int t ){
    if( !t ) return;
    copy_treap( ls[t] );
    vs[++pos] = value[t];
    copy_treap( rs[t] );
}
void print_treap( int t, int pos ){
    if( !t ){
        return;
    }
    print_treap( ls[t] , pos );
    pos += size[ls[t]] + 1;
    cout << value[t] << " \n"[pos==n];
    print_treap( rs[t] , pos );
}
int *cnt;
int *from;
int *to;
int m;
int check_memory( int root ){
    if( CNT_NODE >= 10000000 ){
        pos = 0;
        copy_treap( root );
        CNT_NODE = 0;
        root = 0;
        build_treap( root , 1 , n , vs );
    }
    return root;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    cin >> n >> m;

    vs = new int[n+1];

    for( int i = 1; i <= n; i++ ){
        vs[i] = i;
    }

    int root;
    build_treap( root , 1 , n , vs );

    cnt = new int[m];
    from = new int[m];
    to = new int[m];

    for( int i = 0; i < m; i++ ){
        cin >> cnt[i] >> from[i] >> to[i];
    }

    for( int i = m-1; i >= 0; i-- ){
        root = check_memory(root);

        int l, r, l2, r2, clone;

        split( root , to[i]+cnt[i]-1 , l , r );
        split( l , to[i]-1 , l2 , r2 );

        clone = r2;

        int l3 , r3 , l4 , r4;

        split( root , from[i]+cnt[i]-1 , l3 , r3 );
        split( l3 , from[i]-1 , l4 , r4 );

        root = merge( merge( l4 , clone ) , r3 );
    }

    print_treap( root , 0 );

    //cerr << sizeof(node*) << '\n';
}
