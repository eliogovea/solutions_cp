#include<cstdio>
#include<algorithm>
using namespace std;

int a[26],c;

int main()
{
    scanf("%d",&c);
    while(c--)
    {
        for(int i=0; i<26; i++)
            scanf("%d",&a[i]);
        sort(a,a+26);

        for(int i=25; i>=0 && a[i]; i--)
            for(int j=0; j<a[i]; j++)
            {
                int x=i+'a';
                printf("%c",char(x));
            }
        printf("\n");
    }
    return 0;
}
