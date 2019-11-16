#include <bits/stdc++.h>

#define MAXN 2*100010
#define MAXM 2*100010
using namespace std;

int match[MAXN];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen(  "dat.txt", "r", stdin);
    int n, m;

    cin >> n >> m;
    int s = n+m+1,
        t = n+m+2;

    vector< pair<int,int> > ans;
    for( int i = 1; i <= n; i++ ){
        int x;
        while( cin >> x, x ){
            if( !match[i] && !match[n+x] ){
                ans.push_back( make_pair( i, x ) );
                match[i] = match[n+x] = true;
            }

        }
    }

    cout << ans.size() << '\n';
    for( int i = 0; i < ans.size(); i++ ){
        cout << ans[i].first << " " << ans[i].second << '\n';
    }

}
