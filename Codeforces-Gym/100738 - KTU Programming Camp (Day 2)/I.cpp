// KTU Programming Camp (Day 2)
// 100738I

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100100;
typedef pair<int,int> par;

vector<par> g[MAXN];
vector<int> s[MAXN];

int inback[MAXN];

int k;

void dfs(int v){
    //cout << "v = " << v << '\n';

    inback[v] = 1;

    if( v != 1 && g[v].size() == 0 ){
        return;
    }

    for(int i = 0; i < g[v].size(); i++){
        int u = g[v][i].second;
        dfs(u);
        g[v][i].first = inback[u];
    }

    sort( g[v].begin() , g[v].end() , greater<par>() );
    int ss = 0;

    for(int i = 0; i < g[v].size(); i++){
        int u = g[v][i].second;
        ss += inback[u];
        s[v].push_back(ss);
    }

    int ind = min( k-1 , (int)g[v].size() ) - 1;
    if(ind >= 0){
        inback[v] += s[v][ind];
    }
}

int sol;

void dfs2(int v,int val){
    if( v != 1 && g[v].size() == 0 ){
        sol = max( sol , val + 1 );
        return;
    }

    for(int i = 0; i < g[v].size(); i++){
        int u = g[v][i].second;

        int val2 = val + 1;

        int kk = k-2;

        if( kk >= 0 ){
            if( g[v].size()-1 <= kk ){
                val2 += ( s[v][ g[v].size()-1 ] - inback[u] );
            }
            else if( i <= kk ){
                val2 += ( s[v][ kk+1 ] - inback[u] );
            }
            else{
                val2 += ( s[v][ kk ] );
            }
        }

        dfs2( u , val2 );
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int n; cin >> n >> k;

    for(int i = 1; i <= n; i++){
        int mi; cin >> mi;
        for(int j = 0; j < mi; j++){
            int u; cin >> u;
            g[i].push_back( par( 0 , u ) );
        }
    }

    if( n == 1 ){
        cout << "1\n";
        return 0;
    }

    //cout << "kaka2\n";

    dfs( 1 );

    //cout << "kaka\n";

    sol = 0;

    dfs2( 1 , 0 );

    cout << sol << '\n';
}
