// 2014-2015 ACM-ICPC, NEERC, Eastern Subregional Contest
// 100507J

#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> par;

const int MAXN = 1010;

par x[MAXN];
par y[MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//freopen( "dat.txt", "r", stdin );

	int n; cin >> n;

	int X = 0;
	int Y = 0;

	for( int i = 1; i <= n; i++ ){
        cin >> x[i].first;
        x[i].second = i;
        X += x[i].first;
	}


	for( int i = 1; i <= n; i++ ){
        cin >> y[i].first;
        y[i].second = i;
        Y += y[i].first;
	}

	if( X > Y ){
        sort( x + 1 , x + n + 1 );
        sort( y + 1 , y + n + 1, greater<par>() );
	}
	else{
        sort( y + 1 , y + n + 1 );
        sort( x + 1 , x + n + 1 , greater<par>() );
	}

	for( int i = 1; i <= n; i++ ){
        cout << x[i].second << ' ' << y[i].second << '\n';
	}
}
