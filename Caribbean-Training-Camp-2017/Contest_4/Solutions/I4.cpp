#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1010;
const int MAXE = 2*100010 + 2*1010;
typedef pair<int,int> par;

int ady[MAXE],flow[MAXE],cap[MAXE];
int now[MAXN], last[MAXN];
namespace dinic{
	int next[MAXE];
	int E;
	int s,t,n;
	void init_max_flow(int nn,int ss,int tt, int edges){
		E=2; n=nn; s=ss; t=tt;
		for(int i = 0; i <= n ; i++)
			last[i] = 0;
		for( int i = 2; i <= n+2*edges; i++ ){
			next[i] = 0;
		}
	}
	void add_edge(int v,int u,int c){
	  ady[E]=u;
	  flow[E]=0; cap[E]=c;
	  next[E]=last[v]; last[v]=E++;
	}
	int cola[MAXN],enq,deq,level[MAXN];
	bool BFS(){
	   int i,v,u;
	   for(i=0;i<=n;i++) level[i]=0;
	   level[s]=1;
	   enq=deq=0;  cola[enq++]=s;
	   while(enq-deq>0 && !level[t]){
		  v=cola[deq++];
		  for(int i=last[v];i;i=next[i]){
			 u=ady[i];
			 if(!level[u] && flow[i] < cap[i]){
				 level[u]=level[v]+1;
				 cola[enq++]=u;
			 }
		  }
	   }
	   return level[t];
}
int DFS(int v,int flujo){
   if(v==t) return flujo;
   for(int f, i = now[v]; i; i = now[v] = next[i]){
       int u = ady[i];
       if(level[v]+1 == level[u] && flow[i] < cap[i]){
           if( (f = DFS(u,min(flujo,cap[i]-flow[i])) ) ){
              flow[i]+=f;
              flow[i^1]-=f;
              return f;
           }
       }
   }
   return 0;
}

	int MAXFLOW(){
	   int flow=0,f;
	   while(BFS()){
		   for(int i = 0; i <= n; i++) 
		   	   now[i]=last[i];
		   while( (f = DFS(s, 1<<20 )) ) flow += f;
	   }
	   return flow;
	}
	bool is_saturated( int e ){

		return ( ady[e^1] != s && ady[e] != t && cap[e] == flow[e]);
	}
	
	inline int get_u( int e ){
		return ady[e^1];
	}
	inline int get_v( int e ){
		return ady[e];
	}

};

int src, sink;
bool maximal_matchable[MAXE];
int  match[MAXN]; // node in match
int way[MAXN][MAXN];
int ed_match[MAXE];
int maximal_m[MAXN][MAXN];

namespace scc{
	using namespace dinic;
	int get_node( int e, int x ){
		if( get_u( e ) == x )
			return get_v(e);
		return get_u( e );
	}
	vector<int> comp[MAXN];
	int dfstime[MAXN], low[MAXN], in_stack[MAXN], 
		sccnum = 0,dfsnum = 0;
	stack<par> stk;

	void scc(int u, int e){
	//	cout << "start u: " << u  << "  e: " << e << endl;
		dfstime[ u ] = low[ u ] = ++dfsnum;
		stk.push( make_pair( u, e ) );
		in_stack[ u ] = 1;
		int saturated = (e==-1)?-1:( ed_match[e] || ed_match[e^1] );
		
		for(int i = last[u]; i ; i = dinic::next[i]){
			int v = get_node( i, u );
		//	cout << "v: " << v << '\n';
				//cout << "\ted_m(" << i << "): " << ed_match[i] << '\n';
				//cout << "\te: " << e << " state: " << saturated << '\n';
			if( !match[v] || ed_match[i] == saturated || v == src || v == sink ) 
				continue;

			if(!dfstime[v]){
				scc(v, i);
				low[ u ] = min(low[ u ],low[v]);
			}
			else if(in_stack[v]){ 
				if( dfstime[v] < low[u] ){
					low[u] = dfstime[v];
				//	stk.push( make_pair( 0, i ) );
				}
				//low[ u ] = min(low[u],dfstime[v]);
			
			}
		}
		
		if(dfstime[ u ] == low[ u ]){
		//	cout << "maximal: \n";
			sccnum++;
			while(in_stack[u]){
				par x = stk.top();
				stk.pop();
		//		cout << "nod: " << x.first << endl;
		//		cout << "ed : " << x.second << endl;
				//if( x.first ) 
				in_stack[x.first]=0;
				comp[sccnum].push_back( x.first );
				//maximal_m[ant][x.first] = maximal_m[x.first][ant] = true;	
				//if( in_stack[u] )
				//	maximal_matchable[x.second] = maximal_matchable[x.second^1] = true;
			}
		}
	//	cout << "end u : " << u << '\n';
	}
	void find_scc( int nodes ){
		dfsnum = sccnum = 0;
		for( int i = 1; i <= nodes; i++ )
			low[i] = dfstime[i] = 0;
		for(int i = 1; i <= nodes;i++){
			if( match[i] && !dfstime[i]){
	//		 	cout << "--------------------\n";
				scc(i, -1);
			}
		}
		for( int x = 1; x <= sccnum; x++ ){
			//cerr << "comp: " << x << ":\n";
			for( int i = 0; i < (int)comp[x].size(); i++ ){
				//cerr << comp[x][i] << ' ';
				for( int j = 0; j < (int)comp[x].size(); j++ ){
					int id =  2*way[ comp[x][i] ][ comp[x][j] ]; 
					if( i != j )
						maximal_matchable[id] = maximal_matchable[id^1] = true;
				}
			}
			//cerr << "\n";
		}
	
	}

};

bool mk[MAXN];
queue<par> q;
void bfs(  ){
	while( !q.empty() ){
		int u = q.front().first;
		int e = q.front().second;
		//cerr << "u: " << u << " e: " << e << '\n'; 
		q.pop();
		int saturated;
		if( e == -1 )
			saturated = 1;
		else if( e == -2 )
			saturated = 1;
		else 
			saturated = ed_match[e];
		
		for( int i = last[u]; i ; i = dinic::next[i] ){
			int v = scc::get_node( i, u );
		//	cerr << "v: " << v << endl;
		//	cerr << "ed: " << i/2 <<  "--->match: " <<ed_match[i] << endl;
			if( (ed_match[i^1] == saturated && ed_match[i] == saturated) || v == src || v == sink ) continue;
				
			maximal_matchable[i] = maximal_matchable[i^1] = true;
			if( !mk[v] ){
				q.push( par( v, i ) );
				mk[v] = true;
			}	
		}

	}

}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen( "dat.txt", "r", stdin );

	int n, m ,k;	
	cin >> n >> m >> k;
	src = n+m+1,
	sink  = n+m+2;
	dinic::init_max_flow( n+m+3, src, sink, k );

	for( int i = 0,a,b; i < k; i++ ){
		cin >> a >> b;
		way[a][b+n] = i+1;
		way[b+n][a] = i+1;
		dinic::add_edge( a, b+n, 1 );
		dinic::add_edge( b+n, a, 0 );
	}
	for( int i = 1; i <= n; i++ ){
		dinic::add_edge( src, i, 1 );
		dinic::add_edge( i, src, 0 );
	}
	
	for( int i = 1; i <= m; i++ ){
		dinic::add_edge( n+i, sink, 1 );
		dinic::add_edge( sink, n+i, 0 );
	}


	//int max_match =0;
	dinic::MAXFLOW();
	
	//cout << "match:" << max_match << '\n';

	for( int i = 2; i < dinic::E; i+= 2 ){
		if( dinic::is_saturated( i ) ){
			ed_match[i] = ed_match[i^1] = true;
			maximal_matchable[i] = true;
			int u = dinic::get_u(i),
				v = dinic::get_v(i);
			match[u] = match[v] = true;
			//cerr << "u: " << u << " v: " << (v) << '\n';
			maximal_m[u][v] = maximal_m[v][u] = true;
		}
	}
	
	scc::find_scc( n+m );
	vector<int> ans;
	
	//cerr << "bfs:\n";
	fill( mk, mk+n+m+1, 0 );
	for( int i = 1; i <= n; i++ )
		if( !match[i] ){
			q.push( par(i, -2) );
			mk[i] = true;
		}
	bfs();
	
	//cerr << "bfs2:\n";
	fill( mk, mk+n+m+1, 0 );
	for( int i = 1; i <= m; i++ )
		if( !match[i+n] ){
			q.push( par(i+n, -1) );
			mk[i+n] = true;
		}
	//cerr << '\n';
	bfs();	

	for( int i = 2; i < dinic::E; i+= 2 ){
		if(maximal_matchable[i] || maximal_matchable[i^1])
			ans.push_back( i/2 );
		else{
			int u = dinic::get_u(i),
				v = dinic::get_v(i);
			if( maximal_m[u][v] || maximal_m[v][u] )
				ans.push_back( i/2 );
		}
	}


	cout << ans.size() << '\n';
	for( int i = 0; i < (int)ans.size(); i++ ){
		cout << ans[i] << " \n"[ i+1 == (int)ans.size() ];
	}

}
