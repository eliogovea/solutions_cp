// 2008-2009 ACM-ICPC, NEERC, Moscow Subregional Contest
// 100861A

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int n; cin >> n;

    map <string, int> f;

    vector <string> answer;

    while (n--) {
        string a, b;
        cin >> a >> b;

        if( answer.size() == 10 ){
            continue;
        }

        if (a == "MSU") {
            if (f[a] < 4) {
                answer.push_back(a + " " + b);
            }
        } else {
            if (a != "SCH" && f[a] < 2) {
                answer.push_back(a + " " + b);
            }
        }
        f[a]++;
    }

    cout << answer.size() << "\n";
    for (auto s : answer) {
        cout << s << "\n";
    }
}
