#include<cstdio>
#include<cstring>
int ca;
double c,d,ans;

int main()
{
    for(scanf("%d",&ca); ca--;)
    {
        scanf("%lf%lf",&c,&d);

        ans=(c*d/(c+d))*(c*d/(c+d));

        char a[100];
        sprintf(a,"%.4lf",ans);

        int l=strlen(a),mark=0;
        for(int i=l-1; i>=0; i--)
            if(a[i]!='0')
            {
                mark=i;
                break;
            }

        for(int i=0; i<=mark; i++)
            printf("%c",a[i]);

        printf("\n");
    }
    return 0;
}
