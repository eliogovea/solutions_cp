// 2012-2013 ACM-ICPC, NEERC, Southern Subregional Contest
// 100109E

#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> par;
typedef long long ll;
const int maxn = 2*100000 + 10;
int n;

int g[maxn];
bool drag[maxn];
priority_queue< par > q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen( "input.txt", "r", stdin );
    freopen( "output.txt", "w", stdout);

    cin >> n;
    string aux;
    for( int i = 2; i <= n; i++ ){
        cin >> aux >> g[i];
        drag[i] = bool( aux[0] == 'd' );
    }

    for( int i = 2; i < n; i++ ){
        if( drag[i] ){
            q.push( par( -g[i], i ) );
        }
        else{
            while( q.size() >= g[i] )
                q.pop();
        }
    }

    if( q.size() < g[n] ){
        cout << -1 << '\n';
        return 0;
    }

    vector<int> ans;
    ll money = 0;
    while( !q.empty() ){
        int x = q.top().second;
        q.pop();
        money += g[x];
        ans.push_back(x);
    }
    sort( ans.begin(), ans.end() );
    cout << money << '\n';
    cout << ans.size() << '\n';
    for( int i = 0; i < (int)ans.size(); i++ ){
        cout << ans[i] << " \n"[ i+1 == ans.size() ];
    }

}
