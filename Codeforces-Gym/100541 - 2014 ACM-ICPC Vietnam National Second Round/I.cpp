// 2014 ACM-ICPC Vietnam National Second Round
// 100541I

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;

typedef long long ll;

string mapa[MAXN];
int dp[MAXN][MAXN][5];

int n,m;

bool can_move(int i,int j){
    return (i >= 0 && j >= 0 && i < n && j < m && mapa[i][j] == '1');
}

int solve(int i,int j,int d){
    if( dp[i][j][d] != -1){
        return dp[i][j][d];
    }

    dp[i][j][d] = 0;

    if(d == 1){
        if( can_move(i , j-1) ){
            dp[i][j][d]++;
            if( can_move(i+1 , j-1) ){
                dp[i][j][d]++;
                dp[i][j][d] += solve(i+1,j-1,d);
            }
        }
    }
    else if(d == 2){
        if( can_move(i-1 , j) ){
            dp[i][j][d]++;
            if( can_move(i-1 , j-1) ){
                dp[i][j][d]++;
                dp[i][j][d] += solve(i-1,j-1,d);
            }
        }
    }
    else if(d == 3){
        if( can_move(i , j+1) ){
            dp[i][j][d]++;
            if( can_move(i-1 , j+1) ){
                dp[i][j][d]++;
                dp[i][j][d] += solve(i-1,j+1,d);
            }
        }
    }
    else if(d == 4){
        if( can_move(i+1 , j) ){
            dp[i][j][d]++;
            if( can_move(i+1 , j+1) ){
                dp[i][j][d]++;
                dp[i][j][d] += solve(i+1,j+1,d);
            }
        }
    }

    return dp[i][j][d];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

   // freopen("dat.txt","r",stdin);

    int tc; cin >> tc;

    while(tc--){
        cin >> n >> m;
        for(int i = 0;i < n; i++){
            cin >> mapa[i];
            for(int j = 0; j < m; j++){
                for(int k = 1; k <= 4; k++){
                    dp[i][j][k] = -1;
                }
            }
        }

        ll sol = 0ll;

        for(int i = 0;i < n; i++){
            for(int j = 0; j < m; j++){
                if( can_move(i,j) ){
                    ll sol2 = 1ll;
                    if( can_move(i , j-1) ){
                        sol2 += (ll)solve( i , j-1 , 2 ) + 1ll;
                    }
                    if( can_move(i , j+1) ){
                        sol2 += (ll)solve( i , j+1 , 4 ) + 1ll;
                    }
                    if( can_move(i+1 , j) ){
                        sol2 += (ll)solve( i+1 , j , 1 ) + 1ll;
                    }
                    if( can_move(i-1 , j) ){
                        sol2 += (ll)solve( i-1 , j , 3 ) + 1ll;
                    }
                    sol = max( sol , sol2 );
                }
            }
        }

        cout << sol << '\n';
    }
}
