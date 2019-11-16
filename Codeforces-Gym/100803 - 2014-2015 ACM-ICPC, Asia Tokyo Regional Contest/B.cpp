// 2014-2015 ACM-ICPC, Asia Tokyo Regional Contest
// 100803B

#include <bits/stdc++.h>

using namespace std;

typedef long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    string s; cin >> s;
    ll r; cin >> r;

    int n = s.size();

    ll m = 0;
    ll x = s[0] - '0';

    ll l = s[0] - '0';

    for( int i = 2; i < n; i += 2 ){
        if( s[i-1] == '*' ){
            x *= (ll)( s[i] - '0' );
            l *= (ll)( s[i] - '0' );
        }
        else{
            m += x;
            x = (ll)s[i] - '0';

            l += (ll)( s[i] - '0' );
        }
    }
    m += x;

    if( l == r && m == r ){
        cout << "U\n";
    }
    else if( l != r && m != r ){
        cout << "I\n";
    }
    else if( l == r ){
        cout << "L\n";
    }
    else{
        cout << "M\n";
    }
}
