#include<cstdio>
#include<queue>
using namespace std;
typedef pair<int,int> p;

const int mov[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

char mat[3240][4320];
int C,R;
long t;


queue<p> q;

int main()
{
	scanf("%d%d",&C,&R);
	for(int i=0; i<R; i++)
		scanf("%s",&mat[i]);

	for(int i=0; i<R; i++)
		for(int j=0; j<C; j++)
			if(mat[i][j]=='0')
			{
				t++;
				mat[i][j] = '1';
				for(q.push(p(i,j)); !q.empty(); q.pop())
					for(int r=0; r<4; r++)
					{
						int x=(q.front()).first+mov[r][0],
							y=(q.front()).second+mov[r][1];
						if(x>=0 && x<R && y>=0 && y<C)
							if(mat[x][y]=='0')
							{
								mat[x][y]='1';
								q.push(p(x,y));
							}
					}
			}
	printf("%d\n",t);
	return 0;
}


