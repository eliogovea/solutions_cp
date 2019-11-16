// 2014-2015 CT S02E07: Codeforces Trainings Season 2 Episode 7
// 100523C

#include <bits/stdc++.h>

using namespace std;

#define forr(i, n) for(int i = 0; i < (int)(n); ++i)
#define ffor(i, n) for(int i = 1; i <= (int)(n); ++i)
#define revforr(n , i) for(int i = (int)(n)-1; i >= 0; i--)

#define kasign(a,b) a = b

#define keqq( a , b ) (a == b)
#define kmineqq( a , b ) ( a <= b )
#define kmaxeqq( a , b ) ( a >= b )

#define kmm(a) a++

#define kadd(a,b) a+=b
#define krest(a,b) a-=b
#define kmas(a,b) (a+b)

#define kxorr( a , b ) (a ^ b)

#define kfill( a , n , v ) fill( a , a + n , v )
#define kmod( a , b ) ( a % b )

typedef long long ll;
const int MAXN = 10000;



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    ll n; cin >> n;

    while( !kmod( n , 2 ) ){
        n /= 2;
    }

    if( keqq( n , 1 ) ){
        cout << "TAK\n";
    }
    else{
        cout << "NIE\n";
    }
}
