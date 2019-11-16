#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

char s[100000];
int ans,i,b[(1<<18)+1];

int main()
{
    cin >> s;
    int l = strlen(s);

    for(i=1; l+1-i >= 1<<(i-1); i++)
    {
        for(int j=0; j<l+1-i; j++)
        {
            int n=0,p2=1;
            for(int k=j+i-1; k>=j;k--)
            {
                n+=p2*(s[k]-'0');
                p2*=2;
            }
            b[n]=i;
        }
        for(int j=0; j<1<<i; j++)
        {
            if(b[j]!=i)
            {
                ans=i;
                break;
            }
        }
        if(ans)break;
    }

    if(ans)cout<< ans << endl;
    else cout<< i << endl;
    return 0;
}
