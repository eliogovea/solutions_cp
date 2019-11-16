// 2014-2015 CT S02E10: Codeforces Trainings Season 2 Episode 10 - 2014 Amirkabir University of Technology Annual Programming Contest (AUT APC 14)
// 100534B

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    string b; cin >> b;
    int n = b.size();

    set<string> dic;

    int sol = 0;

    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            string x = "";
            x += b[ i-1 ];
            x += b[ j-1 ];
            int a1 = i, a2 = j;
            while( a1 + a2 <= n ){
                x += b[a1+a2-1];
                int tmp = a1;
                a1 = a2;
                a2 = tmp + a2;
            }
            if( dic.find(x) == dic.end() ){
                sol++;
                dic.insert(x);
            }

            //cout << x << '\n';
        }
    }

    cout << sol << '\n';
}
