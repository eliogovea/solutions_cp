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

    for(int i=0; i<k; i++)
    {
        if(n&(1<<i))s+='7';
        else s+='4';
    }

    reverse(s.begin(),s.end());

    printf("%s\n",s.c_str());
}
