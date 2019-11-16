// 2016-2017 CT S03E02: Codeforces Trainings Season 3 Episode 2 - 2004-2005 OpenCup, Volga Grand Prix
// 101090K

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int tc; cin >> tc;

    while( tc-- ){
        ll n, m; cin >> n >> m;

        if( n == 1ll || m == 1ll || ( n*m ) % 6ll != 0ll ){
            cout << "No\n";
        }
        else{
            cout << "Yes\n";
        }
    }
}
