#include<cstdio>
#include<algorithm>
using namespace std;

int c,n,m,a[50];

int main()
{
    for(scanf("%d",&c);c--;)
    {
        scanf("%d%d",&m,&n);
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);

        sort(a,a+n);

        int c=0,ac=0;
        for(;ac+a[c]<=m && c<n; ac+=a[c],c++);

        printf("%d\n",c);
    }
}
