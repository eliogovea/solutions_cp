// 2003-2004 Summer Petrozavodsk Camp, Andrew Stankevich Contest 3 (ASC 3)
// 100198B

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 600;

vector<int> g[MAXN];

typedef pair<int,int> par;

par arr[MAXN];
int sol[MAXN];

int dic[MAXN];
int a[MAXN];

bool used[MAXN];
int MT[MAXN];
int ind[MAXN];

bool dfs( int u ){
    if( used[u] ){
        return false;
    }

    used[u] = true;

    for(int i = 0; i < g[u].size() ; i++){
        int v = g[u][i];
        if( MT[v] == -1 || dfs( MT[v] ) ){
            MT[v] = u;
            sol[ arr[u-1].second ] = v;
            return true;
        }
    }

    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("beloved.in","r",stdin);
    freopen("beloved.out","w",stdout);

    int n; cin >> n;

    for(int i = 0; i < n; i++){
        cin >> arr[i].first;
        arr[i].second = i+1;
    }

    sort( arr , arr + n , greater<par>() );

    for(int i = 0; i < n; i++){
        a[i+1] = arr[i].first;
        dic[ arr[i].second ] = i+1;
    }

    for(int i = 1; i <= n; i++){
        int u = dic[i];
        int ki; cin >> ki;
        for(int j = 1; j <= ki; j++){
            int v; cin >> v;
            g[u].push_back( v );
        }
    }

    for(int i = 0; i <= n; i++){
        MT[i] = -1;
    }


    for(int u = 1; u <= n; u++){
        for(int i = 0; i <= n; i++){
            used[i] = false;
        }
        dfs(u);
    }

    for(int i = 1; i <= n; i++){
        if( i > 1 ){
            cout << ' ';
        }
        cout << sol[i];
    }

    cout << '\n';
}