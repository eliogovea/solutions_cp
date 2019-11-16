#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,int> par;
const int UP = 0,
	  	  RIGHT = 1,
	  	  DOWN = 2,
	  	  LEFT = 3;
const ll oo = (ll)100000LL * 1000000000LL * 2LL;
const int maxn = 100100;

int dir = 0;
struct event{
	ll x;
	ll lo, hi;
	int val, id;
	bool operator<( const event &b ) const{
		if( x != b.x )
			return x < b.x;
		return val < b.val;
	}
};

int n;
vector<event> e;

void add_events_line( ll &x, ll &y, int dir, ll delta ){
	ll nx, ny;
	if( dir == UP ){
		ny = y+delta;
		nx = x;
		e.push_back( (event){ x, y, ny, +1 } );
		e.push_back( (event){ oo,y, ny, -1 } );
	}
	else if( dir == RIGHT ){
		nx = x + delta;
		ny = y;
		e.push_back( (event){ x, y, -oo, +1 } );
		e.push_back( (event){ nx,y, -oo, -1 } );
	}
	else if( dir == DOWN ){
		ny = y - delta;
		nx = x;
		e.push_back( (event){ -oo, ny, y, +1 } );
		e.push_back( (event){   x, ny, y, -1 } );
	}
	else if( dir == LEFT ){
		nx = x - delta;
		ny = y;
		e.push_back( (event){ nx, y, +oo, +1 } );
		e.push_back( (event){  x, y, +oo, -1 } );
	}
	x = nx;
	y = ny;
}

int get_next_dir( int cur, char c ){
	if( c =='R' )
		cur++;
	else
		cur--;

	return ((cur%4)+4 ) % 4;
}

void add_events_rect( ll x, ll y, int &dir, char turn ){
	int nex_dir = get_next_dir( dir, turn );
	if( dir == UP ){
		if( nex_dir == RIGHT ){//ok
			e.push_back( (event){ x, y, -oo, +1 } );
			e.push_back( (event){ oo, y, -oo, -1 } );
		}
		else if( nex_dir == LEFT ){//ok
			e.push_back( (event){  x, y, oo, +1 } );
			e.push_back( (event){ +oo, y, oo, -1 } );
		}
	}
	else if( dir == RIGHT ){
		if( nex_dir == UP ){///ok
			e.push_back( (event){   x, -oo, y, +1 } );
			e.push_back( (event){ +oo, -oo, y, -1 } );
		}
		else if( nex_dir == DOWN ){//ok
			e.push_back( (event){ -oo, y, -oo, +1 } );
			e.push_back( (event){  x, y, -oo, -1 } );
		}
	}
	else if( dir == DOWN ){
		if( nex_dir == RIGHT ){//ok
			e.push_back( (event){ -oo, -oo, y, +1 } );
			e.push_back( (event){   x, -oo, y, -1 } );
		}
		else if( nex_dir == LEFT ){//ok
			e.push_back( (event){ -oo, y, oo, +1 } );
			e.push_back( (event){   x, y, oo, -1 } );
		}
	}
	else if( dir == LEFT ){
		if( nex_dir == UP ){//ok
			e.push_back( (event){ x, y, +oo, +1 } );
			e.push_back( (event){ +oo,y,+oo, -1 } );
		}
		else if( nex_dir == DOWN ){
			e.push_back( (event){ -oo, y, oo, +1 } );
			e.push_back( (event){   x, y, oo, -1 } );
		}	
	}
	dir = nex_dir;
}

int CNT = 0;
map<ll, int> Hash;
map<int,ll> Un_hash;

void commpress_coord(){
	vector<ll> vals;
	for( int i = 0; i < (int)e.size(); i++ ){
	//	if( e[i].lo > e[i].hi )
	//		swap( e[i].lo, e[i].hi );
		vals.push_back( e[i].x );
		vals.push_back( e[i].lo );
		vals.push_back( e[i].hi );
	}
	sort( vals.begin(), vals.end() );
	vals.erase( unique( vals.begin(), vals.end() ), vals.end() );
	for( int i = 0; i < (int)vals.size(); i++ ){
		Hash[ vals[i] ] = ++CNT;
		Un_hash[ CNT ] = vals[i];
		//cout << "hash( " << vals[i] << ") = " << Hash[ vals[i] ] << '\n'; 
	}	
	for( int i = 0; i < (int)e.size(); i++ ){
		e[i].x = Hash[ e[i].x ];
		e[i].lo = Hash[ e[i].lo ];
		e[i].hi = Hash[ e[i].hi ];
	}
}

ll stree[4*maxn],
   lazy[4*maxn];

void build( int nod, int l, int r ){
	if( l == r ){
		stree[nod] = 0;
		return ;
	}
	int mid = (l+r)>>1;

	build( 2*nod, l, mid );
	build( 2*nod+1, mid+1, r );
	stree[nod] = max( stree[2*nod], stree[2*nod+1] );
}

void propagate( int nod, int l, int r ){
	if( !lazy[nod] ) 
		return;
	
	stree[nod] += lazy[nod];

	if( l == r ){
		lazy[nod] = 0;
		return;
	}
	
	lazy[2*nod] += lazy[nod];
	lazy[2*nod+1] += lazy[nod];
	lazy[nod] = 0;
	return;
}


void update( int nod, int l, int r, int ul, int ur, int val ){
	propagate( nod, l, r );
	if( r < ul || l > ur )
		return;

	if( ul <= l && r <= ur ){
		lazy[nod] += val;
		propagate( nod, l, r );
		return;
	}

	int mid = (l+r)>>1;

	update( 2*nod, l, mid, ul, ur, val );
	update( 2*nod+1, mid+1, r, ul, ur, val );

	stree[nod] = max( stree[2*nod], stree[2*nod+1] );
}

int query( int nod, int l, int r, int ql, int qr ){
	propagate( nod, l, r );
	if( r < ql || l > qr )
		return 0;
	
	if( ql <= l && r <= qr ){
		return stree[nod];
	}
	
	int mid = (l+r)>>1;
	
	int lo = query( 2*nod, l, mid, ql, qr ),
		hi = query( 2*nod+1, mid+1, r, ql, qr );
	
	return max( lo, hi );
}

int get_pos( int nod, int l, int r, int lim ){
	propagate( nod, l, r );
	
	if( l == r ){
		return l;
	}
	int mid = (l+r)>>1;
	propagate( 2*nod, l, mid );
	propagate( 2*nod+1, mid+1, r );
	int ans = 1;	
	if( stree[2*nod] == lim ){
		 ans = get_pos( 2*nod, l, mid, lim );
	}
	else{
		return get_pos( 2*nod+1, mid+1, r, lim );
	}
	if( ans == 1 ){
		return get_pos( 2*nod+1, mid+1, r, lim );
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
//	freopen( "input002.txt", "r", stdin );

	cin >> n;
	ll lx = 0, ly = 0;
	for( int i = 0,contad= 0; i < n; i++){
		//cerr << i << '\n';
		ll a;
		string c;
		cin >> a >> c;
		add_events_line( lx,ly, dir, a );//--> get new coord and make events
		add_events_rect( lx,ly, dir, c[0] ); //-> add corner events and change direction
		for( int j = 3; j >= 0; j-- ){
			e[ e.size()-1-j ].id = ++contad;
		}
	}
/*
	for( int i = 0; i < e.size(); i++ )
//		cerr << "x: " << e[i].x << "-->( " << e[i].lo << "; " << e[i].hi << ") :--> " << e[i].val << '\n';
	cerr << e[i].id << '\n';
	cerr<< "------------------------------\n";
*/
	

	for( int i = 0; i < e.size(); i++ ){
		if( e[i].lo > e[i].hi ){
			swap( e[i].lo, e[i].hi );
		}
		//e[i].hi--;
	}
	//cerr << endl;

	sort( e.begin(), e.end() );

/*	for( int i = 0; i < (int)e.size(); i++ ){
		cerr << "x: " << e[i].x << "-->( " << e[i].lo << "; " << e[i].hi << ") :--> " << e[i].val << " --> " << e[i].id << '\n';
	}
*/	
	commpress_coord();


/*	for( int i = 0; i < e.size(); i++ )
		cerr << "x: " << e[i].x << "-->( " << e[i].lo << "; " << e[i].hi << ") :--> " << e[i].val << '\n';
*/
	build( 1, 1, CNT );
	int ans = 0;
	int x=0,y=0;
	for( int i = 0; i < (int)e.size(); i++ ){
		event cur = e[i];

		int tmp_ans = query( 1, 1, CNT, 1, CNT );
		if( ans < tmp_ans ){

			ans = tmp_ans;
			x = cur.x;
			y = get_pos( 1, 1, CNT, ans ); //tmp_ans.second;
//			cerr << "best: " << ans << "coor: (" << x << "; " << y << ") " << endl;
		}
		update( 1, 1, CNT, cur.lo, cur.hi-1, cur.val );
	
//		cerr << "x: " << e[i].x << "-->( " << e[i].lo << "; " << e[i].hi << ") :--> " << e[i].val << '\n';
		while( i+1 < (int)e.size() && e[i+1].x == e[i].x ){
			i++;

//			cerr << "x: " << e[i].x << "-->( " << e[i].lo << "; " << e[i].hi << ") :--> " << e[i].val << '\n';
			cur = e[i];
			update( 1, 1, CNT, cur.lo, cur.hi-1, cur.val );
		}


	}
//	cerr << ans << '\n';
//	cerr << x << " " << y <<  endl;
	cout << Un_hash[x]-1 << " " << Un_hash[y] << '\n';	
}
