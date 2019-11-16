#include<iostream>
#include<algorithm>
using namespace std;

string s;
int c,ans;


int main()
{
    for(cin >> c; c--;)
    {
        cin >> s;
        reverse(s.begin(),s.end());
        for(int i=0; i<s.size(); i++)
            if(s[i]=='1')
            {
                if(i&1)ans=(ans+1)%3;
                else ans=(ans+2)%3;
            }

        if(ans%3)cout << "NO" << endl;
        else cout << "YES" << endl;
        ans=0;
        //cout << ans << endl << endl;
    }
}
