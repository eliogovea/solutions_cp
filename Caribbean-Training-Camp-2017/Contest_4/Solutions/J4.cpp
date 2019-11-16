#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> par;

const int MAXN = 200100;

int X1[MAXN], X2[MAXN], Y1[MAXN], Y2[MAXN];

vector<int> qs[MAXN];
vector<int> upd[MAXN];

int st[4*MAXN];

void upd_st( int nod, int l, int r, int p, int v ){
    if( l == r ){
        st[nod] = max( st[nod] , v );
        return;
    }

    int ls = nod*2, rs = ls + 1;
    int mid = ( l + r ) / 2;

    if( p <= mid ){
        upd_st( ls , l , mid , p , v );
    }
    else{
        upd_st( rs , mid+1 , r , p , v );
    }

    st[nod] = max( st[ls] , st[rs] );
}

int query_st( int nod, int l, int r, int lq, int rq ){
    if( l > rq || r < lq ){
        return 0;
    }

    if( lq <= l && r <= rq ){
        return st[nod];
    }

    int ls = nod*2, rs = ls + 1;
    int mid = ( l + r ) / 2;

    return max( query_st( ls , l , mid , lq , rq ) ,
                query_st( rs , mid+1 , r , lq , rq ) );
}


int sol[MAXN];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int n; cin >> n;

    vector<int> coord1;
    vector<int> coord2;

    for( int i = 1; i <= n; i++ ){
        cin >> X1[i] >> X2[i] >> Y1[i] >> Y2[i];
        coord1.push_back( X1[i] );
        coord1.push_back( X2[i] );

        coord2.push_back( Y1[i] );
        coord2.push_back( Y2[i] );
    }

    sort( coord1.begin() , coord1.end() );
    coord1.erase( unique( coord1.begin() , coord1.end() ) , coord1.end() );

    sort( coord2.begin() , coord2.end() );
    coord2.erase( unique( coord2.begin() , coord2.end() ) , coord2.end() );

    for( int i = 1; i <= n; i++ ){
        X1[i] = lower_bound( coord1.begin() , coord1.end() , X1[i] ) - coord1.begin();
        X2[i] = lower_bound( coord1.begin() , coord1.end() , X2[i] ) - coord1.begin();

        Y1[i] = lower_bound( coord2.begin() , coord2.end() , Y1[i] ) - coord2.begin();
        Y2[i] = lower_bound( coord2.begin() , coord2.end() , Y2[i] ) - coord2.begin();

        qs[ X1[i] ].push_back(i);
        upd[ X2[i]+1 ].push_back(i);
    }

    int maxX = coord1.size();
    int maxY = coord2.size();

    int ans = 0;

    for( int x = 0; x <= maxX; x++ ){
        for( int j = 0; j < upd[x].size(); j++ ){
            int e = upd[x][j];
            upd_st( 1 , 0 , maxY , Y2[e] , sol[e] );
        }

        for( int j = 0; j < qs[x].size(); j++ ){
            int e = qs[x][j];
            sol[e] = query_st( 1 , 0 , maxY , 0 , Y1[e] ) + 1;
            ans = max( ans , sol[e] );
        }
    }

    cout << ans << '\n';
}
