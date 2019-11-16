// 2014-2015 CTU Open Contest
// 100719H

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1000010;

typedef pair<ll,ll> par;
typedef pair<ll,par> line;

line l[MAXN];
line h[MAXN];
line v[MAXN];

int enqh , deqh , enqv ,  deqv;

bool ok( line l , bool ho ){
    if( ho ){
        ll al = min( l.second.first , l.second.second );
        ll bl = max( l.second.first , l.second.second );

        for( int i = deqv; i < enqv; i++ ){
            ll av = min( v[i].second.first , v[i].second.second );
            ll bv = max( v[i].second.first , v[i].second.second );

            if( al <= v[i].first && v[i].first <= bl &&
                av <= l.first && l.first <= bv ){
                return false;
            }
        }

        for( int i = deqh; i < enqh; i++ ){
            ll ah = min( h[i].second.first , h[i].second.second );
            ll bh = max( h[i].second.first , h[i].second.second );

            if( l.first == h[i].first &&
               ( (al <= ah && ah <= bl) || (al <= bh && bh <= bl) ) ){
                return false;
            }
        }
    }
    else{
        ll al = min( l.second.first , l.second.second );
        ll bl = max( l.second.first , l.second.second );

        for( int i = deqh; i < enqh; i++ ){
            ll ah = min( h[i].second.first , h[i].second.second );
            ll bh = max( h[i].second.first , h[i].second.second );

            if( al <= h[i].first && h[i].first <= bl &&
                ah <= l.first && l.first <= bh ){
                return false;
            }
        }

        for( int i = deqv; i < enqv; i++ ){
            ll av = min( v[i].second.first , v[i].second.second );
            ll bv = max( v[i].second.first , v[i].second.second );

            if( l.first == v[i].first &&
               ( (al <= av && av <= bl) || (al <= bv && bv <= bl) ) ){
                return false;
            }
        }
    }

    return true;
}

const int MAXC = 15;

void addline( line l , bool ho ){
    if( ho ){
        h[enqh++] = l;

        if( enqh - deqh >= MAXC ){
            deqh++;
        }
    }
    else{
        v[enqv++] = l;

        if( enqv - deqv >= MAXC ){
            deqv++;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int n;

    while( cin >> n ){
        enqh = deqh = enqv = deqv = 0;

        par p = par( 0 , 0 );

        ll aa; cin >> aa;

        l[0] = line( p.first , par( p.second , p.second + aa ) );
        p.second += aa;

        for( int i = 1; i < n; i++ ){
            ll a; cin >> a;

            if( !(i & 1) ){ // vertical
                if( !(( i / 2 ) & 1) ){ // north
                    l[i] = line( p.first , par( p.second+1 , p.second + a ) );
                    p.second += a;
                }
                else{ // south
                    l[i] = line( p.first , par( p.second-1 , p.second - a ) );
                    p.second -= a;
                }
            }
            else{
                if( !(( i / 2 ) & 1) ){ // east
                    l[i] = line( p.second , par( p.first+1 , p.first + a ) );
                    p.first += a;
                }
                else{ //west
                    l[i] = line( p.second , par( p.first-1 , p.first - a ) );
                    p.first -= a;
                }
            }
        }

        int i = 0;
        for( ; i < n; i++ ){
            if( !ok( l[i] , (i & 1) ) ){
                cout << i << '\n';
                break;
            }

            addline( l[i] , (i & 1) );
        }

        if( i == n ){
            cout << "OK\n";
        }
    }
}
