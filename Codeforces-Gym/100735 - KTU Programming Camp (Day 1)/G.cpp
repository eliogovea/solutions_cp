// KTU Programming Camp (Day 1)
// 100735G

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int uno = 0 , cero = 0;

    string s; cin >> s;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == '0') cero++;
        else uno++;
    }

    cout << min(cero, uno) << '\n';
}
