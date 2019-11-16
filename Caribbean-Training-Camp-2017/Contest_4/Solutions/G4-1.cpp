#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;

vector<int> g[MAXN];
char op[MAXN];

int n;

int go[MAXN];
int from[MAXN];
bool mk[MAXN];
bool ok[MAXN];

bool dfs( int u ){
    if( mk[u] ){
        return false;
    }

    mk[u] = true;
    for( int i = 0; i < g[u].size(); i++ ){
        int v = g[u][i];
        if( op[v] == 'Y'|| ok[v] ){
            continue;
        }

        if( !from[v] || dfs(from[v]) ){
            go[u] = v;
            from[v] = u;
            return true;
        }
    }

    return false;
}

int kuhn(){
    fill( go , go + n + 1 , 0 );
    fill( from , from + n + 1 , 0 );
    fill( mk , mk + n + 1 , false );

    int mx = 0;
    for( int u = 1; u <= n; u++ ){
        fill( mk , mk + n + 1 , false );
        if( op[u] == 'Y' && !ok[u] && dfs(u) ){
            mx++;
        }
    }

    return mx;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    cin >> n;
    string s; getline( cin , s );

    for( int u = 1; u <= n; u++ ){
        getline( cin , s );
        op[u] = s[0];
        int v = 0;
        for( int i = 2; i < s.size(); i++ ){
            if( s[i] != ' ' ){
                v *= 10;
                v += s[i] - '0';

                if( i+1 == s.size() || s[i+1] == ' ' ){
                    g[u].push_back(v);
                    g[v].push_back(u);
                    v = 0;
                }
            }
        }
    }

    vector<int> sol;

    int mx = kuhn();

    for( int u = 1; u <= n && mx > 0; u++ ){
        ok[u] = true;
        if( kuhn() == mx-1 ){
            sol.push_back(u);
            mx--;
        }
        else{
            ok[u] = false;
        }
    }

    cout << sol.size() << '\n';
    for( int i = 0; i < sol.size(); i++ ){
        cout << sol[i] << '\n';
    }
}
