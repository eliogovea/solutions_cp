// 2015 USP Try-outs
// 101047M

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//freopen("dat.txt", "r", stdin);

	int tc; cin >> tc;

	while( tc-- ){
        int n; cin >> n;
        string s; cin >> s;

        int ini = -1;

        vector<int> sol;

        for( int i = 0; i < n; i++ ){
            if( s[i] == 'D' ){
                int j = i;

                if( i+1 < s.size() ){
                    s[i+1] = (s[i+1] == 'B' ? 'D' : 'B');
                }

                while( j > ini ){
                    sol.push_back(j);
                    j--;
                }

                ini = i;
            }
        }

        if( sol.size() != n ){
            cout << "N\n";
        }
        else{
            cout << "Y\n";
            for( int i = 0; i  < sol.size(); i++ ){
                if( i > 0 ){
                    cout << ' ';
                }
                cout << sol[i]+1;
            }
            cout << '\n';
        }
	}
}
