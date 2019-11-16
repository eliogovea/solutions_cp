#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300;

int from[MAXN];
bool mk[MAXN];

vector<int> g[MAXN];

bool dfs( int u ){
    if( mk[u] ){
        return false;
    }

    mk[u] = true;

    for( int i = 0; i < g[u].size(); i++ ){
        int v = g[u][i];
        if( !from[v] || dfs( from[v] ) ){
            from[v] = u;
            return true;
        }
    }

    return false;
}

typedef pair<int,int> par;

bool ok[MAXN];

int n;
string s;
string c[150];
int ans[150];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("dat.txt","r",stdin);

    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }

    for (int i = 1; i <= s.size(); i++) {
        for (int j = 1; j <= n; j++) {
            bool ok = false;
            for (int k = 0; k < c[j].size(); k++) {
                if (c[j][k] == s[i - 1]) {
                    ok = true;
                    break;
                }
            }
            if (ok) {
                g[i].push_back(j);
            }
        }
    }

    for( int i = 1; i <= s.size(); i++ ){
        fill( mk , mk + n + 1 , false );
        if( !dfs(i) ){
            cout << "NO\n";
            return 0;
        }
    }
    for( int i = 1; i <= n; i++ ){
        if( from[i] ){
            ans[ from[i] ] = i;
        }
    }
    cout << "YES\n";
    for (int i = 1; i <= s.size(); i++) {
        cout << ans[i];
        if (i + 1 <= s.size()) {
            cout << " ";
        }
    }
    cout << "\n";
}
