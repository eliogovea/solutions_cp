#include<iostream>
using namespace std;

string a;

int main()
{
    while(getline(cin,a))
    {
        int l=a.size();
        int c=0;
        for(int i=0; i<l; i++)
        {
            if(a[i]=='#')
            {
                c++;
                i++;
                continue;
            }
            if(a[i]=='@')
            {
                c--;
                i++;
                continue;
            }
            if(!c)cout << a[i];
        }
        cout << endl;
    }
    return 0;
}
