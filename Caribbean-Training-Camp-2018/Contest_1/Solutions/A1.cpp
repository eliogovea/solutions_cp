#include <bits/stdc++.h>

using namespace std;
const int maxn = 5*100000 + 100;

int n;
int a[maxn];

struct node{
	int seg_and, seg_or;
	int seg_min, lazy_and, lazy_or;
	
	node( int val  ){ 
   		seg_min = seg_and = seg_or = seg_min = val;
		lazy_and = (1<<30) -1;
		lazy_or = 0;
	}

	node(  ){
		int val = 0;	
   		seg_min = seg_and = seg_or = seg_min = val;
		lazy_and = (1<<30) -1;
		lazy_or = 0;
	}
};
vector<node> stree;

node comb( const node &a, const node &b ){
	node res(0);
	res.seg_min = min( a.seg_min, b.seg_min );
	res.seg_or = a.seg_or | b.seg_or;
	res.seg_and = a.seg_and & b.seg_and;

	return res;
}

void propagate( int nod, int l, int r ){	
	if( stree[nod].lazy_or == 0 && stree[nod].lazy_and == ( (1<<30) - 1 ) )
		return;
	
	stree[nod].seg_min &= stree[nod].lazy_and;
	stree[nod].seg_min |= stree[nod].lazy_or;

	stree[nod].seg_or &= stree[nod].lazy_and;
	stree[nod].seg_or |= stree[nod].lazy_or;

	stree[nod].seg_and &= stree[nod].lazy_and;
	stree[nod].seg_and |= stree[nod].lazy_or;

	if( l != r ){
		int ls = 2*nod, rs = ls+1;

		stree[ls].lazy_and &= stree[nod].lazy_and;
		stree[ls].lazy_or &= stree[nod].lazy_and;
		stree[ls].lazy_or |= stree[nod].lazy_or;
	
		stree[rs].lazy_and &= stree[nod].lazy_and;
		stree[rs].lazy_or &= stree[nod].lazy_and;
		stree[rs].lazy_or |= stree[nod].lazy_or;
	}
	stree[nod].lazy_and = (1<<30) - 1;
	stree[nod].lazy_or = 0;	
}

void build( int nod, int l, int r ){
	if( l == r ){
		stree[nod] = node( a[l] );
		return;	
	}
	
	int midd = (l+r)>>1;

	build( 2*nod, l, midd );
	build( 2*nod+1, midd+1, r );
	stree[nod] = comb( stree[2*nod], stree[2*nod+1] );
	//cerr << l << " " << r << " " << stree[nod].seg_min << endl;

}

void update( int nod, int l, int r, int ul, int ur, int val, bool _and_ ){
	//cerr << l << " " << r << " " << ul << " " << ur << endl;
	propagate( nod, l, r );
	if( r < ul || l > ur )
		return;

	if( ul <= l && r <= ur ){
	//	cerr << "if 1\n";
	//	cerr << "bits: " << stree[nod].seg_or << " " << stree[nod].seg_and << endl;
		int aux = ( stree[nod].seg_or ^ stree[nod].seg_and ) & ( (_and_)?(~val):val );
	//	cerr << "aux: " << aux << endl;
		if( !aux ) {
	//		cerr<< "if 2\n";
			if( _and_ ){
				stree[nod].lazy_and &= val;
				stree[nod].lazy_or &= val;
			}
			else
				stree[nod].lazy_or |= val;

			propagate( nod, l, r );
			return;
		}
	
	}

	int mid = (l+r)>>1;

	update( 2*nod, l, mid, ul, ur, val, _and_ );
	update( 2*nod+1, mid+1, r, ul, ur, val, _and_ );

	stree[nod] = comb( stree[2*nod], stree[2*nod+1] );	
}

int query( int nod, int l, int r, int ql, int qr ){
	
	//cerr << l << " " << r <<" " << ql << " " << qr; 
	propagate( nod,l, r );
	if( r < ql || l > qr ){
		//cerr << " <--- out of range" << endl;
		return INT_MAX;
	}
	

	if( ql <= l && r <= qr ){
		//cerr << " <--- totaly inside" << endl;

		return stree[nod].seg_min; 	
	}

	//cerr << " <--- split" << endl;
	int mid = (l+r)>>1;

	int lo = query( 2*nod, l, mid, ql, qr ),
		hi = query( 2*nod+1, mid+1,r, ql, qr );
	//cerr << l << " " << r << endl;
	stree[nod] = comb( stree[2*nod], stree[2*nod+1] );
	
	return min( lo, hi );

}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
//	freopen( "dat.txt", "r", stdin );

	cin >> n;
	for( int i = 1; i <= n; i++ ){
		cin >> a[i];
	}
	stree.resize( 4*(n+10) );

	build( 1, 1, n );
	
	int m; 
	cin >> m;

	while( m-- ){
		char t[2];
		int l, r, x;
		cin >> t >> l >> r;
	//	cerr << "q: "<< t << " "<< l << " " <<  r << endl;
		if( t[0] == '&' ){
			cin >> x;
			update( 1, 1, n, l, r, x, 1 );
		} 
		else if( t[0] == '|' ){
			cin >> x;
			update( 1, 1, n, l, r, x, 0 );
		}
		else if( t[0] == '?' ){
	//		cerr << "query: \n";
			cout << query( 1, 1, n, l, r ) << '\n';
		}
	}

}
