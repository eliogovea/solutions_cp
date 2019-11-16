#include<cstdio>
#include<algorithm>
#define MAXN 50000
#define MOD 1000000009
using namespace std;

int cas,n;
int ceros;
long long arr[MAXN+10],sum,cant,maxe,cantme;

int main()
{
	for(scanf("%d",&cas); cas--;)
	{
		scanf("%d",&n);

		maxe=-(long long)1e9-100ll;


		for(int i=0; i<n; i++)
			scanf("%lld",&arr[i]);

		sort(arr,arr+n);

		maxe=arr[n-1];

		if(maxe>0)
        {
            int k=n-1;
            sum=0ll;
            while(k>=0 && arr[k]>0)
                sum=(sum+arr[k]%MOD),
                k--;

            ceros=0;
            while(k>=0 && arr[k]==0)
                ceros++,
                k--;
            //printf("%d\n",ceros);
            cant=1;
            for(int i=1; i<=ceros; i++)
                cant=(cant*2)%MOD;
            printf("%lld %lld\n",sum,cant);
        }
        else if(maxe==0)
        {
            int k=n-1;
            ceros=0;
            while(k>=0 && arr[k]==maxe)
                ceros++,
                k--;
            cant=1;
            for(int i=1; i<=ceros; i++)
                cant=(cant*2)%MOD;
            printf("0 %lld\n",(cant-1+MOD)%MOD);
        }
        else
        {
            int k=n-1;
            cantme=0;
            while(k>=0 && arr[k]==maxe)
                cantme++,
                k--;
            printf("%lld %lld\n",maxe,cantme);
        }
	}
}
