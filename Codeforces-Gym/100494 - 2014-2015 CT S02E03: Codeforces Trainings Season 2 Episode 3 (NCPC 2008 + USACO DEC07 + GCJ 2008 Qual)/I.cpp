// 2014-2015 CT S02E03: Codeforces Trainings Season 2 Episode 3 (NCPC 2008 + USACO DEC07 + GCJ 2008 Qual)
// 100494I

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200100;

int a[MAXN+10];
int next[MAXN+10];
int dic[MAXN+10];
int dic2[MAXN+10];

int st[4*MAXN];

void build_st( int nod, int l , int r ){
    st[nod] = MAXN-1;
    if( l == r ){
        return;
    }

    int ls = nod*2, rs = ls+1;
    int mid = ( l + r ) / 2;

    build_st( ls , l , mid );
    build_st( rs , mid+1 , r );
}

void upd_st( int nod, int l, int r, int pos, bool insert ){
    if( l == r ){
        if( insert ){
            st[nod] = l;
        }
        else{
            st[nod] = MAXN-1;
        }

        return;
    }

    int ls = nod * 2, rs = ls + 1;
    int mid = ( l + r ) / 2;

    if( pos <= mid ){
        upd_st( ls , l , mid , pos , insert );
    }
    else{
        upd_st( rs , mid+1 , r , pos , insert );
    }

    st[nod] = ( next[ st[ls] ] > next[ st[rs] ] ) ? st[ls] : st[rs];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("in.txt","r",stdin);

    int sz, n, m; cin >> sz >> n >> m;

    for( int i = 0; i < m; i++ ){
        cin >> a[i];

        dic[ a[i] ] = MAXN;
    }

    for( int i = m-1; i >= 0; i-- ){
        next[ i ] = dic[ a[i] ];
        dic[ a[i] ] = i;
    }

    next[MAXN-1] = -1;

    fill( st , st + (4*MAXN), MAXN-1 );

    //build_st( 1 , 0 , m-1 );

    set<int> cache;

    int sol = 0;

    for( int i = 0; i < m; i++ ){
        if( cache.size() < sz ){
            if( cache.find( a[i] ) == cache.end() ){
                sol++;
                cache.insert( a[i] );
                upd_st( 1 , 0 , m-1 , i , true );
            }
            else{
                upd_st( 1 , 0 , m-1 , dic2[ a[i] ] , false );
                upd_st( 1 , 0 , m-1 , i , true );
            }
        }
        else{
            if( cache.find( a[i] ) == cache.end() ){
                sol++;
                int ind = st[1];
                cache.erase( a[ind] );
                cache.insert( a[i] );
                upd_st( 1 , 0 , m-1 , ind , false );
                upd_st( 1 , 0 , m-1 , i , true );
            }
            else{
                upd_st( 1 , 0 , m-1 , dic2[ a[i] ] , false );
                upd_st( 1 , 0 , m-1 , i , true );
            }
        }

        dic2[ a[i] ] = i;
    }

    cout << sol << '\n';
}
