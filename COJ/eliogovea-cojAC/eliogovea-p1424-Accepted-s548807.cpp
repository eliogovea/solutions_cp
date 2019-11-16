#include<cstdio>
#include<cmath>
#include<string.h>
#include<algorithm>
using namespace std;

int n,arr[20];
double memo[1<<16];

double area(int a, int b, int c)
{
	if(2.0*max(a,max(b,c)) >= a+b+c)return 0;

	double aa=double(a);
	double bb=double(b);
	double cc=double(c);
	double sp=0.5*(aa+bb+cc);

	return sqrt(sp*(sp-aa)*(sp-bb)*(sp-cc));
}

double DP(int bit_mask)
{

	if(memo[bit_mask] > -0.5)
		return memo[bit_mask];

	double aux=0.0;

	for(int i=0; i<n; i++)
		if(!(bit_mask & (1<<i)))
		{
			for(int j=i+1; j<n; j++)
				if(!(bit_mask & (1<<j)))
				{
					for(int k=j+1; k<n; k++)
                    {
                        if(!(bit_mask & (1<<k)))
							aux=max(aux,area(arr[i],arr[j],arr[k])
										+DP(bit_mask|(1<<i)|(1<<j)|(1<<k)));
                    }
				}
		}
	return memo[bit_mask]=aux;
}

int main()
{
	while(scanf("%d",&n)==1)
	{

		memset(arr,0,sizeof arr);
		memset(memo,-1.0,sizeof memo);

		for(int i=0; i<n; i++)
			scanf("%d",&arr[i]);

		printf("%.4lf\n",DP(0));
	}
}

