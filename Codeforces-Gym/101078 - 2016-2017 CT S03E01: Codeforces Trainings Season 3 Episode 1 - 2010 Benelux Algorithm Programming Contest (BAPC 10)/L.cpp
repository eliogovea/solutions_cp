// 2016-2017 CT S03E01: Codeforces Trainings Season 3 Episode 1 - 2010 Benelux Algorithm Programming Contest (BAPC 10)
// 101078L

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    double sol = 0;

    string s; cin >> s;

    int n = s.size();
    int cs = 0;

    vector<int> ones;

    for( int i = 0; i < n; i++ ){
        if( s[i] == '0' ){
            cs++;
        }
    }

    for( int i = 0; i < cs; i++ ){
        if( s[i] == '1' ){
            ones.push_back(i);
        }
    }

    if( ones.size() == 0 ){
        cout << "0\n";
        return 0;
    }

    int k = ones.size();
    for( int i = cs; i < s.size(); i++ ){
        if( s[i] == '0' ){
            sol += sqrt( (double)(i - ones[--k]) );
        }
    }

    cout.precision( 12 );
    cout << fixed << sol << '\n';
}
