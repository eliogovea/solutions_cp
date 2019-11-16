#include<cstdio>
#include<queue>
#define MAXN 110
using namespace std;

typedef pair<int,int> pii;

const int mov[8][2]={1,0,-1,0,0,1,0,-1,1,1,1,-1,-1,1,-1,-1};

int n,cant,mx,mn,c;
char mat[MAXN][MAXN];

queue<pii> Q;

int main()
{
	while(scanf("%d",&n) && n)
	{
		for(int i=1; i<=n; i++)
			scanf("%s",mat[i]+1);

        for(int i=0; i<=n; i++)
            mat[n+1][i]=' ';

		mx=-1;
		mn=100000;

		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				if(mat[i][j]=='l')
				{
					cant++;
					c=1;
					mat[i][j]='s';
					Q.push(pii(i,j));
					while(!Q.empty())
					{
						int nx=Q.front().first,
							ny=Q.front().second;

                        Q.pop();

						for(int i=0; i<8; i++)
						{
							int dx=nx+mov[i][0],
								dy=ny+mov[i][1];
							if(mat[dx][dy]=='l')
							{
								mat[dx][dy]='s';
								c++;
								Q.push(pii(dx,dy));
							}
						}
					}
					mx=max(mx,c);
					mn=min(mn,c);
				}
		printf("%d %d %d\n",cant,cant?mn:0,cant?mx:0);
		cant=0;
	}
}
