#include<cstdio>
#include<queue>
#define MAXN 110
using namespace std;

const int mov[4][2]={1,0,-1,0,0,1,0,-1};

int n,m,mat[MAXN][MAXN],d[MAXN][MAXN];
queue<pair<int,int> > Q;

int main()
{
	scanf("%d%d",&n,&m);

	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
		{
			d[i][j]=1<<29;
			scanf("%d",&mat[i][j]);
		}

	for(int i=1; i<=n; i++)
	{
		d[i][1]=mat[i][1];
		Q.push(make_pair(i,1));
	}

	while(!Q.empty())
	{
		int i=Q.front().first;
		int j=Q.front().second;

		Q.pop();

		for(int k=0; k<4; k++)
		{
			int ni=i+mov[k][0];
			int nj=j+mov[k][1];

			if(d[ni][nj] > d[i][j] + mat[ni][nj])
			{
				d[ni][nj] = d[i][j] + mat[ni][nj];
				Q.push(make_pair(ni,nj));
			}
		}
	}

	int mn=1<<29;

	for(int i=1; i<=n; i++)
		mn=min(mn,d[i][m]);

	printf("%d\n",mn);
}
