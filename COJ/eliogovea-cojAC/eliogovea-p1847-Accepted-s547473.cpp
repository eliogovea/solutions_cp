#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#define MAXN
using namespace std;

struct point{
    int ind,x,y;
    bool operator<(const point &A)const
    {
        return (x!=A.x)?(x<A.x):(y<A.y);
    }
};

double dist(point &A, point &B)
{
	return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}

int n,a,b;
double min_dist=1e10;

vector<point> P;

void find_min(int lo, int hi)
{
	if(lo>=hi)return;

	int	mid=(lo+hi)>>1;

	find_min(lo,mid);
	find_min(mid+1,hi);

	while(P[mid].x-P[lo].x >= min_dist)lo++;
	while(P[hi].x-P[mid].x >= min_dist)hi--;

	for(int i=lo; i<hi; i++)
		for(int j=i+1; j<=hi; j++)
			if(min_dist > dist(P[i],P[j]))
			{
				min_dist = dist(P[i],P[j]);
				a=P[i].ind;
				b=P[j].ind;
			}
}

int main()
{
	scanf("%d",&n);
	P.resize(n);

	for(int i=0; i<n; i++)
	{
		P[i].ind=i+1;
		scanf("%d%d",&P[i].x,&P[i].y);
	}
	sort(P.begin(),P.end());
	find_min(0,n-1);
	if(a>b)swap(a,b);
	printf("%d %d\n",a,b);
}
