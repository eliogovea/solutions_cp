#include <bits/stdc++.h>

using namespace std;

const int oo = 1000000007;

typedef pair<int,int> par;

struct ev{
    int l, r;
    int id;

    ev(){}
    ev( int l, int r, int id ){
        this->l = l;
        this->r = r;
        this->id = id;
    }

    bool operator < ( const ev &o ) const {
        return l < o.l;
    }
};

struct st{
    int n;
    vector<int> mn;

    st(){}

    st( int n ){
        this->n = n;
        mn.assign(4*n+4,oo);
    }

    void build_st( int nod, int l, int r, vector<par> &vs ){
        if( l == r ){
            this->mn[nod] = vs[l].second;
            return;
        }

        int ls = nod * 2 , rs = ls + 1;
        int mid = ( l + r ) / 2;

        build_st( ls , l , mid , vs );
        build_st( rs , mid+1 , r , vs );

        this->mn[nod] = min( this->mn[ls] , this->mn[rs] );
    }

    int get_min( int nod, int l, int r, int lq, int rq ){
        if( l > rq || r < lq ){
            return oo;
        }

        if( lq <= l && r <= rq ){
            return this->mn[nod];
        }

        int ls = nod*2 , rs = ls + 1;
        int mid = ( l + r ) / 2;

        return min( get_min( ls , l , mid , lq , rq ) ,
                    get_min( rs , mid+1 , r , lq , rq ) );
    }
};


const int MAXN = 300100;

ev events[MAXN];

st ST[4*MAXN];
int mn_l[4*MAXN];
int mx_l[4*MAXN];
vector<par> r_id[4*MAXN];

void build_st( int nod, int l, int r ){
    mn_l[nod] = events[l].l;
    mx_l[nod] = events[r].l;
    r_id[nod].resize( r - l + 1 );
    ST[nod] = st( r - l + 1 );

    if( l == r ){
        r_id[nod][0] = par( events[l].r , events[l].id );
        ST[nod].build_st( 1 , 0 , r - l , r_id[nod] );
        return;
    }

    int ls = nod * 2 , rs = ls + 1;
    int mid = ( l + r ) / 2;

    build_st( ls , l , mid );
    build_st( rs , mid+1 , r );

    merge( r_id[ls].begin() , r_id[ls].end() , r_id[rs].begin() , r_id[rs].end() , r_id[nod].begin() );
    ST[nod].build_st( 1 , 0 , r - l , r_id[nod] );
}

int query_st( int nod, int l, int r, int l1, int l2, int r1, int r2 ){
    if( mn_l[nod] > l2 || mx_l[nod] < l1 ){
        return oo;
    }

    if( l1 <= mn_l[nod] && mx_l[nod] <= l2 ){
        int a = lower_bound( r_id[nod].begin() , r_id[nod].end(), par( r1 , 0 ) ) - r_id[nod].begin();
        int b = lower_bound( r_id[nod].begin() , r_id[nod].end(), par( r2+1 , 0 ) ) - r_id[nod].begin();
        b--;

        if( a > b ){
            return oo;
        }

        return ST[nod].get_min( 1 , 0 , r - l , a , b );
    }

    int ls = nod * 2 , rs = ls + 1;
    int mid = ( l + r ) / 2;

    return min( query_st( ls , l , mid , l1 , l2 , r1 , r2 ) ,
                query_st( rs , mid+1 , r , l1 , l2 , r1 , r2 ) );
}

vector<par> seats[MAXN];

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int n, s, m; cin >> n >> s >> m;

    for( int i = 0; i < m; i++ ){
        int si, a, b; cin >> si >> a >> b; b--;
        seats[si].push_back( par( a , b ) );
    }

    int sz = 0;
    for( int i = 1; i <= s; i++ ){
        if( seats[i].size() == 0 ){
            events[++sz] = ev( 1 , n , i );
            continue;
        }

        sort( seats[i].begin() , seats[i].end() );

        if( seats[i][0].first != 1 ){
            events[++sz] = ev( 1 , seats[i][0].first-1 , i );
        }

        for( int j = 0; j < seats[i].size()-1; j++ ){
            if( seats[i][j].second + 1 != seats[i][j+1].first ){
                events[++sz] = ev( seats[i][j].second+1 , seats[i][j+1].first - 1 , i );
            }
        }

        if( seats[i].back().second != n ){
            events[++sz] = ev( seats[i].back().second+1 , n , i );
        }
    }

    sort( events + 1 , events + 1 + sz );
    build_st( 1 , 1 , sz );

    int q; cin >> q;

    ll p = 0;
    while( q-- ){
        ll x, y; cin >> x >> y;
        ll a = x + p, b = y + p - 1;

        int res = 0;
        if( a < 1ll || (ll)n < b ){
            res = 0;
        }
        else{
            res = query_st( 1 , 1 , sz , 1 , a , b , n );
            if( res == oo ){
                res = 0;
            }
        }

        cout << res << '\n';
        p = res;
    }
}
