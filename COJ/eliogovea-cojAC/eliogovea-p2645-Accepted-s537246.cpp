#include<iostream>
#include<algorithm>
using namespace std;

string s;
int c,ans,sum;

int main()
{
    while(cin >> c && c)
    {
        cin >> s;
        ans=sum=0;
        for(int i=0; i<s.size(); i++)
            sum+=(s[i]-'0');

        for(int i=0; i<s.size(); i++)
            ans=(c*ans+(s[i]-'0'))%sum;

        if(ans)cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}