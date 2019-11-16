// 2011-2012 Northwestern European Regional Contest (NWERC 2011)
// 100729C

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200200;

int BIT[MAXN];

void update_bit( int maxn, int p, int upd ){
    while( p < MAXN ){
        BIT[p] += upd;
        p += ( p & -p );
    }
}

int get_bit( int p ){
    int ret = 0;
    while( p > 0 ){
        ret += BIT[p];
        p -= ( p & -p );
    }

    return ret;
}

int pos[MAXN];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int tc; cin >> tc;
    while( tc-- ){
        int n, m; cin >> n >> m;
        
        int maxn = n + m + 10;
        int top = n + m + 9;
        
        for( int i = 0; i < maxn; i++ ){
            BIT[i] = 0;
        }
        for( int i = n; i >= 1; i--, top-- ){
            pos[i] = top;
            update_bit( maxn , top , 1 );
        }
        for( int i = 0; i < m; i++ ){
            if( i > 0 ){
                cout << ' ';
            }

            int x; cin >> x;
            cout << get_bit( pos[ x ] ) - 1;
            update_bit( maxn , pos[x] , -1 );
            pos[x] = top--;
            update_bit( maxn , pos[x] , 1 );
        }
        cout << '\n';
    }
}
