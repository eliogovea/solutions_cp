#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

bool flag,b;
string s;
vector<int>v;

int main()
{
    for(int i=1; i<=5; i++)
    {
        cin >> s;

        if(s.size()>=3)
        {
            for(int j=0; j<=s.size()-3; j++)
            {
                if(s[j]=='F' && s[j+1]=='B' && s[j+2]=='I')
                {
                    v.push_back(i);
                    flag=1;
                    break;
                }
            }
        }

    }
    if(flag)
        {
            for(int i=0; i<v.size()-1; i++)
                cout << v[i] << " ";
            cout << v[v.size()-1] << endl;
        }

    else cout << "HE GOT AWAY!" << endl;
}
