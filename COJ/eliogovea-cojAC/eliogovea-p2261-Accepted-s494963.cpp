#include<cstdio>
#include<vector>
using namespace std;
bool sieve[2311];

vector<int> p;
int n,cp[2311],x;

int main()
{
    for(int i=2; i<=2310; i++)sieve[i]=1;

    for(int i=2; i*i<=2310; i++)
        if(sieve[i])
            for(int j=i*i; j<=2310; j+=i)sieve[j]=0;

    for(int i=2; i<=2310; i++)if(sieve[i])p.push_back(i);

    for(int i=0; i<p.size(); i++)
        for(int j=p[i]; j<=2310; j+=p[i])cp[j]++;

    scanf("%d",&n);
    bool b=1;
    for(int i=0; i<n; i++)
    {
        scanf("%d",&x);
        if(cp[x]<3)
            b=0;
    }
    if(b)printf("YES\n");
    else printf("NO\n");
    return 0;
}
