#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;

    cin >> s;
    int ans = 1;
    char ch_ans = s[0];
    int cnt = 1;
    for( int i = 1; i < s.size(); i++ ){
        if( s[i] == s[i-1] ){
            cnt++;
        }
        else{
            cnt = 1;
        }
        if( ans < cnt ){
            ans = cnt;
            ch_ans = s[i];
        }
    }
    cout << ans << " " << ch_ans << '\n';
}

