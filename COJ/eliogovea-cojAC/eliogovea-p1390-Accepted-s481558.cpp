#include<cstdio>
#include<vector>
using namespace std;

const int MAX = 20001;

int n,a[MAX],x,maxfac,ans;

bool sieve[MAX];

vector<int> primos;

int main()
{
    for(int i=2; i<=MAX; i++)sieve[i]=1;

    for(int i=2; i*i<=MAX; i++)
    {
        if(sieve[i])
        {
            for(int j=i*i; j<=MAX; j+=i)sieve[j]=0;
        }
    }

    for(int i=2; i<=MAX; i++)if(sieve[i])primos.push_back(i);

    for(int i=0; i<primos.size(); i++)
        for(int j=primos[i]; j<=MAX; j+=primos[i])
            if(primos[i]>a[j])a[j]=primos[i];

    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&x);
        if(a[x]>maxfac)
        {
            ans=x;
            maxfac=a[x];
        }
    }

    printf("%d\n",ans);    
    
    return 0;
}
