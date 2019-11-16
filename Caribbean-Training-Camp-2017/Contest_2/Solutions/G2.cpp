#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct node;
typedef node* pnode;
struct node{
    int size;
    int value;
    pnode l, r;

    node(){}
    node( int value ){
        this->value = value;
        size = 1;
        l = r = NULL;
    }
};

int SIZE( pnode t ){
    return t == NULL ? 0 : t->size;
}

void update( pnode t ){
    if( t == NULL ){
        return;
    }

    t->size = SIZE( t->l ) + 1 + SIZE( t->r );
}

int CNT_NODE = 0;
node nodes[10001000];
pnode newnode( int v ){
    nodes[++CNT_NODE] = node(v);
    return nodes + CNT_NODE;
}

pnode copynode( pnode t ){
    if( t == NULL ){
        return NULL;
    }

    pnode res = newnode( t->value );
    res->l = t->l;
    res->r = t->r;
    res->size = t->size;
    return res;
}

const int elio = 2000000000;
inline int randint( int r = elio ){
    static unsigned int seed = 239017u;
    seed = seed * 1664525u + 1013904223u;
    return seed % r;
}

bool hey( pnode A, pnode B ) {
    //return SIZE(A) > SIZE(B);
    return (ll)(randint()) * (ll)(SIZE(A) + SIZE(B)) < (ll)SIZE(A) * (ll)elio;
}

void split( pnode t, int key, pnode &L, pnode &R, bool copie = true ){
    if( t == NULL ){
        L = R = NULL;
        return;
    }

    //cerr << "key = " << key << "   SIZE( t->l ) = " << SIZE( t->l ) << '\n';

    if( SIZE(t->l)+1 <= key ){
        if( copie ){
            L = copynode(t);
        }
        else{
            L = t;
        }
        split( t->r , key - (SIZE(t->l) + 1) , L->r , R , copie );
        update(L);
    }
    else{
        if( copie ){
            R = copynode(t);
        }
        else{
            R = t;
        }
        split( R->l , key , L , R->l , copie );
        update(R);
    }
}

pnode merge( pnode L, pnode R, bool copie = true ){
    pnode t = NULL;
    if( L == NULL || R == NULL ){
        if( copie ){
            t = L == NULL ? copynode(R) : copynode(L);
        }
        else{
            t = L == NULL ? R : L;
        }
        return t;
    }

    if( hey( L , R ) ){
        if( copie ){
            t = copynode(L);
        }
        else{
            t = L;
        }
        t->r = merge( t->r , R , copie );
    }
    else{
        if( copie ){
            t = copynode(R);
        }
        else{
            t = R;
        }
        t->l = merge( L , t->l , copie );
    }
    update(t);
    return t;
}

void build_treap( pnode &t, int l, int r, int *vs ){
    if( l == r ){
        t = newnode(vs[l]);
        return;
    }

    int mid = ( l + r ) / 2;
    t = newnode(vs[mid]);

    if( mid > l ){
        build_treap( t->l , l , mid-1 , vs );
    }

    if( mid < r ){
        build_treap( t->r , mid+1 , r , vs );
    }

    update(t);
}

int n;

int *vs;

int pos = 0;
void copy_treap( pnode t ){
    if( t == NULL ){
        return;
    }

    copy_treap( t->l );
    vs[++pos] = t->value;
    copy_treap( t->r );
}

void print_treap( pnode t, int pos ){
    if( t == NULL ){
        return;
    }

    print_treap( t->l , pos );
    pos += SIZE(t->l) + 1;

    cout << t->value << " \n"[pos==n];

    print_treap( t->r , pos );
}

int *cnt;
int *from;
int *to;
int m;

pnode check_memory( pnode root ){
    if( CNT_NODE >= 10000000 ){
        pos = 0;
        copy_treap( root );
        CNT_NODE = 0;
        root = NULL;

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

    pnode root;
    build_treap( root , 1 , n , vs );

    cnt = new int[m];
    from = new int[m];
    to = new int[m];

    for( int i = 0; i < m; i++ ){
        cin >> cnt[i] >> from[i] >> to[i];
    }

    for( int i = m-1; i >= 0; i-- ){
        root = check_memory(root);

        pnode l, r, l2, r2, clone;

        split( root , to[i]+cnt[i]-1 , l , r );
        split( l , to[i]-1 , l2 , r2 );

        clone = r2;

        pnode l3 , r3 , l4 , r4;

        split( root , from[i]+cnt[i]-1 , l3 , r3 );
        split( l3 , from[i]-1 , l4 , r4 );

        root = merge( merge( l4 , clone ) , r3 );
    }

    print_treap( root , 0 );

    //cerr << sizeof(node*) << '\n';
}
