#include<cstdio>
#include<cstring>

char n[10];
int l;

int main()
{
    for(int i=0; i<1000; i++)
    {
        scanf("%s",&n);
        l=strlen(n);
        if(l>1 && n[l-1]=='0' )
            printf("2\n");
        else printf("1\n%c\n",n[l-1]);
    }
    return 0;
}
