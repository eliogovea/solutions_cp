#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef complex<long double> Complex;
const double PI = acos(-1);

void fft( vector<Complex> &a, int n, int dir ){

    int lg = 0;
    while( n > (1<<lg) ) lg++;

    assert( n == (1<<lg) );

    for( int i = 0; i < n; i++ ){
        int pos = 0;
        for( int j = 0; j < lg; j++ ){
            pos <<= 1;
            pos |= (i>>j) & 1;
        }

        if( i < pos ){
            swap( a[i], a[pos] );
        }
    }

    for( int i = 1; i <= lg; i++ ){

        int m = 1<<i;
        int k = m>>1;
        Complex w, wn, u, t;
        wn = Complex( cos( (long double)dir*2.0*PI/(long double)m), sin( (long double)dir*2.0*PI/(long double)m ) );

        for( int j = 0; j < n; j += m ){
            w = Complex( 1.0, 0.0 );
            for( int l = j; l < j+k; l++ ){
                t = w*a[l+k];
                u = a[l];
                a[l] = u + t;
                a[l+k] = u - t;
                w *= wn;
            }
        }

    }
    if( dir == -1 ){
        for( int i = 0; i < n; i++ ){
            a[i] /= (long double)n;

        }

    }

}

int B = 1000;
int D = 2;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen( "dat.txt", "r", stdin );

    string a, b;
    cin >> a >> b;

    int siga = 1, sigb = 1;

    if( a[0] == '-' ){
        siga = -1;
        a = a.substr( 1, a.size()-1 );
    }
    if( a[0] == '+' ){
        siga = 1;
        a = a.substr( 1, a.size()-1 );
    }

    if( b[0] == '-' ){
        sigb = -1;
        b = b.substr( 1, b.size()-1 );
    }
    if( b[0] == '+' ){
        sigb = 1;
        b = b.substr( 1, b.size()-1 );
    }


    vector<Complex> P, Q;
    for( int i = a.size()-1; i >= 0;  ){
        int num = 0;
        for( int j = i-D; j <= i; j++ ){
            if( j >= 0 ){
                num *= 10;
                num += a[j] - '0';
            }
        }
        P.push_back( num );
        i -= D+1;

    }
    /*cerr << "p:";
    for( auto e: P )
        cerr << e << " ";
    cerr << endl;*/
    for( int i = b.size()-1; i >= 0;  ){
        int num = 0;
        for( int j = i-D; j <= i; j++ ){
            if( j >= 0 ){
                num *= 10;
                num += b[j] - '0';
            }
        }
        Q.push_back(num);
        i-= D+1;
    }
    /*cerr << "q:";
    for( auto e: Q )
           cerr << e << " ";
    cerr << endl;*/


    int fftn = 1;
    int n = Q.size() + P.size();
    while( n > (fftn) ) fftn <<= 1;
    P.resize( fftn );
    Q.resize( fftn );
    fft( Q, fftn, 1 );

    fft( P, fftn, 1 );

    for( int i = 0; i < P.size(); i++ )
        P[i] *= Q[i];

    fft( P, fftn, -1 );
    vector<ll> ans;
    for( int i = 0; i < P.size(); i++ )
        ans.push_back( round( P[i].real() ) );

    for( int i = 0; i < ans.size(); i++ ){
        if( ans[i] >= B ){
            if( i+1 == ans.size() ){
                ans.push_back( ans[i]/B );
            }
            else ans[i+1] += ans[i]/B;
            ans[i] %= B;
        }

    }
    while( ans.size() && ans.back() == 0 ) ans.pop_back();
    reverse( ans.begin(), ans.end() );
    if( ans.size() == 0 ){
        printf("0\n");
        return 0;
    }

    if( siga != sigb )
        printf( "-" );
    for( int i = 0; i < ans.size(); i++ ){
        if( i == 0 )
            printf( "%lld", ans[i] );
        else{
            printf( "%03lld", ans[i] );
        }
    }
    printf( "\n" );
}
