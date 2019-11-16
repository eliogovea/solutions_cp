// 2014-2015 CT S02E04: Codeforces Trainings Season 2 Episode 4 (US College Rockethon 2014 + COCI 2008-5 + GCJ Finals 2008 C)
// 100497H

#include <bits/stdc++.h>


using namespace std;

long long n;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
//	freopen( "dat.txt", "r", stdin );
	cin >> n;
	bool f = false;
	long long i = 2, sol = 0;
	for( ; i*i <= n; i++ ){
		if( n % i == 0 ){
			f = true;
			break;
		}
		
	}
	if( !f ){
		sol = n-1;
	}
	else sol = n - n/i;
	cout << sol << '\n';

}
