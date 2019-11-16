// 2017-2018 ACM-ICPC Southeastern European Regional Programming Contest (SEERC 2017)
// 101669K

#include <bits/stdc++.h>

using namespace std;

typedef pair<long long,int> par;

const int MAXN = 100100;

int a[MAXN];
long long lazy[4*MAXN];
par mn[4*MAXN];
void build_st( int nod, int l, int r ){
    if( l == r ){
        mn[nod] = par( a[l] , l );
        return;
    }

    int ls = nod*2, rs = ls + 1;
    int mid = ( l + r ) / 2;

    build_st( ls , l , mid );
    build_st( rs , mid + 1 , r );

    mn[nod] = min( mn[ls] , mn[rs] );
}

void propagate_st( int nod, int l, int r ){
    if( lazy[nod] ){
        mn[nod].first += lazy[nod];
        if( l < r ){
            int ls = nod*2, rs = ls + 1;
            lazy[ls] += lazy[nod];
            lazy[rs] += lazy[nod];
        }
        lazy[nod] = 0;
    }
}

void update_st( int nod, int l, int r, int lq, int rq, int upd ){
    propagate_st( nod , l , r );

    if( r < lq || rq < l ){ return; }
    if( lq <= l && r <= rq ){
        lazy[nod] += upd;
        propagate_st( nod , l , r );
        return;
    }

    int ls = nod*2, rs = ls + 1;
    int mid = ( l + r ) / 2;

    update_st( ls , l , mid , lq , rq , upd );
    update_st( rs , mid + 1 , r , lq , rq , upd );

    mn[nod] = min( mn[ls] , mn[rs] );
}

int sol[MAXN];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int n; cin >> n;

    for( int i = 1; i <= n; i++ ){
        cin >> a[i];
    }

    build_st( 1 , 1 , n );

    int i = n;
    while( i >= 1 ){
        //cerr << mn[1].second << '\n';

        if( mn[1].first != 1 ){
            update_st( 1 , 1 , n , 1 , n , -1 );
        }
        else{
            sol[ mn[1].second ] = i;
            update_st( 1 , 1 , n , mn[1].second , mn[1].second , (1<<29) );
            i--;
        }
    }

    for( int i = 1; i <= n; i++ ){
        cout << sol[i] << " \n"[i==n];
    }
}
