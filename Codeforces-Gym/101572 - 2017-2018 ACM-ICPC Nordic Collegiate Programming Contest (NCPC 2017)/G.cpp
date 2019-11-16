// 2017-2018 ACM-ICPC Nordic Collegiate Programming Contest (NCPC 2017)
// 101572G

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200100;

void upd_bit( int *BIT, int p, int upd ){
    while( p < MAXN ){
        BIT[p] += upd;
        p += ( p & -p );
    }
}

int get_bit( int *BIT, int p ){
    int ret = 0;

    while( p > 0 ){
        ret += BIT[p];
        p -= ( p & -p );
    }

    return ret;
}

struct compe{
    int c, p, id, pos;

    compe(){}

    compe( int _c, int _p, int _id, int _pos ){
        c = _c;
        p = _p;
        id = _id;
        pos = _pos;
    }

    bool operator < ( const compe &o ) const {
        if( c != o.c ){
            return c > o.c;
        }
        if( p != o.p ){
            return p < o.p;
        }

        return id < o.id;
    }
};

compe x[MAXN];

int qt[MAXN];
int qp[MAXN];

int c[MAXN], p[MAXN];
int ord[MAXN];

int BIT[MAXN];
int now[MAXN];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int n, m; cin >> n >> m;

    for( int i = 1; i <= n; i++ ){
        x[i] = compe( 0 , 0 , i , i );
    }

    for( int i = 1; i <= m; i++ ){
        cin >> qt[i] >> qp[i];
        int u = qt[i];
        c[u]++;
        p[u] += qp[i];

        x[n+i] = compe( c[u] , p[u] , u , i+n );
    }

    sort( x+1 , x+1+n+m );

    for( int i = 1; i <= n + m; i++ ){
        ord[ x[i].pos ] = i;
    }

    for( int i = 1; i <= n; i++ ){
        upd_bit( BIT , ord[i] , 1 );
        now[i] = ord[i];
    }

    for( int i = 1; i <= m; i++ ){
        int u = qt[i];
        upd_bit( BIT , now[u] , -1 );
        now[u] = ord[n+i];
        upd_bit( BIT , now[u] , 1 );

        cout << get_bit( BIT , now[1] ) << '\n';
    }
}
