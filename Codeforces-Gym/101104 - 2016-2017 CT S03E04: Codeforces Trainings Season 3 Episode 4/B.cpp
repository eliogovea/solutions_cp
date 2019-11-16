// 2016-2017 CT S03E04: Codeforces Trainings Season 3 Episode 4
// 101104B

#include <bits/stdc++.h>

using namespace std;

const int N = 2005;

int tc;
int score[110][1100],
    pt[1000];
pair<int,int> sol[110];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    cin >> tc;
    int p, g;
    while( tc-- ){
        cin >> p >> g;
        for( int i = 0; i < p; i++ ){
            for( int j = 0; j < g; j++ )
                cin >> score[i][j];
            sort( score[i], score[i]+g );
        }

        for( int i = 0; i < p ; i++ ){
            bool ok = false;
            int ans = g;
            fill( pt, pt+p, g );
            for( int j = g-1; j >= 0 && !ok; j-- ){
                for( int k = 0; k < p && !ok; k++ ){
                    if( k == i ) continue;
                    pt[ k ]--;
                    while( pt[k] >= 0 && score[i][j] <= score[ k ][ pt[k] ] )
                        pt[k]--;
                    if( pt[k] == -1 ){
                        ok = true;
                        ans = g - (j + 1);
                    }

                }
            }
            sol[i].second = ans;
           // cout << ans << '\n';
        }

        for( int i = 0; i < p; i++ ){
            int ans = 0;
            fill( pt, pt+p, 0 );
            for( int j = 0; j < g; j++ ){
                for( int k = 0; k < p; k++ ){
                    if( k == i  ) continue;
                    if( pt[k] == g ) continue;
                    while( pt[k] < g && score[i][j] > score[k][ pt[k] ] )
                        pt[k]++;

                }
                int id = -1;
                for (int k = 0; k < p; k++) {
                    if (k == i) {
                        continue;
                    }
                    if (pt[k] != g) {
                        if (id == -1 || score[ id ][ pt[id] ] > score[k][ pt[k] ]) {
                            id = k;
                        }
                    }
                }
                if (id == -1) {
                    //cerr << "--->>> " << i << " " << j << "\n";
                    ans = g - j;
                    break;
                }
                pt[id]++;
                for (int k = 0; k < p; k++) {
                    if (k != i && k != id && pt[k] == j) {
                        pt[k]++;
                    }
                }
            }

            sol[i].first = ans;
        }
        for( int i = 0; i < p; i++ ){
            cout << sol[i].first << ' ' << sol[i].second << '\n';
        }
    }
}
