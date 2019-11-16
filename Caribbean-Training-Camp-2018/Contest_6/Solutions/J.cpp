#include <bits/stdc++.h>

using namespace std;

struct kk{
    int sum, mx, mn;
    bool isnull = false;
    kk( bool isnull = false ) : isnull(isnull) { sum = mx = mn = 0; }
    kk( int sum, int mx, int mn ) : sum(sum), mx(mx), mn(mn){}
};

void mergeKK( const kk &a, const kk &b, kk &c ){
    if( a.isnull && b.isnull ){
        c = kk(true);
    }
    else if( a.isnull ) c = kk( b.sum , b.mx , b.mn );
    else if( b.isnull ) c = kk( a.sum , a.mx , a.mn );
    else c = kk( a.sum + b.sum , b.mx , a.mn );
}

void buildSt( kk *st, int nod, int l, int r, string &s, char &c ){
    if( l == r ){
        if( s[l-1] != c ){
            st[nod] = kk();
            st[nod].isnull = true;
        }
        else{
            st[nod] = kk( 1 , l , l );
        }
        return;
    }

    int ls = nod << 1, rs = ls + 1, mid = (l+r) >> 1;
    buildSt( st , ls , l , mid , s, c );
    buildSt( st , rs , mid+1 , r , s, c );

    mergeKK( st[ls] , st[rs] , st[nod] );
}

void updateSt( kk *st , int nod, int l, int r, int p, int upd ){
    if( l == r ){
        if( upd == -1 ){
            st[nod] = kk( true );
        }
        else{
            st[nod] = kk( 1 , l , l );
        }
        return;
    }

    int ls = nod << 1, rs = ls + 1, mid = (l+r) >> 1;
    if( p <= mid ) {
        updateSt( st , ls , l , mid , p , upd );
    }
    else{
        updateSt( st , rs , mid+1 , r , p , upd );
    }

    mergeKK( st[ls] , st[rs] , st[nod] );
}

kk querySt( kk *st, int nod, int l, int r, int lq, int rq ){
    if( r < lq || rq < l || st[nod].isnull ) return kk(true);
    if( lq <= l && r <= rq ){
        return st[nod];
    }

    int ls = nod << 1, rs = ls + 1, mid = (l+r) >> 1;
    kk a = querySt( st , ls , l , mid , lq , rq );
    kk b = querySt( st , rs , mid+1 , r , lq , rq );

    kk c; mergeKK( a , b , c );
    return c;
}

const int MAXN = 100002;
const int MAXC = 'z' - 'a' + 2;
kk st[MAXC][4*MAXN];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    string s; cin >> s;

    int n = s.size();
    for( char c = 'a'; c <= 'z'; c++ ){
        buildSt( st[c - 'a'] , 1 , 1 , n , s , c );
    }

    int q; cin >> q;

    while( q-- ){
        int t; cin >> t;
        //cerr << "t = " << t <<'\n';

        if( t == 1 ){
            int l, r, k; cin >> l >> r >> k;
            int ini = l;
            char c = 'z';
            char sol = '-';

            while( k > 0 && ini <= r && c >= 'a' ){
                //cerr << "ini = " << ini << '\n';
                kk x = querySt( st[c - 'a'] ,  1 , 1 , n , ini , r );
                if( !x.isnull ){
                    sol = c;
                    k -= x.sum;
                    ini = x.mx + 1;
                }

                c--;
            }

            if( k > 0 ){
                sol = '-';
            }
            cout << sol << '\n';
        }
        else{
            int p; char c; cin >> p >> c;
            if( s[p-1] != c ){
                updateSt( st[ s[p-1] - 'a' ] , 1 , 1 , n , p , -1 );
                s[p-1] = c;
                updateSt( st[ s[p-1] - 'a' ] , 1 , 1 , n , p , 1 );
            }
        }
    }
}
