// 2012-2013 ACM-ICPC, NEERC, Southern Subregional Contest
// 100109F

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 4010;

int c[MAXN][MAXN];
int sz[MAXN];

int n, k;
int cnt = 0;

int ok( int t ){
    multiset<int> pq;

    for( int i = 1; i <= cnt; i++ ){
        if( sz[i] >= t ){
            pq.insert( c[i][t-1] );
        }

        if( pq.size() > k ){
            pq.erase( pq.find( (*pq.begin()) ) );
        }
    }

    if( pq.size() < k ){
        return 0;
    }

    int cost = 0;
    for( multiset<int>::iterator it = pq.begin(); it != pq.end(); it++ ){
        cost += (*it);
    }

    return cost;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    cin >> n >> k;
    map<int,int> dic;

    for( int i = 0; i < n; i++ ){
        int m, cs; cin >> m >> cs;
        if( dic.find(m) == dic.end() ){
            dic[m] = ++cnt;
        }

        int x = dic[m];
        c[x][ sz[x]++ ] = cs;
    }

    for( int i = 1; i <= cnt; i++ ){
        sort( c[i] , c[i] + sz[i] , greater<int>() );
        for( int j = 1; j < sz[i]; j++ ){
            c[i][j] += c[i][j-1];
        }
    }

    int t = 0;
    int cost = 0;
    int ini = 1, fin = n;

    while( ini <= fin ){
        int mid = ( ini + fin ) / 2;
        int cs = 0;

        if( (cs = ok(mid)) ){
            t = mid;
            cost = cs;
            ini = mid+1;
        }
        else{
            fin = mid-1;
        }
    }

    cout << t << ' ' << cost << '\n';
}
