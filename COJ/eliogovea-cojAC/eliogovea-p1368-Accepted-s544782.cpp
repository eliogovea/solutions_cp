#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;


int n;
double pts[15][2],G[15][15];
double ans=1e9;
vector<int> v;

double dist(double x1, double y1, double x2, double y2)
{
	return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}

int main()
{
	scanf("%d",&n);
	v.resize(n);
	for(int i=0; i<n; i++)
	{
		scanf("%lf%lf",&pts[i][0],&pts[i][1]);
		v[i]=i;
	}

	do
	{
		double aux=0.0;
		for(int i=0; i<n-1; i++)
            aux+=dist(pts[v[i]][0],pts[v[i]][1],pts[v[i+1]][0],pts[v[i+1]][1]);
        ans=min(ans,aux);
	}while(next_permutation(v.begin(),v.end()));

	printf("%.2lf\n",ans);
}
