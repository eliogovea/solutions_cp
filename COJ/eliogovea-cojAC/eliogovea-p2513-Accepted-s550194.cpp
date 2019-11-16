#include<cstdio>
#include<set>
#include<algorithm>
#define MAXN 1000
using namespace std;

typedef pair<int,int> punto;
typedef pair<int,pair<int,int> > recta;

recta R(punto P1, punto P2)
{
	recta r;
	int a = P2.second - P1.second;
	int b =P1.first - P2.first;
	int c = P1.first*P2.second - P2.first*P1.second;

	if(a<0 || a==0 && b<0){a=-a; b=-b; c=-c;}
	int d=1;
	if(a)d=__gcd( abs(a), __gcd( abs(b), abs(c) ) );
	else if(b||c)d=__gcd( abs(b), abs(c) );

	a/=d;
	b/=d;
	c/=d;

	return make_pair(a,make_pair(b,c));
}

int n;
punto pts[MAXN+10];
set<recta> s;

int main()
{
	while(scanf("%d",&n) && n)
	{
		s.clear();
		for(int i=1; i<=n; i++)
		{
			scanf("%d%d",&pts[i].first,&pts[i].second);
			for(int j=1; j<i; j++)
				s.insert(R(pts[i],pts[j]));
		}
		printf("%d\n",s.size());
	}
}
