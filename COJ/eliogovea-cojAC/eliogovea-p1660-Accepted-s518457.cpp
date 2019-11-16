#include<cstdio>
#include<vector>
#include<queue>
#include<limits.h>
#define MAXN 1002
using namespace std;

typedef pair<int,int> p;
typedef vector<p>::iterator pii;

const int mov[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

int mat[MAXN][MAXN],cost[2][MAXN][MAXN];
p B,N;
vector<p> St;
queue<p> Q;
int w,h,s=1<<29;



void BFS(int x, p start)
{
	cost[x][start.first][start.second]=0;
	for(Q.push(start);!Q.empty();Q.pop())
	{
		for(int k=0; k<4; k++)
		{
			p aux = Q.front();
			int dx=aux.first+mov[k][0],
				dy=aux.second+mov[k][1];
			if(mat[dx][dy]==1 || mat[dx][dy]==3)continue;
			if(cost[x][dx][dy] > cost[x][aux.first][aux.second]+1)
			{
				cost[x][dx][dy] = cost[x][aux.first][aux.second]+1;
				Q.push(p(dx,dy));
			}
		}
	}
}

int main()
{
	scanf("%d%d",&w,&h);
	for(int i=1; i<=h; i++)
		for(int j=1; j<=w; j++)
		{
			scanf("%d",&mat[i][j]);
			cost[0][i][j]=cost[1][i][j]=1<<29;
			if(mat[i][j]==2)
				B = p(i,j);
			if(mat[i][j]==3)
				N = p(i,j);
			if(mat[i][j]==4)
				St.push_back(p(i,j));
		}
	BFS(0,B);
	BFS(1,N);

	for(pii ii=St.begin(); ii!=St.end(); ii++)
		s=min(s,cost[0][ii->first][ii->second]+cost[1][ii->first][ii->second]);

	printf("%d\n",s);
	return 0;
}
