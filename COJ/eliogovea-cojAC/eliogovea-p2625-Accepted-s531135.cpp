#include<cstdio>

char c[3]={'O','I','E'};
int n,m;

int main()
{
    scanf("%d%d",&n,&m);

    for(int i=0; i<n; i++)
    {
        int r=i%3;
        for(int j=0; j<m; j++,r=(r+1)%3)
            printf("%c",c[r]);
        printf("\n");
    }
}
