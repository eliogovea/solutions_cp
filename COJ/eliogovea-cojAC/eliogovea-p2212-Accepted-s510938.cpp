#include<iostream>
#include<cstring>
using namespace std;

char d[26],b[26],l[26];
int diet[26];
int c;

int main()
{
    cin >> c;
    while(c--)
    {
        cin >> d >> b >> l;
        bool f=1;
        for(int i=0; i<strlen(d); i++)
        {
            int x = d[i]-'A';
            diet[x]=1;
        }
        for(int i=0; i<strlen(b); i++)
        {
            int x=b[i]-'A';
            if(diet[x]==0 || diet[x]==2)
            {
                f=0; break;
            }
            else diet[x]++;
        }
        for(int i=0; i<strlen(l); i++)
        {
            int x=l[i]-'A';
            if(diet[x]==0 || diet[x]==2)
            {
                f=0;break;
            }
            else diet[x]++;
        }
        if(f)
        {
            for(int i=0; i<26; i++)
                if(diet[i]==1)
                    {
                      int x=i+'A';
                      cout << char(x);
                    }
            cout << endl;
        }
        else cout << "CHEATER" << endl;

        for(int i=0; i<26; i++)
            diet[i]=0;
    }
}
