// 2013-2014 Wide-Siberian Olympiad: Onsite round
// 10124108

#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v[1200];
int neg;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen( "input.txt", "r", stdin );
    freopen( "output.txt", "w", stdout );


    cin >> n;
    int ans = 0;
    for( int i = 1,x; i <= n; i++ ){
        cin >> x;
        string s;
        vector<string> aux(x);
        for( int j = 0,d; j < x; j++ )
            cin >> aux[j];
        reverse( aux.begin(), aux.end() );

        for( int j = 0,d; j < x; j++ ){
            s = aux[j];
            if( s == "bw" )
                d = 0;
            else if( s == "c" )
                d = 1;

            if( !v[i].size() || v[i][ v[i].size()-1 ] != d ){
                v[i].push_back( d );
                if( !d ) neg++;
            }
        }
        if( v[i].back() == 0 ){
            ans++;
            v[i].pop_back();
            neg--;

        }
    }

    /*if( n == 1 ){
        int zero = 0, one = 0;
        for( int i = 1; i+1 < (int)v[1].size(); i++ ){

            if( v[1][i] == 0 && v[1][i+1] == 1 && v[1][i-1] == 1 ){
                cout << -1 << '\n';
                return 0;
            }
        }
        if( v[1].size() == 1 ){
            cout << 1 << '\n';
            return 0;
        }
        if( v[1][0] == 0 && v[1][1] == 1 ){
            cout << 1 << '\n';
            return 0;
        }
        cout << 2 << '\n';
        return 0;
    }
*/
    while( neg ){
        for( int i = 1; i <= n; i++ ){
            int sz = v[i].size();
            if( sz > 1 ){
                if( neg == 1 ){
                    ans++;
                    neg--;
                    v[i].pop_back();
                    v[i].pop_back();
                    break;
                }
                else if( n == 1 ){
                    cout << "-1\n";
                    return 0;
                }
                ans += 2;
                neg--;

                v[i].pop_back();
                v[i].pop_back();
            }
        }
    }
    for( int i = 1; i <= n; i++ )
        if( v[i].size() ) ans++;

    cout << ans << '\n';
}
