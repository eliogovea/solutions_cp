#include<cstdio>
#include<cmath>

int a,b;
int ans;

int main()
{
	while(scanf("%d%d",&a,&b)==2)
	{
	    ans=0;
	    for(int i=1; i*i*i*i*i*i<=b; i++)ans++;
	    for(int i=1; i*i*i*i*i*i<a; i++)ans--;
	    printf("%d\n",ans);
	}
}
