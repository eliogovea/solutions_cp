// 2016-2017 CT S03E05: Codeforces Trainings Season 3 Episode 5 (2016 Stanford Local Programming Contest, Extended)
// 101116G

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXN = 500100;

ll st[2][4*MAXN];
ll lazyA[2][4*MAXN];
ll lazyS[2][4*MAXN];

void build_st( ll *st, ll *lazyA , ll *lazyS, int nod, int l, int r ){
    lazyA[nod] = lazyS[nod] = -1;

    if( l == r ){
        st[nod] = 0ll;
        return;
    }

    int ls = nod * 2, rs = ls + 1;
    int mid = ( l + r ) / 2;

    build_st( st , lazyA , lazyS, ls , l , mid );
    build_st( st , lazyA , lazyS, rs , mid+1 , r );
}

void propagate_st( ll *st , ll *lazyA , ll *lazyS, int nod, int l, int r ){
    if( lazyA[nod] != -1 ){
        if( l == r ){
            st[nod] += lazyS[nod];
        }
        else{
            int ls = nod*2, rs = ls + 1;
            int mid = ( l + r ) / 2;

            lazyS[ls] = max( lazyS[ls] , 0ll );
            lazyS[rs] = max( lazyS[rs] , 0ll );

            lazyA[ls] = max( lazyA[ls] , 0ll );
            lazyA[rs] = max( lazyA[rs] , 0ll );

            lazyS[ls] += lazyS[nod];
            lazyA[ls] += lazyA[nod];

            lazyS[rs] += lazyS[nod] + lazyA[nod] * ( mid+1-l );
            lazyA[rs] += lazyA[nod];
        }

        lazyA[nod] = -1;
        lazyS[nod] = -1;
    }
}

void update_st( ll *st , ll *lazyA , ll *lazyS, int nod, int l, int r, int lq, int rq, ll S, ll A ){
    propagate_st( st , lazyA , lazyS , nod , l , r );

    if( r < lq || l > rq ){
        return;
    }

    if( lq <= l && r <= rq ){
        lazyS[nod] = max( lazyS[nod] , 0ll );
        lazyA[nod] = max( lazyA[nod] , 0ll );

        lazyS[nod] += S + A * ( l - lq );
        lazyA[nod] += A;

        propagate_st( st , lazyA , lazyS , nod , l , r );

        return;
    }

    int ls = nod*2 , rs = ls + 1;
    int mid = ( l + r ) / 2;

    update_st( st , lazyA , lazyS, ls , l , mid , lq , rq , S , A );
    update_st( st , lazyA , lazyS, rs , mid+1 , r , lq , rq , S , A );
}

ll query_st( ll *st , ll *lazyA , ll *lazyS, int nod, int l, int r, int pos ){
    propagate_st( st , lazyA , lazyS , nod , l , r );

    if( l == r ){
        return st[nod];
    }

    int mid = ( l + r ) / 2;
    if( pos <= mid ){
        int ls = nod*2;
        return query_st( st , lazyA , lazyS, ls , l , mid , pos );
    }

    int rs = nod*2 + 1;
    return query_st( st , lazyA , lazyS, rs , mid+1 , r , pos );
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//freopen("dat.txt", "r", stdin);

	int tc; cin >> tc;

	while( tc-- ){
        int n , m; cin >> m >> n;

        build_st( st[0] , lazyA[0] , lazyS[0] , 1 , 1 , n );
        build_st( st[1] , lazyA[1] , lazyS[1] , 1 , 1 , n );

        while( m-- ){
            char typ; cin >> typ;

            if( typ == 'U' ){
                char dir; cin >> dir;

                if( dir == 'E' ){
                    int i, s, a, d; cin >> i >> s >> a >> d;
                    update_st( st[0] , lazyA[0] , lazyS[0] , 1 , 1 , n , i , i + d - 1, s , a );
                }
                else{
                    int i, s, a, d; cin >> i >> s >> a >> d;
                    i = n - i + 1;

                    update_st( st[1] , lazyA[1] , lazyS[1] , 1 , 1 , n , i , i + d - 1 , s , a );
                }
            }
            else{
                int pos; cin >> pos;
                cout << query_st( st[0] , lazyA[0] , lazyS[0] , 1 , 1 , n , pos ) +
                        query_st( st[1] , lazyA[1] , lazyS[1] , 1 , 1 , n , n - pos + 1 ) << '\n';
            }
        }
    }
}
