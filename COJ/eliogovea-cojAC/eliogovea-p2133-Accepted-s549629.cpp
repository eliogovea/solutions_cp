#include<iostream>
#include<cstdio>
#include<vector>
#define MAXN 30
using namespace std;

struct point{int x,y;};
struct circ{int x,y,r;};
struct rect{int x1,y1,x2,y2;};

bool insidec(point a, circ c)
{
	return ((a.x-c.x)*(a.x-c.x)+(a.y-c.y)*(a.y-c.y) <= c.r*c.r);
}

bool insider(point a, rect r)
{
	return ( a.x>=r.x1 && a.x<=r.x2 && a.y>=r.y1 && a.y<=r.y2);
}

string tip;
int n;
point P;
circ c;
rect r;
vector<circ> ac;
vector<circ>::iterator cit;
vector<rect> ar;
vector<rect>::iterator rit;

int main()
{
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		cin >> tip;
		if(tip=="rectangle")
		{
			scanf("%d%d%d%d",&r.x1,&r.y1,&r.x2,&r.y2);
			ar.push_back(r);
		}
		else
		{
			scanf("%d%d%d",&c.x,&c.y,&c.r);
			ac.push_back(c);
		}
	}
    scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		scanf("%d%d",&P.x,&P.y);
		int cant=0;
		for(cit=ac.begin(); cit!=ac.end(); cit++)
			cant+=insidec(P,*cit);
		for(rit=ar.begin(); rit!=ar.end(); rit++)
			cant+=insider(P,*rit);
		printf("%d\n",cant);
	}
}
