// 2015-2016 Petrozavodsk Winter Training Camp, Makoto rng_58 Soejima Сontest 4
// 100959E

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<int> a;
int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen( "dat.txt", "r", stdin );

    cin >> n;

    for( int i = 0,x; i < n; i++ ){
        cin >> x;
        a.push_back(x);
    }
    sort( a.begin(), a.end() );

    int sol = 0;
    ll acc = 0;
    for( int i = 0; i < n ;i++ ){
        if( a[i] > acc ){
            acc += a[i];
            sol++;
        }
    }
    cout << sol << '\n';
}
