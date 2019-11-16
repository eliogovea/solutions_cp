// 2014-2015 CT S02E07: Codeforces Trainings Season 2 Episode 7
// 100523F

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
const int MAXN = 1000005;

typedef pair<int,int> par;

multiset<int> col;

int d[MAXN];
bool mk[MAXN];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int n, k; cin >> n >> k;

    forr( i , n ){
        cin >> d[i];
        kasign( d[i] , d[i] * 5 );
    }

    forr( i , k ){
        int x; cin >> x;
        col.insert( x );
    }

    sort( d , kmas( d , n ) , greater<int>() );

    int sol( 0 );

    forr( i , n ){
        int a( (d[i]/5)*3 );
        int b( (d[i]/5)*2 );

        multiset<int>::iterator it( col.lower_bound( d[i] ) );

        if( keqq( it , col.end() ) ){
            kadd( sol , 2 );

            kasign( it , col.lower_bound(a) );
            if( keqq( it , col.end() ) ){
                cout << "NIE\n";
                return 0;
            }
            else{
                col.erase( it );
            }

            kasign( it , col.lower_bound(b) );
            if( keqq( it , col.end() ) ){
                cout << "NIE\n";
                return 0;
            }
            else{
                col.erase( it );
            }
        }
        else{
            kadd( sol , 1 );
            col.erase( it );
        }
    }

    cout << sol << '\n';
}
