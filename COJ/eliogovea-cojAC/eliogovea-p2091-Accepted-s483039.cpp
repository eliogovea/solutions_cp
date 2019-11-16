#include<iostream>
#include<cstring>
using namespace std;

bool b[123];
char a[10000];
int c,ans;

int main()
{
    cin >> c;

    while(c--)
    {
        cin >> a;

        int l=strlen(a);

        for(int i=0; i<l; i++)b[a[i]]=1;

        for(int i=48; i<=122; i++)
        {
            if(b[i])ans++;
            b[i]=0;
        }
        cout << ans << endl;
        ans=0;
    }

    return 0;
}
