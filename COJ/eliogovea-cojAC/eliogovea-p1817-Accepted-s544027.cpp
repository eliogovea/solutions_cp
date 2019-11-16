#include<cstdio>
#include<vector>
#define MAXC 1000010
#define MAX 1000000
using namespace std;

vector<int> p;
vector<int>::iterator vit;
bool s[MAXC];
int n,x,c1,c2,a1[MAXC],a2[MAXC];
int main()
{
    for(int i=2; i*i<=MAX; i++)
        for(int j=i*i; j<=MAX; j+=i)
            if(!s[j])s[j]=1;

    for(int i=2; i<=MAX; i++)
        if(!s[i])p.push_back(i);

    for(vit=p.begin(); vit!=p.end(); vit++)
    {
        for(int j=*vit; j<=MAX; j+=*vit)
            a1[j]++;
        for(int i=1; i*(*vit)<=MAX; i++)
            a2[i]++;
    }

    for(scanf("%d",&n);n--;)
    {
        scanf("%d",&x);
        printf("%d %d\n",a1[x],a2[x]);
    }
}
