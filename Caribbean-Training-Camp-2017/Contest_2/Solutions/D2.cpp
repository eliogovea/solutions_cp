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

const int MAXN = 400100;

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

int diff[MAXN];
int uni[MAXN];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("dat.txt","r",stdin);

    int n, m; cin >> n >> m;

    diff[0] = 0;
    uni[0] = 0;

    build_st(roots[0], 1, m);

    string op;
    int x;
    long long s = 0LL, y;
    int last = 0;
    for (int i = 1; i <= n; i++) {
        cin >> op;
        if (op[0] == 'a') {
            cin >> x;
            int c = get_v(roots[last], 1, m, x);
            roots[i] = new_version(roots[last], 1, m, x, c + 1);
            diff[i] = diff[last];
            uni[i] = uni[last];
            if (c == 0) {
                diff[i]++;
                uni[i]++;
            } else if (c == 1) {
                uni[i]--;
            }
            last = i;
        } else if (op[0] == 'r') {
            cin >> x;
            int c = get_v(roots[last], 1, m, x);
            if (c == 0) {
                roots[i] = roots[last];
                uni[i] = uni[last];
                diff[i] = diff[last];
            } else {
                roots[i] = new_version(roots[last], 1, m, x, c - 1);
                diff[i] = diff[last];
                uni[i] = uni[last];
                if (c == 1) {
                    diff[i]--;
                    uni[i]--;
                } else if (c == 2) {
                    uni[i]++;
                }
            }
            last = i;
        } else if (op[0] == 'd') {
            cin >> y;
            y = (y + s) % (long long)i;
            roots[i] = roots[last];
            diff[i] = diff[last];
            uni[i] = uni[last];
            s += (long long)diff[y];
            cout << diff[y] << "\n";
        } else if (op[0] == 'u') {
            cin >> y;
            y = (y + s) % (long long)i;
            roots[i] = roots[last];
            diff[i] = diff[last];
            uni[i] = uni[last];
            s += (long long)uni[y];
            cout << uni[y] << "\n";
        } else {
            cin >> x >> y;
            y = (y + s) % (long long)i;
            roots[i] = roots[last];
            diff[i] = diff[last];
            uni[i] = uni[last];
            int ans = get_v(roots[y], 1, m, x);
            s += (long long)ans;
            cout << ans << "\n";
        }
    }
}
