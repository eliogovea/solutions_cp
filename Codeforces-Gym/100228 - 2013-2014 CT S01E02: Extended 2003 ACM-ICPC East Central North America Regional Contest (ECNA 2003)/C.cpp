// 2013-2014 CT S01E02: Extended 2003 ACM-ICPC East Central North America Regional Contest (ECNA 2003)
// 100228C

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000100;
const int MAX = 1000000;

vector<int> f[MAXN];
bool mark[MAXN];
int m[MAXN];

int sol[MAXN];
bool mk[MAXN];

int getm( int p ){
    while( m[p] <= MAX && mk[  m[p] ] ){
        m[p] += p;
    }

    return m[p];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    for( int i = 2; i <= MAX; i += 2 ){
        f[i].push_back( 2 );
    }

    int i;

    for( i = 3; i <= MAX; i += 2 ){
        if( !mark[i] ){
            for( int j = i; j <= MAX; j += i ){
                f[j].push_back(i);
                mark[j] = true;
            }
        }
    }

    for( int i = 1; i <= MAX; i++ ){
        m[i] = i;
    }

    sol[1] = 1;
    sol[2] = 2;

    mk[1] = true;
    mk[2] = true;

    int kk = 2;

    int cc = 2;

    for( int i = 3; cc < 300000; i++ ){
        int xi = 1000000;
        for( int j = 0; j < f[kk].size(); j++ ){
            xi = min( xi , getm( f[kk][j] ) );
        }

        mk[xi] = true;
        sol[xi] = i;
        kk = xi;

        if( kk <= 300000 ){
            cc++;
        }
    }

    int n;

    while( cin >> n, n ){
        cout << "The number " << n << " appears in location " << sol[n] <<  ".\n";
    }
}
