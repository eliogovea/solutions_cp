// 2012 Nordic Collegiate Programming Contest (NCPC)
// 100112C

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> par;

const int MAXN = 1000010;

int n;
par a[MAXN];
int ind[MAXN];
int pos[MAXN];

string l[MAXN];
int sz;

int get_num( string &s ){
    int n = s.size();

    int num = 0;
    for( int i = 0; i < n; i++ ){
        num *= 10;
        num += s[i] - '0';
    }

    return num;
}

int BIT[MAXN];

void update_bit( int ind , int upd ){
    while( ind < n ){
        BIT[ind] += upd;
        ind += ( ind & -ind );
    }
}

int query_bit( int ind ){
    int ret = 0;
    while( ind > 0 ){
        ret += BIT[ind];
        ind -= ( ind & -ind );
    }
    return ret;
}

int get_ith( int ith ){
    int p = 0;
    int ini = 1, fin = n-1;
    while( ini <= fin ){
        int mid = ( ini + fin ) / 2;
        if( query_bit( mid ) >= ith ){
            p = mid;
            fin = mid - 1;
        }
        else{
            ini = mid + 1;
        }
    }

    return p;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    n = 1;
    sz = 0;

    while( cin >> l[sz] ){
        if( l[sz][0] != '#' ){
            a[n] = par( get_num( l[sz] ) , sz );
            n++;
        }
        sz++;
    }

    sort( a + 1 , a + n );

    for( int i = 1; i < n; i++ ){
        ind[ a[i].second ] = i;
    }

    int cant = 0;

    for( int i = 0; i < sz; i++ ){
        if( l[i][0] != '#' ){
            update_bit( ind[i] , 1 );
            cant++;
        }
        else{
            int ith = ( cant & 1 ) ? ( cant + 1 ) / 2 : cant / 2 + 1;
            int p = get_ith( ith );

            cout << a[p].first << '\n';

            update_bit( p , -1 );
            cant--;
        }
    }
}
