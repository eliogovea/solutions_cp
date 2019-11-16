// 2017-2018 ACM-ICPC Northern Eurasia (Northeastern European Regional) Contest (NEERC 17)
// 101630E

#include <bits/stdc++.h>

using namespace std;

int items[2000];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

  //  freopen("dat.txt","r",stdin);
    int n;
    cin >> n;
    vector<int> ans;
    bool imposible = false;
    for( int i = 0,x; i < n && !imposible; i++ ){
        cin >> x;
        if( x >= 0 )
            items[x]++;
        else{
            if( x < 0 )
                x *= -1;
            if( items[x] > 0 ){
                items[x]--;
            }
            else if( items[0] > 0 ){
                items[0]--;
                ans.push_back( x );
            }
            else{
                imposible = true;

            }
        }
    }

    while( items[0] > 0 ){
        items[0]--;
        ans.push_back( 1 );
    }
    if( imposible )
        cout << "No\n";
    else{
        cout << "Yes\n";
        for( int i = 0; i < ans.size(); i++ ){
            cout << ans[i] << " \n"[i+1==ans.size()];
        }
    }
}
