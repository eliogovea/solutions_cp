#include<cstdio>
#include<cstring>

char a[7];

bool e(char x[])
{
    int l=strlen(x);
    for(int i=0,j=l-1; i<j; i++,j--)
    {
        if((x[i]-'0')<(x[j]-'0'))return 1;
        else if((x[i]-'0')>(x[j]-'0'))return 0;
    }
    return 0;
}

int main()
{
    while(scanf("%s",&a)!=EOF)
    {
        if(e(a))printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
