// 2015 V (XVI) Volga Region Open Team Student Programming Contest
// 100703F

#include <bits/stdc++.h>

using namespace std;

const int oo = (1<<30);
const int MAXV = 500;
const int MAXE = 1000010;

struct edge{
    int dest;
    int cap, flow, cost;
    int next;
    edge(){}
    edge(int dest, int cap, int cost, int next) :
        dest(dest), cap(cap), cost(cost), next(next){flow = 0;}
};
int nodes, source, sink;
int size;

edge g[MAXE];
int first[MAXV];
int nLast[MAXV]; //last node
int eLast[MAXV]; //last edge
int cst[MAXV];

void initialize_MFMC(int __nodes, int __source, int __sink){
    size = 0;
    nodes = __nodes;
    source = __source;
    sink = __sink;
    for(int i = 0; i < nodes; i++)
        first[i] = -1;
}

//para adicionar un arco no-dirigido (i,j)
//esta funcion debe llamarse dos veces
//desde i->j y desde j->i
void addEdge(int u, int v, int c, int cost){
    g[ size ] = edge(v, c, +cost, first[u]);
    first[u] = size++;
    g[ size ] = edge(u, 0, -cost, first[v]);
    first[v] = size++;
}

typedef pair<int,int> pii;
pii maxFlowMinCost(int F){
    int flow = 0; int flowCost = 0;

    while(flow < F){
        priority_queue<pii> Q;
        for (int i = 0; i < nodes; i++)
            cst[i] = oo;

        cst[source] = 0;
        Q.push(make_pair(0, source));
        while(!Q.empty()){
            int u = Q.top().second;
            int c = -Q.top().first;
            Q.pop();
            if(u == sink) break;
            for(int k = first[u]; k != -1; k = g[k].next){
                int newU = g[k].dest;
                int newC = g[k].cost + c;
                if (g[k].cap > g[k].flow && newC < cst[newU]){
                    cst[newU] = newC;
                    //keep track//
                    nLast[newU] = u;
                    eLast[newU] = k;
                    //keep track//
                    Q.push(make_pair(-newC, newU));
                }
            }
        }
        if (cst[sink] == oo) break;
        int push = oo;
        for (int u = sink; u != source; u = nLast[u])
            push = min(push, g[ eLast[u] ].cap - g[ eLast[u] ].flow);
        if(flow + push > F) push = F - flow;
        flow += push;
        flowCost += cst[sink] * push;
        for(int u = sink; u != source; u = nLast[u]){
            g[ eLast[u]   ].flow += push;
            g[ eLast[u]^1 ].flow -= push;
        }
    }
    return make_pair(flow, flowCost);
}

int xs[MAXV];
int ys[MAXV];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int m,n; cin >> m >> n;

    for( int i = 1; i <= n; i++ ){
        cin >> xs[i];
    }

    for( int i = 1; i <= n; i++ ){
        cin >> ys[i];
    }

    int s = 0 , t = 3;
    int X = 1, Y = 2;

    initialize_MFMC( n + 4 , 0 , 3 );

    int cap1 = ( m / 2 )  + ( m % 2 );
    int cap2 = ( m / 2 );

    addEdge( s , X , cap1 , 0 );
    addEdge( s , Y , cap2 , 0 );

    for( int i = 1; i <= n; i++ ){
        addEdge( i + 3 , t , 1 , 0 );

        addEdge( X , i + 3 , 1 , xs[i] );
        addEdge( Y , i + 3 , 1 , ys[i] );
    }

    pii MCMF = maxFlowMinCost(oo);

    int outp = MCMF.second;

    initialize_MFMC( n + 4 , 0 , 3 );

    addEdge( s , Y , cap1 , 0 );
    addEdge( s , X , cap2 , 0 );

    for( int i = 1; i <= n; i++ ){
        addEdge( i + 3 , t , 1 , 0 );

        addEdge( X , i + 3 , 1 , xs[i] );
        addEdge( Y , i + 3 , 1 , ys[i] );
    }

    MCMF = maxFlowMinCost(oo);
    outp = min( outp , MCMF.second );

    cout << outp << '\n';
}
