// 2009-2010 Petrozavodsk Winter Training Camp, Warsaw Contest
// 100603J

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int B1 = 37;
const int M1 = (1 << 27) + ( 1 << 25 ) + 1;

const int B2 = 43;
const int M2 = 1000000007;

const ll DD = 10000000000ll;

int add( int a, int b, int mod ){
    a += b;
    if( a >= mod ){
        a -= mod;
    }
    return a;
}

int rest( int a, int b, int mod ){
    a -= b;
    if( a < 0 ){
        a += mod;
    }

    return a;
}

int mult( int a, int b, int mod ){
    return ( (ll)a * (ll)b ) % mod;
}


int n,l, m;

const int MAXN = 1010;
const int MAXL = 105;

string s[MAXN];
int PW1[MAXN];
int PW2[MAXN];

int h1[MAXN];
int h2[MAXN];

ll h[MAXN];

typedef pair<int,int> par;
vector<par> trains[MAXN];

struct data{
    vector<int> t;
    vector<int> change;
    vector<int> v;
    vector<int> st;

    int n;

    data(){}

    void init(){
        n = 0;
        for( int i = 1; i < t.size(); i++ ){
            if( t[n] == t[i] ){
                change[n] += change[i];
            }
            else{
                n++;
                t[n] = t[i];
                change[n] = change[i];
            }
        }
        n++;

        v.assign( n , 0 );
        st.assign( n*4 + 2 , 0 );

        for( int i = 0; i < n; i++ ){
            if( i > 0 ){
                v[i] = v[i-1];
            }
            v[i] += change[i];
        }

        build_st( 1 , 0 , n-1 );
    }

    void build_st( int nod, int l, int r ){
        if( l == r ){
            st[nod] = v[l];
            return;
        }

        int ls = nod*2 , rs = ls + 1;
        int mid = ( l + r ) / 2;

        build_st( ls , l , mid );
        build_st( rs , mid+1 , r );

        st[nod] = max( st[ls] , st[rs] );
    }

    int query_st( int nod, int l, int r, int lq, int rq ){
        if( r < lq || rq < l ){
            return 0;
        }

        if( lq <= l && r <= rq ){
            return st[nod];
        }

        int ls = nod*2 , rs = ls + 1;
        int mid = ( l + r ) / 2;

        return max( query_st( ls , l , mid , lq , rq ) ,
                    query_st( rs , mid+1 , r , lq , rq ) );
    }

    int query( int tl, int tr ){
        int l = lower_bound( t.begin() , t.begin() + n , tl ) - t.begin();
        int r = upper_bound( t.begin() , t.begin() + n , tr ) - t.begin();
        r--;

        if( r < l ){
            return 0;
        }

        return query_st( 1 , 0 , n-1 , l , r );
    }
};

data x[500000];

int sz;
map<ll,int> dic;

inline int get_id( ll h ){
    if( dic.find(h) == dic.end() ){
        dic[h] = ++sz;
    }

    return dic[h];
}

inline void insert_in_x( int id, int t, int change ){
    x[id].t.push_back( t );
    x[id].change.push_back( change );
}

inline void insert_in_trains( int p, int id, int t ){
    trains[p].push_back( par( id , t ) );
}

int sol[MAXN];

int sz2;
map<string,int> dic2;
int get_id2( string h ){
    if( dic2.find(h) == dic2.end() ){
        dic2[h] = ++sz2;
    }

    return dic2[h];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    cin >> n >> l >> m;

    PW1[0] = 1;
    PW2[0] = 1;
    for( int i = 1; i <= l; i++ ){
        PW1[i] = mult( PW1[i-1] , B1 , M1 );
        PW2[i] = mult( PW2[i-1] , B2 , M2 );
    }

    for( int i = 1; i <= n; i++ ){
        cin >> s[i];
        for( int j = 0; j < s[i].size(); j++ ){
            h1[i] = add( mult( h1[i] , B1, M1 ) , s[i][j] - 'a' , M1 );
            h2[i] = add( mult( h2[i] , B2, M2 ) , s[i][j] - 'a' , M2 );
        }

        h[i] = (ll)h1[i] * DD + (ll)h2[i];

        int id = get_id( h[i] );

        //cerr << id << " " << get_id2( s[i] ) << '\n';

        insert_in_trains( i , id , 0 );
        insert_in_x( id , 0 , 1 );
    }

    for( int time = 1; time <= m; time++ ){
        int p1,w1,p2,w2; cin >> p1 >> w1 >> p2 >> w2;
        //cerr << p1 << " " << w1 << ' ' << p2 << ' ' << w2 << '\n';

        if( s[p1][w1-1] == s[p2][w2-1] ){
            continue;
        }

        //cerr << p1 << "--" << p2 << "    " << s[p1] << "   " << s[p2] << "  ----->  ";

        //cerr << get_id( h[p1] ) << " " << get_id2( s[p1] ) << '\n';
        //cerr << get_id( h[p2] ) << " " << get_id2( s[p2] ) << '\n';

        if( p1 == p2 ){
            insert_in_x( get_id( h[p1] ) , time , -1 );
        }
        else{
            insert_in_x( get_id( h[p1] ) , time , -1 );
            insert_in_x( get_id( h[p2] ) , time , -1 );
        }

        h1[p1] = rest( h1[p1] , mult( s[p1][w1-1] , PW1[ s[p1].size() - w1 ] , M1 ) , M1 );
        h2[p1] = rest( h2[p1] , mult( s[p1][w1-1] , PW2[ s[p1].size() - w1 ] , M2 ) , M2 );

        h1[p2] = rest( h1[p2] , mult( s[p2][w2-1] , PW1[ s[p2].size() - w2 ] , M1 ) , M1 );
        h2[p2] = rest( h2[p2] , mult( s[p2][w2-1] , PW2[ s[p2].size() - w2 ] , M2 ) , M2 );

        swap( s[p1][w1-1] , s[p2][w2-1] );

        h1[p1] = add( h1[p1] , mult( s[p1][w1-1] , PW1[ s[p1].size() - w1 ] , M1 ) , M1 );
        h2[p1] = add( h2[p1] , mult( s[p1][w1-1] , PW2[ s[p1].size() - w1 ] , M2 ) , M2 );
        h[p1] = (ll)h1[p1] * DD + (ll)h2[p1];

        h1[p2] = add( h1[p2] , mult( s[p2][w2-1] , PW1[ s[p2].size() - w2 ] , M1 ) , M1 );
        h2[p2] = add( h2[p2] , mult( s[p2][w2-1] , PW2[ s[p2].size() - w2 ] , M2 ) , M2 );
        h[p2] = (ll)h1[p2] * DD + (ll)h2[p2];

        insert_in_trains( p1 , get_id( h[p1] ) , time );

        if( p1 != p2 ){
            insert_in_trains( p2 , get_id( h[p2] ) , time );
        }
        //cerr << get_id( h[p1] ) << " " << get_id2( s[p1] ) << '\n';
        //cerr << get_id( h[p2] ) << " " << get_id2( s[p2] ) << '\n';

        insert_in_x( get_id( h[p1] ) , time , 1 );

        if( p1 != p2 ){
            insert_in_x( get_id( h[p2] ) , time , 1 );
        }
    }

    for( int i = 1; i <= sz; i++ ){
        x[i].init();
    }

    for( int i = 1; i <= n; i++ ){
        insert_in_trains( i , 0 , m+5 );
        for( int j = 0; j+1 < trains[i].size(); j++ ){
            int id = trains[i][j].first;
            int tl = trains[i][j].second;
            int tr = trains[i][j+1].second - 1;

            sol[i] = max( sol[i] , x[id].query( tl , tr ) );
        }

        cout << sol[i] << '\n';
    }
}
