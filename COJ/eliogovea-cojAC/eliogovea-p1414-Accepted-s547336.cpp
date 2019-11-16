#include<cstdio>
#include<iostream>
#include<queue>
#define MAXN 8
using namespace std;

const int mov[][2]={{1,2},{2,1},{-1,2},{2,-1},{1,-2},{-2,1},{-1,-2},{-2,-1}};
int tab[8][8][8][8];
queue<pair<int,int> >Q;

void BFS(int i, int j)
{
	tab[i][j][i][j]=0;
	for(int ii=0; ii<8; ii++)
		for(int jj=0; jj<8; jj++)
			tab[i][j][ii][jj]=1<<29;

	tab[i][j][i][j]=0;
	Q.push(make_pair(i,j));
	while(!Q.empty())
	{
		int ii=Q.front().first;
		int jj=Q.front().second;
		Q.pop();

		for(int r=0; r<8; r++)
		{
			int ni=ii+mov[r][0];
			int nj=jj+mov[r][1];

			if(ni>=0 && ni<8 && nj>=0 && nj<8)
				if(tab[i][j][ni][nj] > tab[i][j][ii][jj]+1)
				{
					tab[i][j][ni][nj] = tab[i][j][ii][jj]+1;
					Q.push(make_pair(ni,nj));
				}
		}

	}
}

int p1i,p1j,p2i,p2j;
string line;
char pos1[2],pos2[2],pc1,pc2;

int main()
{
	for(int i=0; i<8; i++)
		for(int j=0; j<8; j++)
			BFS(i,j);

    while(getline(cin,line))
    {
        if(line=="## ##")return 0;
        int p1i=line[0]-'a';
        int p1j=line[1]-'0'-1;
        int p2i=line[3]-'a';
        int p2j=line[4]-'0'-1;
        int ans=tab[p1i][p1j][p2i][p2j];
        cout << "To get from " << line[0] << line[1] << " to " << line[3] << line[4]
            <<  " takes " << ans << " knight moves." << endl;
    }
}
