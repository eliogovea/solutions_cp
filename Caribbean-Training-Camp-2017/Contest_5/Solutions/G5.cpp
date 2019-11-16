#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100002;
const int ro = 350;

int mex[MAXN][ro];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    //freopen("dat.txt", "r", stdin);

    int MAX = 100000;

    for( int i = 1; i <= MAX; i++ ){
        for( int k = 1; k <= ro; k++ ){
            if( k > i ){
                mex[i][k] = 0;
                continue;
            }

            if( mex[i-k][k] != 0 && (i < (k+1) || mex[i-(k+1)][k+1] != 0) ){
                mex[i][k] = 0;
            }
            else if( mex[i-k][k] != 1 && (i < (k+1) || mex[i-(k+1)][k+1] != 1) ){
                mex[i][k] = 1;
            }
            else{
                mex[i][k] = 2;
            }
        }
    }

    int n; int tc = 1;
    while( cin >> n , n ){
        if( n == 1 || !mex[n-1][1] ){
            cout << "Case #" << tc << ": First player wins.\n";
        }
        else{
            cout << "Case #" << tc << ": Second player wins.\n";
        }

        tc++;
    }
}
