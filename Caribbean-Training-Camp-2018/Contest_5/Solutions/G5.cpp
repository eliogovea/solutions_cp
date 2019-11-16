#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000000+10;

int w[maxn+100];

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

   // freopen("dat.txt","r",stdin);
    w[0] = false;
    int k;
    cin >> k;
    vector<int> t(k);
    for( int i = 0; i < k; i++ )
        cin >> t[i];

    for( int i = 1; i < maxn; i++ ){
        bool win = false;

        for( auto x: t ){
            if(  i-x >= 0 && !w[i-x] ){
                win = true;
            }
        }
        w[i] = win;
    }

    cin >> n;
    while( n-- ){
        int x;
        cin >> x;
        if( w[x] )
            cout << "First\n";
        else
            cout << "Second\n";


    }
}
