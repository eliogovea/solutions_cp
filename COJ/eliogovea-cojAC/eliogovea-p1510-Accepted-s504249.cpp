#include<cstdio>
#include<cstring>
int n,l,k;
char a[100];

int main()
{
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%s",&a);
        l=strlen(a);
        for(int j=0; j<l; j+=k)
        {
            k=1;
            while(j+k<l && a[j]==a[j+k])k++;
            if(k>9)
            {
                printf("@");
                for(int r=1; 9*r<=k; r++)
                    printf("9%c",a[j]);
                if(k%9)
                {
                    if(k%9<=3)
                        for(int r=1; r<=k%9; r++)
                            printf("%c",a[j]);
                    else printf("%d%c",k%9,a[j]);
                }
            }
            else if(k>3 && k<=9)
                printf("@%d%c",k,a[j]);

            else if(k<=3)
                for(int r=1; r<=k; r++)
                    printf("%c",a[j]);
        }
        printf("\n");
    }
    return 0;
}
