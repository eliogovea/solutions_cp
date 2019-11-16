// 2014-2015 ACM-ICPC, NEERC, Southern Subregional Contest
// 100513K

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2005;

int g[MAXN][MAXN];
bool mk[MAXN];

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);

    //freopen("dat.txt", "r", stdin);

    //int tc; cin >> tc;
    int tc;
    scanf("%d",&tc);

    while( tc-- ){
        int n; scanf("%d",&n); //cin >> n;

        for( int i = 1; i <= n; i++ ){
            mk[i] = false;

            for( int j = 1; j <= n; j++ ){
                scanf("%d",&g[i][j]);//cin >> g[i][j];
            }
        }

        mk[1] = true;

        for( int i = 2; i <= n; i++ ){
            int v = g[1][i];
            int nod = 1;

            for( int j = 2; j <= n; j++ ){
                if( mk[ g[v][j] ] ){
                    nod = g[v][j];
                    break;
                }
            }

            mk[v] = true;

            //cout << nod << ' ' << v << '\n';
            printf("%d %d\n",nod, v);
        }

        printf("\n");
    }
}
