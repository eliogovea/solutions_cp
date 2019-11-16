// 2017-2018 ACM-ICPC Nordic Collegiate Programming Contest (NCPC 2017)
// 101572I

#include <bits/stdc++.h>

using namespace std;

const int oo = (1 << 29);
const int MAXN = 505;

vector<int> g[MAXN];

string names[MAXN];

bool mk[MAXN][MAXN];
int d[MAXN][MAXN];
int p[MAXN][MAXN];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int n; cin >> n;

    unordered_map<string,int> dic;

    for( int i = 1; i <= n; i++ ){
        cin >> names[i];
        dic[ names[i] ] = i;
    }

    for( int i = 1; i <= n; i++ ){
        string kk; int l; cin >> kk >> l;

        string s;
        getline(cin,s);
        for( int j = 1; j <= l; j++ ){
            s = "";
            getline( cin , s );

            //cerr << s << '\n';

            string name = "";
            bool ok = false;
            for( int c = 0; c < s.size(); c++ ){
                if( s[c] == ' ' ){
                    if( ok ){
                        g[i].push_back( dic[name] );

                        //cerr << names[i] << " ----> " << name << '\n';
                    }

                    ok = true;
                    name = "";
                    continue;
                }

                if( s[c] == ',' ){
                    continue;
                }

                name += s[c];

                if( c == s.size()-1 ){
                    g[i].push_back( dic[name] );
                    //cerr << names[i] << " ----> " << name << '\n';
                }
            }
        }
    }

    //return 0;

    for( int i = 1; i <= n; i++ ){
        for( int j = 1; j <= n; j++ ){
            d[i][j] = oo;
        }

        d[i][i] = 0;
    }

    for( int u = 1; u <= n; u++ ){
        for( int j = 0; j < g[u].size(); j++ ){
            int v = g[u][j];

            d[u][v] = 1;
            p[u][v] = u;
            mk[u][v] = true;

            if( u == v ){
                cout << names[u] << '\n';
                return 0;
            }
        }
    }

    for( int k = 1; k <= n; k++ ){
        for( int u = 1; u <= n; u++ ){
            for( int v = 1; v <= n; v++ ){
                if( d[u][k] + d[k][v] < d[u][v] ){
                    d[u][v] = d[u][k] + d[k][v];
                    p[u][v] = p[k][v];
                }
            }
        }
    }

    int ini = -1, fin = -1;
    for( int u = 1; u <= n; u++ ){
        for( int v = 1; v <= n; v++ ){
            if( u == v ){
                continue;
            }

            if( d[u][v] != oo && mk[v][u] && ( ini == -1 || d[u][v] + 1 < d[ini][fin] + 1 ) ){
                ini = u;
                fin = v;
            }
        }
    }

    if( ini == -1 ){
        cout << "SHIP IT\n";
        return 0;
    }

    vector<string> sol;
    sol.push_back( names[ini] );
    while( ini != fin ){
        sol.push_back( names[fin] );
        fin = p[ini][fin];
    }

    for( int i = sol.size()-1; i >= 0; i-- ){
        cout << sol[i] << " \n"[i == 0];
    }
}
