#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

typedef pair<int,int> pii;

const int mov[8][2]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};

char mat[110][110];
int R,C,x,y,ans,dx,dy,m1[110][110];
queue<pii> Q;

int main()
{
	scanf("%d%d%d%d",&C,&R,&x,&y);

	for(int i=1; i<=R; i++)
        scanf("%s",mat[i]+1);

    y=R+1-y;

	Q.push(pii(y,x));
	mat[y][x]='*';

	while(!Q.empty())
	{
		x=Q.front().first;
		y=Q.front().second;
		Q.pop();

		for(int i=0; i<8; i++)
		{
			dx=x+mov[i][0];
			dy=y+mov[i][1];

			if(mat[dx][dy]=='.')
					mat[dx][dy]='*',
					m1[dx][dy]=m1[x][y]+1,
					ans=max(ans,m1[dx][dy]),
					Q.push(pii(dx,dy));
		}
	}

	printf("%d\n",ans);
	return 0;
}
