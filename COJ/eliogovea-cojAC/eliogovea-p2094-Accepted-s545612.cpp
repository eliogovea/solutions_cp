#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

const int mov[4][2]={1,0,-1,0,0,1,0,-1};

int n,m,cant,mx;
char line[100010];
vector<vector<char> > mat;
queue<pair<int,int> > Q;

int main()
{
	scanf("%d%d",&n,&m);
	mat.resize(n+2);
	for(int i=0; i<=n+1; i++)
		mat[i].resize(m+2);

	for(int i=1; i<=n; i++)
	{
		scanf("%s",line+1);
		for(int j=1; j<=m; j++)
			mat[i][j]=line[j];
	}

	/*for(int i=0; i<=n+1; i++)
    {
        for(int j=0; j<=m+1; j++)
            printf("%c",mat[i][j]!=(char(0))?mat[i][j]:'x');
        printf("\n");
    }*/

	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			if(mat[i][j]=='1')
			{
				cant++;
				int k=0;
				mat[i][j]='0';
				Q.push(make_pair(i,j));

				while(!Q.empty())
				{
					int ii=Q.front().first,
						jj=Q.front().second;

                    k++;

					Q.pop();

					for(int k=0; k<4; k++)
					{
						int ni=ii+mov[k][0];
						int nj=jj+mov[k][1];
						if(mat[ni][nj]=='1')
                        {
                            mat[ni][nj]='0';
                            Q.push(make_pair(ni,nj));
                        }

					}
				}
				mx=max(mx,k);
			}
	printf("%d %d\n",cant,mx);
}
