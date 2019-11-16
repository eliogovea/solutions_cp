// 2014-2015 CT S02E03: Codeforces Trainings Season 2 Episode 3 (NCPC 2008 + USACO DEC07 + GCJ 2008 Qual)
// 100494E

/*
 * =====================================================================================
 *
 *       Filename:  E.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/04/16 09:35:44
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */
#include <bits/stdc++.h>

using namespace std;

long long n, b, h, w;
long long l[20000];
int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);	
	//freopen( "dat.txt", "r", stdin );
	cin >> n >> b >> h >> w;
	long long sol = 210LL*5000000LL;
	for( long long  i = 1, p; i <= h; i++ ){
		cin >> p;
		for( long long j = 1; j <= w; j++ )
			cin >> l[j];
		if( p*n > b )
			continue;/* 
		long long m = 1200;
		for( int j = 1; j <= w;j++ )
			if( l[j] >= n )
				m = min(m, l[j]);
*/
		long long m = *max_element( l+1, l+w+1 );
		if( m >= n ){
			sol = min( sol, p*n );
		}
		//cout<<m<<endl;
	}
	if( sol == 210LL*5000000LL)
		cout << "stay home\n";
	else
		cout << sol << '\n';
}

