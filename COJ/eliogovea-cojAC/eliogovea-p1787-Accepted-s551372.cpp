#include<iostream>
#define MAXN 1000
#define mod 1000000007
using namespace std;

int n,x;
long long dp[MAXN+10][MAXN+10],ac[MAXN+10];

int main()
{
	for(int i=1; i<=MAXN; i++)
    {
        dp[i][1]=dp[i][i]=1ll;
        ac[i]=1ll;
        for(int j=2; j<i; j++)
            dp[i][j]=(dp[i-1][j-1]+(j*dp[i-1][j])%mod)%mod,
                ac[i]=(ac[i]+dp[i][j])%mod;
        ac[i]=(ac[i]+1ll)%mod;
    }

    ac[1]=1ll;

    for(cin >> n; n--;)
    {
        cin >> x;
        cout << ac[x];
        if(n)cout << endl;
    }
}
