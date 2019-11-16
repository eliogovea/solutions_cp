// 2015-2016 ACM-ICPC, NEERC, Northern Subregional Contest
// 100801L

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200;

int m[MAXN][MAXN];
int mx[MAXN][MAXN][4];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("lucky.in","r",stdin);
    freopen("lucky.out","w",stdout);

    int r, c; cin >> r >> c;

    int outp = 0;

    for(int i = 0; i < r; i++){
        for( int j = 0; j < c; j++ ){
            cin >> m[i][j];
            if( j == 0 ){
                mx[i][j][0] = m[i][j];
                outp++;
            }
            else{
                mx[i][j][0] = max( m[i][j] , mx[i][j-1][0] );
                if( m[i][j] > mx[i][j-1][0] ){
                    outp++;
                }
            }

            if( i == 0 ){
                mx[i][j][1] = m[i][j];
                outp++;
            }
            else{
                mx[i][j][1] = max( m[i][j] , mx[i-1][j][1] );
                if( m[i][j] > mx[i-1][j][1] ){
                    outp++;
                }
            }
        }
    }

    for( int i = r-1; i >= 0; i-- ){
        for( int j = c-1; j >= 0; j-- ){
            if( j == c-1 ){
                mx[i][j][2] = m[i][j];
                outp++;
            }
            else{
                mx[i][j][2] = max( m[i][j] , mx[i][j+1][2] );
                if( m[i][j] > mx[i][j+1][2] ){
                    outp++;
                }
            }

            if( i == r-1 ){
                mx[i][j][3] = m[i][j];
                outp++;
            }
            else{
                mx[i][j][3] = max( m[i][j] , mx[i+1][j][3] );
                if( m[i][j] > mx[i+1][j][3] ){
                    outp++;
                }
            }
        }
    }

    cout << outp << '\n';
}
