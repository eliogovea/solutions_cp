#include<cstdio>
#include<algorithm>
#include<queue>
#define MAXN 1010
using namespace std;

typedef pair<int,pair<int,int> >pp;

const int mov[4][2]={1,0,0,1,-1,0,0,-1};

int n;
char map[MAXN][MAXN];
int dist[MAXN][MAXN],x1,x2,y1,y2;
bool mark[MAXN][MAXN];

priority_queue<pp,vector<pp>,greater<pp> > Q;

int main()
{
	scanf("%d",&n);

	for(int i=1; i<=n; i++)
	{
		scanf("%s",map[i]+1);
		for(int j=1; j<=n; j++)
			dist[i][j]=1<<29;
	}
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);

	dist[x1][y1]=0;
	Q.push(make_pair(0,make_pair(x1,y1)));

	while(!Q.empty())
	{
		int d=Q.top().first;
		int x=Q.top().second.first;
		int y=Q.top().second.second;

		Q.pop();

		if(mark[x][y])continue;
		mark[x][y]=1;

		for(int r=0; r<4; r++)
		{
			int nx=x+mov[r][0];
			int ny=y+mov[r][1];
			int cal=((map[nx][ny]-'0')-(map[x][y]-'0') > 0)?(map[nx][ny]-'0')-(map[x][y]-'0'):0;

			if(d + cal < dist[nx][ny])
			{
				dist[nx][ny]=d+cal;
				Q.push(make_pair(dist[nx][ny],make_pair(nx,ny)));
			}
		}
	}
    printf("%d\n",dist[x2][y2]);
}
