#include<cstdio>
#include<vector>
using namespace std;
const int MAX=1000001;
bool sieve[MAX];
int sd[MAX],k[MAX],c,a,b,f,sol[MAX][14];

vector<int> p;

int main()
{
    for(int i=2; i<MAX; i++)sieve[i]=1;

    for(int i=2; i*i<MAX; i++)
        if(sieve[i])
            for(int j=i*i; j<MAX; j+=i)sieve[j]=0;

    for(int i=2; i<MAX; i++)if(sieve[i])p.push_back(i);

    for(int i=0; i<p.size(); i++)
        for(int j=2*p[i]; j<MAX; j+=p[i])sd[j]+=p[i];

    for(int i=2; i<MAX; i++)
    {
        int j=i;
        while(j)
        {
            k[i]++;
            j=sd[j];
        }
    }


    for(int i=2; i<MAX; i++)
        for(int j=0; j<=12; j++)sol[i][j]=sol[i-1][j]+(k[i]==j);

    scanf("%d",&c);
    while(c--)
    {
        scanf("%d%d%d",&a,&b,&f);
        if(f>12)printf("0\n");
        else printf("%d\n",sol[b][f]-sol[a-1][f]);
    }
    return 0;
}
