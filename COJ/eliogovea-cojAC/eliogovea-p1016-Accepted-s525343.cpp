#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>
#define MAXN 110
using namespace std;

struct next
{
    int nodo;
    double costo;
    next(int a, double b)
    {
        nodo=a;
        costo=b;
    }
    bool operator<(const next &x)const
    {
        return costo>x.costo;
    }
};

double dist(double x1, double y1, double x2, double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

priority_queue<next> Q;

int n,act;
bool mark[MAXN];
double p[MAXN][2],G[MAXN][MAXN],sol,cost;

int main()
{
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%lf%lf",&p[i][0],&p[i][1]);
        for(int j=0; j<i; j++)
            G[i][j]=G[j][i]=dist(p[i][0],p[i][1],p[j][0],p[j][1]);
    }

    Q.push(next(0,0.0));
    while(!Q.empty())
    {
        act = Q.top().nodo;
        cost = Q.top().costo;
        Q.pop();

        if(!mark[act])
        {
            mark[act]=1;
            sol+=cost;
            for(int i=0; i<n; i++)
                if(!mark[i])
                    Q.push(next(i,G[act][i]));
        }
    }
    printf("%.2lf\n",sol);
    return 0;
}
