// 2014-2015 ACM-ICPC, NEERC, Eastern Subregional Contest
// 100507L

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//freopen("dat.txt","r",stdin);

	set<char> c[3];

	c[0].insert('A');
	c[0].insert('P');
	c[0].insert('O');
	c[0].insert('R');

	c[1].insert('B');
	c[1].insert('M');
	c[1].insert('S');

	c[2].insert('D');
	c[2].insert('G');
	c[2].insert('J');
	c[2].insert('K');
	c[2].insert('T');
	c[2].insert('W');

	int n; cin >> n;

	int sol = 0;

	int cur = 0;
	for( int i  = 0; i < n; i++ ){
        string x; cin >> x;
        int next = cur;
        if( c[0].find( x[0] ) != c[0].end() ){
            next = 0;
        }
        else if( c[1].find( x[0] ) != c[1].end() ){
            next = 1;
        }
        else if( c[2].find( x[0] ) != c[2].end() ){
            next = 2;
        }

        sol += abs( next - cur );
        cur = next;
	}

	cout << sol << '\n';
}
