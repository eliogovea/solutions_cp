#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> par;
typedef pair<par,int> kk;

const int MAXN = 100100;

vector<par> g[MAXN];

int ini[MAXN], fin[MAXN], tini[MAXN], tfin[MAXN];

int mn_lwb[MAXN];

map<par,kk> dic;

int a, b, ta, tb, lwb_tb;

bool dfs( int nod, int e, int lwb_father ){
    int lwb = lower_bound( g[nod].begin() , g[nod].end() , par( tfin[e] , 0 ) ) - g[nod].begin();

    if( lwb >= mn_lwb[nod] ){
        return false;
    }

    if( nod == b && lwb_tb >= lwb ){
        lwb_tb = lwb;
        dic[ par( nod , lwb ) ] = kk( par( ini[e] , lwb_father ) , e );
        return true;
    }
    dic[ par( nod , lwb ) ] = kk( par( ini[e] , lwb_father ) , e );

    int tmp = mn_lwb[nod];
    mn_lwb[nod] = lwb;

    for( int i = lwb; i < tmp; i++ ){
        int e2 = g[nod][i].second;

        if( dfs( fin[e2] , e2 , lwb ) ){
            return true;
        }
    }

    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int n, m; cin >> n >> m;

    for( int i = 1; i <= m; i++ ){
        cin >> ini[i] >> fin[i] >> tini[i] >> tfin[i];

        g[ ini[i] ].push_back( par( tini[i] , i ) );
    }

    cin >> a >> b >> ta >> tb;

    g[b].push_back( par( tb , 0 ) );

    for( int i = 1; i <= n; i++ ){
        sort( g[i].begin() , g[i].end() );
        mn_lwb[i] = g[i].size();
    }

    lwb_tb = lower_bound( g[b].begin() , g[b].end() , par( tb , 0 ) ) - g[b].begin();

    ini[0] = 0;
    tfin[0] = ta;

    if( !dfs( a , 0 , 0 ) ){
        cout << "Impossible\n";
        return 0;
    }

    vector<int> sol;
    int nod = b;
    int lwb = lwb_tb;

    while( nod ){
        kk go = dic[ par( nod , lwb ) ];
        int e = go.second;
        sol.push_back(e);

        nod = go.first.first;
        lwb = go.first.second;
    }

    cout << sol.size()-1 << '\n';
    for( int i = sol.size()-2; i >= 0; i-- ){
        cout << sol[i] << " \n"[i==0];
    }
}
