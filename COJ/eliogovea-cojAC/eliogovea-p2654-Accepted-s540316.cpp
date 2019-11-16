#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

long n;
string s;

int main()
{
    scanf("%ld",&n);

    int k=0;
    while(n-(1<<k)>=0)
    {
        n-=(1<<k);
        k++;
    }

    for(int i=k-1; i>=0; i--)
       printf("%c",(n&(1<<i))?'7':'4');

    printf("\n");
}
