#include<cstdio>

int a[26],c;
char n[30];

int main()
{
    scanf("%d",&c);
    while(c--)
    {
        scanf("%s",&n);
        int i=n[0]-'a';
        a[i]++;
    }
    bool b=1;
    for(int i=0; i<26; i++)
        if(a[i]>=5)
        {
            b=0;
            int j=i+'a';
            printf("%c",char(j));
        }
    if(b)printf("PREDAJA");
    printf("\n");
    return 0;
}
