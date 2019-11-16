// 2015-2016 ACM-ICPC, NEERC, Moscow Subregional Contest
// 100792I


#include <bits/stdc++.h>

using namespace std;
int n;
int dp[100000],a,b;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("data.txt","r",stdin);
    cin >> n;
    for( int i = 1; i <= n; i++ ){
        cin >> a >> b;
        for( int j = a; j <= b; j++ ){
            dp[j] = 1;
            }

    }
    for( int i = 1;i <= 2080; i++ ){
        dp[i] += dp[i-1];
    }
    for( int i = 1;i <= 2000-180 ; i++ ){
        if( dp[i+179]-dp[i-1] > 90 ){
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    
}

