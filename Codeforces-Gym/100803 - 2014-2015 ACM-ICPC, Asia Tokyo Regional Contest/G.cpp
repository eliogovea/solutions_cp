// 2014-2015 ACM-ICPC, Asia Tokyo Regional Contest
// 100803G

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300100;

typedef pair<int,int> par;

int sum[MAXN*4];
int mini[MAXN*4];
int lazy[MAXN*4];
const int oo = (1<<29);

par join( par x, par y ){
    par ret = par( x.first + y.first , min( x.second , y.second ) );
    return ret;
}

void propagate_st(int node, int l, int r){
    if( lazy[node] != 0 ){

        sum[node] += ( r - l + 1 ) * lazy[node];
        mini[node] += lazy[node];

        if( l != r ){
            lazy[ node*2 ] += lazy[ node ];
            lazy[ ( node*2 ) + 1 ] += lazy[ node ];
        }

        lazy[ node ] = 0;
    }
}

void update_st( int node,int l,int r, int lq, int rq, int upd ){
    propagate_st( node , l  , r );

    if( l > rq || r < lq ){
        return;
    }
    if( lq <= l && r <= rq ){
        lazy[node] += upd;
        propagate_st( node , l, r );
        return;
    }
    int ls = node*2 , rs = ls + 1;
    int mid = ( l + r ) / 2;

    update_st( ls , l , mid , lq , rq , upd );
    update_st( rs , mid+1 , r , lq , rq , upd );

    par tmp = join( par( sum[ls] , mini[ls] ) , par( sum[rs] , mini[rs] ) );
    sum[node] = tmp.first;
    mini[node] = tmp.second;
}

int query_st( int node , int l , int r, int lq, int rq ){
    propagate_st( node, l, r );

    if( l > rq || r < lq ){
        return oo;
    }
    if( lq <= l && r <= rq ){
        return mini[node ];
    }

    int ls = node*2 , rs = ls + 1;
    int mid = ( l + r ) / 2;

    return min( query_st( ls , l , mid , lq , rq ) ,
                query_st( rs , mid+1 , r , lq , rq ) );
}

set<int> aa;
set<int> cc;

int n;

int get( int l, int r, int upd ){
    int sol = r;
    while( l <= r ){
        int mid = ( l + r ) / 2;
        int p = mid;
        if( upd < 0 ){
            p = *aa.lower_bound( mid );
        }
        else{
            p = *cc.lower_bound( mid );
        }

        if( query_st( 1 , 1 , n , p , n ) + upd >= 0 ){
            sol = p;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }

    update_st( 1 , 1 , n , sol , n , upd );

    return sol;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int q; cin >> n >> q;
    string s; cin >> s;

    for( int i = 1; i <= n; i++ ){
        if( s[i-1] == ')' ){
            update_st( 1 , 1 , n , i, n, -1 );
            cc.insert( i );
        }
        else{
            update_st( 1 , 1 , n , i, n, 1 );
            aa.insert( i );
        }
    }

    for( int i = 0; i < q; i++ ){
        int p; cin >> p;

        int upd = 2;

        if( cc.find( p ) != cc.end() ){
            update_st( 1 , 1 , n , p , n , 2 );
            cc.erase( cc.find(p) );
            aa.insert( p );
            upd = -2;
        }
        else{
            update_st( 1 , 1 , n , p , n , -2 );
            aa.erase( aa.find(p) );
            cc.insert( p );
        }

        int sol = get( 1 , p , upd );
        cout << sol << '\n';

        if( upd < 0 ){
            aa.erase( sol );
            cc.insert( sol );
        }
        else{
            cc.erase( sol );
            aa.insert( sol );
        }
    }
}
