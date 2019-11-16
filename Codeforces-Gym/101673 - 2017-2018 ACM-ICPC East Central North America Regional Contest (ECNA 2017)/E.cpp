// 2017-2018 ACM-ICPC East Central North America Regional Contest (ECNA 2017)
// 101673E

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 510;

int n;
unordered_map<string,int> dic;

const int oo = (1<<29);

inline int getId( string s ){
    if( dic.find( s ) == dic.end() ){
        dic[s] = ++n;
    }
    return dic[s];
}

bool is[MAXN][MAXN];
int mx[MAXN][MAXN];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int N, m; cin >> N >> m;

    for( int i = 0; i < MAXN; i++ ){
        for( int j = 0; j < MAXN; j++ ){
            mx[i][j] = -oo;
        }
        is[i][i] = true;
    }

    for( int i = 0; i < N; i++ ){
        string su, op, sv; cin >> su >> op >> sv;

        int u = getId( su );
        int v = getId( sv );

        if( op == "is-a" ){
            is[u][v] = true;
            mx[u][v] = max( mx[u][v] , 0 );
        }
        else{
            mx[u][v] = 1;
        }
    }

    for (int it = 0; it < 5; it++) {
        for( int k = 1; k <= n; k++ ){
            for( int i = 1; i <= n; i++ ){
                for( int j = 1; j <= n; j++ ){
                    is[i][j] = is[i][j] || (is[i][k] && is[k][j]);

                    if( mx[i][k] != -oo && mx[k][j] != -oo ){
                        mx[i][j] = max( mx[i][j] , max(mx[i][k], mx[k][j]) );
                    }
                }
            }
        }
    }


    for( int q = 1; q <= m; q++ ){
        string su, op, sv; cin >> su >> op >> sv;
        if( dic.find( su ) == dic.end() || dic.find( sv ) == dic.end() ){
            cout << "Query " << q << ": false\n";
            continue;
        }

        int u = getId(su);
        int v = getId(sv);

        cout << "Query " << q << ": ";

        if( op == "is-a" ){
            if( is[u][v] ){
                cout << "true";
            }
            else{
                cout << "false";
            }
        }
        else{
            if( mx[u][v] < 1 ){
                cout << "false";
            }
            else{
                cout << "true";
            }
        }

        cout << "\n";
    }
}
