#include <bits/stdc++.h>

using namespace std;
typedef complex<long double> Complex;
typedef vector<Complex> poly;
const long double PI = acos(-1);
typedef long long ll;
int a;
int b, b_pow;
poly Pow[30];

void normalize( poly &a ){
	int n = a.size();
	for( int i = 0; i < n; i++ ){
		a[i] = Complex( (ll)round(real( a[i] )), 0.0 );
		ll x = round( a[i].real() );
		if( x >= b ){
			if( i+1 == n ){
				a.push_back( x/b );
				n++;
			}
			else
				a[i+1] = Complex( (ll)round( a[i+1].real() ) + x/b, 0.0 );
			x %= b;
			a[i] = Complex(x,0.0);
		}
	}
	while( a.size() > 1 &&  (ll)round(a.back().real()) == 0 ) a.pop_back();
	a.push_back(0);
	a.push_back(0);

}

void fft( vector<Complex> &a, int dir ){
	int n = a.size();
	int lg = 0;
	while( n > (1<<lg) ) lg++;
	n = 1<<lg;
	a.resize( n );
	//assert( n == (1<<lg) );

	for( int i = 0; i < n; i++ ){
		int pos = 0;
		for( int j = 0; j < lg; j++ ){
			pos <<= 1;
			pos |= (i>>j) & 1;
		}
		if( i < pos )
			swap( a[i], a[pos] );
	}
	Complex w, wn, u, t;
	for( int i = 1; i <= lg; i++ ){
		int m = 1<<i;
		int k = m>>1;
		wn = Complex( cos( 2.0*dir*PI/(long double)m ), sin( 2.0*dir*PI/(long double)m ) );
		for( int j = 0; j < n; j+= m ){
			w = Complex(1.0,0);
			for( int l = j; l < j+k; l++ ){
				t = w * a[l+k];
				u = a[l];
				a[l] = u + t;
				a[l+k] = u - t;
				w *= wn;
			}
		
		}
	}

	if( dir == -1 ){
		for( int i = 0; i < n; i++ )
			a[i] /= (double)n;
	}
}
void mult_base( vector<Complex> P, vector<Complex> &R ){
	int n = 2*P.size() -1;
	int lg = 0;
	while( n > (1<<lg) ) lg++;
	n = 1<<lg;
	P.resize( n );
	fft( P, 1 );
	R.resize( n );
	for( int i = 0; i < n; i++ )
		R[i] = P[i] * P[i];
	fft( R, -1 );


}
void mult( vector<Complex> &P, vector<Complex> Q ){
	if( !P.size() ){
		P.push_back( Complex(0.0,0.0) );
		//cerr << "NULL poly" << endl;
	}
	if( !Q.size() ){
		Q.push_back( 0.0 );
	}
	int n = P.size() + Q.size()-1;
	int lg = 0;
	while( n > (1<<lg) ) lg++;
	n = 1<<lg;
	//cerr << "n: " << n << endl;
	P.resize( n );
	Q.resize( n );
	fft( P, 1 );
	fft( Q, 1 );
	for( int i = 0; i < n; i++ )
		P[i] *= Q[i];
	/*cerr << "R: ";
	copy( R.begin(), R.end(), ostream_iterator<Complex>(cerr, " ") ); cerr << endl;*/
	fft( P, -1 );

}

void add( poly &a, const poly &o ){
	
	int n = max(a.size(), o.size() );
	if( n > a.size() ) a.resize( n );
	for( int i = 0; i < o.size(); i++ ){
		a[i] = Complex( a[i].real() + o[i].real(), 0.0 );
	}
}

poly convert_base( int num ){
	//cerr << "convert base: " << ch << endl;
	poly ans;
	while( num > 0 ){
		ans.push_back( num % b );
		num /= b;
	}
	if( !ans.size() ) ans.push_back( Complex(0.0) );
	/*cerr << "pol: "; 
	for( auto e: ans )
		cerr << (int)e.real();
	cerr << endl;*/
	return ans;
}

void print( const vector<poly> &last  ){
		cerr << "last: ";
		for( int i = 0; i <  (int)last.size()  ; i++ ){
			cerr << "[";
			copy( last[i].begin(), last[i].end(), ostream_iterator<Complex>( cerr, " " ) );
			cerr << "]";
		}
		cerr << endl;

}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen( "dat.txt", "r", stdin );

	string s;
	cin >> a;
	cin >> s;
	cin >> b;
	int orig_b = b;
	b *= b;
	//cerr << "s: " << s << endl;
	int sig = 0;
	if( s[0] == '-' ){
		sig = 1;
		s = s.substr( 1, s.size()-1 );
	}
	int n = s.size();

	int lg = 0;
	while( n > (1<<lg) ) lg++;
	vector<poly> last(1<<lg), temp;
	
	for( int i = 0; i < n; i++ ){
		last[n-i-1] = convert_base( s[i]-'0' ) ;
	}
	n = 1<<lg;
	

	{
		int aa = a;
		while( aa > 0 ){
			Pow[1].push_back( aa%b );
			aa /= b;
		}
	
	}
	Pow[0].push_back( Complex( 1,0.0 ) );
	//print(last);
	//cerr<< "lg: " << lg << endl;
	for( int i = 2; i <= lg+1; i++){
		mult_base( Pow[i-1], Pow[i] );
		normalize( Pow[i] );
	}
	
	poly q, p;
	for( int i = 1; last.size() > 1; i++ ){
		//cerr << "i: " << i << endl;	
		//print( last );
		int m = 1<<i;
		int cnt = 0;
		temp.clear();
		for( int j = 0; j < n; j += m ){
			q = last[cnt++];
			p = last[cnt++];
			mult( p, Pow[i]);
			normalize( p );
			add( p, q );
			normalize( p );
			temp.push_back( p );
		}
		//last.swap( temp );


		last = temp;
	}

	//print( last );
	vector<ll> ans;
	for( int i = 0; i < last[0].size(); i++ )
		ans.push_back( round(last[0][i].real()) );

	for( int i = 0; i < ans.size(); i++ ){
		if( ans[i] >= b ){
			if( i+1 == ans.size() )
				ans.push_back( ans[i]/b );
			else
				ans[i+1] += ans[i]/b;
			ans[i] %= b;
		}
	}
	
	while( ans.size() && ans.back() == 0 ) ans.pop_back();
	reverse( ans.begin(), ans.end() );
	if( sig && ans.size() )
		cout << "-";
	vector<int> v;
	//for( auto e: ans )
	//	cerr << e;
	//cerr << endl;
	for( int i = 0; i < ans.size(); i++ ){
		
		v.clear();
		while( ans[i] > 0 ){
			int x = ans[i] %orig_b;
			v.push_back( x );
			ans[i] /= orig_b;
		}
		if( i > 0 ) while( v.size() < 2 ) v.push_back( 0 );
		reverse( v.begin(), v.end() );	
		for( auto e:v )
			cout << e;	
	}

	cout << endl;;

	return 0;
}
