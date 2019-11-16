// 2017-2018 ACM-ICPC Northern Eurasia (Northeastern European Regional) Contest (NEERC 17)
// 101630B

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll W, H;
bool check( ll a, ll b, ll h ){
    ///1 , 2, 4
    if( (a + 2*h <= W && 2*h + 2*b <= H) ||
        (a + 2*h <= H && 2*h + 2*b <= W) )
        return true;
    ///3, 5, 6
    if( (2*h + 2*b <= W && a+h+b <= H) ||
        (2*h + 2*b <= H && a+h+b <= W) )
        return true;
    //7
    if( (2*b + h + a <= H && 2*h + a <= W ) ||
        (2*b + h + a <= W && 2*h + a <= H ) )
        return true;
    //8, 10
    if( (2*h + b + a <= W && a + b + h <= H) ||
        (2*h + b + a <= H && a + b + h <= W) )
        return true;
    //9
    if( (3*a + h + b <= W && b + h <= H) ||
        (3*a + h + b <= H && b + h <= W))
        return true;
    //11
    if(( 2*h + b <= W && 2*a + h + b <= H ) ||
       ( 2*h + b <= H && 2*a + h + b <= W ))
       return true;

    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);
    vector<ll> v(3);
    cin >> v[0] >> v[1] >> v[2];
    cin >> H >> W;

    sort( v.begin(), v.end() );

    do{
        if( check( v[0], v[1], v[2] ) ){
            cout << "Yes\n";
            return 0;
        }
    }while( next_permutation( v.begin(), v.end() ) );

    cout << "No\n";
    return 0;
}
