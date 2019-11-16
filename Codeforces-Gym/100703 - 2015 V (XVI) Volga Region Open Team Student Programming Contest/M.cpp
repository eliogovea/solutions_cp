// 2015 V (XVI) Volga Region Open Team Student Programming Contest
// 100703M

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<double,int> pdi;

int n;
int q[1001], c[1001],p[1001];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
  //  freopen("data.txt", "r",stdin);
    cin >> n;
    for( int i = 1; i <= n; i++ )
        cin >> q[i];
    for( int i = 1; i <= n; i++ )
        cin >> c[i];
    for( int i = 1; i <= n; i++ )
        cin >> p[i];

    int kake = 0;
    for( int i = 1; i <= n; i++ )
        kake = max( kake, q[i]/c[i] + (q[i]%c[i]?1:0) );
    int sol = 0;
    for( int i = 1; i <= n; i++ )
        sol += ( kake*c[i]-q[i] )*p[i];

    cout << sol << endl;

}
