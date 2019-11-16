#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> par;

const int MAXN = 100100;

int W[MAXN];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int n, s; cin >> n >> s;

    set<par> dic;

    for( int i = 1; i <= n; i++ ){
        int w; cin >> w;
        W[i] = w;

        dic.insert( par( w , i ) );
    }

    vector<int> sol;

    int x = 0;
    int wx = 0;

    while( !dic.empty() ){
        if( !x ){
            x = (*dic.begin()).second;
            wx = (*dic.begin()).first;

            sol.push_back(x);
            dic.erase( dic.begin() );
        }

        if( dic.empty() ){
            break;
        }

        set<par>::iterator it = dic.upper_bound( par( s - wx , (1<<29) ) );

        if( it == dic.end() ){
            it = dic.begin();
        }

        int y = (*it).second;
        int wy = (*it).first;

        sol.push_back(y);
        dic.erase(it);

        if( wx + wy > s ){
            x = y;
            wx = wy;
        }
        else{
            x = 0;
            wx = 0;
        }
    }

    int cnt = 0;
    int i = 0;
    while( i < sol.size() ){
        cnt++;
        if( i+1 < sol.size() ){
            if( W[sol[i]] + W[ sol[i+1] ] <= s ){
                i++;
            }
        }

        i++;
    }

    cout << cnt << '\n';
    for( int i = 0; i < sol.size(); i++ ){
        cout << W[ sol[i] ] << " \n"[i+1==sol.size()];
    }
}
