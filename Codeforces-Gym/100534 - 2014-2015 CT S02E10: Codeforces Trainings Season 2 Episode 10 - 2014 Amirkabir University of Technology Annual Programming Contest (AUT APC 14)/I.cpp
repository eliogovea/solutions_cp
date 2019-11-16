// 2014-2015 CT S02E10: Codeforces Trainings Season 2 Episode 10 - 2014 Amirkabir University of Technology Annual Programming Contest (AUT APC 14)
// 100534I

#include <bits/stdc++.h>

using namespace std;


const int MAXN = 10000;
const int MAXM = 100000;
const int oo = 100000000;

int ady[MAXM],next[MAXM],flow[MAXM],cap[MAXM];
int E,last[MAXN],now[MAXN];

int s,t,n;
void init_max_flow(int nn,int ss,int tt){
    E=2; n=nn; s=ss; t=tt;
    for(int i=0;i<=n;i++) last[i] = 0;
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
   for(int f,i=now[v];i;i=now[v]=next[i]){
       int u=ady[i];
       if(level[v]<level[u] && flow[i]<cap[i]){
           if(f = DFS(u,min(flujo,cap[i]-flow[i]))){
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
       for(int i=0;i<=n;i++) now[i]=last[i];
       while(f = DFS(s,oo)) flow += f;
   }
   return flow;
}


typedef pair<int,int> par;
vector<par> g[MAXN];

int d1[MAXN] , d2[MAXN];
int mk1[MAXN] , mk2[MAXN];

void dijkstra( int n, int begin, int *d ,int *mk ){
    priority_queue< par > cola;
    for(int i = 1; i <= n; i++){
        d[i] = oo;
    }
    d[begin] = 0;
    cola.push( par( 0 , begin ) );

    while( !cola.empty() ){
        int u = cola.top().second; cola.pop();

        if( mk[u] ){
            continue;
        }

        mk[u] = true;

        for(int i = 0; i < g[u].size(); i++){
            int v = g[u][i].first;
            int w = g[u][i].second;

            if( !mk[v] && d[v] > d[u] + w ){
                d[v] = d[u] + w;
                cola.push( par( -d[v] , v ) );
            }
        }
    }
}

bool ok[MAXN];

typedef pair< par , int > arc;

arc arcos[MAXM];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int n,m; cin >> n >> m;

    int kkk = oo;

    for(int i = 0; i < m; i++){
        int u,v,c; cin >> u >> v >> c; u++; v++;
        g[u].push_back( par(v,c) );
        g[v].push_back( par(u,c) );

        if( ( u == 1 && v == n ) || ( u == n && v == 1 ) ){
            kkk = min( kkk , c );
        }

        arcos[i] = arc( par( u, v ) , c );
    }

    dijkstra( n , 1 , d1 , mk1  );
    dijkstra( n , n , d2 , mk2  );

    if( d1[n] == oo ){
        cout << "0\n";
        return 0;
    }

    if( d1[n] == kkk ){
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    init_max_flow( n * 2 , 1+n , n );

    for(int i = 1; i <= n; i++){
        ok[i] = ( d1[i] + d2[i] == d1[n] );
        add_edge( i , i + n , 1 );
        add_edge( i + n , i , 0 );
    }

    for(int i = 0; i < m; i++){
        int u = arcos[i].first.first;
        int v = arcos[i].first.second;
        int w = arcos[i].second;

        if( ok[u] && ok[v] && ( ( d1[u] + w + d2[v] == d1[n] ) || ( d1[v] + w + d2[u] == d1[n] ) ) ){
            if( u != n && v != 1 ){
                add_edge( u+n , v , 1 );
                add_edge( v , u+n , 0 );
            }

            if( v != n && u != 1 ){
                add_edge( v+n , u , 1 );
                add_edge( u , v+n , 0 );
            }
        }
    }

    cout << MAXFLOW() << '\n';
}
