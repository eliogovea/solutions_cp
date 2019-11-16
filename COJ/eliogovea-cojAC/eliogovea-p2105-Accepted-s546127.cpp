#include<cstdio>
#include<vector>
#include<queue>
#define MAXN 1001
using namespace std;

const int mov[4][2]={1,0,-1,0,0,1,0,-1};

int n,m,ans;
char mat[MAXN][MAXN],line[MAXN];
bool mark[MAXN][MAXN];
queue<pair<int,int> > Q;

bool is(int a, int b)
{
	bool f=0;
	for(int i=0; i<4; i++)
		f|=(mat[a+mov[i][0]][b+mov[i][1]]=='-');
	return f;
}

int main()
{
	scanf("%d%d",&n,&m);

	for(int i=1; i<=n; i++)
		scanf("%s",mat[i]+1);

	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			if(mat[i][j]=='+' && !mark[i][j])
			{
				ans+=is(i,j);
				mark[i][j]=1;
				Q.push(make_pair(i,j));

				while(!Q.empty())
				{
					int ii=Q.front().first;
					int jj=Q.front().second;

					Q.pop();

					for(int k=0; k<4; k++)
					{
						int ni=ii+mov[k][0];
						int nj=jj+mov[k][1];

						if(!mark[ni][nj] && mat[ni][nj]=='+')
                        {
                            mark[ni][nj]=1;
                            ans+=is(ni,nj);
                            Q.push(make_pair(ni,nj));
                        }

					}

				}
			}

	printf("%d\n",ans);
}
