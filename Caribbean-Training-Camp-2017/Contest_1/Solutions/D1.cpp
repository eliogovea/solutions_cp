#include<bits/stdc++.h>

using namespace std;
const int maxn = 1000100;
typedef pair<int,int> pii;
struct event{
	int x, lo, hi;
	int acc;
	event( int _x = 0, int _lo = 0, int _hi = 0, int _a = 0 ){
		x = _x; 
		lo = _lo; hi = _hi;
		acc = _a;
	}
	bool operator<( const event& b ) const{
		if( x != b.x )
			return x < b.x;
		return acc < b.acc;
	}
};

struct ST{
	int n;
	vector<pii> stree;
	vector<int> lazy;

	ST( int __n = 0 ){
		if( !__n ) return;
		n = __n;
		stree.resize( 4*(n+10)+10 );
		lazy.resize( 4*(n+10)+10 );
	}
	void inicialize(){
		build( 1, 1, n );
	}
	void build( int nod, int l, int r ){
		if( l == r ){
			stree[nod].second = l;
			return;
		}
		int mid = (l+r)>>1;
		build( 2*nod, l, mid );
		build( 2*nod+1, mid+1, r );
		stree[nod] = max( stree[2*nod], stree[2*nod+1] );
	}
	
	void Update( int x, int y, int v ){
		update( 1, 1, n, x, y, v );
	}
	pii get_max(){
		propagate( 1, 1, n );
		return stree[1];
		//return query( 1, 1, n, 1, n );
	}
	void propagate( int nod, int l, int r ){
		if( lazy[nod] == 0 ) return;
		stree[nod].first += lazy[nod];
		if( l == r ){
			lazy[nod] = 0;
			return;
		}
		lazy[2*nod  ] += lazy[nod];
		lazy[2*nod+1] += lazy[nod];
		lazy[nod] = 0;
	}

	void update( int nod, int l ,int r, int ul, int ur, int v ){
		propagate( nod, l, r );
		if( r < ul || l > ur )
			return;

		if( ul <= l && r <= ur ){
			lazy[nod] += v;
			propagate( nod, l, r );
			return;
		}

		int mid = (l+r)>>1;

		update( 2*nod, l, mid, ul, ur, v );
		update( 2*nod+1, mid+1, r, ul, ur, v );
		stree[nod] = max( stree[2*nod], stree[2*nod+1] );
	}
};

struct range_tree{
	int n;
	vector< vector<int> > stree;
	vector<int> mx_y;	
	vector<int> mn_y;
	range_tree( int __n = 0 ){
		if( !__n ) return;
		n = __n;
		stree.resize( 4*n+10 );
		mx_y.resize( 4*n+10 );
		mn_y.resize( 4*n+10 );
	}

	void inicialize( vector<pii>&v ){
		build( 1, 1, n, v );	
	}

	void build( int nod, int l, int r, vector<pii> &v ){
		if( l == r ){
			mx_y[nod] = mn_y[nod] = v[l-1].second;
			stree[nod].push_back( v[l-1].first );
			return;
		}

		int mid = (l+r)>>1;

		build( 2*nod, l, mid, v );
		build( 2*nod+1, mid+1, r, v );
		
		mx_y[nod] = max( mx_y[2*nod], mx_y[2*nod+1] );
		mn_y[nod] = min( mn_y[2*nod], mn_y[2*nod+1] );

		stree[nod].resize( r-l+1 );
		merge( stree[2*nod].begin(), stree[2*nod].end(),
			   stree[2*nod+1].begin(), stree[2*nod+1].end(),
			   stree[nod].begin());
	}
	
	pii query( int nod, int l, int r, int ql, int qr, int xl, int xr ){
		if( mn_y[nod] > qr || mx_y[nod] < ql )
			return pii(-1,-1);
		if( ql <= mn_y[nod] && mx_y[nod] <= qr ){
			vector<int> &cur = stree[nod];
			int lo = lower_bound( cur.begin(), cur.end(), xl ) - cur.begin();
			int up = upper_bound( cur.begin(), cur.end(), xr ) - cur.begin();
			up--;
			if( lo > up ){
			//	cerr << "ERRROR!!!!!" << endl;
				return pii(-1,-1);
			}
			return pii( cur[lo], cur[up] );
		}

		int mid = (l+r)>>1;

		pii lo = query( 2*nod, l, mid, ql,qr,xl,xr ),
			hi = query( 2*nod+1, mid+1, r, ql,qr,xl,xr );
		if( lo == pii(-1,-1) )
			return hi;
		if( hi == pii(-1,-1) )
			return lo;
		return pii( min(lo.first, hi.first), max(lo.second, hi.second) );
	}
	
	pii Query( int y1, int y2, int x1, int x2  ){
		return query( 1, 1, n, y1, y2, x1, x2 );
	}
};


int n;
int h[maxn];
int possible_corner[maxn];
int idx[maxn];
int acc[maxn][2];
vector<pii> up, 
			down, 
			corner;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
//	freopen( "dat.txt", "r", stdin );


	cin >> n;

	for( int i = 1; i <= n; i++ ){
		cin >> h[i];
		
	}

	for( int i = 1; i <= n; i++ ){
		if( up.empty() || h[ up[ up.size()-1 ].first ] < h[i] ){
			up.push_back( pii( i,h[i] ) );
			idx[i] = up.size();
			possible_corner[i] = 1;//up;
			corner.push_back( pii(h[i], i) );
		}
	} 

	for( int i = n; i >= 1; i-- ){
		if( down.empty() || h[ down[ down.size()-1 ].first ] > h[i] ){
			down.push_back( pii(i,h[i] ) );
			idx[i] = down.size();
			possible_corner[i] = -1;//down
			corner.push_back( pii( h[i], i ) );
		}
	} 
	
	sort( corner.begin(), corner.end() );
	for( int i = 0; i < (int)corner.size(); i++ ) 
		swap( corner[i].first, corner[i].second );

	range_tree RT = range_tree( corner.size() );
	RT.inicialize( corner );
	
	vector<event> e; 
	for( int i = 1; i <= n; i++ ){
		if( possible_corner[i] == 0 ){
			pii ys = RT.Query( h[i], n, 1, i );
			//cerr << "i: " << i << endl;
			pii xs = RT.Query( 1, h[i], i, n+1 );
			//cerr << "i: " << i << endl;
			//cerr << "ys = (" << ys.first << "; " << ys.second << ")\n";
			//cerr << "xs = (" << xs.first << "; " << xs.second << ")\n";
			if( ys.first == -1 || xs.first == -1 ) continue;
			e.push_back( event( xs.first , ys.first, ys.second, +1 ) );
			e.push_back( event( xs.second+1, ys.first, ys.second,-1 ) );
		}
	}
	sort( e.begin(), e.end() );
	/*for( int i = 0; i < (int)e.size(); i++ ){
		cerr << "t: "<<e[i].x << "   lo: " << e[i].lo << "    hi: " << e[i].hi << "   acc: " << e[i].acc << '\n';
	}*/
	ST st = ST(n);
	st.inicialize();
	int ans = 0;
	pii sol;
//	cerr << "-------Segment Tree---------\n";	
	for( int i = 0; i < (int)e.size(); i++ ){
		st.Update( e[i].lo, e[i].hi, e[i].acc );
		pii tmp = st.get_max();
		if( ans < tmp.first ){
			ans = tmp.first;
			sol = pii( tmp.second, e[i].x );
		}
	}	

	if( ans < 1 ){
		//cerr << ans << '\n';
		cout << "-1 -1\n";
	}
	else{
		//cerr << "ans: " << ans << '\n';
		cout << sol.first << " " << sol.second<< '\n';
		//cout << up[ sol.second-1 ].second << " " << down[ sol.first-1 ].second << '\n';
	}

}
