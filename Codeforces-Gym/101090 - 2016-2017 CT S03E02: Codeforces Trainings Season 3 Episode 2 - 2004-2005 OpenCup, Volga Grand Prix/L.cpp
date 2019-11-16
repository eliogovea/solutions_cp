// 2016-2017 CT S03E02: Codeforces Trainings Season 3 Episode 2 - 2004-2005 OpenCup, Volga Grand Prix
// 101090L

#include <bits/stdc++.h>

using namespace std;



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int n; cin >> n;

    vector<int> b;
    vector<int> r;

    for( int i = 0; i < n ; i++ ){
        string s; cin >> s;
        int x = 0;
        for( int j = 0; j+1 < s.size(); j++ ){
            x *= 10;
            x += s[j] - '0';
        }
        x--;

        if( s[ s.size()-1 ] == 'B' ){
            b.push_back( x );
        }
        else{
            r.push_back( x );
        }
    }

    sort( b.begin() , b.end() );
    sort( r.begin() , r.end() );

    if( b.size() == 0 || r.size() == 0 ){
        cout << "0\n";
        return 0;
    }

    int sol = 0;
    for( int i = 0; i < min( b.size() , r.size() ); i++ ){
        sol += b[ b.size()-1-i ];
        sol += r[ r.size()-1-i ];
    }

    cout << sol << '\n';
}
