// 2014-2015 CT S02E05: Codeforces Trainings Season 2 Episode 5 - 2009-2010 ACM-ICPC, NEERC, Southern Subregional Contest
// 100503H

#include <bits/stdc++.h>

using namespace std;
const double EPS = 1e-5;
int d,e,f;
double s, m, p;

int check( double x ){
//    cout << x << endl;
    double a = 0.0, b = 0.0, accb = 0.0;
    for( int i = 1; i<= m; i++ ){
        a = (s-accb)*p/100;
        b = ( x - a );
        accb += b;
        if( abs( accb-s ) < EPS || accb-EPS > s ){
            return 1;
        }
    }
    return 0;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    freopen( "input.txt", "r", stdin );
    freopen( "output.txt", "w", stdout );
	cin >> d >> e >> f;
    s =d; m = e; p = f;
	double ini = 0.0, fin = s+s;

	for(int i = 1; i <= 500; ++i ){
        double mid = (ini+fin)/(double)2.0;

        int v = check(mid);
        if( v ){
            fin = mid;
        }
        else
            ini = mid;
	}
	cout.precision(10);
	//cout << fixed <<(90.000 - ini) <<endl;
    cout << fixed << (ini+fin)/(double)2.0 << '\n';
}

