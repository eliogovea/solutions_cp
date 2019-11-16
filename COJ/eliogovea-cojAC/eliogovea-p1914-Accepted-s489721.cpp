#include<cstdio>

long long pts[10000][2],n,q,xc,yc,r,c;

int main()
{
    scanf("%d%d",&n,&q);
    for(int i=0; i<n; i++)scanf("%d%d",&pts[i][0],&pts[i][1]);

    for(int i=0; i<q; i++)
    {
        scanf("%d%d%d",&xc,&yc,&r);
        c=0;
        for(int j=0; j<n; j++)
            if((pts[j][0]-xc)*(pts[j][0]-xc)+(pts[j][1]-yc)*(pts[j][1]-yc) <= r*r)c++;

        printf("%d\n",c);
    }
    return 0;
}
