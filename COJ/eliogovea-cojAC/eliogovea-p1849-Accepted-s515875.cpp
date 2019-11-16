#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int t,l,b;

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&l,&b);
        printf("%.4f\n",(double(l))*sqrt(l*l-abs(b-l)*abs(b-l)));
    }
    return 0;
}
