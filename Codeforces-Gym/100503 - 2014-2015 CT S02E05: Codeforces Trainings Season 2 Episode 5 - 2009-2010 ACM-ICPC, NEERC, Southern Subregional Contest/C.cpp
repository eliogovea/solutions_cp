// 2014-2015 CT S02E05: Codeforces Trainings Season 2 Episode 5 - 2009-2010 ACM-ICPC, NEERC, Southern Subregional Contest
// 100503C

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200000;

typedef long long ll;

struct arc{
    ll ind , a, b, r, c;
    arc(){}
    arc( ll indd, ll aa, ll bb, ll rr, ll cc ){
        ind = indd;
        a = aa;
        b = bb;
        r = rr;
        c = cc;
    }

    bool operator < ( const arc &o ) const {
        if( r != o.r ){
            return r > o.r;
        }
        return c > o.c;
    }
}arcs[MAXN];

int setof[MAXN];
bool join( int u, int v ){
    int ju = u;
    while( setof[ju] > 0 ){
        ju = setof[ju];
    }

    int jv = v;
    while( setof[jv] > 0 ){
        jv = setof[jv];
    }

    if( ju == jv ){
        return false;
    }

    if( setof[ju] < setof[jv] ){
        setof[ju] += setof[jv];
        setof[jv] = ju;
    }
    else{
        setof[jv] += setof[ju];
        setof[ju] = jv;
    }

    return true;
}

int nums[MAXN];

bool comp( const arc &x, const arc &y ){
    return x.c < y.c;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    //freopen("in.txt","r",stdin);

    int n; cin >> n;

    int sz = 0;

    for( int i = 0; i < n; i++ ){
        arcs[i].ind = i+1;
        cin >> arcs[i].a >> arcs[i].b >> arcs[i].r >> arcs[i].c;
        nums[sz++] = arcs[i].a;
        nums[sz++] = arcs[i].b;
    }
    sort( nums, nums + sz );

    map<int,int>  dic;
    int k = 0;
    for( int i = 0; i < sz; i++ ){
        if( i == 0 || nums[i] != nums[i-1] ){
            k++;
        }
        dic[ nums[i] ] = k;
    }

    fill( setof , setof + sz + 1 , -1 );

    ll sol = 0ll;

    sort( arcs , arcs + n );

    for( int i = 0; i < n; i++ ){
        int u = dic[ arcs[i].a ];
        int v = dic[ arcs[i].b ];

        if( join( u , v ) ){
            sol += arcs[i].c;
        }
    }

    cout << sol << '\n';
    sort( arcs , arcs + n , comp );

    for( int i = 0; i < n; i++ ){
        if( i > 0 ){
            cout << ' ';
        }
        cout << arcs[i].ind;
    }
    cout << '\n';
}
