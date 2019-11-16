// 2017-2018 ACM-ICPC Southeastern European Regional Programming Contest (SEERC 2017)
// 101669F

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 6000;
ll acc0;
int n;
ll c[maxn];
typedef pair<ll,int> plli;
//vector< plli > power_off, power_on, optional;
set<plli> on, off, optional;


ll solve( const set<plli> &on, const set<plli> &off){
    ll ret = 0;
    ll acc = acc0;
    for( auto it = off.rbegin(); it != off.rend(); it++ ){
        acc -= it->first;
        ret += acc;
    }
    for( auto it = on.begin(); it != on.end(); it++ ){
        acc += it->first;
        ret += acc;
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen( "dat.txt", "r", stdin );

    cin >> n;

    for( int i = 0; i < n; i++ ){
        cin >> c[i];
    }
    string a, b;
    cin >> a;
    for( int i = 0; i < n; i++ ){
        acc0 += ( a[i]=='1'?c[i]:0 );
    }
    cin >> b;
    for( int i = 0; i < n; i++ ){

        if( b[i] == '1' && a[i] == '0' ){
            on.insert( make_pair( c[i], i ) );
        }
        if( b[i] == '0' && a[i] == '1' ){
            off.insert( make_pair( c[i], i ) );
        }
        if( b[i] == '1' && a[i] == '1' )
            optional.insert( make_pair(c[i], i) );
    }


    ll ans = solve( on, off );
    for( auto it = optional.rbegin(); it != optional.rend(); it++ ){
        off.insert( *it );
        on.insert( *it );
        ans = min( ans, solve( on, off ) );

    }

    cout << ans << '\n';

}
