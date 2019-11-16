// 2014-2015 ACM-ICPC, NEERC, Eastern Subregional Contest
// 100507I

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen( "dat.txt", "r", stdin );
	string up, down;
	cin >> up >> down;
    int sol = 0;
	for( int i = 0, j = 0; i < (int)up.size() || j < (int)down.size() ;  ){
       // cout << up[i]<< " " << down[j] << endl;

        if(  ( i >= up.size() || up[i] == 'R' || up[i] == 'F') &&( j >= down.size() || down[j] == 'R' || down[j] == 'F') ){
            sol++;
            i++; j++;
        }
        else if( up[i] == 'L' ){
            while( j < down.size() && (  down[j] == 'F'|| down[j] == 'R') ){
                j++;
                sol++;
            }
            i++; j++;
            sol++;
        }
        else if( down[j] == 'L' ){
            while( i < up.size() && ( up[i] == 'F' || up[i] == 'R') ){
                i++;
                sol++;
            }
            sol++;
            i++;
            j++;

        }

	}
	cout << sol << '\n';

}
