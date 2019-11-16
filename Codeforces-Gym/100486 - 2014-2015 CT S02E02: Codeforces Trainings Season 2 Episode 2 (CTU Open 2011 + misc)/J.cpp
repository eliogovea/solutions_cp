// 2014-2015 CT S02E02: Codeforces Trainings Season 2 Episode 2 (CTU Open 2011 + misc)
// 100486J

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5000;

string a[MAXN];
int mark[MAXN];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int tc; cin >> tc;

    string s;

    getline( cin , s );

    int mk = 1;

    while(tc--){
        int n; cin >> n;
        getline( cin , s );

        map<string, int> dic;

        for(int i = 1; i <= n; i++){
            getline( cin , a[i] );
            dic[ a[i] ] = i;
        }

        int q; cin >> q;
        getline( cin , s );

        int outp = 0;
        int c = 0;

        while( q-- ){
            getline( cin , s );
            int x = dic[ s ];

            if( mark[x] != mk ){
                mark[x] = mk;
                c++;
                if( c == n ){
                    outp++;
                    mk++;
                    c = 1;
                    mark[x] = mk;
                }
            }
        }

        cout << outp << '\n';
        mk++;
    }
}
